%{
#include <stdlib.h>
#include <stdio.h>
#include "sTable.c"
#include "iTable.c"
#include "pTable.c"

char string[16]; //Taille max du nom de variable
int count=0;
int nbrInstr=0;
int countIF=0;
int countELSE=0;
int countWHILE=0;
int varBool=0;
int countFUNCTION=0;
int countArgs=0;
int argsDeclared=0;
condition ifCond;
condition whileCond;
condition elseCond;
char funName[16];
void yyerror(char *s);
symbol * st; //symbol table
instruction * it; //instruction table
parameter * pt; //parameters table
%}

%union {int nb; char string[16];} //associer une étiquette à chaque entier
%token 
tMAIN tRETURN
tIF tWHILE
tPRINT tELSE
tAO tAF tPO tPF tV tPV
tEQUAL
tVOID
tINT tSTRING
tSUB tADD tMUL tDIV
tINF tSUP tEQEQ
tTRUE tFALSE
tCONST

%token <nb> tNB //Etiquette entier
%token <string> tID //Etiquette nom variable/fonction
%type <nb> Type
%type <string> FunCall
%type <nb> Operand
//%type <string> FunName
%start Program

%left tADD tSUB //Priorité à gauche
%left tMUL tDIV //Priorité à gauche

%%

//A MAIN IS OBLIGATORY AND ALL OTHER FUNCTIONS MUST BE DECLARED AFTER THE MAIN FUNCTION (TO AVOID MESSING WITH THE JMP INSTRUCTIONS OF THE FUNCTIONS)
Program: Main Functions;

Main: tVOID tMAIN tPO tPF tAO Body tAF{
  instruction end = addInstruction(it,"NOP",-1,-1,-1);
};

Functions: Function | Function Functions;

//INT MAIN AND VOID MAIN ARE BOTH POSSIBLE AND MEAN THE SAME THING
//DELETED FUNNAME AND ADDED 3 DIFFERENT CASES TO ADD JMP INSTRUCTIONS AT THE END OF FUNCTIONS OTHER THAN MAIN
Function: tINT tID tPO{
  incrementDepth("FUNCTION");
  strcpy(funName,$2);
  countArgs=0;
  }
  DecArgs tPF tAO{
  countFUNCTION=iTableSize;
} 
  Body
  tRETURN tID tPV {
    printf("!!!!!!!!!!!!!Patching COP Instruction!!!!!!!!!!!!!!!!\n");
    updateCOPInstruction(it,getAddrName(st,$11),$2);
  }
  tAF{
  int returnLine = findJMPLine(it,$2) + 1; 
  //FUNCTION THAT FINDS THE JMP INSTRUCTION GENERATED AT THE MOMENT OF CALLING THE FUNCTION AND
  //RETURNS THE CORRESPONDING ASM/INSTRUCTION LINE
  instruction i = addInstruction(it,"JMP",returnLine,-1,-1); 
 
  int functionAsmLines=iTableSize-countFUNCTION;
  int patch = i.num - functionAsmLines + 1;
  updateJMPInstructionFunction(it,patch,$2,argsDeclared);
  argsDeclared=0;

  deleteSymbols(st);
  print_sTable(st);
  decrementDepth("FUNCTION");
}

        | tVOID tID tPO{
  incrementDepth("FUNCTION");
  strcpy(funName,$2);
  countArgs=0;
          } DecArgs tPF tAO{
  countFUNCTION=iTableSize;
        } Body tAF{
  int returnLine = findJMPLine(it,$2) + 1; 
  instruction i = addInstruction(it,"JMP",returnLine,-1,-1);

  int functionAsmLines=iTableSize-countFUNCTION;
  int patch = i.num - functionAsmLines + 1;
  updateJMPInstructionFunction(it,patch,$2,argsDeclared); //THERE ARE AS MANY ADDITIONAL COP INSTRUCTIONS AS THERE ARE ARGS DECLARED. JMP INSTRUCTIONS MUST BE PATCHED ACCORDINGLY.
  argsDeclared=0;

  deleteSymbols(st);
  print_sTable(st);
  decrementDepth("FUNCTION"); 
        }
        | ;


FunCall: tID { strcpy(funName , $1); }  tPO{strcpy(funName,$1);} CallArgs tPF {
     instruction i = addInstructionWithFunctionName(it,"JMP",-1,-1,-1,$1); //PATCHED LATER 
};

