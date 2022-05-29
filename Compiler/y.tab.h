/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tMAIN = 258,
    tRETURN = 259,
    tIF = 260,
    tWHILE = 261,
    tPRINT = 262,
    tELSE = 263,
    tAO = 264,
    tAF = 265,
    tPO = 266,
    tPF = 267,
    tV = 268,
    tPV = 269,
    tEQUAL = 270,
    tVOID = 271,
    tINT = 272,
    tSTRING = 273,
    tSUB = 274,
    tADD = 275,
    tMUL = 276,
    tDIV = 277,
    tINF = 278,
    tSUP = 279,
    tEQEQ = 280,
    tTRUE = 281,
    tFALSE = 282,
    tCONST = 283,
    tNB = 284,
    tID = 285
  };
#endif
/* Tokens.  */
#define tMAIN 258
#define tRETURN 259
#define tIF 260
#define tWHILE 261
#define tPRINT 262
#define tELSE 263
#define tAO 264
#define tAF 265
#define tPO 266
#define tPF 267
#define tV 268
#define tPV 269
#define tEQUAL 270
#define tVOID 271
#define tINT 272
#define tSTRING 273
#define tSUB 274
#define tADD 275
#define tMUL 276
#define tDIV 277
#define tINF 278
#define tSUP 279
#define tEQEQ 280
#define tTRUE 281
#define tFALSE 282
#define tCONST 283
#define tNB 284
#define tID 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "Yacc.y"
int nb; char string[16];

#line 120 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
