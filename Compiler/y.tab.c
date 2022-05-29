/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Yacc.y"

#include <stdlib.h>
#include <stdio.h>
#include "sTable.c"
#include "iTable.c"
#include "pTable.c"

char string[16]; //Taille max du nom de variable
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

#line 95 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 26 "Yacc.y"
int nb; char string[16];

#line 210 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

#define YYUNDEFTOK  2
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    55,    57,    57,    61,    66,    66,    70,
      61,    94,    98,    98,    94,   115,   115,   115,   119,   119,
     128,   129,   129,   131,   131,   134,   135,   137,   137,   139,
     139,   144,   145,   145,   146,   147,   148,   149,   150,   152,
     157,   151,   176,   175,   210,   212,   215,   226,   241,   251,
     251,   262,   262,   272,   274,   281,   282,   289,   296,   303,
     310,   317,   326,   355,   355,   361,   360,   384,   386,   391,
     392,   396,   397,   404,   419,   432,   447,   448,   454,   458,
     463,   476,   488
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tMAIN", "tRETURN", "tIF", "tWHILE",
  "tPRINT", "tELSE", "tAO", "tAF", "tPO", "tPF", "tV", "tPV", "tEQUAL",
  "tVOID", "tINT", "tSTRING", "tSUB", "tADD", "tMUL", "tDIV", "tINF",
  "tSUP", "tEQEQ", "tTRUE", "tFALSE", "tCONST", "tNB", "tID", "$accept",
  "Program", "Main", "Functions", "Function", "$@1", "$@2", "$@3", "$@4",
  "$@5", "$@6", "$@7", "FunCall", "$@8", "$@9", "DecArgs", "$@10",
  "NextDecArg", "CallArgs", "$@11", "CallArgNext", "Type", "Body",
  "Instructions", "Instruction", "$@12", "$@13", "$@14", "Print",
  "PrintArg", "VarDeclarationAndAssign", "VarDeclaration", "$@15",
  "NextVar", "$@16", "Operand", "Operations", "VarAssign", "ifCondition",
  "$@17", "elseCondition", "$@18", "whileCondition", "ifBoolExpression",
  "ifComparaison", "whileBoolExpression", "whileComparaison", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285
};
# endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-78)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,    15,    21,     7,    17,   -93,     0,     9,   -93,     7,
      23,    41,    44,   -93,    28,   -93,   -93,     4,    40,    40,
      56,    60,    78,   -93,    77,    93,    91,   101,   -93,    10,
     -93,   -93,   -93,   -93,   103,   104,    85,   -93,   -93,    46,
      64,    -4,    66,   105,   -93,    87,   -93,   -93,   -93,   -93,
     -93,   102,   106,   -93,   -93,   -93,    86,   -93,    26,   -93,
     107,   -93,   -93,   -93,    88,    63,   108,   -93,   -93,   -93,
     109,   111,    22,   -93,   110,     4,     4,   113,   114,   115,
      66,    66,    66,    66,    66,    66,    66,   -93,    66,    66,
      66,   -93,   117,   -93,    72,    74,     5,   118,   119,    40,
     -93,   -93,   -93,    84,    84,   -93,   -93,    58,    58,    58,
     124,    58,    58,    58,   -93,   120,   -93,   122,   121,   123,
     -93,   125,   -93,   -93,   -93,   -93,     4,     1,   127,   -93,
      72,   -93,   120,   -93,   -93,   -93,    97,   124,   129,   136,
     -93,   -93,   -93,   -93,   -93,   -93,   112,     4,     5,   130,
     131,   -93,   -93,   -93,   133,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     2,     4,
       0,     0,     0,     5,     0,    11,     6,    30,    20,    20,
       0,     0,     0,    29,    15,     0,     0,     0,    31,    33,
      35,    36,    37,    38,     0,     0,     0,    12,     7,     0,
       0,     0,     0,     0,    34,     0,     3,    32,    39,    42,
      18,     0,     0,    71,    72,    57,    56,    54,     0,    55,
       0,    69,    78,    79,    56,     0,     0,    76,    46,    45,
       0,    56,     0,    16,    49,    30,    30,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,     0,
       0,    68,     0,    62,    26,     0,    30,     0,     0,    20,
      19,    13,     8,    59,    58,    60,    61,    74,    75,    73,
      67,    81,    82,    80,    44,    28,    23,     0,     0,     0,
      53,     0,    50,    40,    43,    21,    30,    30,     0,    64,
      26,    25,    28,    17,    47,    48,     0,    67,     0,     0,
      65,    27,    24,    51,    41,    14,     0,    30,    30,     0,
       0,    52,     9,    66,     0,    10
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,   137,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -17,   -93,   -93,   -18,   -93,   -93,    18,   -93,
      13,   -92,   -73,   126,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,    -1,   -93,   -20,   -93,   -93,   -93,   -93,
      12,   -93,   -93,   -93,   -93,   -93,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    19,    52,   127,   154,    18,
      51,   126,    57,    43,    94,    37,    77,   100,   117,   132,
     131,    26,    27,    28,    29,    75,   137,    76,    30,    70,
      31,    32,    96,   122,   148,    58,    59,    33,    34,   110,
     129,   147,    35,    60,    61,    66,    67
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    38,    97,    98,   121,   -33,    20,    21,    22,    20,
      21,    22,    25,     1,   -33,    20,    21,    22,     4,   120,
      65,     5,    72,     6,     7,    68,    69,   -30,    10,    23,
      11,    24,    23,    23,    24,    14,    93,    17,    23,    12,
      24,    80,    81,    82,    83,    80,    81,    82,    83,    84,
      85,    86,    15,   138,   139,    16,   121,    36,    25,    25,
     103,   104,   105,   106,   107,   108,   109,    39,   111,   112,
     113,    40,    53,    54,   150,    55,    56,    80,    81,    82,
      83,   125,    80,    81,    82,    83,    88,    89,    90,    41,
      62,    63,    42,    55,    64,    55,    71,   -15,   -70,   -15,
     -77,   115,   116,   118,   119,    82,    83,    44,    45,    25,
      25,    46,    48,    49,    78,    50,    73,    74,    79,    87,
      91,    92,   -15,   101,   102,    95,    99,   143,   123,   124,
      25,   114,   128,   130,   133,   134,   140,   135,   136,   145,
     146,   153,   149,   155,   152,   142,    13,   151,   141,   144,
       0,     0,     0,     0,     0,    47
};