DecArgs: tINT tID{
  
  argsDeclared++;
  //ADDING DECLARATED VARIABLES IN ()
  symbol local = addSymbol(st,$2,1);
  //instruction i = addInstruction(it,"COP",getAddrName(st,$3),sTableSize-1,-1);
  instruction i = addInstruction(it,"COP",local.addr,findPassedParameter(pt,funName,countArgs),-1);
  countArgs++;

} NextDecArg |;
NextDecArg: tV DecArgs |;

CallArgs: tID{
  addParameter(pt,funName,getAddrName(st,$1));
} CallArgNext
 | tNB CallArgNext
 |;

CallArgNext: tV CallArgs | ;

Type: tCONST { $$ = 2; } | { $$ = 1; }; //IF VAR THEN 1 IF CONST THEN 2


//FunName: tMAIN {varMain=1;} | tID {varMain=0;}; //TO AVOID DECLARATIONS OUTSIDE THE MAIN FUNCTION

Body: Instructions;
Instructions: Instruction Instructions |;
Instruction: FunCall tPV;
           | Print
           | VarDeclarationAndAssign
           | VarDeclaration 
           | VarAssign 
           | ifCondition
tAO { //DEPTH HANDELING
  incrementDepth("IF");
  countIF=iTableSize;
}
Body
tAF {
  int ifAsmLines=iTableSize-countIF;

  if (ifCond.arg2) {
    updateJMPInstruction(it, ifAsmLines);
  } 
  else if (ifCond.arg3){
    updateJMFInstruction(it, ifAsmLines);
  }
  elseCond = ifCond;
  ifCond = init_cond();

  deleteSymbols(st);
  print_sTable(st);
  decrementDepth("IF");
}
elseCondition

           | whileCondition
tAO { //DEPTH HANDELING
  incrementDepth("WHILE");
  countWHILE=iTableSize;

  if (whileCond.arg1) { //TRUE
    //instruction i = addInstruction(it,"JMP",-1,-1,-1); //PATCHED LATER    
  } 

}
Body
tAF {
  int whileAsmLines=iTableSize-countWHILE;

  if (whileCond.arg1) { //WHILE TRUE
    instruction i = addInstruction(it,"JMP",-1,-1,-1);
    updateJMPInstructionBackwards(it, whileAsmLines-1);
  } 
  else if (whileCond.arg2){ //WHILE FALSE
    //updateJMFInstruction(it, ifAsmLines);
    updateJMPInstruction(it, whileAsmLines);
  }
  else if (whileCond.arg3){ //WHILE VARIABLE
    updateJMFInstruction(it, whileAsmLines+1);
    instruction i = addInstruction(it,"JMP",-1,-1,-1); //PATCHED LATER 
    updateJMPInstructionBackwards(it, whileAsmLines+nbrInstr-1);
    //+nbrInstr TO JUMP BACK TO THE RE EVALUATION OF THE WHILE CONDITION, nbrInstr REPRESENTS THE NUMBER OF GENERATED INSTRUCTIONS IN ()
  }
  whileCond = init_cond();

  deleteSymbols(st);
  print_sTable(st);
  decrementDepth("WHILE");
};



Print: tPRINT tPO PrintArg tPF tPV;
PrintArg : //OPERAND NOT IMPLEMENTED YET!
  tID {
    printf("##############################################\n");
    printf("TableDepth: %d\n");
    printf("Addr: %d\n",getAddrName(st,$1));
    instruction i = addInstruction(it,"PRI",getAddrName(st,$1),-1,-1); 
  }
  | tNB {
    symbol tmp = addSymbol(st,"tmp_nb_print",1);
    instruction i = addInstruction(it,"AFC",tmp.addr,$1,-1);
    instruction j = addInstruction(it,"PRI",tmp.addr,-1,-1); 
    unstack(st);
  };


//NOTE: Multiple Variables declarations AND Var Assigns cannot occur in the same line!! Example: int a,b=3;

