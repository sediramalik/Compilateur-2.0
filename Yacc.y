%{
#include <stdlib.h>
#include <stdio.h>
#include "sTable.c"
#include "iTable.c"

int string[16]; //Taille max du nom de variable
int countIF=0;
int countELSE=0;
int countWHILE=0;
condition ifCond;
condition whileCond;
condition elseCond;
void yyerror(char *s);
symbol * st; //symbol table
instruction * it; //instruction table
%}

%union {int nb; char string[16];} //associer une étiquette à chaque entier
%token 
tMAIN
tIF tWHILE
tPRINT tELSE
tAO tAF tPO tPF tV tPV
tEQUAL
tVOID
tINT tSTRING
tSUB tADD tMUL tDIV
tINF tSUP tEQEQ
tTRUE tFALSE

%token <nb> tNB //Etiquette entier
%token <string> tID //Etiquette nom variable/fonction
%type <nb> Type
%start Program

%left tADD tSUB //Priorité à gauche
%left tMUL tDIV //Priorité à gauche

%%

Program: Functions;

Functions: Function | Function Functions;
Function: FunType FunName tPO DecArgs tPF tAO Body tAF;
FunCall: FunName tPO CallArgs tPF tPV;

DecArgs: Type tID NextDecArg |;
NextDecArg: tV DecArgs |;

CallArgs: Operand CallArgNext |;
CallArgNext: tV CallArgs |;

Type: tINT { $$ = 1; } | tSTRING{ $$ = 2; }; //IF INT THEN 1 IF STRING THEN 2
FunType: tVOID | Type;

FunName: tMAIN | tID; 

Body: Instructions;
Instructions: Instruction Instructions |;
Instruction: FunCall 
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

  if (whileCond.arg1) {
    instruction i = addInstruction(it,"JMP",-1,-1,-1); //PATCHED LATER    
  } 

}
Body
tAF {
  int whileAsmLines=iTableSize-countWHILE;

  if (whileCond.arg1) {
    updateJMPInstruction(it, whileAsmLines-1);
  } 
  else if (whileCond.arg2){
    //updateJMFInstruction(it, ifAsmLines);
    updateJMPInstruction(it, whileAsmLines);
  }
  else if (whileCond.arg3){
    updateJMFInstruction(it, whileAsmLines+1);
    instruction i = addInstruction(it,"JMP",-1,-1,-1); //PATCHED LATER 
    updateJMPInstructionBackwards(it, whileAsmLines);
  }
  whileCond = init_cond();

  deleteSymbols(st);
  print_sTable(st);
  decrementDepth("WHILE");
};

//VarDeclarationAndAssign NOT AVAILABLE FOR FUNCALL AND OPERATIONS! (NOT YET)
VarDeclarationAndAssign : Type tID tEQUAL tNB tPV {
   printf("VAR DECLARATION & ASSIGN FOUND\n"); 
   symbol s = addSymbol(st,$2,$1);
   symbol tmp = addSymbol(st,"tmp_nb",1); //INT FOR NOW
   instruction i = addInstruction(it,"AFC",tmp.addr,$4,-1);
   instruction j = addInstruction(it,"COP",getAddrName(st,$2),sTableSize-1,-1);
   unstack(st);
}
                        |Type tID tEQUAL tID tPV {
   printf("VAR DECLARATION & ASSIGN FOUND\n"); 
   symbol s = addSymbol(st,$2,$1);
   symbol tmp = addSymbol(st,"tmp_nb",1); //INT FOR NOW
   instruction i = addInstruction(it,"COP",tmp.addr,getAddrName(st,$4),-1);
   instruction j = addInstruction(it,"COP",getAddrName(st,$2),sTableSize-1,-1);
   unstack(st);
};


VarDeclaration : Type tID tPV { //SIMPLE DECLARATION WITHOUT VAR ASSIGN
  printf("VAR DECLARATION FOUND\n");
  symbol s = addSymbol(st,$2,$1);

};

Operand:  FunCall
        | Operations
        | tID{ //MUST BE STORED IN A TMP VARIABLE
  printf("OPERAND tID FOUND \n");
  printf("tID to add in symbol table as tmp: \n");
  symbol tmp = addSymbol(st,"tmp_id",1); //INT FOR NOW
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

VarAssign : tID tEQUAL Operand tPV {
  printf("VAR ASSIGN FOUND \n");
  if (getAddrName(st,$1)==-1){
    printf("ERROR: Variable %s not declared! \n",$1);
  }
  else{
  instruction i = addInstruction(it,"COP",getAddrName(st,$1),sTableSize-1,-1);
  unstack(st);
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
}|;

whileCondition: tWHILE tPO whileBoolExpression tPF {

};


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
// limitedLoop=1; 
whileCond = construct_cond(0,0,1);
                
              }
              | tTRUE {
//infiniteLoop=1;    
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
  yydebug=1;
  yyparse();
  printf("END OF PARSER \n");
  printf("Printing table of symbols: \n");
  print_sTable(st);

  printf("Printing table of instructions: \n");
  print_iTable(it);  
  fclose (ASM);
  return 0;
}