static const yytype_int16 yycheck[] =
{
      17,    19,    75,    76,    96,     4,     5,     6,     7,     5,
       6,     7,    29,    16,    10,     5,     6,     7,     3,    14,
      40,     0,    42,    16,    17,    29,    30,    17,    11,    28,
      30,    30,    28,    28,    30,    12,    14,     9,    28,    30,
      30,    19,    20,    21,    22,    19,    20,    21,    22,    23,
      24,    25,    11,   126,   127,    11,   148,    17,    75,    76,
      80,    81,    82,    83,    84,    85,    86,    11,    88,    89,
      90,    11,    26,    27,   147,    29,    30,    19,    20,    21,
      22,    99,    19,    20,    21,    22,    23,    24,    25,    11,
      26,    27,    15,    29,    30,    29,    30,    11,    12,    11,
      12,    29,    30,    29,    30,    21,    22,    14,    17,   126,
     127,    10,     9,     9,    12,    30,    11,    30,    12,    12,
      12,    12,    11,     9,     9,    15,    13,    30,    10,    10,
     147,    14,     8,    13,    12,    14,     9,    14,    13,    10,
       4,    10,    30,    10,    14,   132,     9,   148,   130,   137,
      -1,    -1,    -1,    -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    32,    33,     3,     0,    16,    17,    34,    35,
      11,    30,    30,    34,    12,    11,    11,     9,    40,    36,
       5,     6,     7,    28,    30,    43,    52,    53,    54,    55,
      59,    61,    62,    68,    69,    73,    17,    46,    46,    11,
      11,    11,    15,    44,    14,    17,    10,    54,     9,     9,
      30,    41,    37,    26,    27,    29,    30,    43,    66,    67,
      74,    75,    26,    27,    30,    66,    76,    77,    29,    30,
      60,    30,    66,    11,    30,    56,    58,    47,    12,    12,
      19,    20,    21,    22,    23,    24,    25,    12,    23,    24,
      25,    12,    12,    14,    45,    15,    63,    53,    53,    13,
      48,     9,     9,    66,    66,    66,    66,    66,    66,    66,
      70,    66,    66,    66,    14,    29,    30,    49,    29,    30,
      14,    52,    64,    10,    10,    46,    42,    38,     8,    71,
      13,    51,    50,    12,    14,    14,    13,    57,    53,    53,
       9,    49,    51,    30,    71,    10,     4,    72,    65,    30,
      53,    64,    14,    10,    39,    10
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    34,    34,    36,    37,    38,    39,
      35,    40,    41,    42,    35,    44,    45,    43,    47,    46,
      46,    48,    48,    50,    49,    49,    49,    51,    51,    52,
      52,    53,    54,    54,    55,    55,    55,    55,    55,    56,
      57,    55,    58,    55,    59,    60,    60,    61,    61,    63,
      62,    65,    64,    64,    66,    66,    66,    66,    67,    67,
      67,    67,    68,    70,    69,    72,    71,    71,    73,    74,
      74,    74,    74,    75,    75,    75,    76,    76,    76,    76,
      77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     7,     1,     2,     0,     0,     0,     0,
      15,     0,     0,     0,    11,     0,     0,     6,     0,     4,
       0,     2,     0,     0,     3,     2,     0,     2,     0,     1,
       0,     1,     2,     0,     2,     1,     1,     1,     1,     0,
       0,     7,     0,     5,     5,     1,     1,     6,     6,     0,
       5,     0,     5,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     4,     0,     6,     0,     5,     0,     4,     1,
       1,     1,     1,     3,     3,     3,     1,     1,     1,     1,
       3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3:
#line 55 "Yacc.y"
                                      {}
#line 1495 "y.tab.c"
    break;

  case 6:
#line 61 "Yacc.y"
                      {
  incrementDepth("FUNCTION");
  strcpy(funName,(yyvsp[-1].string));
  countArgs=0;
  }
#line 1505 "y.tab.c"
    break;

  case 7:
#line 66 "Yacc.y"
          {strcpy(funName," ");}
#line 1511 "y.tab.c"
    break;

  case 8:
#line 66 "Yacc.y"
                                        {
  countFUNCTION=iTableSize;
}
#line 1519 "y.tab.c"
    break;

  case 9:
#line 70 "Yacc.y"
                  {

    //ret returnSymbol = addReturn(rt,,); //LAST SYMBOL FOR FUNCTION
    //instruction i = addInstruction(it,"COP",returnSymbol.addr,getAddrName(st,$2),-1); 
    //instruction i = addInstruction(it,"COP",,getAddrName($2),-1)


  }
#line 1532 "y.tab.c"
    break;

  case 10:
#line 78 "Yacc.y"
     {
  int returnLine = findJMPLine(it,(yyvsp[-13].string)) + 1; 
  //FUNCTION THAT FINDS THE JMP INSTRUCTION GENERATED AT THE MOMENT OF CALLING THE FUNCTION AND
  //RETURNS THE CORRESPONDING ASM/INSTRUCTION LINE
  instruction i = addInstruction(it,"JMP",returnLine,-1,-1); 
 
  int functionAsmLines=iTableSize-countFUNCTION;
  int patch = i.num - functionAsmLines + 1;
  updateJMPInstructionFunction(it,patch,(yyvsp[-13].string),argsDeclared);
  argsDeclared=0;

  deleteSymbols(st);
  print_sTable(st);
  decrementDepth("FUNCTION");
}
#line 1552 "y.tab.c"
    break;

  case 11:
#line 94 "Yacc.y"
                       {
  incrementDepth("FUNCTION");
  strcpy(funName,(yyvsp[-1].string));
  countArgs=0;
          }
#line 1562 "y.tab.c"
    break;

  case 12:
#line 98 "Yacc.y"
                    {strcpy(funName," ");}
#line 1568 "y.tab.c"
    break;

  case 13:
#line 98 "Yacc.y"
                                                  {
  countFUNCTION=iTableSize;
        }
#line 1576 "y.tab.c"
    break;

  case 14:
#line 100 "Yacc.y"
                  {
  int returnLine = findJMPLine(it,(yyvsp[-9].string)) + 1; 
  instruction i = addInstruction(it,"JMP",returnLine,-1,-1);

  int functionAsmLines=iTableSize-countFUNCTION;
  int patch = i.num - functionAsmLines + 1;
  updateJMPInstructionFunction(it,patch,(yyvsp[-9].string),argsDeclared); //THERE ARE AS MANY ADDITIONAL COP INSTRUCTIONS AS THERE ARE ARGS DECLARED. JMP INSTRUCTIONS MUST BE PATCHED ACCORDINGLY.
  argsDeclared=0;

  deleteSymbols(st);
  print_sTable(st);
  decrementDepth("FUNCTION"); 
        }
#line 1594 "y.tab.c"
    break;

  case 15:
#line 115 "Yacc.y"
             { strcpy(funName , (yyvsp[0].string)); }
#line 1600 "y.tab.c"
    break;

  case 16:
#line 115 "Yacc.y"
                                           {strcpy(funName,(yyvsp[-2].string));}
#line 1606 "y.tab.c"
    break;

  case 17:
#line 115 "Yacc.y"
                                                                              {
     instruction i = addInstructionWithFunctionName(it,"JMP",-1,-1,-1,(yyvsp[-5].string)); //PATCHED LATER 
}
#line 1614 "y.tab.c"
    break;

  case 18:
#line 119 "Yacc.y"
                 {
  
  argsDeclared++;
  //ADDING DECLARATED VARIABLES IN ()
  symbol local = addSymbol(st,(yyvsp[0].string),1);
  //instruction i = addInstruction(it,"COP",getAddrName(st,$3),sTableSize-1,-1);
  instruction i = addInstruction(it,"COP",local.addr,findPassedParameter(pt,funName,countArgs),-1);
  countArgs++;

}
#line 1629 "y.tab.c"
    break;

  case 23:
#line 131 "Yacc.y"
             {
  addParameter(pt,funName,getAddrName(st,(yyvsp[0].string),sTableDepth));
}
#line 1637 "y.tab.c"
    break;

  case 29:
#line 139 "Yacc.y"
             { (yyval.nb) = 2; }
#line 1643 "y.tab.c"
    break;

  case 30:
#line 139 "Yacc.y"
                           { (yyval.nb) = 1; }
#line 1649 "y.tab.c"
    break;

  case 39:
#line 152 "Yacc.y"
    { //DEPTH HANDELING
  incrementDepth("IF");
  countIF=iTableSize;
}
#line 1658 "y.tab.c"
    break;

  case 40:
#line 157 "Yacc.y"
    {
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
#line 1679 "y.tab.c"
    break;

  case 42:
#line 176 "Yacc.y"
    { //DEPTH HANDELING
  incrementDepth("WHILE");
  countWHILE=iTableSize;

  if (whileCond.arg1) {
    instruction i = addInstruction(it,"JMP",-1,-1,-1); //PATCHED LATER    
  } 

}
#line 1693 "y.tab.c"
    break;

  case 43:
#line 186 "Yacc.y"
    {
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
}
#line 1719 "y.tab.c"
    break;

  case 45:
#line 212 "Yacc.y"
      {
    instruction i = addInstruction(it,"PRI",getAddrName(st,(yyvsp[0].string),sTableDepth),-1,-1); 
  }
#line 1727 "y.tab.c"
    break;

  case 46:
#line 215 "Yacc.y"
        {
    symbol tmp = addSymbol(st,"tmp_nb_print",1);
    instruction i = addInstruction(it,"AFC",tmp.addr,(yyvsp[0].nb),-1);
    instruction j = addInstruction(it,"PRI",tmp.addr,-1,-1); 
    unstack(st);
  }
#line 1738 "y.tab.c"
    break;

  case 47:
#line 226 "Yacc.y"
                                                       {
    printf("DECLARATION & ASSIGN FOUND\n"); 
    symbol s = addSymbol(st,(yyvsp[-3].string),(yyvsp[-5].nb));
    symbol tmp = addSymbol(st,"tmp_nb",1); 
    instruction i = addInstruction(it,"AFC",tmp.addr,(yyvsp[-1].nb),-1);
    instruction j = addInstruction(it,"COP",getAddrName(st,(yyvsp[-3].string),sTableDepth),sTableSize-1,-1);
    unstack(st);

}
#line 1752 "y.tab.c"
    break;

  case 48:
#line 241 "Yacc.y"
                                                       {
   printf("DECLARATION & ASSIGN FOUND\n"); 
   symbol s = addSymbol(st,(yyvsp[-3].string),(yyvsp[-5].nb));
   symbol tmp = addSymbol(st,"tmp_nb",1); 
   instruction i = addInstruction(it,"COP",tmp.addr,getAddrName(st,(yyvsp[-1].string),sTableDepth),-1);
   instruction j = addInstruction(it,"COP",getAddrName(st,(yyvsp[-3].string),sTableDepth),sTableSize-1,-1);
   unstack(st);
}
#line 1765 "y.tab.c"
    break;

  case 49:
#line 251 "Yacc.y"
                               { //SIMPLE DECLARATION WITHOUT VAR ASSIGN
  if ((yyvsp[-2].nb) == 1){ //ONLY FOR VARS
    printf("VAR DECLARATION FOUND\n");
  }
  else if ((yyvsp[-2].nb) == 2){
    printf("CONST DECLARATION FOUND\n");
  }
  symbol s = addSymbol(st,(yyvsp[0].string),(yyvsp[-2].nb));
  varBool=(yyvsp[-2].nb); 

}
#line 1781 "y.tab.c"
    break;

  case 51:
#line 262 "Yacc.y"
                      {
    if (varBool == 1){
      printf("NEXT VAR DECLARATION FOUND\n");
    }
    else if (varBool == 2){
      printf("NEXT CONST DECLARATION FOUND\n");
    }
    symbol s = addSymbol(st,(yyvsp[0].string),varBool);

}
#line 1796 "y.tab.c"
    break;

  case 53:
#line 272 "Yacc.y"
                {varBool=0;}
#line 1802 "y.tab.c"
    break;

  case 54:
#line 274 "Yacc.y"
                 {
  printf("OPERAND FunCall FOUND \n");
  printf("Return of FunCall to add in symbol table as tmp: \n");
  symbol tmp = addSymbol(st,"tmp_funcall",1); 
  instruction i = addInstructionWithFunctionName(it,"COP",tmp.addr,-1,-1,funName); //PATCHED LATER

}
#line 1814 "y.tab.c"
    break;

  case 56:
#line 282 "Yacc.y"
             { //MUST BE STORED IN A TMP VARIABLE
  printf("OPERAND tID FOUND \n");
  printf("tID to add in symbol table as tmp: \n");
  symbol tmp = addSymbol(st,"tmp_id",1); 
  instruction i = addInstruction(it,"COP",tmp.addr,getAddrName(st,(yyvsp[0].string),sTableDepth),-1);

}
#line 1826 "y.tab.c"
    break;

  case 57:
#line 289 "Yacc.y"
             { //MUST BE STORED IN A TMP VARIABLE
  printf("OPERAND tNB FOUND \n");
  printf("tNB to add in symbol table as tmp: \n");
  symbol tmp = addSymbol(st,"tmp_nb",1); //INT FOR NOW
  instruction i = addInstruction(it,"AFC",tmp.addr,(yyvsp[0].nb),-1);
        }
#line 1837 "y.tab.c"
    break;

  case 58:
#line 296 "Yacc.y"
                                {
  printf("ADD OPERATION FOUND: \n");
  int addrArg2 = unstack(st); 
  int addrArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_add",1); //INT FOR NOW
  instruction i = addInstruction(it,"ADD",getAddr(st,result),addrArg1,addrArg2);
}
#line 1849 "y.tab.c"
    break;

  case 59:
#line 303 "Yacc.y"
                                 {
  printf("SUB OPERATION FOUND: \n");
  int addrArg2 = unstack(st);
  int addrArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_sub",1);
  instruction i = addInstruction(it,"SUB",getAddr(st,result),addrArg1,addrArg2);
}
#line 1861 "y.tab.c"
    break;

  case 60:
#line 310 "Yacc.y"
                                 {
  printf("MUL OPERATION FOUND: \n");
  int addrArg2 = unstack(st);
  int addrArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_mul",1);
  instruction i = addInstruction(it,"MUL",getAddr(st,result),addrArg1,addrArg2);
            }
#line 1873 "y.tab.c"
    break;

  case 61:
#line 317 "Yacc.y"
                                 {
  printf("DIV OPERATION FOUND: \n");
  int addrArg2 = unstack(st);
  int addrArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_div",1);
  instruction i = addInstruction(it,"DIV",getAddr(st,result),addrArg1,addrArg2);    
            }
#line 1885 "y.tab.c"
    break;

  case 62:
#line 326 "Yacc.y"
                                   {
  if (getSymbolByName(st,(yyvsp[-3].string),sTableDepth).type == 1){
    printf("VAR ASSIGN FOUND \n");
    if (getAddrName(st,(yyvsp[-3].string),sTableDepth)==-1){
      printf("ERROR: Variable %s not declared! \n",(yyvsp[-3].string));
    }
    else{
    instruction i = addInstruction(it,"COP",getAddrName(st,(yyvsp[-3].string),sTableDepth),sTableSize-1,-1);
    unstack(st);
  }
  }
  else if (getSymbolByName(st,(yyvsp[-3].string),sTableDepth).type == 2){
    if (!getSymbolByName(st,(yyvsp[-3].string),sTableDepth).assigned){
      printf("CONST ASSIGN FOUND \n");
      if (getAddrName(st,(yyvsp[-3].string),sTableDepth)==-1){
       printf("ERROR: Constant %s not declared! \n",(yyvsp[-3].string));
      }
      else{
      instruction i = addInstruction(it,"COP",getAddrName(st,(yyvsp[-3].string),sTableDepth),sTableSize-1,-1);
      printf("Changing assign status from 0 to 1\n");
      const_assigned(&st[getAddrName(st,(yyvsp[-3].string),sTableDepth)]);
      print_sTable(st);
      unstack(st);
      }
    } else {printf("ERROR: RE-ASSIGNING A CONSTANT IS NOT POSSIBLE\n");}
  }
}
#line 1917 "y.tab.c"
    break;

  case 63:
#line 355 "Yacc.y"
                                          {
//AT THIS POINT, WE HAVE A tmp_eqeq IN THE SYMBOL TABLE

}
#line 1926 "y.tab.c"
    break;

  case 65:
#line 361 "Yacc.y"
   {
  incrementDepth("ELSE");
  countELSE=iTableSize;
  if (elseCond.arg3){ //NO JMP FOR IF FALSE AND IF TRUE
    updateJMFInstructionOne(it);
    //AT THE END OF THE IF STATEMENT WE ADD A JMP INSTRUCTIONTO JUMP THE ELSE IN CASE THE CONDITION OF THE IF IS TRUE
    //JMP IS AN UNCONDITIONAL INSTRUCTION, WE ONLY NEED ARG1 WICH WILL BE PATCHED LATER ON
    instruction i = addInstruction(it,"JMP",-1,-1,-1);

  }

}
#line 1943 "y.tab.c"
    break;

  case 66:
#line 374 "Yacc.y"
    {
  //PATCHING JMP STATEMENT
  if (elseCond.arg3){ //NO JMP FOR IF FALSE AND IF TRUE
    int elseAsmLines=iTableSize-countELSE;
    updateJMPInstruction(it, elseAsmLines-1); //PATCH
  }
  elseCond = init_cond();
  deleteSymbols(st);
  print_sTable(st);
  decrementDepth("ELSE");
}
#line 1959 "y.tab.c"
    break;

  case 68:
#line 386 "Yacc.y"
                                                   {

}
#line 1967 "y.tab.c"
    break;

  case 70:
#line 392 "Yacc.y"
                    {
instruction i = addInstruction(it,"JMF",getAddrName(st,(yyvsp[0].string),sTableDepth),-1,-1); //PATCHED LATER    
ifCond = construct_cond(0,0,1);         
              }
#line 1976 "y.tab.c"
    break;

  case 72:
#line 397 "Yacc.y"
                      {
instruction i = addInstruction(it,"JMP",-1,-1,-1); //PATCHED LATER
ifCond = construct_cond(0,1,0);
              }
#line 1985 "y.tab.c"
    break;

  case 73:
#line 404 "Yacc.y"
                                     {

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
#line 2005 "y.tab.c"
    break;

  case 74:
#line 419 "Yacc.y"
                                     {

  printf("INF COMPARAISON FOUND: \n");
  int infArg2 = unstack(st);
  int infArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_inf",1);
  instruction i_inf = addInstruction(it,"INF",getAddr(st,result),infArg1,infArg2); //THE result VARIABLE OVERWRITES infArg1 BY HAVING THE SAME ADDRESS
  instruction i_jmf = addInstruction(it,"JMF",getAddr(st,result),-1,-1); //ARG2 INIT -1 THEN PATCHED
  ifCond = construct_cond(0,0,1); 
  unstack(st); //TO GET RID OF TMP_INF


}
#line 2023 "y.tab.c"
    break;

  case 75:
#line 432 "Yacc.y"
                                     {

  printf("INF COMPARAISON FOUND: \n");
  int supArg2 = unstack(st);
  int supArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_sup",1);
  instruction i_equ = addInstruction(it,"SUP",getAddr(st,result),supArg1,supArg2); //THE result VARIABLE OVERWRITES supArg1 BY HAVING THE SAME ADDRESS
  instruction i_jmf = addInstruction(it,"JMF",getAddr(st,result),-1,-1); //ARG2 INIT -1 THEN PATCHED
  ifCond = construct_cond(0,0,1); 
  unstack(st); //TO GET RID OF TMP_SUP


}
#line 2041 "y.tab.c"
    break;

  case 77:
#line 448 "Yacc.y"
                    {
instruction i = addInstruction(it,"JMF",getAddrName(st,(yyvsp[0].string),sTableDepth),-1,-1); //PATCHED LATER 
// limitedLoop=1; 
whileCond = construct_cond(0,0,1);
                
              }
#line 2052 "y.tab.c"
    break;

  case 78:
#line 454 "Yacc.y"
                      {
//infiniteLoop=1;    
whileCond = construct_cond(1,0,0);          
              }
#line 2061 "y.tab.c"
    break;

  case 79:
#line 458 "Yacc.y"
                      {
instruction i = addInstruction(it,"JMP",-1,-1,-1); //PATCHED LATER                
whileCond = construct_cond(0,1,0);
              }
#line 2070 "y.tab.c"
    break;

  case 80:
#line 463 "Yacc.y"
                                        {
  printf("WHILE EQEQ COMPARAISON FOUND: \n");
  int eqeqArg2 = unstack(st);
  int eqeqArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_eqeq",1);
  instruction i_equ = addInstruction(it,"EQU",getAddr(st,result),eqeqArg1,eqeqArg2);

  instruction i_jmf = addInstruction(it,"JMF",getAddr(st,result),-1,-1);  
  whileCond = construct_cond(0,0,1);
  unstack(st); //TO GET RID OF TMP_EQEQ


}
#line 2088 "y.tab.c"
    break;

  case 81:
#line 476 "Yacc.y"
                                     {
  printf("WHILE INF COMPARAISON FOUND: \n");
  int infArg2 = unstack(st);
  int infArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_inf",1);
  instruction i_inf = addInstruction(it,"INF",getAddr(st,result),infArg1,infArg2);

  instruction i_jmf = addInstruction(it,"JMF",getAddr(st,result),-1,-1); 
  whileCond = construct_cond(0,0,1);
  unstack(st); //TO GET RID OF TMP_INF

}
#line 2105 "y.tab.c"
    break;

  case 82:
#line 488 "Yacc.y"
                                     {
  printf("WHILE SUP COMPARAISON FOUND: \n");
  int supArg2 = unstack(st);
  int supArg1 = unstack(st);
  symbol result = addSymbol(st,"tmp_sup",1);
  instruction i_sup = addInstruction(it,"SUP",getAddr(st,result),supArg1,supArg2);

  instruction i_jmf = addInstruction(it,"JMF",getAddr(st,result),-1,-1); 
  whileCond = construct_cond(0,0,1);
  unstack(st); //TO GET RID OF TMP_SUP

}
#line 2122 "y.tab.c"
    break;


#line 2126 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 503 "Yacc.y"

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

  fclose (ASM);
  return 0;
}