//VarDeclarationAndAssign NOT AVAILABLE FOR FUNCALL AND OPERATIONS! (NOT YET)
VarDeclarationAndAssign : Type tINT tID tEQUAL tNB tPV {
    printf("DECLARATION & ASSIGN FOUND\n"); 
    if ($1 == 2) {symbol s = addSymbolAssigned(st,$3,$1);} //IF IT IS A CONSTANT WE CHANGE ITS ASSIGNED FIELD TO 1
    else {symbol s = addSymbol(st,$3,$1);}
    symbol tmp = addSymbol(st,"tmp_nb",1); 
    instruction i = addInstruction(it,"AFC",tmp.addr,$5,-1);
    instruction j = addInstruction(it,"COP",getAddrName(st,$3),sTableSize-1,-1);
    unstack(st);

}

//RE-ASSIGNING A CONSTANT IS NOT POSSIBLE
//CONSTANT MUST BE ASSIGNED IMMEDIATELY AFTER DECLARATION



                        | Type tINT tID tEQUAL tID tPV {
   printf("DECLARATION & ASSIGN FOUND\n"); 
   symbol s = addSymbol(st,$3,$1);
   symbol tmp = addSymbol(st,"tmp_nb",1); 
   instruction i = addInstruction(it,"COP",tmp.addr,getAddrName(st,$5),-1);
   instruction j = addInstruction(it,"COP",getAddrName(st,$3),sTableSize-1,-1);
   unstack(st);
};

//MULTIPLE VARIABLES AND CONSTANTS DECLARATION INCLUDED
VarDeclaration : Type tINT tID { //SIMPLE DECLARATION WITHOUT VAR ASSIGN
  if ($1 == 1){ //ONLY FOR VARS
    printf("VAR DECLARATION FOUND\n");
  }
  else if ($1 == 2){
    printf("CONST DECLARATION FOUND\n");
  }
  symbol s = addSymbol(st,$3,$1);
  varBool=$1; 

} NextVar;
NextVar : Type tV tID {
    if (varBool == 1){
      printf("NEXT VAR DECLARATION FOUND\n");
    }
    else if (varBool == 2){
      printf("NEXT CONST DECLARATION FOUND\n");
    }
    symbol s = addSymbol(st,$3,varBool);

}
  NextVar | tPV {varBool=0;};

Operand:  FunCall{
  printf("OPERAND FunCall FOUND \n");
  $$ = 1; //OPERAND IS SET TO 1 FOR FUNCALL
  //WHEN WE ASSIGN A VARIABLE TO A FUNCTION (a = fun(b)) WE DON'T NEED A TMP VARIABLE. WE SIMPLY PATCH THE COP INSTRUCTION AT THE END.)
}
        | Operations
        | tID{ //MUST BE STORED IN A TMP VARIABLE
  printf("OPERAND tID FOUND \n");
  printf("tID to add in symbol table as tmp: \n");
  symbol tmp = addSymbol(st,"tmp_id",1); 
  instruction i = addInstruction(it,"COP",tmp.addr,getAddrName(st,$1),-1);

}
        | tNB{ //MUST BE STORED IN A TMP VARIABLE
  printf("OPERAND tNB FOUND \n");
  printf("tNB to add in symbol table as tmp: \n");
  symbol tmp = addSymbol(st,"tmp_nb",1); //INT FOR NOW
  instruction i = addInstruction(it,"AFC",tmp.addr,$1,-1);
        }; 

Operations: Operand tADD Operand{
  printf("ADD OPERATION FOUND: \n");
  int addrArg2 = unstack(st); 
  int addrArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_add",1); //INT FOR NOW
  instruction i = addInstruction(it,"ADD",getAddr(st,result),addrArg1,addrArg2);
}
            |Operand tSUB Operand{
  printf("SUB OPERATION FOUND: \n");
  int addrArg2 = unstack(st);
  int addrArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_sub",1);
  instruction i = addInstruction(it,"SUB",getAddr(st,result),addrArg1,addrArg2);
}
            |Operand tMUL Operand{
  printf("MUL OPERATION FOUND: \n");
  int addrArg2 = unstack(st);
  int addrArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_mul",1);
  instruction i = addInstruction(it,"MUL",getAddr(st,result),addrArg1,addrArg2);
            }
            |Operand tDIV Operand{
  printf("DIV OPERATION FOUND: \n");
  int addrArg2 = unstack(st);
  int addrArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_div",1);
  instruction i = addInstruction(it,"DIV",getAddr(st,result),addrArg1,addrArg2);    
            };

