%{
#include <stdlib.h>
#include <stdio.h>
#include "sTable.c"
#include "iTable.c"

int string[16]; //Taille max du nom de variable
int count=0;
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
           | VarDeclaration 
           | VarAssign 
           | ifCondition
tAO { //DEPTH HANDELING
  printf("Entering condition. Increasing depth\n");
  incrementDepth();
  count=iTableSize;
}
Body
tAF {
  int numAsmLines=iTableSize-count;
  updateJumpInstruction(it, numAsmLines); //PATCH
  printf("Exiting condition. Deleting symbols\n");
  deleteSymbols(st);
  print_sTable(st);
  printf("Decrementing depth\n");
  decrementDepth();
};
           | whileCondition tAO { //DEPTH HANDELING
  printf("Entering condition. Increasing depth\n");
  incrementDepth();
}
Body
tAF {
  printf("Exiting condition. Deleting symbols\n");
  deleteSymbols(st);
  print_sTable(st);
  printf("Decrementing depth\n");
  decrementDepth();
}
elseCondition;

//NOTE: LANGUAGE ONLY RECOGNIZES VAR DECLARATIONS WITHOUT VAR ASSIGN
VarDeclaration : Type tID tPV { //SIMPLE DECLARATION WITHOUT VAR ASSIGN
  
  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
  printf("DECLARATION FOUND\n");
  symbol s = addSymbol(st,$2,$1,-1);
  printf("Added symbol: \n");
  printSymbol(s);
  // printf("Last symbol in symbol table: \n");
  // printSymbol(st[sTableSize-1]);
  printf("Content of symbol table: \n");
  print_sTable(st);
  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

};

Operand:  FunCall
        | Operations
        | tID{ //MUST BE STORED IN A TMP VARIABLE
  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
  printf("OPERAND tID FOUND \n");
  printf("tID to add in symbol table as tmp: \n");
  symbol tmp = addSymbol(st,"tmp_id",1,-1);
  printf("Added tmp in symbol table: \n");
  printSymbol(tmp);
  instruction i = addInstruction(it,"COP",tmp.addr,getAddrName(st,$1),-1);
  printf("Added instruction: \n");
  printInstruction(i);
  printf("Content of symbol table: \n");
  print_sTable(st);
  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

}
        | tNB{ //MUST BE STORED IN A TMP VARIABLE
  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
  printf("OPERAND tNB FOUND \n");
  printf("tNB to add in symbol table as tmp: \n");
  symbol tmp = addSymbol(st,"tmp_nb",1,$1);
  printf("Added tmp in symbol table: \n");
  printSymbol(tmp);
  instruction i = addInstruction(it,"AFC",tmp.addr,$1,-1);
  printf("Added instruction: \n");
  printInstruction(i);
  printf("Content of symbol table: \n");
  print_sTable(st);
  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        }; 

Operations: Operand tADD Operand{
  printf("+++++++++++++++++++++++++++++++++++++++\n");
  printf("ADD OPERATION FOUND: \n");
  int addrArg2 = unstack(st);
  printf("Variable arg2 unstacked had address: \n");
  printf("%d\n",addrArg2);
  int addrArg1 = unstack(st);
  printf("Variable arg1 unstacked had address: \n");
  printf("%d\n",addrArg1);
  symbol result = addSymbol(st,"tmp_add",1,-1);
  instruction i = addInstruction(it,"ADD",getAddr(st,result),addrArg1,addrArg2);
  printf("Added instruction: \n");
  printInstruction(i);
  printf("+++++++++++++++++++++++++++++++++++++++\n");
}
            |Operand tSUB Operand{
  printf("---------------------------------------\n");
  printf("SUB OPERATION FOUND: \n");
  int addrArg2 = unstack(st);
  printf("Variable arg2 unstacked had address: \n");
  printf("%d\n",addrArg2);
  int addrArg1 = unstack(st);
  printf("Variable arg1 unstacked had address: \n");
  printf("%d\n",addrArg1);
  symbol result = addSymbol(st,"tmp_sub",1,-1);
  instruction i = addInstruction(it,"SUB",getAddr(st,result),addrArg1,addrArg2);
  printf("Added instruction: \n");
  printInstruction(i);
  printf("---------------------------------------\n");
}
            |Operand tMUL Operand{
  printf("***************************************\n");
  printf("MUL OPERATION FOUND: \n");
  int addrArg2 = unstack(st);
  printf("Variable arg2 unstacked had address: \n");
  printf("%d\n",addrArg2);
  int addrArg1 = unstack(st);
  printf("Variable arg1 unstacked had address: \n");
  printf("%d\n",addrArg1);
  symbol result = addSymbol(st,"tmp_mul",1,-1);
  instruction i = addInstruction(it,"MUL",getAddr(st,result),addrArg1,addrArg2);
  printf("Added instruction: \n");
  printInstruction(i);
  printf("***************************************\n");
            }
            |Operand tDIV Operand{
  printf("///////////////////////////////////////\n");
  printf("DIV OPERATION FOUND: \n");
  int addrArg2 = unstack(st);
  printf("Variable arg2 unstacked had address: \n");
  printf("%d\n",addrArg2);
  int addrArg1 = unstack(st);
  printf("Variable arg1 unstacked had address: \n");
  printf("%d\n",addrArg1);
  symbol result = addSymbol(st,"tmp_div",1,-1);
  instruction i = addInstruction(it,"DIV",getAddr(st,result),addrArg1,addrArg2);
  printf("Added instruction: \n");
  printInstruction(i);    
  printf("///////////////////////////////////////\n");        
            };

VarAssign : tID tEQUAL Operand tPV {
  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
  printf("VAR ASSIGN FOUND \n");
  printf("Content of symbol table before unstacking: \n");
  print_sTable(st);
  instruction i = addInstruction(it,"COP",getAddrName(st,$1),sTableSize-1,-1);
  unstack(st);
  printf("Added instruction: \n");
  printInstruction(i);
  printf("Content of symbol table after unstacking: \n");
  print_sTable(st);
  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
};

ifCondition: tIF ArgCondition {
//AT THIS POINT, WE HAVE A tmp_eqeq IN THE SYMBOL TABLE

};

elseCondition: tELSE tAO Body tAF |;

whileCondition: tWHILE ArgCondition {

};

ArgCondition: tPO BoolExpression tPF;

BoolExpression: Comparaison | tID | tTRUE | tFALSE;
Comparator: tINF | tSUP | tEQEQ;
//Comparaison: Operand Operator Operand
Comparaison: Operand tEQEQ Operand {
  printf("=====================================\n");
  printf("EQEQ COMPARAISON FOUND: \n");
  int eqeqArg2 = unstack(st);
  printf("Variable arg2 unstacked had address: \n");
  printf("%d\n",eqeqArg2);
  int eqeqArg1 = unstack(st);
  printf("Variable arg1 unstacked had address: \n");
  printf("%d\n",eqeqArg1);
  symbol result = addSymbol(st,"tmp_eqeq",1,-1);
  printf("Added symbol: \n");
  printSymbol(result);
  printf("Content of symbol table: \n");
  print_sTable(st);
  //INSTRUCTION EQU IS GOING TO CONTROL WHERE THE JUMP WILL BE
  //DEPENDING ON WETHER THE CONDITION IS TRUE OR FALSE
  instruction i_equ = addInstruction(it,"EQU",getAddr(st,result),eqeqArg1,eqeqArg2);
  printf("Added instruction: \n");
  printInstruction(i_equ);
  instruction i_jmf = addInstruction(it,"JMF",getAddr(st,result),-1,-1); //ARG2 INIT -1 THEN PATCHED
  printf("Added instruction: \n");
  printInstruction(i_jmf);
  unstack(st); //TO GET RID OF TMP_EQEQ
  printf("=====================================\n");
};

%%
void yyerror(char *s) { fprintf(stderr, "%s\n", s); }

int main(void) {
  printf("Start\n");
  st = init_sTable();
  it = init_iTable();
  yydebug=1;
  yyparse();
  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
  printf("END OF PARSER \n");
  printf("Printing table of symbols: \n");
  print_sTable(st);

  printf("Printing table of instructions: \n");
  print_iTable(it);  
  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
  return 0;
}
