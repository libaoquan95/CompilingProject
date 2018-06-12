/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 
#include <iostream>
#include <list>
#include "ast.h"

extern int cur_line_num;
int yylex();
void yyerror(const char* msg) {
    printf("ERROR: %s at line %d \n", msg, cur_line_num);
}

#line 81 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_Le = 258,
    T_Ge = 259,
    T_Eq = 260,
    T_Ne = 261,
    T_And = 262,
    T_Or = 263,
    T_Void = 264,
    T_Int = 265,
    T_Double = 266,
    T_Boolean = 267,
    T_String = 268,
    T_Class = 269,
    T_Interface = 270,
    T_Null = 271,
    T_This = 272,
    T_Extends = 273,
    T_Implements = 274,
    T_For = 275,
    T_While = 276,
    T_If = 277,
    T_Else = 278,
    T_Return = 279,
    T_Break = 280,
    T_New = 281,
    T_NewArray = 282,
    T_Print = 283,
    T_ReadInteger = 284,
    T_ReadLine = 285,
    T_IntConstant = 286,
    T_DoubleConstant = 287,
    T_StringConstant = 288,
    T_Identifier = 289,
    T_BooleanConstant = 290,
    T_OR = 291,
    T_AND = 292,
    T_LET = 293,
    T_HET = 294,
    T_ELSE = 295,
    T_IFX = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "parser.y" /* yacc.c:355  */
 
    int     integerConstant; 
    int     boolConstant; 
    const   char *stringConstant; 
    double  doubleConstant; 
    char    identifier[128]; 


    int      ival;
    char     *sval;
    double   dval;
    int      bval;

#line 174 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 191 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   592

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,    50,     2,     2,
      53,    36,    48,    46,    38,    47,    52,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    57,
      42,    39,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    40,    41,    44,    45,    55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    86,    87,    90,    91,    95,    99,   103,
     104,   105,   106,   107,   108,   112,   113,   117,   118,   121,
     122,   127,   134,   139,   143,   144,   147,   148,   149,   152,
     153,   154,   158,   159,   162,   163,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   178,   179,   180,   181,   185,
     186,   187,   188,   192,   194,   198,   199,   202,   203,   206,
     210,   214,   216,   220,   221,   224,   227,   230,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   257,   262,   267,   272,   277,   282
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Le", "T_Ge", "T_Eq", "T_Ne", "T_And",
  "T_Or", "T_Void", "T_Int", "T_Double", "T_Boolean", "T_String",
  "T_Class", "T_Interface", "T_Null", "T_This", "T_Extends",
  "T_Implements", "T_For", "T_While", "T_If", "T_Else", "T_Return",
  "T_Break", "T_New", "T_NewArray", "T_Print", "T_ReadInteger",
  "T_ReadLine", "T_IntConstant", "T_DoubleConstant", "T_StringConstant",
  "T_Identifier", "T_BooleanConstant", "')'", "']'", "','", "'='", "T_OR",
  "T_AND", "'<'", "'>'", "T_LET", "T_HET", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "'.'", "'('", "'['", "T_ELSE", "T_IFX", "';'", "'{'",
  "'}'", "$accept", "Program", "VariableDecl", "Variable", "Type",
  "Formals", "VariableMore", "FunctionDecl", "FunctionDefn", "ClassDefn",
  "ExtendsQ", "Fieldlist", "Field", "StmtBlock", "Stmtlist", "Stmt",
  "SimpleStmt", "LValue", "Call", "Actuals", "ExprMore", "ForStmt",
  "WhileStmt", "IfStmt", "ReturnStmt", "BreakStmt", "PrintStmt",
  "BoolExpr", "Expr", "Constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    41,    93,    44,    61,
     291,   292,    60,    62,   293,   294,    43,    45,    42,    47,
      37,    33,    46,    40,    91,   295,   296,    59,   123,   125
};
# endif

#define YYPACT_NINF -146

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-146)))