//CONST ASSIGN IS ONLY POSSIBLE IF THE CONSTANT HAS BEEN DECLARED WITHOUT ASSIGNING IT
VarAssign : tID tEQUAL Operand tPV {
  if (getSymbolByName(st,$1).type == 1){
    printf("VAR ASSIGN FOUND \n");
    if (getAddrName(st,$1)==-1){
      printf("ERROR: Variable %s not declared! \n",$1);
    }
    else{
     printf("Depth of the variable %s is %d\n",$1,getSymbolByName(st,$1).depth); 
    if ($3 != 1){
        instruction i = addInstruction(it,"COP",getAddrName(st,$1),sTableSize-1,-1);
        unstack(st); //IF IT IS A FUNCALL WE DO NOT UNSTACK BECAUSE WE DID NOT USE ANY TMP VARIABLES
    }

    else {
        instruction i = addInstructionWithReturn(it,"COP",getAddrName(st,$1),sTableSize-1,-1,funName);
    }

  }
  }
  else if (getSymbolByName(st,$1).type == 2){
    if (!getSymbolByName(st,$1).assigned){
      printf("CONST ASSIGN FOUND \n");
      if (getAddrName(st,$1)==-1){
       printf("ERROR: Constant %s not declared! \n",$1);
      }
      else{
      instruction i = addInstruction(it,"COP",getAddrName(st,$1),sTableSize-1,-1);
      printf("Changing assign status from 0 to 1\n");
      const_assigned(&st[getAddrName(st,$1)]);
      print_sTable(st);
      unstack(st);
      }
    } else {printf("ERROR: RE-ASSIGNING A CONSTANT IS NOT POSSIBLE\n");}
  }
};


ifCondition: tIF tPO ifBoolExpression tPF {
//AT THIS POINT, WE HAVE A tmp_eqeq IN THE SYMBOL TABLE

} elseCondition;

elseCondition: tELSE 
tAO{
  incrementDepth("ELSE");
  countELSE=iTableSize;
  if (elseCond.arg3){ //NO JMP FOR IF FALSE AND IF TRUE
    updateJMFInstructionOne(it);
    //AT THE END OF THE IF STATEMENT WE ADD A JMP INSTRUCTIONTO JUMP THE ELSE IN CASE THE CONDITION OF THE IF IS TRUE
    //JMP IS AN UNCONDITIONAL INSTRUCTION, WE ONLY NEED ARG1 WICH WILL BE PATCHED LATER ON
    instruction i = addInstruction(it,"JMP",-1,-1,-1);

  }

}
Body
 tAF{
  //PATCHING JMP STATEMENT
  if (elseCond.arg3){ //NO JMP FOR IF FALSE AND IF TRUE
    int elseAsmLines=iTableSize-countELSE;
    updateJMPInstruction(it, elseAsmLines-1); //PATCH
  }
  elseCond = init_cond();
  deleteSymbols(st);
  print_sTable(st);
  decrementDepth("ELSE");
} |;
//COUNT IS USED TO COUNT THE GENERATED INSTRUCTIONS BETWEEN ()
whileCondition: tWHILE tPO{count=iTableSize;} whileBoolExpression tPF {nbrInstr=iTableSize-count;};


ifBoolExpression: ifComparaison
              | tID {
instruction i = addInstruction(it,"JMF",getAddrName(st,$1),-1,-1); //PATCHED LATER    
ifCond = construct_cond(0,0,1);         
              }
              | tTRUE //NOTHING TO DO
              | tFALSE{
instruction i = addInstruction(it,"JMP",-1,-1,-1); //PATCHED LATER
ifCond = construct_cond(0,1,0);
              };

Comparator: tINF | tSUP | tEQEQ;

