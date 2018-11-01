/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         HSQL_STYPE
#define YYLTYPE         HSQL_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         hsql_parse
#define yylex           hsql_lex
#define yyerror         hsql_error
#define yydebug         hsql_debug
#define yynerrs         hsql_nerrs


/* Copy the first part of user declarations.  */
#line 1 "bison_parser.y" /* yacc.c:339  */

/**
 * bison_parser.y
 * defines bison_parser.h
 * outputs bison_parser.c
 *
 * Grammar File Spec: http://dinosaur.compilertools.net/bison/bison_6.html
 *
 */
/*********************************
 ** Section 1: C Declarations
 *********************************/

#include "bison_parser.h"
#include "flex_lexer.h"

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace hsql;

int yyerror(YYLTYPE* llocp, hsql::SQLParser* parser, yyscan_t scanner, const char *msg) {
	//result->setIsValid(false);
	//result->setErrorDetails(strdup(msg), llocp->first_line, llocp->first_column);
	return 0;
}


#line 104 "bison_parser.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison_parser.h".  */
#ifndef YY_HSQL_BISON_PARSER_H_INCLUDED
# define YY_HSQL_BISON_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef HSQL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define HSQL_DEBUG 1
#  else
#   define HSQL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define HSQL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined HSQL_DEBUG */
#if HSQL_DEBUG
extern int hsql_debug;
#endif
/* "%code requires" blocks.  */
#line 36 "bison_parser.y" /* yacc.c:355  */

// %code requires block

#include "../SQLParser.h"
#include "parser_typedef.h"

#include "../../Aql/Aggregator.h"
#include "../../Aql/AstNode.h"
#include "../../Aql/Function.h"
#include "../../Aql/Parser.h"
#include "../../Aql/Quantifier.h"
#include "../../Aql/Query.h"

// Auto update column and line number
#define YY_USER_ACTION \
		yylloc->first_line = yylloc->last_line; \
		yylloc->first_column = yylloc->last_column; \
		for(int i = 0; yytext[i] != '\0'; i++) { \
			yylloc->total_column++; \
			yylloc->string_length++; \
				if(yytext[i] == '\n') { \
						yylloc->last_line++; \
						yylloc->last_column = 0; \
				} \
				else { \
						yylloc->last_column++; \
				} \
		}