#define YYTABLE_NINF -64

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-64)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      87,  -146,   -24,    82,  -146,    -6,  -146,  -146,   -20,   -19,
    -146,    21,  -146,    80,     2,  -146,  -146,  -146,  -146,  -146,
      13,  -146,  -146,   -16,   -30,  -146,  -146,  -146,  -146,  -146,
      -5,    12,     7,  -146,    43,  -146,    49,    48,    72,  -146,
       4,   309,  -146,  -146,  -146,  -146,  -146,   133,   473,  -146,
    -146,    33,    34,    58,   222,  -146,    78,    61,    63,    65,
      66,  -146,  -146,  -146,    67,  -146,   374,   374,   374,  -146,
    -146,  -146,  -146,    68,    89,    -7,  -146,  -146,  -146,    69,
      73,    74,   486,  -146,   260,   374,   374,  -146,  -146,  -146,
     486,    85,   374,   374,    99,   104,   298,    50,   218,   390,
    -146,   374,  -146,  -146,  -146,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   114,   374,
       6,    94,   116,   486,   120,   134,   407,   -27,   486,  -146,
    -146,   137,   131,  -146,   486,   486,   486,   538,   538,   486,
     486,   129,   129,    50,    50,   218,   218,   218,   121,   459,
     374,   184,   184,  -146,   345,  -146,   374,  -146,   298,  -146,
     125,  -146,   164,  -146,    59,   486,   152,   336,   184,  -146,
    -146,   153,  -146,   184,  -146
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     2,    25,     1,     3,     0,     0,
      24,     0,    28,     0,     6,    13,     9,    10,    11,    12,
       0,    23,    29,     0,     0,    30,    31,    26,    14,     5,
       7,     0,     0,    15,     8,    19,     0,     0,    17,     7,
       0,     0,    33,    21,    35,    22,    20,     0,     6,    96,
      70,     0,     0,     0,     0,    65,     0,     0,     0,     0,
       0,    92,    93,    95,    50,    94,     0,     0,     0,    32,
      36,    44,    34,     0,    69,    71,    40,    39,    38,     0,
       0,     0,     0,    68,     0,     0,     0,    52,    69,    71,
      64,     0,     0,     0,     0,     0,     0,    78,    87,     0,
      37,     0,    42,    41,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,     0,     0,    67,     0,     0,     0,     0,    57,    88,
      89,     0,    55,    72,    45,    80,    82,    83,    84,    85,
      86,    79,    81,    73,    74,    75,    76,    77,    49,     0,
       0,     0,     0,    90,     0,    66,     0,    54,     0,    51,
       0,    60,    61,    16,     0,    58,     0,     0,     0,    91,
      53,     0,    62,     0,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,   186,     5,   -13,  -146,  -146,  -146,  -146,   199,
    -146,  -146,  -146,   163,  -146,  -145,   -82,   -46,   -44,    62,
     135,  -146,  -146,  -146,  -146,  -146,  -146,   -71,   -41,  -146
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    70,    23,    36,    37,    38,    25,    26,     4,
       9,    13,    27,    71,    47,    72,    73,    88,    89,   131,
     132,    76,    77,    78,    79,    80,    81,   122,    82,    83
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    74,   121,    75,    30,    42,   161,   162,    34,   155,
       5,   156,     8,    90,    10,   124,    15,    16,    17,    18,
      19,    20,    12,   172,    31,    97,    98,    99,   174,   -46,
     -27,   -27,   -27,   -27,   -27,   -27,   -16,    35,    74,    11,
      75,    29,   -48,   -18,   123,   123,    46,    28,    32,    33,
     -46,   126,   128,   105,   106,   128,   -16,   109,   110,    -8,
     134,    43,    44,   -48,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   -16,   149,   160,
     -27,    14,     6,    39,    40,   171,    84,    85,     1,    15,
      16,    17,    18,    19,    20,   169,     2,   -16,   115,   116,
     117,     2,   118,    31,   119,    74,    74,    75,    75,   123,
      41,    86,    91,    31,    92,   165,    93,   128,    94,    95,
      96,    74,    74,    75,    75,   100,   102,    74,   101,    75,
     103,   104,   105,   106,    48,   129,   109,   110,   125,    21,
     130,   164,    15,    16,    17,    18,    19,    20,   148,    49,
      50,   150,   151,    51,    52,    53,   152,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   156,
     153,   -64,   -64,   157,   158,   113,   114,   115,   116,   117,
      66,   118,   167,   119,    67,    48,    68,   168,   170,   173,
     -47,    44,    69,    15,    16,    17,    18,    19,    20,    22,
      49,    50,     7,    45,    51,    52,    53,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     166,   105,   106,    87,     0,   109,   110,     0,   127,     0,
       0,    66,     0,     0,     0,    67,     0,    68,    49,    50,
       0,   -47,    44,     0,     0,     0,     0,     0,    56,    57,
       0,    59,    60,    61,    62,    63,    64,    65,     0,     0,
       0,   120,     0,     0,     0,     0,     0,     0,     0,    66,
     118,     0,   119,    67,     0,    68,    49,    50,     0,   -63,
       0,     0,     0,     0,     0,     0,    56,    57,     0,    59,
      60,    61,    62,    63,    64,    65,     0,     0,     0,    87,
       0,     0,     0,     0,     0,     0,     0,    66,     0,     0,
      34,    67,     0,    68,    49,    50,     0,   -47,    15,    16,
      17,    18,    19,    20,    56,    57,     0,    59,    60,    61,
      62,    63,    64,    65,   -56,     0,     0,   120,     0,     0,
       0,     0,     0,     0,     0,    66,   163,     0,     0,    67,
       0,    68,    49,    50,    15,    16,    17,    18,    19,    20,
       0,     0,    56,    57,     0,    59,    60,    61,    62,    63,
      64,    65,   -47,     0,     0,    87,     0,     0,     0,     0,
       0,     0,     0,    66,     0,     0,     0,    67,     0,    68,
      49,    50,     0,   105,   106,   107,   108,   109,   110,     0,
      56,    57,     0,    59,    60,    61,    62,    63,    64,    65,
     105,   106,   107,   108,   109,   110,     0,     0,     0,     0,
       0,    66,     0,     0,     0,    67,   133,    68,     0,     0,
       0,     0,   111,   112,     0,     0,   113,   114,   115,   116,
     117,     0,   118,     0,   119,   154,     0,     0,     0,   111,
     112,     0,     0,   113,   114,   115,   116,   117,     0,   118,
       0,   119,   105,   106,   107,   108,   109,   110,     0,     0,
       0,     0,     0,     0,     0,     0,   -52,   -52,   -52,   -52,
     -52,   -52,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   110,     0,   159,     0,     0,     0,
       0,   111,   112,     0,     0,   113,   114,   115,   116,   117,
       0,   118,   -52,   119,     0,   -52,   -52,     0,     0,   -52,
       0,   -52,   -52,   -52,     0,   -52,     0,   -16,   111,   112,
       0,     0,   113,   114,   115,   116,   117,     0,   118,     0,
     119,   105,   106,   -64,   -64,   109,   110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,   112,     0,     0,   113,   114,   115,   116,   117,     0,
     118,     0,   119
};

