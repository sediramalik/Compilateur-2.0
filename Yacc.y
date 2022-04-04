%{
#include <stdlib.h>
#include <stdio.h>
#include "sTable.c"
#include "iTable.c"


int string[16]; //Taille max du nom de variable
void yyerror(char *s);
symbol * st; //symbol table
instruction * it; //instruction table
%}

%union {int nb; char string[16];} //associer une étiquette à chaque entier
%token 
tMAIN tCONST
tIF tWHILE
tPRINT tELSE
tAO tAF tPO tPF tV tPV
tEQUAL
tVOID
tINT tSTRING
tSUB tADD tMUL tDIV
tINF tSUP

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
           | Condition tAO {incrementDepth();} Body tAF {deleteSymbols(st);decrementDepth();};

//NOTE: LANGUAGE ONLY RECOGNIZES VAR DECLARATIONS WITHOUT VAR ASSIGN
VarDeclaration : Type tID { //SIMPLE DECLARATION WITHOUT VAR ASSIGN
  
  symbol s = addSymbol(st,$2,$1,-1);
  printf("Added symbol: \n");
  printSymbol(s);
  printf("Last symbol in table: \n");
  printSymbol(st[sTableSize-1]);
  printf("Content of table: \n");
  print_sTable(st);

} tPV;

Operand:  FunCall
        | Operations
        | tNB{ //MUST BE STORED IN A TMP VARIABLE

          symbol tmp = addSymbol(symbol * st, char * "tmp",1,$1);
          //addInstruction(it,"AFC",tmp.addr,$1,-1);
        }; 
        | tID{ //MUST BE STORED IN A TMP VARIABLE

        }; 

Operator: tSUB | tADD | tDIV | tMUL;

Operations: Operand Operator Operand;
VarAssign : tID tEQUAL Operand tPV;

Condition: tIF ArgCondition | tWHILE ArgCondition;
ArgCondition: tPO BoolExpression tPF;

BoolExpression: Comparaison | tID;
Comparator: tINF | tSUP;
Comparaison: Operand Comparator Operand;

%%
void yyerror(char *s) { fprintf(stderr, "%s\n", s); }

int main(void) {
  printf("Start\n");
  st = init_sTable();
  it = init_iTable();
  yydebug=1;
  yyparse();

  printf("Printing table of symbols: \n");
  //print_iTable(st);

  printf("Printing table of instructions: \n");
  //print_iTable(it);  
  return 0;
}