#line 172 "bison_parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef HSQL_TOKENTYPE
# define HSQL_TOKENTYPE
  enum hsql_tokentype
  {
    SQL_INTVAL = 258,
    SQL_IDENTIFIER = 259,
    SQL_STRING = 260,
    SQL_FLOATVAL = 261,
    SQL_DEALLOCATE = 262,
    SQL_PARAMETERS = 263,
    SQL_INTERSECT = 264,
    SQL_TEMPORARY = 265,
    SQL_TIMESTAMP = 266,
    SQL_DISTINCT = 267,
    SQL_NVARCHAR = 268,
    SQL_RESTRICT = 269,
    SQL_TRUNCATE = 270,
    SQL_ANALYZE = 271,
    SQL_BETWEEN = 272,
    SQL_CASCADE = 273,
    SQL_COLUMNS = 274,
    SQL_CONTROL = 275,
    SQL_DEFAULT = 276,
    SQL_EXECUTE = 277,
    SQL_EXPLAIN = 278,
    SQL_HISTORY = 279,
    SQL_INTEGER = 280,
    SQL_NATURAL = 281,
    SQL_PREPARE = 282,
    SQL_PRIMARY = 283,
    SQL_SCHEMAS = 284,
    SQL_SPATIAL = 285,
    SQL_VIRTUAL = 286,
    SQL_BEFORE = 287,
    SQL_COLUMN = 288,
    SQL_CREATE = 289,
    SQL_DELETE = 290,
    SQL_DIRECT = 291,
    SQL_DOUBLE = 292,
    SQL_ESCAPE = 293,
    SQL_EXCEPT = 294,
    SQL_EXISTS = 295,
    SQL_EXTRACT = 296,
    SQL_GLOBAL = 297,
    SQL_HAVING = 298,
    SQL_IMPORT = 299,
    SQL_INSERT = 300,
    SQL_ISNULL = 301,
    SQL_OFFSET = 302,
    SQL_RENAME = 303,
    SQL_SCHEMA = 304,
    SQL_SELECT = 305,
    SQL_SORTED = 306,
    SQL_TABLES = 307,
    SQL_UNIQUE = 308,
    SQL_UNLOAD = 309,
    SQL_UPDATE = 310,
    SQL_VALUES = 311,
    SQL_AFTER = 312,
    SQL_ALTER = 313,
    SQL_CROSS = 314,
    SQL_DELTA = 315,
    SQL_GROUP = 316,
    SQL_INDEX = 317,
    SQL_INNER = 318,
    SQL_LIMIT = 319,
    SQL_LOCAL = 320,
    SQL_MERGE = 321,
    SQL_MINUS = 322,
    SQL_ORDER = 323,
    SQL_OUTER = 324,
    SQL_RIGHT = 325,
    SQL_TABLE = 326,
    SQL_UNION = 327,
    SQL_USING = 328,
    SQL_WHERE = 329,
    SQL_CALL = 330,
    SQL_CASE = 331,
    SQL_DATE = 332,
    SQL_DESC = 333,
    SQL_DROP = 334,
    SQL_ELSE = 335,
    SQL_FILE = 336,
    SQL_FROM = 337,
    SQL_FULL = 338,
    SQL_HASH = 339,
    SQL_HINT = 340,
    SQL_INTO = 341,
    SQL_JOIN = 342,
    SQL_LEFT = 343,
    SQL_LIKE = 344,
    SQL_LOAD = 345,
    SQL_NULL = 346,
    SQL_PLAN = 347,
    SQL_SHOW = 348,
    SQL_TEXT = 349,
    SQL_THEN = 350,
    SQL_TIME = 351,
    SQL_VIEW = 352,
    SQL_WHEN = 353,
    SQL_WITH = 354,
    SQL_ADD = 355,
    SQL_ALL = 356,
    SQL_AND = 357,
    SQL_ASC = 358,
    SQL_CSV = 359,
    SQL_END = 360,
    SQL_FOR = 361,
    SQL_INT = 362,
    SQL_KEY = 363,
    SQL_NOT = 364,
    SQL_OFF = 365,
    SQL_SET = 366,
    SQL_TBL = 367,
    SQL_TOP = 368,
    SQL_AS = 369,
    SQL_BY = 370,
    SQL_IF = 371,
    SQL_IN = 372,
    SQL_IS = 373,
    SQL_OF = 374,
    SQL_ON = 375,
    SQL_OR = 376,
    SQL_TO = 377,
    SQL_ARRAY = 378,
    SQL_CONCAT = 379,
    SQL_ILIKE = 380,
    SQL_SECOND = 381,
    SQL_MINUTE = 382,
    SQL_HOUR = 383,
    SQL_DAY = 384,
    SQL_MONTH = 385,
    SQL_YEAR = 386,
    SQL_EQUALS = 387,
    SQL_NOTEQUALS = 388,
    SQL_LESS = 389,
    SQL_GREATER = 390,
    SQL_LESSEQ = 391,
    SQL_GREATEREQ = 392,
    SQL_NOTNULL = 393,
    SQL_UMINUS = 394
  };
#endif

/* Value type.  */
#if ! defined HSQL_STYPE && ! defined HSQL_STYPE_IS_DECLARED

union HSQL_STYPE
{
#line 98 "bison_parser.y" /* yacc.c:355  */

  arangodb::aql::AstNode*  node;
  double fval;
  int64_t ival;
  char* sval;
  uintmax_t uval;
  bool bval;

  struct {
    char*                  value;
    size_t                 length;
  }                        strval;
  bool                     boolval;
  int64_t                  intval;

#line 340 "bison_parser.cpp" /* yacc.c:355  */
};

typedef union HSQL_STYPE HSQL_STYPE;
# define HSQL_STYPE_IS_TRIVIAL 1
# define HSQL_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined HSQL_LTYPE && ! defined HSQL_LTYPE_IS_DECLARED
typedef struct HSQL_LTYPE HSQL_LTYPE;
struct HSQL_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define HSQL_LTYPE_IS_DECLARED 1
# define HSQL_LTYPE_IS_TRIVIAL 1
#endif



int hsql_parse (hsql::SQLParser* parser, yyscan_t scanner);

#endif /* !YY_HSQL_BISON_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 370 "bison_parser.cpp" /* yacc.c:358  */

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
         || (defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL \
             && defined HSQL_STYPE_IS_TRIVIAL && HSQL_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   522

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  157
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  282

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   394

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   146,     2,     2,
     151,   152,   144,   142,   155,   143,   153,   145,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   154,
     135,   132,   136,   156,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   149,     2,   150,   147,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   133,   134,   137,
     138,   139,   140,   141,   148
};