ifComparaison: Operand tEQEQ Operand {

  printf("EQEQ COMPARAISON FOUND: \n");
  int eqeqArg2 = unstack(st);
  int eqeqArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_eqeq",1);
  //INSTRUCTION EQU IS GOING TO CONTROL WHERE THE JUMP WILL BE
  //DEPENDING ON WETHER THE CONDITION IS TRUE OR FALSE
  instruction i_equ = addInstruction(it,"EQU",getAddr(st,result),eqeqArg1,eqeqArg2); //THE result VARIABLE OVERWRITES eqeqArg1 BY HAVING THE SAME ADDRESS
  instruction i_jmf = addInstruction(it,"JMF",getAddr(st,result),-1,-1); //ARG2 INIT -1 THEN PATCHED
  ifCond = construct_cond(0,0,1); 
  unstack(st); //TO GET RID OF TMP_EQEQ


}
              | Operand tINF Operand {

  printf("INF COMPARAISON FOUND: \n");
  int infArg2 = unstack(st);
  int infArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_inf",1);
  instruction i_inf = addInstruction(it,"INF",getAddr(st,result),infArg1,infArg2); //THE result VARIABLE OVERWRITES infArg1 BY HAVING THE SAME ADDRESS
  instruction i_jmf = addInstruction(it,"JMF",getAddr(st,result),-1,-1); //ARG2 INIT -1 THEN PATCHED
  ifCond = construct_cond(0,0,1); 
  unstack(st); //TO GET RID OF TMP_INF


}
              | Operand tSUP Operand {

  printf("INF COMPARAISON FOUND: \n");
  int supArg2 = unstack(st);
  int supArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_sup",1);
  instruction i_equ = addInstruction(it,"SUP",getAddr(st,result),supArg1,supArg2); //THE result VARIABLE OVERWRITES supArg1 BY HAVING THE SAME ADDRESS
  instruction i_jmf = addInstruction(it,"JMF",getAddr(st,result),-1,-1); //ARG2 INIT -1 THEN PATCHED
  ifCond = construct_cond(0,0,1); 
  unstack(st); //TO GET RID OF TMP_SUP


};


whileBoolExpression: whileComparaison
              | tID {
instruction i = addInstruction(it,"JMF",getAddrName(st,$1),-1,-1); //PATCHED LATER 
whileCond = construct_cond(0,0,1);
                
              }
              | tTRUE {   
whileCond = construct_cond(1,0,0);          
              }
              | tFALSE{
instruction i = addInstruction(it,"JMP",-1,-1,-1); //PATCHED LATER                
whileCond = construct_cond(0,1,0);
              };

whileComparaison: Operand tEQEQ Operand {
  printf("WHILE EQEQ COMPARAISON FOUND: \n");
  int eqeqArg2 = unstack(st);
  int eqeqArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_eqeq",1);
  instruction i_equ = addInstruction(it,"EQU",getAddr(st,result),eqeqArg1,eqeqArg2);

  instruction i_jmf = addInstruction(it,"JMF",getAddr(st,result),-1,-1);  
  whileCond = construct_cond(0,0,1);
  unstack(st); //TO GET RID OF TMP_EQEQ


}
              | Operand tINF Operand {
  printf("WHILE INF COMPARAISON FOUND: \n");
  int infArg2 = unstack(st);
  int infArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_inf",1);
  instruction i_inf = addInstruction(it,"INF",getAddr(st,result),infArg1,infArg2);

  instruction i_jmf = addInstruction(it,"JMF",getAddr(st,result),-1,-1); 
  whileCond = construct_cond(0,0,1);
  unstack(st); //TO GET RID OF TMP_INF

}
              | Operand tSUP Operand {
  printf("WHILE SUP COMPARAISON FOUND: \n");
  int supArg2 = unstack(st);
  int supArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_sup",1);
  instruction i_sup = addInstruction(it,"SUP",getAddr(st,result),supArg1,supArg2);

  instruction i_jmf = addInstruction(it,"JMF",getAddr(st,result),-1,-1); 
  whileCond = construct_cond(0,0,1);
  unstack(st); //TO GET RID OF TMP_SUP

};



%%
void yyerror(char *s) { fprintf(stderr, "%s\n", s); }

int main(void) {
  printf("Start\n");
  ASM=fopen("ASM","w");
  st = init_sTable();
  it = init_iTable();
  pt = init_pTable();
  yydebug=1;
  yyparse();
  printf("END OF PARSER \n");

  print_sTable(st);

  print_iTable(it); 

  print_pTable(pt);  

  printf("Interpreting code \n");

  interpretCode(it,iTableSize);

  printf("Printing register table:\n");
  
  printInterpreter();

  fclose (ASM);
  return 0;
}
