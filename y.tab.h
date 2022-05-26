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
    tIF = 259,
    tWHILE = 260,
    tPRINT = 261,
    tELSE = 262,
    tAO = 263,
    tAF = 264,
    tPO = 265,
    tPF = 266,
    tV = 267,
    tPV = 268,
    tEQUAL = 269,
    tVOID = 270,
    tINT = 271,
    tSTRING = 272,
    tSUB = 273,
    tADD = 274,
    tMUL = 275,
    tDIV = 276,
    tINF = 277,
    tSUP = 278,
    tEQEQ = 279,
    tTRUE = 280,
    tFALSE = 281,
    tNB = 282,
    tID = 283
  };
#endif
/* Tokens.  */
#define tMAIN 258
#define tIF 259
#define tWHILE 260
#define tPRINT 261
#define tELSE 262
#define tAO 263
#define tAF 264
#define tPO 265
#define tPF 266
#define tV 267
#define tPV 268
#define tEQUAL 269
#define tVOID 270
#define tINT 271
#define tSTRING 272
#define tSUB 273
#define tADD 274
#define tMUL 275
#define tDIV 276
#define tINF 277
#define tSUP 278
#define tEQEQ 279
#define tTRUE 280
#define tFALSE 281
#define tNB 282
#define tID 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "Yacc.y"
int nb; char string[16];

#line 116 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