#if HSQL_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   170,   170,   175,   178,   183,   188,   193,   195,   197,
     202,   205,   210,   212,   217,   222,   223,   227,   231,   232,
     233,   237,   238,   242,   244,   248,   249,   252,   253,   257,
     258,   262,   266,   268,   271,   276,   280,   285,   288,   293,
     296,   301,   306,   309,   312,   320,   321,   325,   330,   332,
     334,   336,   338,   342,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   366,   368,   372,   374,   376,   378,   380,
     384,   386,   389,   392,   395,   398,   401,   404,   407,   410,
     413,   420,   421,   422,   423,   427,   431,   435,   436,   437,
     438,   439,   440,   443,   447,   451,   452,   456,   457,   458,
     459,   462,   463,   464,   465,   466,   467,   468,   472,   473,
     477,   478,   482,   483,   484,   485,   489,   490,   491,   492,
     496,   497,   501,   505,   506,   510,   514,   515,   519,   520,
     523,   524,   528,   536,   537,   543,   544,   548,   549,   554,
     555,   560,   565,   567,   572,   573,   577,   578,   585,   588,
     592,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   611,   620,   621,   625,   626
};
#endif

#if HSQL_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTVAL", "IDENTIFIER", "STRING",
  "FLOATVAL", "DEALLOCATE", "PARAMETERS", "INTERSECT", "TEMPORARY",
  "TIMESTAMP", "DISTINCT", "NVARCHAR", "RESTRICT", "TRUNCATE", "ANALYZE",
  "BETWEEN", "CASCADE", "COLUMNS", "CONTROL", "DEFAULT", "EXECUTE",
  "EXPLAIN", "HISTORY", "INTEGER", "NATURAL", "PREPARE", "PRIMARY",
  "SCHEMAS", "SPATIAL", "VIRTUAL", "BEFORE", "COLUMN", "CREATE", "DELETE",
  "DIRECT", "DOUBLE", "ESCAPE", "EXCEPT", "EXISTS", "EXTRACT", "GLOBAL",
  "HAVING", "IMPORT", "INSERT", "ISNULL", "OFFSET", "RENAME", "SCHEMA",
  "SELECT", "SORTED", "TABLES", "UNIQUE", "UNLOAD", "UPDATE", "VALUES",
  "AFTER", "ALTER", "CROSS", "DELTA", "GROUP", "INDEX", "INNER", "LIMIT",
  "LOCAL", "MERGE", "MINUS", "ORDER", "OUTER", "RIGHT", "TABLE", "UNION",
  "USING", "WHERE", "CALL", "CASE", "DATE", "DESC", "DROP", "ELSE", "FILE",
  "FROM", "FULL", "HASH", "HINT", "INTO", "JOIN", "LEFT", "LIKE", "LOAD",
  "NULL", "PLAN", "SHOW", "TEXT", "THEN", "TIME", "VIEW", "WHEN", "WITH",
  "ADD", "ALL", "AND", "ASC", "CSV", "END", "FOR", "INT", "KEY", "NOT",
  "OFF", "SET", "TBL", "TOP", "AS", "BY", "IF", "IN", "IS", "OF", "ON",
  "OR", "TO", "ARRAY", "CONCAT", "ILIKE", "SECOND", "MINUTE", "HOUR",
  "DAY", "MONTH", "YEAR", "'='", "EQUALS", "NOTEQUALS", "'<'", "'>'",
  "LESS", "GREATER", "LESSEQ", "GREATEREQ", "NOTNULL", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'^'", "UMINUS", "'['", "']'", "'('", "')'", "'.'", "';'",
  "','", "'?'", "$accept", "input", "statement_list", "statement",
  "preparable_statement", "select_statement", "select_with_paren",
  "select_no_paren", "select_clause", "select_paren_or_clause",
  "set_operator", "set_type", "opt_all", "opt_group", "opt_having",
  "opt_top", "opt_where", "select_list", "opt_from_clause", "from_clause",
  "opt_limit", "int_literal", "opt_order", "order_list", "order_desc",
  "opt_order_type", "expr_list", "expr_alias", "expr", "operand",
  "scalar_expr", "unary_expr", "binary_expr", "case_expr", "array_expr",
  "extract_expr", "datetime_field", "array_index", "between_expr",
  "case_list", "column_name", "comp_expr", "exists_expr", "function_expr",
  "in_expr", "literal", "logic_expr", "null_literal", "num_literal",
  "string_literal", "alias", "opt_alias", "opt_distinct", "param_expr",
  "table_ref", "table_ref_atomic", "nonjoin_table_ref_atomic",
  "table_ref_commalist", "table_ref_name", "table_name", "table_alias",
  "opt_table_alias", "join_clause", "opt_join_type", "join_condition",
  "opt_semicolon", "ident_commalist", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,    61,   387,   388,    60,    62,   389,   390,   391,
     392,   393,    43,    45,    42,    47,    37,    94,   394,    91,
      93,    40,    41,    46,    59,    44,    63
};
# endif

#define YYPACT_NINF -200

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-200)))

