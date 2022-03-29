%{
#include <stdlib.h>
#include <stdio.h>
#include "sTable.c"

int string[16]; //Taille max du nom de variable
void yyerror(char *s);
symbol * t; //table
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
%type <nb> Type0
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

Type0: tCONST {$$ = 1; } | {$$ = 0; }; //IF CONST THEN 1 ELSE 0
Type: tINT { $$ = 1; } | tSTRING{ $$ = 2; }; //IF INT THEN 1 IF STRING THEN 2
FunType: tVOID | Type;

FunName: tMAIN | tID; 

Body: Instructions;
Instructions: Instruction Instructions |;
Instruction: FunCall 
           | VarDeclaration 
           | VarAssign 
           | Condition tAO {incrementDepth();} Body tAF {deleteSymbols(t);decrementDepth();};

VarDeclaration : Type0 Type tID {
  
  symbol s = addSymbol(t,$3,$1,$2);
  printf("Added symbol: \n");
  printSymbol(s);
  printf("Last symbol in table: \n");
  printSymbol(t[sTableSize-1]);
  printf("Content of table: \n");
  print_sTable(t);

} tPV;

Operand:  FunCall
        | Operations
        | tNB{}; //MUST BE STORED IN A TMP VARIABLE
        | tID{}; //MUST BE STORED IN A TMP VARIABLE

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
  t = init_sTable();
  yydebug=1;
  yyparse();
  return 0;
}