static const yytype_int16 yycheck[] =
{
      13,    47,    84,    47,    34,     1,   151,   152,     1,    36,
      34,    38,    18,    54,    34,    86,     9,    10,    11,    12,
      13,    14,     1,   168,    54,    66,    67,    68,   173,    36,
       9,    10,    11,    12,    13,    14,    34,    32,    84,    58,
      84,    57,    36,    36,    85,    86,    41,    34,    53,    37,
      57,    92,    93,     3,     4,    96,    54,     7,     8,    57,
     101,    57,    58,    57,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    34,   119,   150,
      59,     1,     0,    34,    36,   167,    53,    53,     1,     9,
      10,    11,    12,    13,    14,    36,    14,    54,    48,    49,
      50,    14,    52,    54,    54,   151,   152,   151,   152,   150,
      38,    53,    34,    54,    53,   156,    53,   158,    53,    53,
      53,   167,   168,   167,   168,    57,    57,   173,    39,   173,
      57,    57,     3,     4,     1,    36,     7,     8,    53,    59,
      36,   154,     9,    10,    11,    12,    13,    14,    34,    16,
      17,    57,    36,    20,    21,    22,    36,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    38,
      36,    42,    43,    36,    53,    46,    47,    48,    49,    50,
      47,    52,    57,    54,    51,     1,    53,    23,    36,    36,
      57,    58,    59,     9,    10,    11,    12,    13,    14,    13,
      16,    17,     3,    40,    20,    21,    22,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     158,     3,     4,     1,    -1,     7,     8,    -1,    93,    -1,
      -1,    47,    -1,    -1,    -1,    51,    -1,    53,    16,    17,
      -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      52,    -1,    54,    51,    -1,    53,    16,    17,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
       1,    51,    -1,    53,    16,    17,    -1,    57,     9,    10,
      11,    12,    13,    14,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,     1,    -1,    -1,    51,
      -1,    53,    16,    17,     9,    10,    11,    12,    13,    14,
      -1,    -1,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    51,    -1,    53,
      16,    17,    -1,     3,     4,     5,     6,     7,     8,    -1,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    51,    36,    53,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    52,    -1,    54,    38,    -1,    -1,    -1,    42,
      43,    -1,    -1,    46,    47,    48,    49,    50,    -1,    52,
      -1,    54,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    37,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    52,    39,    54,    -1,    42,    43,    -1,    -1,    46,
      -1,    48,    49,    50,    -1,    52,    -1,    54,    42,    43,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    52,    -1,
      54,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      52,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    14,    61,    69,    34,     0,    69,    18,    70,
      34,    58,     1,    71,     1,     9,    10,    11,    12,    13,
      14,    59,    62,    63,    64,    67,    68,    72,    34,    57,
      34,    54,    53,    37,     1,    63,    64,    65,    66,    34,
      36,    38,     1,    57,    58,    73,    63,    74,     1,    16,
      17,    20,    21,    22,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    47,    51,    53,    59,
      62,    73,    75,    76,    77,    78,    81,    82,    83,    84,
      85,    86,    88,    89,    53,    53,    53,     1,    77,    78,
      88,    34,    53,    53,    53,    53,    53,    88,    88,    88,
      57,    39,    57,    57,    57,     3,     4,     5,     6,     7,
       8,    42,    43,    46,    47,    48,    49,    50,    52,    54,
       1,    76,    87,    88,    87,    53,    88,    80,    88,    36,
      36,    79,    80,    36,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    34,    88,
      57,    36,    36,    36,    38,    36,    38,    36,    53,    37,
      87,    75,    75,     1,    64,    88,    79,    57,    23,    36,
      36,    76,    75,    36,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    61,    62,    62,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    66,
      66,    67,    68,    69,    70,    70,    71,    71,    71,    72,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    76,    77,
      77,    77,    77,    78,    78,    79,    79,    80,    80,    81,
      82,    83,    83,    84,    84,    85,    86,    87,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    89,    89,    89,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     3,     1,     1,     0,     1,
       3,     6,     6,     6,     2,     0,     2,     0,     1,     1,
       1,     1,     3,     1,     2,     0,     1,     2,     1,     1,
       1,     2,     2,     2,     1,     3,     1,     0,     1,     3,
       1,     4,     1,     6,     4,     1,     0,     1,     3,     9,
       5,     5,     7,     1,     2,     1,     4,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       4,     6,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 85 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n", "Program", "ClassDefn");         }
#line 1478 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 86 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n", "Program", "Program ClassDefn"); }
#line 1484 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 87 "parser.y" /* yacc.c:1646  */
    { yyerror("Program");                                      }
#line 1490 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 90 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "VariableDecl", "Variable ;");  }
#line 1496 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 91 "parser.y" /* yacc.c:1646  */
    { yyerror("VariableDecl");                                 }
#line 1502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 95 "parser.y" /* yacc.c:1646  */
    { 
                                          printf("%15s -> %-15s |",  "Variable", "Type Identifier");  
                                          printf("%15s -> %s %s \n",  "Variable", "Type", (yyvsp[0].sval));  
                                        }
#line 1511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 99 "parser.y" /* yacc.c:1646  */
    { yyerror("Variable");                                     }
#line 1517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 103 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Type", "Int");       }
#line 1523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 104 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Type", "Double");    }
#line 1529 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 105 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Type", "Bool");      }
#line 1535 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 106 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Type", "String");    }
#line 1541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 107 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Type", "Void");      }
#line 1547 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 108 "parser.y" /* yacc.c:1646  */
    { 
                                          printf("%15s -> %-15s |","Type", "Identifier");  
                                          printf("%15s -> %s %s\n", "Type", "calss", (yyvsp[0].sval));
                                        }
#line 1556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 112 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Type", "Type[]");    }
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 113 "parser.y" /* yacc.c:1646  */
    { yyerror("Type");                               }
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 117 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Formals", "VariableMore,"); }
#line 1574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 118 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Formals", " ");             }
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 121 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "VariableMore", "Variable");           }
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 123 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Formals", "VariableMore , Variable"); }
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 127 "parser.y" /* yacc.c:1646  */
    { 
                                        printf("%15s -> %-15s |",  "FunctionDecl", "Identifier(Formals)"); 
                                        printf("%15s -> %s \n",    "FunctionDecl", (yyvsp[-4].sval));           
                                        }