#define YYTABLE_NINF -161

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-161)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -33,   -94,   -33,    43,  -112,  -200,  -200,  -200,    16,  -200,
     159,    46,    52,   -87,   -82,  -200,   -33,  -200,  -200,  -200,
    -200,   -33,    -5,   -24,   -33,    39,  -200,  -200,  -200,   119,
    -200,  -200,  -200,  -200,  -200,    44,  -200,  -200,   119,    44,
      46,  -200,     4,  -200,  -200,   -12,   -11,    18,  -200,   148,
     -36,   173,  -200,    94,  -200,    85,  -200,    47,  -200,    24,
     201,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
      39,    49,  -200,   -64,    39,  -200,   -10,     2,   121,   240,
     119,    45,   -54,    22,   173,   311,   119,   214,    53,   -90,
      -3,   125,  -200,   119,  -200,   119,   203,   119,  -200,  -200,
     173,  -200,   173,   -71,    57,    10,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,    46,  -200,   119,  -200,  -200,  -200,  -200,  -200,   119,
    -200,  -200,    60,  -200,  -200,  -200,  -200,  -200,  -200,   127,
     -68,    12,   119,   119,  -200,   121,   124,  -115,  -200,  -200,
      62,   -33,  -200,   196,  -200,    61,  -200,     7,  -200,   119,
     158,  -200,  -200,  -200,   118,   263,   343,   173,    72,    94,
    -200,   130,    76,   343,   343,   343,   343,   373,   373,   373,
     373,   214,   214,   -19,   -19,   -19,   -88,    83,  -200,   -48,
    -200,   119,   119,   119,  -200,    70,   -65,    74,  -200,   230,
      84,   153,  -200,  -200,  -200,   166,   172,   177,   161,    -3,
     247,  -200,  -200,  -200,   -61,   137,  -200,   173,   343,    94,
     101,   -23,  -200,  -200,  -200,   -89,   -61,    79,  -200,   119,
    -200,  -200,     7,    -3,  -200,  -200,  -200,    -3,   218,   103,
     119,   311,   104,    35,  -200,  -200,  -200,  -200,   -61,  -200,
    -200,   123,   254,   -35,  -200,  -200,   109,   119,  -200,    42,
     119,  -200,     6,   -61,  -200,  -200,   257,   -61,   114,   116,
    -200,  -200
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    28,     0,     0,   163,     3,     5,     6,     7,     8,
      38,     0,   131,     0,     0,     1,   162,     2,    19,    20,
      18,     0,    22,     0,     0,     0,    36,    27,   130,     0,
      11,    10,     4,    15,    16,    38,    21,    17,     0,    38,
       0,    12,    97,   125,   123,     0,     0,     0,   122,     0,
       0,     0,    99,     0,   132,    33,   124,    31,    45,   129,
      48,    55,    56,    57,    58,    61,    60,    54,    49,    63,
      70,    51,    59,    52,    64,    50,   118,   117,   116,   119,
       0,    37,    39,    44,     0,    35,   131,     0,     0,     0,
       0,     0,     0,     0,     0,    66,     0,    65,     0,     0,
       0,    30,    32,     0,   127,     0,     0,     0,   128,    47,
       0,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,    43,    42,    41,    13,   110,     0,
      98,   100,     0,    87,    88,    89,    90,    91,    92,     0,
       0,     0,     0,     0,    83,     0,     0,     0,    62,    53,
     142,     0,    34,   133,   135,     0,   137,   147,   136,     0,
      24,    46,   120,   126,   121,     0,    77,     0,     0,     0,
      68,     0,    80,    79,   101,   102,   103,   104,   105,   106,
     107,    72,    71,    74,    73,    75,    76,     0,    40,     0,
     108,     0,     0,     0,    81,     0,     0,     0,    85,     0,
       0,     0,   159,   151,   157,   155,   158,   153,     0,     0,
       0,   144,   146,   141,    29,     0,    14,     0,    78,     0,
       0,     0,    69,    93,   111,     0,    95,     0,    84,     0,
     109,   143,   147,     0,   154,   156,   152,     0,   134,   126,
       0,    94,     0,     0,   114,   112,    86,    82,    96,   138,
     148,   160,     0,    26,   115,   113,     0,     0,   164,     0,
       0,    23,     0,   161,   149,   145,     0,    25,    97,     0,
     165,   150
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -200,  -200,  -200,   253,  -200,   111,    69,     1,    87,   249,
     264,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
     -51,     5,    67,  -200,   143,  -200,   -92,   175,   -38,   -44,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,   189,
      13,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,
     227,  -200,   207,  -200,  -200,  -199,    51,  -200,  -200,  -200,
    -200,    55,  -200,  -200,  -200,  -200,  -200
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    35,
      21,    22,    37,   226,   271,    12,   170,    55,   101,   102,
      41,    56,    25,    81,    82,   136,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,   149,    67,    68,    92,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
     221,   109,    29,    79,   162,   163,   164,   165,   166,   167,
     222,   223,   168,   218,   274,    17,   269
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,   160,    28,    14,   157,    95,   140,    97,   270,    91,
     278,   104,   105,   105,   134,    99,    27,     1,   177,    11,
     248,    26,    42,    43,    44,    18,   152,   202,   104,   132,
     239,   107,   107,   137,   105,   208,   116,   105,   105,   135,
     103,   105,    16,    15,   153,    85,   178,   199,   261,    26,
      95,   154,   150,   107,    98,    19,   107,   107,    45,    46,
     107,   131,   159,   256,    28,    30,   175,   172,   176,   174,
      31,    13,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   231,    20,   142,
      33,    38,   203,    33,    47,    83,    36,    26,    42,    43,
      44,   180,    80,    40,   234,   116,    84,   103,    34,    48,
     153,    34,    23,    96,   205,   206,    90,   204,     2,   181,
     103,   220,    26,    42,    43,    44,   105,    49,   130,   255,
     131,   224,   103,   228,    45,    46,   197,   253,   106,    88,
      89,    50,   138,    90,     1,   107,   141,   105,   161,   211,
      52,    26,    42,    43,    44,    86,   207,    87,   263,    45,
      46,    51,    52,   235,   236,   237,   107,   100,    18,    53,
      47,     1,   105,   155,    54,   238,    26,    42,    43,    44,
     230,   105,   212,   251,   257,    48,   213,   265,    93,    46,
     103,   107,   214,   215,   275,    47,   266,   276,    19,   169,
     107,   258,   103,    49,   133,   158,   216,   173,   179,   201,
      48,   217,   200,   177,    46,   209,   219,    50,   110,   225,
     105,   232,   211,   229,    47,   131,   240,    23,    49,   273,
     252,    20,   277,   233,   241,   244,   242,    51,    52,    48,
     243,   245,    50,   267,   211,    53,   246,   111,   247,    47,
      54,   249,   250,   254,   262,   212,   264,    94,   268,   213,
     272,   280,    51,    52,    48,   214,   215,    87,   281,    32,
      53,    50,   210,    39,    24,    54,   198,   212,   171,   216,
     151,   213,    94,  -160,   217,   279,   108,   214,   215,     0,
     112,    51,    52,   139,   260,     0,    50,   259,     0,    53,
       0,   216,     0,     0,    54,  -160,   217,     0,     0,   111,
     113,     0,     0,     0,     0,     0,    51,    52,   114,   115,
       0,     0,     0,     0,    53,   116,   117,     0,     0,    54,
       0,     0,     0,   118,   119,   120,   121,   122,   116,     0,
     123,   124,     0,   125,   126,   127,   128,   129,   130,     0,
     131,  -139,   112,     0,     0,     0,     0,   111,   127,   128,
     129,   130,     0,   131,     0,   227,   143,   144,   145,   146,
     147,   148,   156,  -140,     0,     0,     0,     0,     0,     0,
       0,   115,     0,     0,     0,     0,     0,   116,   117,   111,
       0,     0,     0,     0,     0,   118,   119,   120,   121,   122,
     112,     0,   123,   124,     0,   125,   126,   127,   128,   129,
     130,     0,   131,     0,     0,     0,     0,     0,     0,   111,
     156,     0,     0,     0,     0,     0,     0,     0,     0,   115,
       0,     0,  -161,     0,     0,   116,   117,     0,     0,     0,
       0,     0,     0,   118,   119,   120,   121,   122,     0,     0,
     123,   124,     0,   125,   126,   127,   128,   129,   130,     0,
     131,   115,     0,     0,     0,     0,     0,   116,  -161,     0,
       0,     0,     0,     0,     0,  -161,  -161,  -161,   121,   122,
       0,     0,   123,   124,     0,   125,   126,   127,   128,   129,
     130,   115,   131,     0,     0,     0,     0,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -161,  -161,
       0,     0,  -161,  -161,     0,   125,   126,   127,   128,   129,
     130,     0,   131
};

