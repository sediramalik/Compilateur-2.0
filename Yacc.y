%{
#include <stdlib.h>
#include <stdio.h>
#include "Table.c"
int string[16]; //Taille max du nom de variable
void yyerror(char *s);
symbol* t; //table
%}

%union {int nb; char string[16];} //associer une étiquette à chaque entier
%token 
tMAIN tCONST tPRINT
tIF tWHILE tELSE
tAO tAF tPO tPF tV tPV
tEQUAL
tVOID
tINT tSTRING
tSUB tADD tMUL tDIV
tINF tSUP

%token <nb> tNB //Etiquette entier
%token <string> tID //Etiquette nom variable/fonction
%start Program

%left tADD tSUB //Priorité à gauche
%left tMUL tDIV //Priorité à gauche

%%

Program: Functions;

Functions: Function | Function Functions;
Function: FunType FunName tPO DecArgs tPF tAO Body tAF;
FunCall: FunName tPO CallArgs tPF ;

DecArgs: Type tID NextDecArg |;
NextDecArg: tV DecArgs |;

CallArgs: Operand CallArgNext |;
CallArgNext: tV CallArgs |;

Type0: tCONST |;
Type: tINT | tSTRING;
FunType: tVOID | Type;

FunName: tMAIN | tID; 

Body: Instructions;
Instructions: Instruction Instructions |;
Instruction: FunCall tPV 
          | VarDeclaration tPV;
          | VarAssign tPV;
          | Condition tAO {tableDepth++;} Body tAF {deleteSymbols(t);tableDepth--;};

VarDeclaration : Type0 Type tID {
  symbol s = {varname:$3, type0:$1, type:$2, value:NULL};
  printf("Created symbol: ");
  printSymbol(s);
  addSymbol(t,$3);
  printf("Added symbol: ");
  printSymbol(t[tableSize-1])
};

Operand:  FunCall | Operations | tNB | tID;
Operator: tSUB | tADD | tDIV | tMUL;

Operations: Operand Operator Operand;
VarAssign : tID tEQUAL Operand;

Condition: tIF ArgCondition | tWHILE ArgCondition;
ArgCondition: tPO BoolExpression tPF;

BoolExpression: Comparaison | tID;
Comparator: tINF | tSUP;
Comparaison: Operand Comparator Operand;

%%
void yyerror(char *s) { fprintf(stderr, "%s\n", s); }
int main(void) {
  printf("Compilateur\n");
  yydebug=1;
  yyparse();
  return 0;
}