#line 1601 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 135 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %-15s \n",  "FunctionDefn", "Identifier(Formals) StmtBlock"); }
#line 1607 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 140 "parser.y" /* yacc.c:1646  */
    { printf("Class Identifier ExtendsQ { Fieldlist } \n");           }
#line 1613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 143 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "ExtendsQ", "T_Extends T_Identifier"); }
#line 1619 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 144 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "ExtendsQ", " ");                      }
#line 1625 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 147 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Fieldlist", "Fieldlist Field");       }
#line 1631 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 148 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Fieldlist", " ");                     }
#line 1637 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 149 "parser.y" /* yacc.c:1646  */
    { yyerror("Fieldlist");                                           }
#line 1643 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 152 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Field", "VariableDecl");     }
#line 1649 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 153 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Field", "FunctionDecl");     }
#line 1655 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 154 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Field", "FunctionDefn");     }
#line 1661 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 158 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "StmtBlock", ":{ Stmtlist } ");}
#line 1667 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 159 "parser.y" /* yacc.c:1646  */
    { yyerror("StmtBlock");                                   }
#line 1673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 162 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Stmtlist", "Stmtlist Stmt");  }
#line 1679 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 163 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Stmtlist", " ");              }
#line 1685 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 166 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Stmt", "VariableDecl");       }
#line 1691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 167 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Stmt", "SimpleStmt ;");       }
#line 1697 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 168 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Stmt", "IfStmt");             }
#line 1703 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 169 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Stmt", "WhileStmt ");         }
#line 1709 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 170 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Stmt", "ForStmt ");           }
#line 1715 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 171 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Stmt", "BreakStmt ;");        }
#line 1721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 172 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Stmt", "ReturnStmt ;");       }
#line 1727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 173 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Stmt", "PrintStmt ;");        }
#line 1733 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 174 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Stmt", "StmtBlock ");         }
#line 1739 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 178 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "SimpleStmt", "LValue = Expr ");}
#line 1745 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 179 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "SimpleStmt", "Call ");         }
#line 1751 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 180 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "SimpleStmt", " ");             }
#line 1757 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 181 "parser.y" /* yacc.c:1646  */
    { yyerror("SimpleStmt");                                   }