static const yytype_int16 yycheck[] =
{
      38,     4,    12,     2,    96,    49,     4,    51,    43,    47,
       4,     4,   102,   102,    78,    53,    11,    50,    89,   113,
     219,     3,     4,     5,     6,     9,    80,    95,     4,    80,
      95,   121,   121,    84,   102,   150,   124,   102,   102,   103,
     155,   102,   154,     0,    98,    40,   117,   139,   247,     3,
      94,   105,    90,   121,    53,    39,   121,   121,    40,    41,
     121,   149,   152,   152,    12,   152,   110,   105,   112,   107,
     152,     2,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   179,    72,    88,
      21,   115,    80,    24,    76,   133,   101,     3,     4,     5,
       6,    91,    35,    64,   152,   124,    39,   155,    21,    91,
      98,    24,    68,   149,   152,   153,    98,   105,   151,   109,
     155,   114,     3,     4,     5,     6,   102,   109,   147,   152,
     149,   169,   155,   177,    40,    41,   131,   229,   114,   151,
     151,   123,   152,    98,    50,   121,   144,   102,   151,    26,
     144,     3,     4,     5,     6,   151,   155,   153,   250,    40,
      41,   143,   144,   201,   202,   203,   121,    82,     9,   151,
      76,    50,   102,   151,   156,   105,     3,     4,     5,     6,
     179,   102,    59,   227,   105,    91,    63,   152,    40,    41,
     155,   121,    69,    70,   152,    76,    73,   155,    39,    74,
     121,   239,   155,   109,   155,   152,    83,     4,   151,    82,
      91,    88,   152,    89,    41,   153,   155,   123,    17,    61,
     102,    91,    26,   151,    76,   149,   152,    68,   109,   267,
     229,    72,   270,   150,     4,    69,   152,   143,   144,    91,
      87,    69,   123,   120,    26,   151,    69,    46,    87,    76,
     156,     4,   115,   152,   151,    59,   152,   109,     4,    63,
     151,     4,   143,   144,    91,    69,    70,   153,   152,    16,
     151,   123,   161,    24,    10,   156,   133,    59,   103,    83,
      91,    63,   109,    87,    88,   272,    59,    69,    70,    -1,
      89,   143,   144,    86,   243,    -1,   123,   242,    -1,   151,
      -1,    83,    -1,    -1,   156,    87,    88,    -1,    -1,    46,
     109,    -1,    -1,    -1,    -1,    -1,   143,   144,   117,   118,
      -1,    -1,    -1,    -1,   151,   124,   125,    -1,    -1,   156,
      -1,    -1,    -1,   132,   133,   134,   135,   136,   124,    -1,
     139,   140,    -1,   142,   143,   144,   145,   146,   147,    -1,
     149,   155,    89,    -1,    -1,    -1,    -1,    46,   144,   145,
     146,   147,    -1,   149,    -1,   102,   126,   127,   128,   129,
     130,   131,   109,   155,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,    -1,    -1,    -1,    -1,   124,   125,    46,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      89,    -1,   139,   140,    -1,   142,   143,   144,   145,   146,
     147,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    46,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,    -1,    89,    -1,    -1,   124,   125,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
     139,   140,    -1,   142,   143,   144,   145,   146,   147,    -1,
     149,   118,    -1,    -1,    -1,    -1,    -1,   124,   125,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,   139,   140,    -1,   142,   143,   144,   145,   146,
     147,   118,   149,    -1,    -1,    -1,    -1,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,
      -1,    -1,   139,   140,    -1,   142,   143,   144,   145,   146,
     147,    -1,   149
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,   151,   158,   159,   160,   161,   162,   163,   164,
     165,   113,   172,   163,   164,     0,   154,   222,     9,    39,
      72,   167,   168,    68,   167,   179,     3,   178,    12,   209,
     152,   152,   160,   163,   165,   166,   101,   169,   115,   166,
      64,   177,     4,     5,     6,    40,    41,    76,    91,   109,
     123,   143,   144,   151,   156,   174,   178,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   194,   195,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   210,
     179,   180,   181,   185,   179,   178,   151,   153,   151,   151,
      98,   185,   196,    40,   109,   186,   149,   186,   164,   185,
      82,   175,   176,   155,     4,   102,   114,   121,   207,   208,
      17,    46,    89,   109,   117,   118,   124,   125,   132,   133,
     134,   135,   136,   139,   140,   142,   143,   144,   145,   146,
     147,   149,   177,   155,    78,   103,   182,   177,   152,   209,
       4,   144,   164,   126,   127,   128,   129,   130,   131,   193,
     185,   196,    80,    98,   105,   151,   109,   183,   152,   152,
       4,   151,   211,   212,   213,   214,   215,   216,   219,    74,
     173,   184,   185,     4,   185,   186,   186,    89,   117,   151,
      91,   109,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   178,   181,   183,
     152,    82,    95,    80,   105,   185,   185,   164,   150,   153,
     162,    26,    59,    63,    69,    70,    83,    88,   220,   155,
     114,   207,   217,   218,   185,    61,   170,   102,   186,   151,
     164,   183,    91,   150,   152,   185,   185,   185,   105,    95,
     152,     4,   152,    87,    69,    69,    69,    87,   212,     4,
     115,   186,   164,   183,   152,   152,   152,   105,   185,   218,
     213,   212,   151,   183,   152,   152,    73,   120,     4,   223,
      43,   171,   151,   185,   221,   152,   155,   185,     4,   197,
       4,   152
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   157,   158,   159,   159,   160,   161,   162,   162,   162,
     163,   163,   164,   164,   165,   166,   166,   167,   168,   168,
     168,   169,   169,   170,   170,   171,   171,   172,   172,   173,
     173,   174,   175,   175,   176,   177,   178,   179,   179,   180,
     180,   181,   182,   182,   182,   183,   183,   184,   185,   185,
     185,   185,   185,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   187,   187,   188,   188,   188,   188,   188,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   190,   190,   190,   190,   191,   192,   193,   193,   193,
     193,   193,   193,   194,   195,   196,   196,   197,   197,   197,
     197,   198,   198,   198,   198,   198,   198,   198,   199,   199,
     200,   200,   201,   201,   201,   201,   202,   202,   202,   202,
     203,   203,   204,   205,   205,   206,   207,   207,   208,   208,
     209,   209,   210,   211,   211,   212,   212,   213,   213,   214,
     214,   215,   216,   216,   217,   217,   218,   218,   219,   219,
     219,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   221,   222,   222,   223,   223
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     1,     1,     1,     1,     5,
       3,     3,     3,     5,     7,     1,     1,     2,     1,     1,
       1,     1,     0,     4,     0,     2,     0,     2,     0,     2,
       0,     1,     1,     0,     2,     2,     1,     3,     0,     1,
       3,     2,     1,     1,     0,     1,     3,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     2,     2,     2,     3,     4,
       1,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       3,     4,     6,     3,     5,     4,     6,     1,     1,     1,
       1,     1,     1,     4,     5,     4,     5,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     5,
       3,     5,     5,     6,     5,     6,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     2,     1,     1,     0,
       1,     0,     1,     1,     3,     1,     1,     1,     4,     1,
       3,     2,     1,     3,     1,     5,     1,     0,     4,     6,
       8,     1,     2,     1,     2,     1,     2,     1,     1,     1,
       0,     1,     1,     0,     1,     3
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
      yyerror (&yylloc, parser, scanner, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if HSQL_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, parser, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParser* parser, yyscan_t scanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (parser);
  YYUSE (scanner);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParser* parser, yyscan_t scanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, parser, scanner);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, hsql::SQLParser* parser, yyscan_t scanner)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , parser, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, parser, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !HSQL_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !HSQL_DEBUG */


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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, hsql::SQLParser* parser, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (parser);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (hsql::SQLParser* parser, yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 80 "bison_parser.y" /* yacc.c:1430  */
{
	// Initialize
	yylloc.first_column = 0;
	yylloc.last_column = 0;
	yylloc.first_line = 0;
	yylloc.last_line = 0;
	yylloc.total_column = 0;
	yylloc.string_length = 0;
}

#line 1677 "bison_parser.cpp" /* yacc.c:1430  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
  *++yylsp = yylloc;
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 170 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 1868 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 3:
#line 175 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 1875 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 4:
#line 178 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 1882 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 5:
#line 183 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 1889 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 6:
#line 188 "bison_parser.y" /* yacc.c:1648  */
    {
	}
#line 1896 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 9:
#line 197 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 1903 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 10:
#line 202 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 1910 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 11:
#line 205 "bison_parser.y" /* yacc.c:1648  */
    {
	}
#line 1917 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 12:
#line 210 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 1924 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 13:
#line 212 "bison_parser.y" /* yacc.c:1648  */
    {
	}
#line 1931 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 14:
#line 217 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 1938 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 23:
#line 242 "bison_parser.y" /* yacc.c:1648  */
    {
		}
#line 1945 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 24:
#line 244 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 1951 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 25:
#line 248 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 1957 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 26:
#line 249 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 1963 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 27:
#line 252 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 1969 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 28:
#line 253 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 1975 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 29:
#line 257 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 1981 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 30:
#line 258 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 1987 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 32:
#line 266 "bison_parser.y" /* yacc.c:1648  */
    {
        }
#line 1994 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 33:
#line 268 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2000 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 34:
#line 271 "bison_parser.y" /* yacc.c:1648  */
    {
		}
#line 2007 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 35:
#line 276 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2014 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 36:
#line 280 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2021 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 37:
#line 285 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2028 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 38:
#line 288 "bison_parser.y" /* yacc.c:1648  */
    {
	}
#line 2035 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 39:
#line 293 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2042 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 40:
#line 296 "bison_parser.y" /* yacc.c:1648  */
    {
	}
#line 2049 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 41:
#line 301 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2056 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 42:
#line 306 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2063 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 43:
#line 309 "bison_parser.y" /* yacc.c:1648  */
    {
	}
#line 2070 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 44:
#line 312 "bison_parser.y" /* yacc.c:1648  */
    {
	}
#line 2077 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 45:
#line 320 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2083 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 46:
#line 321 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2089 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 47:
#line 325 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2096 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 53:
#line 342 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2103 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 62:
#line 361 "bison_parser.y" /* yacc.c:1648  */
    {
	}
#line 2110 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 65:
#line 372 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2116 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 66:
#line 374 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2122 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 67:
#line 376 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2128 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 68:
#line 378 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2134 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 69:
#line 380 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2140 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 71:
#line 386 "bison_parser.y" /* yacc.c:1648  */
    {
	}
#line 2147 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 72:
#line 389 "bison_parser.y" /* yacc.c:1648  */
    {
	}
#line 2154 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 73:
#line 392 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2161 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 74:
#line 395 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2168 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 75:
#line 398 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2175 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 76:
#line 401 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2182 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 77:
#line 404 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2189 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 78:
#line 407 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2196 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 79:
#line 410 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2203 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 80:
#line 413 "bison_parser.y" /* yacc.c:1648  */
    {
    }
#line 2210 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 81:
#line 420 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2216 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 82:
#line 421 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2222 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 83:
#line 422 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2228 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 84:
#line 423 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2234 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 85:
#line 427 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2240 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 86:
#line 431 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2246 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 87:
#line 435 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2252 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 88:
#line 436 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2258 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 89:
#line 437 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2264 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 90:
#line 438 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2270 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 91:
#line 439 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2276 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 92:
#line 440 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2282 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 93:
#line 443 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2288 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 94:
#line 447 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2294 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 95:
#line 451 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2300 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 96:
#line 452 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2306 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 97:
#line 456 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2312 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 98:
#line 457 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2318 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 99:
#line 458 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2324 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 100:
#line 459 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2330 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 101:
#line 462 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2336 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 102:
#line 463 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2342 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 103:
#line 464 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2348 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 104:
#line 465 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2354 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 105:
#line 466 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2360 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 106:
#line 467 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2366 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 107:
#line 468 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2372 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 108:
#line 472 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2378 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 109:
#line 473 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2384 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 110:
#line 477 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2390 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 111:
#line 478 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2396 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 112:
#line 482 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2402 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 113:
#line 483 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2408 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 114:
#line 484 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2414 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 115:
#line 485 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2420 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 120:
#line 496 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2426 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 121:
#line 497 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2432 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 122:
#line 501 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2438 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 123:
#line 505 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2444 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 125:
#line 510 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2450 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 126:
#line 514 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2456 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 127:
#line 515 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2462 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 129:
#line 520 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2468 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 130:
#line 523 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2474 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 131:
#line 524 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2480 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 132:
#line 528 "bison_parser.y" /* yacc.c:1648  */
    {
		}
#line 2487 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 134:
#line 537 "bison_parser.y" /* yacc.c:1648  */
    {
		}
#line 2494 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 138:
#line 549 "bison_parser.y" /* yacc.c:1648  */
    {
		}
#line 2501 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 139:
#line 554 "bison_parser.y" /* yacc.c:1648  */
    { }
#line 2507 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 140:
#line 555 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2513 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 141:
#line 560 "bison_parser.y" /* yacc.c:1648  */
    {
		}
#line 2520 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 142:
#line 565 "bison_parser.y" /* yacc.c:1648  */
    {
		}
#line 2527 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 143:
#line 567 "bison_parser.y" /* yacc.c:1648  */
    {
	    }
#line 2534 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 145:
#line 573 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2540 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 147:
#line 578 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2546 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 148:
#line 586 "bison_parser.y" /* yacc.c:1648  */
    {
		}
#line 2553 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 149:
#line 589 "bison_parser.y" /* yacc.c:1648  */
    {
		}
#line 2560 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 150:
#line 593 "bison_parser.y" /* yacc.c:1648  */
    {
		}
#line 2567 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 151:
#line 598 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2573 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 152:
#line 599 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2579 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 153:
#line 600 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2585 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 154:
#line 601 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2591 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 155:
#line 602 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2597 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 156:
#line 603 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2603 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 157:
#line 604 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2609 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 158:
#line 605 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2615 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 159:
#line 606 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2621 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 160:
#line 607 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2627 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 164:
#line 625 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2633 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 165:
#line 626 "bison_parser.y" /* yacc.c:1648  */
    {}
#line 2639 "bison_parser.cpp" /* yacc.c:1648  */
    break;


#line 2643 "bison_parser.cpp" /* yacc.c:1648  */
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
  *++yylsp = yyloc;

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
      yyerror (&yylloc, parser, scanner, YY_("syntax error"));
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
        yyerror (&yylloc, parser, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, parser, scanner);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, parser, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, parser, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, parser, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, parser, scanner);
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
#line 630 "bison_parser.y" /* yacc.c:1907  */
