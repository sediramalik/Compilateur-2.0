%{
#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"
%}

%option noyywrap
%option nounput
%option noinput
%%

[ \t\n]+  {}; 
	
"main"  {return tMAIN;}	
"int"   {return tINT;}
"printf" {return tPRINT;}
"if"    {return tIF;}
"while"    {return tWHILE;}
"else"    {return tELSE;}
"void" {return tVOID;}
"string" {return tSTRING;}
"print" {return tPRINT;}
"true" {return tTRUE;}
"false" {return tFALSE;}
"const" {return tCONST;}

"{"     {return tAO;}
"}"     {return tAF;}
"("     {return tPO;}
")"     {return tPF;}

"," {return tV;}
";" {return tPV;}
"="	{return tEQUAL;}
"==" {return tEQEQ;}
"-"	{return tSUB;}
"+"	{return tADD;}
"*"	{return tMUL;}
"/"	{return tDIV;}
"<"	{return tINF;}
">"	{return tSUP;}

[a-zA-Z]+[A-Za-z0-9|_]* {strcpy(yylval.string, yytext);return tID;}
[0-9]+(e[0-9]+)? {yylval.nb = (int) strtold(yytext, NULL);return tNB;}


%%