#line 1763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 185 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "LValue", "Expr . T_Identifier");}
#line 1769 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 186 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "LValue", "T_Identifier");       }
#line 1775 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 187 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "LValue", "Expr [ Expr ] ");     }
#line 1781 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 188 "parser.y" /* yacc.c:1646  */
    { yyerror("LValue");                                        }
#line 1787 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 193 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n", "Call", "Expr . T_Identifier ( Actuals ) ");}
#line 1793 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 195 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n", "Call", "T_Identifier ( Actuals ) ");       }
#line 1799 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 198 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Actuals", "ExprMore");                    }
#line 1805 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 199 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Actuals", "");                            }
#line 1811 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 202 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "ExprMore", "Expr");                       }
#line 1817 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 203 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "ExprMore", "ExprMore , Expr");            }
#line 1823 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 207 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "ForStmt", "For (SimpleStmt BoolExpr SimpleStmt ) Stmt ");}
#line 1829 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 211 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "WhileStmt", "While ( BoolExpr ) Stmt ");  }
#line 1835 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 215 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "IfStmt", "If (BoolExpr ) Stmt %prec T_IFX "); }
#line 1841 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 217 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "IfStmt", "If (BoolExpr ) Stmt T_Else Stmt "); }
#line 1847 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 220 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "ReturnStmt", "Return");                   }
#line 1853 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 221 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "ReturnStmt", "Return Expr ");             }
#line 1859 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 224 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "ReturnStmt", "Break");                    }
#line 1865 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 227 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "PrintStmt", "Print (ExprMore) ");         }
#line 1871 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 230 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "BoolExpr", "Expr");          }
#line 1877 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 233 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "Constant");          }
#line 1883 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 234 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "LValue");            }
#line 1889 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 235 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "This");              }
#line 1895 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 236 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "Call");              }
#line 1901 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 237 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "( Expr) ");          }
#line 1907 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 238 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "Expr + Expr ");      }
#line 1913 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 239 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "Expr - Expr ");      }
#line 1919 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 240 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "Expr * Expr ");      }
#line 1925 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 241 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "Expr /Expr ");       }
#line 1931 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 242 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "Expr % Expr ");      }
#line 1937 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 243 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "- Expr ");           }
#line 1943 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 244 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "Expr < Expr ");      }
#line 1949 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 245 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "LessEqual Expr ");   }
#line 1955 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 246 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "Expr >Expr ");       }
#line 1961 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 247 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "GreaterEqual");      }
#line 1967 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 248 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "Equal Expr ");       }
#line 1973 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 249 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "NotEqual Expr ");    }
#line 1979 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 250 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "And Expr ");         }
#line 1985 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 251 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "Or Expr ");          }
#line 1991 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 252 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "! Expr ");           }
#line 1997 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 253 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "Expr ReadInteger ( ) "); }
#line 2003 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 254 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "Expr ReadLine ( ) ");    }
#line 2009 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 256 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "New Identifier ( ) ");   }
#line 2015 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 258 "parser.y" /* yacc.c:1646  */
    { printf("%15s -> %s \n",  "Expr", "NewArray ( Expr , Type )");}
#line 2021 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 262 "parser.y" /* yacc.c:1646  */
    { 
                                        printf("%15s -> %-15s |",  "Constant", "IntConstant");   
                                        printf("%15s -> %d \n",    "Constant", (yyvsp[0].ival));
                                        (yyval.sval) = (yyvsp[0].ival);
                                        }
#line 2031 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 267 "parser.y" /* yacc.c:1646  */
    { 
                                        printf("%15s -> %-15s |",  "Constant", "DoubleConstant");
                                        printf("%15s -> %s \n",    "Constant", (yyvsp[0].sval));      
                                        (yyval.sval) = atof((yyvsp[0].sval));      
                                        }
#line 2041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 272 "parser.y" /* yacc.c:1646  */
    { 
                                        printf("%15s -> %-15s |",  "Constant", "BoolConstant"); 
                                        printf("%15s -> %d \n",    "Constant", (yyvsp[0].bval));
                                        (yyval.sval) = (yyvsp[0].bval);   
                                        }
#line 2051 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 277 "parser.y" /* yacc.c:1646  */
    { 
                                        printf("%15s -> %-15s |",  "Constant", "StringConstant"); 
                                        printf("%15s -> %s \n",    "Constant", (yyvsp[0].sval));
                                        (yyval.sval) = (yyvsp[0].sval);   
                                        }
#line 2061 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 282 "parser.y" /* yacc.c:1646  */
    { 
                                        printf("%15s -> %s\n",   "Constant", "Null");
                                        (yyval.sval) = null;
                                        }
#line 2070 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2074 "parser.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 288 "parser.y" /* yacc.c:1906  */


int main() {
    return yyparse();
}

