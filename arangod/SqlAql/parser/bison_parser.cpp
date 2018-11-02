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

#include "../sql/statements.h"
#include "../SQLParser.h"
#include "parser_typedef.h"
#include "../../Aql/Parser.h"
#include "../../Aql/AstNode.h"

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

#line 168 "bison_parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef HSQL_TOKENTYPE
# define HSQL_TOKENTYPE
  enum hsql_tokentype
  {
    SQL_IDENTIFIER = 258,
    SQL_STRING = 259,
    SQL_FLOATVAL = 260,
    SQL_INTVAL = 261,
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
#line 99 "bison_parser.y" /* yacc.c:355  */

	double fval;
	int64_t ival;
	char* sval;
	uintmax_t uval;
	bool bval;

	hsql::SQLStatement* statement;
	hsql::SelectStatement* 	select_stmt;
	hsql::ImportStatement* 	import_stmt;
	hsql::CreateStatement* 	create_stmt;
	hsql::InsertStatement* 	insert_stmt;
	hsql::DeleteStatement* 	delete_stmt;
	hsql::UpdateStatement* 	update_stmt;
	hsql::DropStatement*   	drop_stmt;
	hsql::PrepareStatement* prep_stmt;
	hsql::ExecuteStatement* exec_stmt;
	hsql::ShowStatement*    show_stmt;

	hsql::TableName table_name;
	hsql::TableRef* table;
	hsql::Expr* expr;
	hsql::OrderDescription* order;
	hsql::OrderType order_type;
	hsql::DatetimeField datetime_field;
	hsql::LimitDescription* limit;
	hsql::ColumnDefinition* column_t;
	hsql::GroupByDescription* group_t;
	hsql::UpdateClause* update_t;
	hsql::Alias* alias_t;

	std::vector<hsql::SQLStatement*>* stmt_vec;

	std::vector<char*>* str_vec;
	std::vector<hsql::TableRef*>* table_vec;
	std::vector<hsql::ColumnDefinition*>* column_vec;
	std::vector<hsql::UpdateClause*>* update_vec;
	std::vector<hsql::Expr*>* expr_vec;
	std::vector<hsql::OrderDescription*>* order_vec;

#line 361 "bison_parser.cpp" /* yacc.c:355  */
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

#line 391 "bison_parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   646

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  157
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  227
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  413

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
       0,   255,   255,   276,   282,   291,   295,   299,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   323,   324,   329,
     330,   334,   338,   350,   357,   360,   364,   376,   385,   389,
     399,   402,   416,   423,   430,   441,   442,   446,   447,   451,
     458,   459,   460,   461,   471,   477,   483,   491,   492,   501,
     510,   523,   530,   541,   542,   552,   561,   562,   566,   578,
     579,   580,   597,   598,   602,   603,   607,   617,   634,   638,
     639,   640,   644,   645,   649,   677,   678,   682,   686,   687,
     690,   722,   723,   727,   732,   736,   737,   740,   741,   745,
     746,   750,   754,   755,   756,   762,   763,   767,   768,   769,
     770,   771,   772,   773,   774,   781,   782,   786,   787,   791,
     801,   802,   803,   804,   805,   809,   810,   811,   812,   813,
     814,   815,   816,   817,   818,   822,   826,   830,   831,   832,
     833,   834,   838,   839,   840,   841,   842,   843,   844,   845,
     846,   847,   848,   852,   853,   857,   858,   859,   860,   866,
     867,   868,   869,   873,   874,   878,   879,   883,   884,   885,
     886,   887,   888,   889,   893,   894,   898,   902,   903,   904,
     905,   906,   907,   910,   914,   918,   922,   923,   924,   940,
     944,   945,   946,   947,   951,   956,   957,   961,   965,   969,
     981,   982,   992,   993,   997,   998,  1007,  1008,  1013,  1024,
    1033,  1034,  1039,  1040,  1045,  1046,  1050,  1051,  1056,  1057,
    1065,  1073,  1083,  1102,  1103,  1104,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,  1116,  1125,  1126,  1131,  1132
};
#endif

#if HSQL_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "FLOATVAL",
  "INTVAL", "DEALLOCATE", "PARAMETERS", "INTERSECT", "TEMPORARY",
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
  "preparable_statement", "opt_hints", "hint_list", "hint",
  "prepare_statement", "prepare_target_query", "execute_statement",
  "import_statement", "import_file_type", "file_path", "show_statement",
  "create_statement", "opt_not_exists", "column_def_commalist",
  "column_def", "column_type", "drop_statement", "opt_exists",
  "delete_statement", "truncate_statement", "insert_statement",
  "opt_column_list", "update_statement", "update_clause_commalist",
  "update_clause", "select_statement", "select_with_paren",
  "select_paren_or_clause", "select_no_paren", "set_operator", "set_type",
  "opt_all", "select_clause", "opt_distinct", "select_list",
  "opt_from_clause", "from_clause", "opt_where", "opt_group", "opt_having",
  "opt_order", "order_list", "order_desc", "opt_order_type", "opt_top",
  "opt_limit", "expr_list", "literal_list", "expr_alias", "expr",
  "operand", "scalar_expr", "unary_expr", "binary_expr", "logic_expr",
  "in_expr", "case_expr", "case_list", "exists_expr", "comp_expr",
  "function_expr", "extract_expr", "datetime_field", "array_expr",
  "array_index", "between_expr", "column_name", "literal",
  "string_literal", "num_literal", "int_literal", "null_literal",
  "param_expr", "table_ref", "table_ref_atomic",
  "nonjoin_table_ref_atomic", "table_ref_commalist", "table_ref_name",
  "table_ref_name_no_alias", "table_name", "table_alias",
  "opt_table_alias", "alias", "opt_alias", "join_clause", "opt_join_type",
  "join_condition", "opt_semicolon", "ident_commalist", YY_NULLPTR
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

#define YYPACT_NINF -312

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-312)))

#define YYTABLE_NINF -223

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-223)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     309,    18,    43,    79,    99,   -18,    44,    45,    52,    -3,
      43,    33,     2,   -39,   180,    34,  -312,   136,   136,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,     3,
    -312,     5,   192,    83,  -312,    68,   146,   135,   135,    43,
     153,    43,   257,   255,   170,  -312,   169,   169,    43,  -312,
     140,   147,  -312,   309,  -312,   202,  -312,  -312,  -312,  -312,
    -312,   -39,   197,   187,   -39,   -15,  -312,   300,    20,   302,
     205,    43,    43,   237,  -312,   234,   167,  -312,  -312,  -312,
     161,   316,   281,    43,    43,  -312,  -312,  -312,  -312,   171,
    -312,   259,  -312,  -312,  -312,   161,   259,   257,    28,  -312,
    -312,  -312,  -312,  -312,  -312,    27,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,   283,   -63,   167,   161,  -312,   321,
     326,    81,    91,   179,   181,   118,   219,   184,   285,  -312,
     157,   252,   182,  -312,    14,   322,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,   203,   -69,  -312,  -312,  -312,  -312,   335,   -15,   185,
    -312,   -43,   -15,  -312,   294,   299,   301,  -312,    20,  -312,
     235,   346,   238,   -41,   265,  -312,  -312,    31,   204,  -312,
      16,    12,   306,   251,   161,   128,    -6,   206,   285,   402,
     161,    66,   208,   -55,     4,   237,  -312,   161,  -312,   161,
     355,   161,  -312,  -312,   285,  -312,   285,   -62,   214,    24,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   257,   161,   316,  -312,   215,
      32,  -312,  -312,   161,  -312,  -312,  -312,  -312,   257,   257,
     257,  -312,   286,    -7,    62,  -312,   -39,    43,  -312,   366,
      20,  -312,   161,  -312,  -312,   220,  -312,  -312,  -312,  -312,
    -312,  -312,   289,   -45,    95,   161,   161,  -312,   306,   284,
     -57,  -312,  -312,   -39,  -312,    26,  -312,   228,  -312,     6,
    -312,   313,  -312,  -312,  -312,   282,   361,   432,   285,   236,
     157,  -312,   295,   240,   432,   432,   432,   432,   274,   274,
     274,   274,    66,    66,    96,    96,    96,   -87,   241,   -41,
    -312,    20,  -312,   335,  -312,  -312,  -312,  -312,   321,  -312,
    -312,  -312,  -312,  -312,  -312,   346,  -312,  -312,  -312,    77,
     101,  -312,   161,   161,   161,  -312,    87,    75,   243,  -312,
     244,   298,  -312,  -312,  -312,   324,   328,   330,   303,     4,
     397,  -312,  -312,  -312,   288,  -312,   285,   432,   157,   249,
     116,  -312,  -312,   120,  -312,  -312,  -312,  -312,  -312,   -51,
     -41,   129,  -312,   161,  -312,     6,     4,  -312,  -312,  -312,
       4,   195,   253,   161,   402,   254,   121,  -312,  -312,  -312,
    -312,  -312,   -41,  -312,  -312,   526,   326,   -30,  -312,  -312,
     261,   161,   141,   161,  -312,    13,   -41,  -312,  -312,   -41,
     262,   270,  -312
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
       0,     0,     0,     0,     0,   225,     3,    18,    18,    16,
       9,     7,    10,    15,    12,    13,    11,    14,     8,    59,
      60,    88,     0,   200,    50,    25,     0,    36,    36,     0,
       0,     0,     0,    76,     0,   199,    48,    48,     0,    30,
       0,     0,     1,   224,     2,     0,     6,     5,    70,    71,
      69,     0,    73,     0,     0,   104,    46,     0,     0,     0,
       0,     0,     0,    82,    28,     0,    54,   187,    95,    75,
       0,     0,     0,     0,     0,    31,    63,    62,     4,     0,
      64,    88,    65,    72,    68,     0,    88,     0,     0,    66,
     201,   184,   185,   188,   189,     0,   107,   180,   181,   186,
     182,   183,    24,    23,     0,     0,    54,     0,    49,     0,
       0,     0,   176,     0,     0,     0,     0,     0,     0,   178,
       0,    79,    77,   105,   209,   110,   117,   118,   119,   112,
     114,   120,   113,   132,   121,   122,   123,   116,   111,   125,
     126,     0,    82,    56,    47,    44,    45,     0,   104,    87,
      89,    94,   104,    99,   101,   100,    97,    26,     0,    35,
       0,     0,     0,    81,     0,    29,   226,     0,     0,    52,
      76,     0,     0,     0,     0,     0,     0,     0,     0,   128,
       0,   127,     0,     0,     0,    82,    78,     0,   207,     0,
       0,     0,   208,   109,     0,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    21,
       0,    19,    61,     0,    93,    92,    91,    67,     0,     0,
       0,   108,     0,     0,     0,    37,     0,     0,    53,     0,
       0,   164,     0,   177,   179,     0,   167,   168,   169,   170,
     171,   172,     0,     0,     0,     0,     0,   151,     0,     0,
       0,   124,   115,     0,    80,   190,   192,     0,   194,   205,
     193,    84,   106,   143,   206,   144,     0,   139,     0,     0,
       0,   130,     0,   142,   141,   157,   158,   159,   160,   161,
     162,   163,   134,   133,   136,   135,   137,   138,     0,    58,
      57,     0,    17,     0,    90,   103,   102,    98,     0,    41,
      42,    43,    40,    39,    33,     0,    34,    27,   227,     0,
       0,   155,     0,     0,     0,   149,     0,     0,     0,   173,
       0,     0,   221,   213,   219,   217,   220,   215,     0,     0,
       0,   204,   198,   202,     0,    74,     0,   140,     0,     0,
       0,   131,   174,     0,    20,    32,    38,    51,   165,     0,
     153,     0,   152,     0,   156,   205,     0,   216,   218,   214,
       0,   191,   206,     0,   175,     0,     0,   147,   145,    22,
     166,   150,   154,   195,   210,   222,     0,    86,   148,   146,
       0,     0,     0,     0,    83,     0,   223,   211,   203,    85,
     176,     0,   212
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -312,  -312,  -312,   352,  -312,   406,  -312,   112,  -312,  -312,
    -312,  -312,  -312,   108,  -312,  -312,   389,  -312,   105,  -312,
    -312,   385,  -312,  -312,  -312,   317,  -312,  -312,   207,  -206,
      30,   371,   -13,   407,  -312,  -312,   233,   263,  -312,  -312,
    -312,  -130,  -312,  -312,    82,  -312,   209,  -312,  -312,  -129,
    -184,  -230,   247,   -94,   -70,  -312,  -312,  -312,  -312,  -312,
    -312,   260,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
      46,   -65,  -115,  -312,   -34,  -312,  -312,  -312,  -311,    61,
    -312,  -312,  -312,     0,  -312,    74,   318,  -312,  -312,  -312,
    -312,  -312,    57
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    56,   230,   231,    18,   113,
      19,    20,    75,   174,    21,    22,    71,   244,   245,   323,
      23,    83,    24,    25,    26,   121,    27,   152,   153,    28,
      29,    91,    30,    61,    62,    94,    31,    80,   131,   195,
     196,   118,   355,   404,    65,   159,   160,   236,    43,    99,
     132,   105,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   186,   142,   143,   144,   145,   262,   146,   147,   148,
     149,   150,   107,   108,   109,   110,   111,   274,   275,   276,
     277,   278,    44,   279,   351,   352,   353,   203,   280,   348,
     407,    54,   177
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,   161,    34,   106,   175,   117,   270,    33,    78,   198,
      45,     9,    58,   403,    58,   253,   410,   198,   319,   170,
     329,    48,   228,   173,   101,   102,    77,   288,    79,   232,
     320,   185,    97,   237,    77,   234,   193,   210,   381,    73,
     326,    76,    59,    50,    59,    32,    33,   199,    85,    98,
     333,   199,   341,    37,    49,   289,   189,   199,   191,   199,
     235,   199,   225,   163,   166,   281,   201,   340,   330,   395,
     201,   115,   116,    63,   265,    60,   201,    60,   201,    38,
     201,   363,    35,   155,   156,   342,   227,   321,   171,   343,
     263,    90,   266,   339,    90,   344,   345,   272,   197,   267,
     322,   390,    36,   241,    46,   283,   360,   285,   179,   346,
      42,   103,    13,  -222,   347,   291,   199,   192,   189,   164,
     350,   122,   101,   102,    77,   197,    39,    40,   200,   165,
      47,     9,   309,   292,   286,   201,   287,   178,    41,   161,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   273,   254,   129,   123,   124,
     122,   101,   102,    77,   122,   101,   102,    77,   251,   255,
     373,   336,   337,   158,   386,   334,   104,   199,   162,   167,
      52,  -196,   168,   248,   312,   106,   249,   313,    53,   199,
     210,   308,   372,   266,   125,    66,   201,   123,   124,   397,
     335,   123,   124,   175,   315,   316,   317,     9,   201,   103,
     221,   222,   223,   224,   324,   225,   184,   325,   357,    68,
     210,   341,   122,   101,   102,    77,   184,   126,    69,   367,
     199,   199,   168,   125,   391,    55,    67,   125,   369,   370,
     371,   127,   180,   224,   181,   225,   106,   327,   103,   201,
     201,    70,   103,   368,   342,   338,   197,    74,   343,   187,
     124,   128,   129,    77,   344,   345,   126,    79,   388,   130,
     126,   197,   389,   399,   104,   168,   197,   359,   346,   392,
     127,    81,  -222,   347,   127,    82,   384,    89,   122,   101,
     102,    77,    86,   408,    92,   125,   249,    92,    93,    87,
     128,   129,    95,   100,   128,   129,   112,   406,   130,   409,
     103,   117,   130,   104,   114,   119,     1,   104,   120,   151,
     205,   154,   157,   169,     2,   101,   124,    63,   188,   176,
     182,     3,   183,   190,   194,   226,     4,   197,   229,   204,
     233,   238,   127,     5,     6,   385,   239,   242,   240,   243,
    -197,   247,   246,     7,     8,   250,     9,   268,   284,     9,
     271,   125,   128,   129,    10,   290,   311,   318,   205,   328,
     130,   332,   331,   288,   354,   104,   103,   256,   257,   258,
     259,   260,   261,   349,   199,   376,   361,   358,    11,   225,
     380,   362,   209,   377,   188,   374,   375,   378,   210,   379,
     382,   387,    12,   383,   396,    88,   398,   205,   127,  -223,
    -223,   206,   405,  -223,  -223,   181,   219,   220,   221,   222,
     223,   224,   412,   225,    57,   364,   365,    72,   128,   129,
     366,   207,    84,   172,   310,    96,   130,   394,    64,   208,
     209,   104,   314,   252,   282,   264,   210,   211,   205,   393,
     206,   411,   202,   402,   212,   213,   214,   215,   216,     0,
      13,   217,   218,   356,   219,   220,   221,   222,   223,   224,
     269,   225,     0,     0,     0,     0,     0,     0,   205,   209,
       0,     0,     0,     0,     0,   210,   211,     0,     0,     0,
       0,   206,     0,   212,   213,   214,   215,   216,     0,     0,
     217,   218,     0,   219,   220,   221,   222,   223,   224,     0,
     225,   269,     0,     0,     0,     0,     0,     0,     0,     0,
     209,  -223,     0,     0,     0,     0,   210,   211,     0,     0,
       0,     0,     0,     0,   212,   213,   214,   215,   216,     0,
       0,   217,   218,     0,   219,   220,   221,   222,   223,   224,
     209,   225,   341,     0,     0,     0,   210,  -223,     0,     0,
       0,     0,     0,     0,  -223,  -223,  -223,   215,   216,     0,
       0,   217,   218,     0,   219,   220,   221,   222,   223,   224,
       0,   225,     0,     0,     0,   342,     0,     0,     0,   343,
       0,     0,     0,     0,     0,   344,   345,     0,     0,   400,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   346,
       0,     0,     0,     0,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   401
};

static const yytype_int16 yycheck[] =
{
      13,    95,     2,    68,   119,    74,   190,     3,    42,     3,
      10,    50,     9,    43,     9,     3,     3,     3,    25,    82,
     250,    19,   152,   117,     4,     5,     6,    89,    12,   158,
      37,   125,    47,   162,     6,    78,   130,   124,   349,    39,
     246,    41,    39,    13,    39,    27,     3,   102,    48,    64,
      95,   102,    26,    71,    52,   117,   126,   102,   128,   102,
     103,   102,   149,    97,    98,   195,   121,   273,   252,   380,
     121,    71,    72,    68,    80,    72,   121,    72,   121,    97,
     121,   311,     3,    83,    84,    59,   155,    94,   151,    63,
     184,    61,    98,   150,    64,    69,    70,   152,   155,   105,
     107,   152,     3,   168,    71,   199,   290,   201,   121,    83,
     113,    91,   151,    87,    88,    91,   102,   130,   188,    91,
     114,     3,     4,     5,     6,   155,    82,    82,   114,   101,
      97,    50,   226,   109,   204,   121,   206,    56,    86,   233,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   151,   144,   144,    40,    41,
       3,     4,     5,     6,     3,     4,     5,     6,   152,   182,
      95,   265,   266,    91,   358,    80,   156,   102,    96,   152,
       0,   155,   155,   152,   152,   250,   155,   155,   154,   102,
     124,   225,   105,    98,    76,     3,   121,    40,    41,   383,
     105,    40,    41,   318,   238,   239,   240,    50,   121,    91,
     144,   145,   146,   147,   152,   149,    98,   155,   288,   151,
     124,    26,     3,     4,     5,     6,    98,   109,    82,   152,
     102,   102,   155,    76,   105,    99,   153,    76,   332,   333,
     334,   123,   151,   147,   153,   149,   311,   247,    91,   121,
     121,   116,    91,   152,    59,   268,   155,   104,    63,    40,
      41,   143,   144,     6,    69,    70,   109,    12,   152,   151,
     109,   155,   152,   152,   156,   155,   155,   290,    83,   373,
     123,   111,    87,    88,   123,   116,   356,    85,     3,     4,
       5,     6,   152,   152,    61,    76,   155,    64,   101,   152,
     143,   144,   115,     3,   143,   144,     4,   401,   151,   403,
      91,    74,   151,   156,   109,    81,     7,   156,   151,     3,
      46,    40,   151,    40,    15,     4,    41,    68,   109,     3,
     151,    22,   151,   149,    82,   132,    27,   155,     3,    17,
     155,    47,   123,    34,    35,   358,    47,   112,    47,     3,
     155,    86,   114,    44,    45,   151,    50,   151,     3,    50,
     152,    76,   143,   144,    55,   151,   151,    81,    46,     3,
     151,    82,   152,    89,    61,   156,    91,   126,   127,   128,
     129,   130,   131,   155,   102,    87,    91,   151,    79,   149,
      87,   150,   118,    69,   109,   152,   152,    69,   124,    69,
       3,   152,    93,   115,   151,    53,   152,    46,   123,   135,
     136,    89,   151,   139,   140,   153,   142,   143,   144,   145,
     146,   147,   152,   149,    18,   313,   318,    38,   143,   144,
     325,   109,    47,   116,   227,    64,   151,   376,    31,   117,
     118,   156,   233,   180,   197,   185,   124,   125,    46,   375,
      89,   405,   134,   396,   132,   133,   134,   135,   136,    -1,
     151,   139,   140,   102,   142,   143,   144,   145,   146,   147,
     109,   149,    -1,    -1,    -1,    -1,    -1,    -1,    46,   118,
      -1,    -1,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,
      -1,    89,    -1,   132,   133,   134,   135,   136,    -1,    -1,
     139,   140,    -1,   142,   143,   144,   145,   146,   147,    -1,
     149,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    89,    -1,    -1,    -1,    -1,   124,   125,    -1,    -1,
      -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,   139,   140,    -1,   142,   143,   144,   145,   146,   147,
     118,   149,    26,    -1,    -1,    -1,   124,   125,    -1,    -1,
      -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,
      -1,   139,   140,    -1,   142,   143,   144,   145,   146,   147,
      -1,   149,    -1,    -1,    -1,    59,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    15,    22,    27,    34,    35,    44,    45,    50,
      55,    79,    93,   151,   158,   159,   160,   161,   165,   167,
     168,   171,   172,   177,   179,   180,   181,   183,   186,   187,
     189,   193,    27,     3,   240,     3,     3,    71,    97,    82,
      82,    86,   113,   205,   239,   240,    71,    97,    19,    52,
     187,   189,     0,   154,   248,    99,   162,   162,     9,    39,
      72,   190,   191,    68,   190,   201,     3,   153,   151,    82,
     116,   173,   173,   240,   104,   169,   240,     6,   231,    12,
     194,   111,   116,   178,   178,   240,   152,   152,   160,    85,
     187,   188,   193,   101,   192,   115,   188,    47,    64,   206,
       3,     4,     5,    91,   156,   208,   228,   229,   230,   231,
     232,   233,     4,   166,   109,   240,   240,    74,   198,    81,
     151,   182,     3,    40,    41,    76,   109,   123,   143,   144,
     151,   195,   207,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   219,   220,   221,   222,   224,   225,   226,   227,
     228,     3,   184,   185,    40,   240,   240,   151,   201,   202,
     203,   210,   201,   231,    91,   101,   231,   152,   155,    40,
      82,   151,   182,   210,   170,   229,     3,   249,    56,   189,
     151,   153,   151,   151,    98,   210,   218,    40,   109,   211,
     149,   211,   189,   210,    82,   196,   197,   155,     3,   102,
     114,   121,   243,   244,    17,    46,    89,   109,   117,   118,
     124,   125,   132,   133,   134,   135,   136,   139,   140,   142,
     143,   144,   145,   146,   147,   149,   132,   155,   198,     3,
     163,   164,   206,   155,    78,   103,   204,   206,    47,    47,
      47,   228,   112,     3,   174,   175,   114,    86,   152,   155,
     151,   152,   194,     3,   144,   189,   126,   127,   128,   129,
     130,   131,   223,   210,   218,    80,    98,   105,   151,   109,
     207,   152,   152,   151,   234,   235,   236,   237,   238,   240,
     245,   198,   209,   210,     3,   210,   211,   211,    89,   117,
     151,    91,   109,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   231,   210,
     185,   151,   152,   155,   203,   231,   231,   231,    81,    25,
      37,    94,   107,   176,   152,   155,   186,   240,     3,   208,
     207,   152,    82,    95,    80,   105,   210,   210,   189,   150,
     186,    26,    59,    63,    69,    70,    83,    88,   246,   155,
     114,   241,   242,   243,    61,   199,   102,   211,   151,   189,
     207,    91,   150,   208,   164,   170,   175,   152,   152,   210,
     210,   210,   105,    95,   152,   152,    87,    69,    69,    69,
      87,   235,     3,   115,   211,   189,   207,   152,   152,   152,
     152,   105,   210,   242,   236,   235,   151,   207,   152,   152,
      73,   120,   249,    43,   200,   151,   210,   247,   152,   210,
       3,   227,   152
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   157,   158,   159,   159,   160,   160,   160,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   162,   162,   163,
     163,   164,   164,   165,   166,   167,   167,   168,   169,   170,
     171,   171,   172,   172,   172,   173,   173,   174,   174,   175,
     176,   176,   176,   176,   177,   177,   177,   178,   178,   179,
     180,   181,   181,   182,   182,   183,   184,   184,   185,   186,
     186,   186,   187,   187,   188,   188,   189,   189,   190,   191,
     191,   191,   192,   192,   193,   194,   194,   195,   196,   196,
     197,   198,   198,   199,   199,   200,   200,   201,   201,   202,
     202,   203,   204,   204,   204,   205,   205,   206,   206,   206,
     206,   206,   206,   206,   206,   207,   207,   208,   208,   209,
     210,   210,   210,   210,   210,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   212,   212,   213,   213,   213,
     213,   213,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   215,   215,   216,   216,   216,   216,   217,
     217,   217,   217,   218,   218,   219,   219,   220,   220,   220,
     220,   220,   220,   220,   221,   221,   222,   223,   223,   223,
     223,   223,   223,   224,   225,   226,   227,   227,   227,   227,
     228,   228,   228,   228,   229,   230,   230,   231,   232,   233,
     234,   234,   235,   235,   236,   236,   237,   237,   238,   239,
     240,   240,   241,   241,   242,   242,   243,   243,   244,   244,
     245,   245,   245,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   247,   248,   248,   249,   249
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     0,     1,
       3,     1,     4,     4,     1,     2,     5,     7,     1,     1,
       2,     3,     8,     7,     7,     3,     0,     1,     3,     2,
       1,     1,     1,     1,     4,     4,     3,     2,     0,     4,
       2,     8,     5,     3,     0,     5,     1,     3,     3,     1,
       1,     5,     3,     3,     1,     1,     3,     5,     2,     1,
       1,     1,     1,     0,     7,     1,     0,     1,     1,     0,
       2,     2,     0,     4,     0,     2,     0,     3,     0,     1,
       3,     2,     1,     1,     0,     2,     0,     2,     4,     2,
       2,     2,     4,     4,     0,     1,     3,     1,     3,     2,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     2,     2,     2,
       3,     4,     1,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     3,     3,     3,     5,     6,     5,     6,     4,
       6,     3,     5,     4,     5,     4,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     6,     1,     1,     1,
       1,     1,     1,     4,     4,     5,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     4,     1,     3,     2,     1,
       1,     3,     1,     5,     1,     0,     2,     1,     1,     0,
       4,     6,     8,     1,     2,     1,     2,     1,     2,     1,
       1,     1,     0,     1,     1,     0,     1,     3
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
  switch (yytype)
    {
          case 3: /* IDENTIFIER  */
#line 146 "bison_parser.y" /* yacc.c:1258  */
      { free( (((*yyvaluep).sval)) ); }
#line 1685 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 4: /* STRING  */
#line 146 "bison_parser.y" /* yacc.c:1258  */
      { free( (((*yyvaluep).sval)) ); }
#line 1691 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 5: /* FLOATVAL  */
#line 144 "bison_parser.y" /* yacc.c:1258  */
      { }
#line 1697 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 6: /* INTVAL  */
#line 144 "bison_parser.y" /* yacc.c:1258  */
      { }
#line 1703 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 159: /* statement_list  */
#line 147 "bison_parser.y" /* yacc.c:1258  */
      {
	if ((((*yyvaluep).stmt_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).stmt_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).stmt_vec));
}
#line 1716 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 160: /* statement  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).statement)); }
#line 1722 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 161: /* preparable_statement  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).statement)); }
#line 1728 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 162: /* opt_hints  */
#line 147 "bison_parser.y" /* yacc.c:1258  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1741 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 163: /* hint_list  */
#line 147 "bison_parser.y" /* yacc.c:1258  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1754 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 164: /* hint  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 1760 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 165: /* prepare_statement  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).prep_stmt)); }
#line 1766 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 166: /* prepare_target_query  */
#line 146 "bison_parser.y" /* yacc.c:1258  */
      { free( (((*yyvaluep).sval)) ); }
#line 1772 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 167: /* execute_statement  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).exec_stmt)); }
#line 1778 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 168: /* import_statement  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).import_stmt)); }
#line 1784 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 169: /* import_file_type  */
#line 144 "bison_parser.y" /* yacc.c:1258  */
      { }
#line 1790 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 170: /* file_path  */
#line 146 "bison_parser.y" /* yacc.c:1258  */
      { free( (((*yyvaluep).sval)) ); }
#line 1796 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 171: /* show_statement  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).show_stmt)); }
#line 1802 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 172: /* create_statement  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).create_stmt)); }
#line 1808 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 173: /* opt_not_exists  */
#line 144 "bison_parser.y" /* yacc.c:1258  */
      { }
#line 1814 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 174: /* column_def_commalist  */
#line 147 "bison_parser.y" /* yacc.c:1258  */
      {
	if ((((*yyvaluep).column_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).column_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).column_vec));
}
#line 1827 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 175: /* column_def  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).column_t)); }
#line 1833 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 176: /* column_type  */
#line 144 "bison_parser.y" /* yacc.c:1258  */
      { }
#line 1839 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 177: /* drop_statement  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).drop_stmt)); }
#line 1845 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 178: /* opt_exists  */
#line 144 "bison_parser.y" /* yacc.c:1258  */
      { }
#line 1851 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 179: /* delete_statement  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).delete_stmt)); }
#line 1857 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 180: /* truncate_statement  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).delete_stmt)); }
#line 1863 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 181: /* insert_statement  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).insert_stmt)); }
#line 1869 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 182: /* opt_column_list  */
#line 147 "bison_parser.y" /* yacc.c:1258  */
      {
	if ((((*yyvaluep).str_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).str_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).str_vec));
}
#line 1882 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 183: /* update_statement  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).update_stmt)); }
#line 1888 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 184: /* update_clause_commalist  */
#line 147 "bison_parser.y" /* yacc.c:1258  */
      {
	if ((((*yyvaluep).update_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).update_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).update_vec));
}
#line 1901 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 185: /* update_clause  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).update_t)); }
#line 1907 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 186: /* select_statement  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1913 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 187: /* select_with_paren  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1919 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 188: /* select_paren_or_clause  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1925 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 189: /* select_no_paren  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1931 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 193: /* select_clause  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1937 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 194: /* opt_distinct  */
#line 144 "bison_parser.y" /* yacc.c:1258  */
      { }
#line 1943 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 195: /* select_list  */
#line 147 "bison_parser.y" /* yacc.c:1258  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1956 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 196: /* opt_from_clause  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).table)); }
#line 1962 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 197: /* from_clause  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).table)); }
#line 1968 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 198: /* opt_where  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 1974 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 199: /* opt_group  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).group_t)); }
#line 1980 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 200: /* opt_having  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 1986 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 201: /* opt_order  */
#line 147 "bison_parser.y" /* yacc.c:1258  */
      {
	if ((((*yyvaluep).order_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).order_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).order_vec));
}
#line 1999 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 202: /* order_list  */
#line 147 "bison_parser.y" /* yacc.c:1258  */
      {
	if ((((*yyvaluep).order_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).order_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).order_vec));
}
#line 2012 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 203: /* order_desc  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).order)); }
#line 2018 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 204: /* opt_order_type  */
#line 144 "bison_parser.y" /* yacc.c:1258  */
      { }
#line 2024 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 205: /* opt_top  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).limit)); }
#line 2030 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 206: /* opt_limit  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).limit)); }
#line 2036 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 207: /* expr_list  */
#line 147 "bison_parser.y" /* yacc.c:1258  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 2049 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 208: /* literal_list  */
#line 147 "bison_parser.y" /* yacc.c:1258  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 2062 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 209: /* expr_alias  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2068 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 210: /* expr  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2074 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 211: /* operand  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2080 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 212: /* scalar_expr  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2086 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 213: /* unary_expr  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2092 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 214: /* binary_expr  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2098 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 215: /* logic_expr  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2104 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 216: /* in_expr  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2110 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 217: /* case_expr  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2116 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 218: /* case_list  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2122 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 219: /* exists_expr  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2128 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 220: /* comp_expr  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2134 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 221: /* function_expr  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2140 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 222: /* extract_expr  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2146 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 223: /* datetime_field  */
#line 144 "bison_parser.y" /* yacc.c:1258  */
      { }
#line 2152 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 224: /* array_expr  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2158 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 225: /* array_index  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2164 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 226: /* between_expr  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2170 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 227: /* column_name  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2176 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 228: /* literal  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2182 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 229: /* string_literal  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2188 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 230: /* num_literal  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2194 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 231: /* int_literal  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2200 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 232: /* null_literal  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2206 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 233: /* param_expr  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2212 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 234: /* table_ref  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).table)); }
#line 2218 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 235: /* table_ref_atomic  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).table)); }
#line 2224 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 236: /* nonjoin_table_ref_atomic  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).table)); }
#line 2230 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 237: /* table_ref_commalist  */
#line 147 "bison_parser.y" /* yacc.c:1258  */
      {
	if ((((*yyvaluep).table_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).table_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).table_vec));
}
#line 2243 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 238: /* table_ref_name  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).table)); }
#line 2249 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 239: /* table_ref_name_no_alias  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).table)); }
#line 2255 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 240: /* table_name  */
#line 145 "bison_parser.y" /* yacc.c:1258  */
      { free( (((*yyvaluep).table_name).name) ); free( (((*yyvaluep).table_name).schema) ); }
#line 2261 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 241: /* table_alias  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).alias_t)); }
#line 2267 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 242: /* opt_table_alias  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).alias_t)); }
#line 2273 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 243: /* alias  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).alias_t)); }
#line 2279 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 244: /* opt_alias  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).alias_t)); }
#line 2285 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 245: /* join_clause  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).table)); }
#line 2291 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 246: /* opt_join_type  */
#line 144 "bison_parser.y" /* yacc.c:1258  */
      { }
#line 2297 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 247: /* join_condition  */
#line 155 "bison_parser.y" /* yacc.c:1258  */
      { delete (((*yyvaluep).expr)); }
#line 2303 "bison_parser.cpp" /* yacc.c:1258  */
        break;

    case 249: /* ident_commalist  */
#line 147 "bison_parser.y" /* yacc.c:1258  */
      {
	if ((((*yyvaluep).str_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).str_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).str_vec));
}
#line 2316 "bison_parser.cpp" /* yacc.c:1258  */
        break;


      default:
        break;
    }
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
#line 76 "bison_parser.y" /* yacc.c:1430  */
{
	// Initialize
	yylloc.first_column = 0;
	yylloc.last_column = 0;
	yylloc.first_line = 0;
	yylloc.last_line = 0;
	yylloc.total_column = 0;
	yylloc.string_length = 0;
}

#line 2435 "bison_parser.cpp" /* yacc.c:1430  */
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
#line 255 "bison_parser.y" /* yacc.c:1648  */
    {
			for (SQLStatement* stmt : *(yyvsp[-1].stmt_vec)) {
				// Transfers ownership of the statement.
				//result->addStatement(stmt);
			}

			unsigned param_id = 0;
			for (void* param : yyloc.param_list) {
				if (param != nullptr) {
					Expr* expr = (Expr*) param;
					expr->ival = param_id;
					//result->addParameter(expr);
					++param_id;
				}
			}
			delete (yyvsp[-1].stmt_vec);
		}
#line 2641 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 3:
#line 276 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyvsp[0].statement)->stringLength = yylloc.string_length;
			yylloc.string_length = 0;
			(yyval.stmt_vec) = new std::vector<SQLStatement*>();
			(yyval.stmt_vec)->push_back((yyvsp[0].statement));
		}
#line 2652 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 4:
#line 282 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyvsp[0].statement)->stringLength = yylloc.string_length;
			yylloc.string_length = 0;
			(yyvsp[-2].stmt_vec)->push_back((yyvsp[0].statement));
			(yyval.stmt_vec) = (yyvsp[-2].stmt_vec);
		}
#line 2663 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 5:
#line 291 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.statement) = (yyvsp[-1].prep_stmt);
			(yyval.statement)->hints = (yyvsp[0].expr_vec);
		}
#line 2672 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 6:
#line 295 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.statement) = (yyvsp[-1].statement);
			(yyval.statement)->hints = (yyvsp[0].expr_vec);
		}
#line 2681 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 7:
#line 299 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.statement) = (yyvsp[0].show_stmt);
		}
#line 2689 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 8:
#line 306 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.statement) = (yyvsp[0].select_stmt); }
#line 2695 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 9:
#line 307 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.statement) = (yyvsp[0].import_stmt); }
#line 2701 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 10:
#line 308 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.statement) = (yyvsp[0].create_stmt); }
#line 2707 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 11:
#line 309 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.statement) = (yyvsp[0].insert_stmt); }
#line 2713 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 12:
#line 310 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 2719 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 13:
#line 311 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 2725 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 14:
#line 312 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.statement) = (yyvsp[0].update_stmt); }
#line 2731 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 15:
#line 313 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.statement) = (yyvsp[0].drop_stmt); }
#line 2737 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 16:
#line 314 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.statement) = (yyvsp[0].exec_stmt); }
#line 2743 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 17:
#line 323 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr_vec) = (yyvsp[-1].expr_vec); }
#line 2749 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 18:
#line 324 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr_vec) = nullptr; }
#line 2755 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 19:
#line 329 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 2761 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 20:
#line 330 "bison_parser.y" /* yacc.c:1648  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 2767 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 21:
#line 334 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.expr) = Expr::make(kExprHint);
			(yyval.expr)->name = (yyvsp[0].sval);
		}
#line 2776 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 22:
#line 338 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.expr) = Expr::make(kExprHint);
			(yyval.expr)->name = (yyvsp[-3].sval);
			(yyval.expr)->exprList = (yyvsp[-1].expr_vec);
		}
#line 2786 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 23:
#line 350 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.prep_stmt) = new PrepareStatement();
			(yyval.prep_stmt)->name = (yyvsp[-2].sval);
			(yyval.prep_stmt)->query = (yyvsp[0].sval);
		}
#line 2796 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 25:
#line 360 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.exec_stmt) = new ExecuteStatement();
			(yyval.exec_stmt)->name = (yyvsp[0].sval);
		}
#line 2805 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 26:
#line 364 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.exec_stmt) = new ExecuteStatement();
			(yyval.exec_stmt)->name = (yyvsp[-3].sval);
			(yyval.exec_stmt)->parameters = (yyvsp[-1].expr_vec);
		}
#line 2815 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 27:
#line 376 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.import_stmt) = new ImportStatement((ImportType) (yyvsp[-4].uval));
			(yyval.import_stmt)->filePath = (yyvsp[-2].sval);
			(yyval.import_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.import_stmt)->tableName = (yyvsp[0].table_name).name;
		}
#line 2826 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 28:
#line 385 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = kImportCSV; }
#line 2832 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 29:
#line 389 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.sval) = strdup((yyvsp[0].expr)->name); delete (yyvsp[0].expr); }
#line 2838 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 30:
#line 399 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.show_stmt) = new ShowStatement(kShowTables);
		}
#line 2846 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 31:
#line 402 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.show_stmt) = new ShowStatement(kShowColumns);
			(yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.show_stmt)->name = (yyvsp[0].table_name).name;
		}
#line 2856 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 32:
#line 416 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.create_stmt) = new CreateStatement(kCreateTableFromTbl);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-5].bval);
			(yyval.create_stmt)->schema = (yyvsp[-4].table_name).schema;
			(yyval.create_stmt)->tableName = (yyvsp[-4].table_name).name;
			(yyval.create_stmt)->filePath = (yyvsp[0].sval);
		}
#line 2868 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 33:
#line 423 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.create_stmt) = new CreateStatement(kCreateTable);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
			(yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
			(yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
			(yyval.create_stmt)->columns = (yyvsp[-1].column_vec);
		}
#line 2880 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 34:
#line 430 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.create_stmt) = new CreateStatement(kCreateView);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
			(yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
			(yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
			(yyval.create_stmt)->viewColumns = (yyvsp[-2].str_vec);
			(yyval.create_stmt)->select = (yyvsp[0].select_stmt);
		}
#line 2893 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 35:
#line 441 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.bval) = true; }
#line 2899 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 36:
#line 442 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.bval) = false; }
#line 2905 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 37:
#line 446 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.column_vec) = new std::vector<ColumnDefinition*>(); (yyval.column_vec)->push_back((yyvsp[0].column_t)); }
#line 2911 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 38:
#line 447 "bison_parser.y" /* yacc.c:1648  */
    { (yyvsp[-2].column_vec)->push_back((yyvsp[0].column_t)); (yyval.column_vec) = (yyvsp[-2].column_vec); }
#line 2917 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 39:
#line 451 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.column_t) = new ColumnDefinition((yyvsp[-1].sval), (ColumnDefinition::DataType) (yyvsp[0].uval));
		}
#line 2925 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 40:
#line 458 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = ColumnDefinition::INT; }
#line 2931 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 41:
#line 459 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = ColumnDefinition::INT; }
#line 2937 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 42:
#line 460 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = ColumnDefinition::DOUBLE; }
#line 2943 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 43:
#line 461 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = ColumnDefinition::TEXT; }
#line 2949 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 44:
#line 471 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.drop_stmt) = new DropStatement(kDropTable);
			(yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
			(yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
		}
#line 2960 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 45:
#line 477 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.drop_stmt) = new DropStatement(kDropView);
			(yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
			(yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
		}
#line 2971 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 46:
#line 483 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.drop_stmt) = new DropStatement(kDropPreparedStatement);
			(yyval.drop_stmt)->ifExists = false;
			(yyval.drop_stmt)->name = (yyvsp[0].sval);
		}
#line 2981 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 47:
#line 491 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.bval) = true; }
#line 2987 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 48:
#line 492 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.bval) = false; }
#line 2993 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 49:
#line 501 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.delete_stmt) = new DeleteStatement();
			(yyval.delete_stmt)->schema = (yyvsp[-1].table_name).schema;
			(yyval.delete_stmt)->tableName = (yyvsp[-1].table_name).name;
			(yyval.delete_stmt)->expr = (yyvsp[0].expr);
		}
#line 3004 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 50:
#line 510 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.delete_stmt) = new DeleteStatement();
			(yyval.delete_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.delete_stmt)->tableName = (yyvsp[0].table_name).name;
		}
#line 3014 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 51:
#line 523 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.insert_stmt) = new InsertStatement(kInsertValues);
			(yyval.insert_stmt)->schema = (yyvsp[-5].table_name).schema;
			(yyval.insert_stmt)->tableName = (yyvsp[-5].table_name).name;
			(yyval.insert_stmt)->columns = (yyvsp[-4].str_vec);
			(yyval.insert_stmt)->values = (yyvsp[-1].expr_vec);
		}
#line 3026 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 52:
#line 530 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.insert_stmt) = new InsertStatement(kInsertSelect);
			(yyval.insert_stmt)->schema = (yyvsp[-2].table_name).schema;
			(yyval.insert_stmt)->tableName = (yyvsp[-2].table_name).name;
			(yyval.insert_stmt)->columns = (yyvsp[-1].str_vec);
			(yyval.insert_stmt)->select = (yyvsp[0].select_stmt);
		}
#line 3038 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 53:
#line 541 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.str_vec) = (yyvsp[-1].str_vec); }
#line 3044 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 54:
#line 542 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.str_vec) = nullptr; }
#line 3050 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 55:
#line 552 "bison_parser.y" /* yacc.c:1648  */
    {
		(yyval.update_stmt) = new UpdateStatement();
		(yyval.update_stmt)->table = (yyvsp[-3].table);
		(yyval.update_stmt)->updates = (yyvsp[-1].update_vec);
		(yyval.update_stmt)->where = (yyvsp[0].expr);
	}
#line 3061 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 56:
#line 561 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.update_vec) = new std::vector<UpdateClause*>(); (yyval.update_vec)->push_back((yyvsp[0].update_t)); }
#line 3067 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 57:
#line 562 "bison_parser.y" /* yacc.c:1648  */
    { (yyvsp[-2].update_vec)->push_back((yyvsp[0].update_t)); (yyval.update_vec) = (yyvsp[-2].update_vec); }
#line 3073 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 58:
#line 566 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.update_t) = new UpdateClause();
			(yyval.update_t)->column = (yyvsp[-2].sval);
			(yyval.update_t)->value = (yyvsp[0].expr);
		}
#line 3083 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 61:
#line 580 "bison_parser.y" /* yacc.c:1648  */
    {
			// TODO: allow multiple unions (through linked list)
			// TODO: capture type of set_operator
			// TODO: might overwrite order and limit of first select here
			(yyval.select_stmt) = (yyvsp[-4].select_stmt);
			(yyval.select_stmt)->unionSelect = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order_vec);

			// Limit could have been set by TOP.
			if ((yyvsp[0].limit) != nullptr) {
				delete (yyval.select_stmt)->limit;
				(yyval.select_stmt)->limit = (yyvsp[0].limit);
			}
		}
#line 3102 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 62:
#line 597 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 3108 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 63:
#line 598 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 3114 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 66:
#line 607 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.select_stmt) = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order_vec);

			// Limit could have been set by TOP.
			if ((yyvsp[0].limit) != nullptr) {
				delete (yyval.select_stmt)->limit;
				(yyval.select_stmt)->limit = (yyvsp[0].limit);
			}
		}
#line 3129 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 67:
#line 617 "bison_parser.y" /* yacc.c:1648  */
    {
			// TODO: allow multiple unions (through linked list)
			// TODO: capture type of set_operator
			// TODO: might overwrite order and limit of first select here
			(yyval.select_stmt) = (yyvsp[-4].select_stmt);
			(yyval.select_stmt)->unionSelect = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order_vec);

			// Limit could have been set by TOP.
			if ((yyvsp[0].limit) != nullptr) {
				delete (yyval.select_stmt)->limit;
				(yyval.select_stmt)->limit = (yyvsp[0].limit);
			}
		}
#line 3148 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 74:
#line 649 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.select_stmt) = new SelectStatement();
			(yyval.select_stmt)->limit = (yyvsp[-5].limit);
			(yyval.select_stmt)->selectDistinct = (yyvsp[-4].bval);
			(yyval.select_stmt)->selectList = (yyvsp[-3].expr_vec);
			(yyval.select_stmt)->fromTable = (yyvsp[-2].table);
			(yyval.select_stmt)->whereClause = (yyvsp[-1].expr);
			(yyval.select_stmt)->groupBy = (yyvsp[0].group_t);

			parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_FOR);
			parser->pushStack(parser->ast()->createNodeVariable(TRI_CHAR_LENGTH_PAIR("ROW"), true));

			arangodb::aql::AstNode* variableNode = static_cast<arangodb::aql::AstNode*>(parser->popStack());
            TRI_ASSERT(variableNode != nullptr);
            arangodb::aql::Variable* variable = static_cast<arangodb::aql::Variable*>(variableNode->getData());

            arangodb::aql::AstNode* node = nullptr;

            arangodb::aql::AstNode* options = nullptr;
            node = parser->ast()->createNodeFor(variable, (yyvsp[-2].table)->node, options);

            parser->ast()->addOperation(node);

            // Handle the return part of the AQL AST.
		}
#line 3178 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 75:
#line 677 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.bval) = true; }
#line 3184 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 76:
#line 678 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.bval) = false; }
#line 3190 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 78:
#line 686 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.table) = (yyvsp[0].table); }
#line 3196 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 79:
#line 687 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.table) = nullptr; }
#line 3202 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 80:
#line 690 "bison_parser.y" /* yacc.c:1648  */
    {
		     (yyval.table) = (yyvsp[0].table);
		     auto ast = parser->ast();
		     arangodb::aql::AstNode* node = nullptr;
		     auto variable = ast->scopes()->getVariable(TRI_CHAR_LENGTH_PAIR((yyval.table)->getName()), true);
		     if (variable == nullptr) {
		        if (ast->scopes()->canUseCurrentVariable() && strcmp((yyval.table)->getName(), "CURRENT") == 0) {
                    variable = ast->scopes()->getCurrentVariable();
                }
                else if (strcmp((yyval.table)->getName(), arangodb::aql::Variable::NAME_CURRENT) == 0) {
                    variable = ast->scopes()->getCurrentVariable();
                }
		     } // if (variable == nullptr)

             if (variable != nullptr) {
                // variable alias exists, now use it
                node = ast->createNodeReference(variable);
             }
             if (node == nullptr) {
                // variable not found. so it must have been a collection or view
                auto const& resolver = parser->query()->resolver();
                node = ast->createNodeDataSource(resolver, TRI_CHAR_LENGTH_PAIR((yyval.table)->getName()),
                              arangodb::AccessMode::Type::READ, true, false);
             }
             TRI_ASSERT(node != nullptr);
             (yyval.table)->node = node;
		     std::cout << "-----> SQL::from_clause::FROM table_ref::$$ = " << (yyval.table) << std::endl;
        }
#line 3235 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 81:
#line 722 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 3241 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 82:
#line 723 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = nullptr; }
#line 3247 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 83:
#line 727 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.group_t) = new GroupByDescription();
			(yyval.group_t)->columns = (yyvsp[-1].expr_vec);
			(yyval.group_t)->having = (yyvsp[0].expr);
		}
#line 3257 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 84:
#line 732 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.group_t) = nullptr; }
#line 3263 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 85:
#line 736 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 3269 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 86:
#line 737 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = nullptr; }
#line 3275 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 87:
#line 740 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.order_vec) = (yyvsp[0].order_vec); }
#line 3281 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 88:
#line 741 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.order_vec) = nullptr; }
#line 3287 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 89:
#line 745 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.order_vec) = new std::vector<OrderDescription*>(); (yyval.order_vec)->push_back((yyvsp[0].order)); }
#line 3293 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 90:
#line 746 "bison_parser.y" /* yacc.c:1648  */
    { (yyvsp[-2].order_vec)->push_back((yyvsp[0].order)); (yyval.order_vec) = (yyvsp[-2].order_vec); }
#line 3299 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 91:
#line 750 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.order) = new OrderDescription((yyvsp[0].order_type), (yyvsp[-1].expr)); }
#line 3305 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 92:
#line 754 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.order_type) = kOrderAsc; }
#line 3311 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 93:
#line 755 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.order_type) = kOrderDesc; }
#line 3317 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 94:
#line 756 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.order_type) = kOrderAsc; }
#line 3323 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 95:
#line 762 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.limit) = new LimitDescription((yyvsp[0].expr)->ival, kNoOffset); delete (yyvsp[0].expr); }
#line 3329 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 96:
#line 763 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.limit) = nullptr; }
#line 3335 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 97:
#line 767 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.limit) = new LimitDescription((yyvsp[0].expr)->ival, kNoOffset); delete (yyvsp[0].expr); }
#line 3341 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 98:
#line 768 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.limit) = new LimitDescription((yyvsp[-2].expr)->ival, (yyvsp[0].expr)->ival); delete (yyvsp[-2].expr); delete (yyvsp[0].expr); }
#line 3347 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 99:
#line 769 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.limit) = new LimitDescription(kNoLimit, (yyvsp[0].expr)->ival); delete (yyvsp[0].expr); }
#line 3353 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 100:
#line 770 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.limit) = nullptr; }
#line 3359 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 101:
#line 771 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.limit) = nullptr;  }
#line 3365 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 102:
#line 772 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.limit) = new LimitDescription(kNoLimit, (yyvsp[0].expr)->ival); delete (yyvsp[0].expr); }
#line 3371 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 103:
#line 773 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.limit) = new LimitDescription(kNoLimit, (yyvsp[0].expr)->ival); delete (yyvsp[0].expr); }
#line 3377 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 104:
#line 774 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.limit) = nullptr; }
#line 3383 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 105:
#line 781 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 3389 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 106:
#line 782 "bison_parser.y" /* yacc.c:1648  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 3395 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 107:
#line 786 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 3401 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 108:
#line 787 "bison_parser.y" /* yacc.c:1648  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 3407 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 109:
#line 791 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.expr) = (yyvsp[-1].expr);
			if ((yyvsp[0].alias_t)) {
				(yyval.expr)->alias = strdup((yyvsp[0].alias_t)->name);
				delete (yyvsp[0].alias_t);
			}
		}
#line 3419 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 115:
#line 809 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 3425 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 124:
#line 818 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeSelect((yyvsp[-1].select_stmt)); }
#line 3431 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 125:
#line 822 "bison_parser.y" /* yacc.c:1648  */
    {
		    (yyval.expr) = (yyvsp[0].expr);
		    (yyval.expr)->node = static_cast<arangodb::aql::AstNode*>(parser->popStack());
		}
#line 3440 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 127:
#line 830 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpUnary(kOpUnaryMinus, (yyvsp[0].expr)); }
#line 3446 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 128:
#line 831 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, (yyvsp[0].expr)); }
#line 3452 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 129:
#line 832 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-1].expr)); }
#line 3458 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 130:
#line 833 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-2].expr)); }
#line 3464 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 131:
#line 834 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeOpUnary(kOpIsNull, (yyvsp[-3].expr))); }
#line 3470 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 133:
#line 839 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpMinus, (yyvsp[0].expr)); }
#line 3476 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 134:
#line 840 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPlus, (yyvsp[0].expr)); }
#line 3482 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 135:
#line 841 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpSlash, (yyvsp[0].expr)); }
#line 3488 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 136:
#line 842 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAsterisk, (yyvsp[0].expr)); }
#line 3494 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 137:
#line 843 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPercentage, (yyvsp[0].expr)); }
#line 3500 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 138:
#line 844 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpCaret, (yyvsp[0].expr)); }
#line 3506 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 139:
#line 845 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLike, (yyvsp[0].expr)); }
#line 3512 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 140:
#line 846 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-3].expr), kOpNotLike, (yyvsp[0].expr)); }
#line 3518 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 141:
#line 847 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpILike, (yyvsp[0].expr)); }
#line 3524 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 142:
#line 848 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpConcat, (yyvsp[0].expr)); }
#line 3530 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 143:
#line 852 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAnd, (yyvsp[0].expr)); }
#line 3536 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 144:
#line 853 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpOr, (yyvsp[0].expr)); }
#line 3542 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 145:
#line 857 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].expr_vec)); }
#line 3548 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 146:
#line 858 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].expr_vec))); }
#line 3554 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 147:
#line 859 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].select_stmt)); }
#line 3560 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 148:
#line 860 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].select_stmt))); }
#line 3566 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 149:
#line 866 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeCase((yyvsp[-2].expr), (yyvsp[-1].expr), nullptr); }
#line 3572 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 150:
#line 867 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeCase((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 3578 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 151:
#line 868 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-1].expr), nullptr); }
#line 3584 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 152:
#line 869 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 3590 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 153:
#line 873 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeCaseList(Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 3596 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 154:
#line 874 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::caseListAppend((yyvsp[-4].expr), Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 3602 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 155:
#line 878 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeExists((yyvsp[-1].select_stmt)); }
#line 3608 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 156:
#line 879 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeExists((yyvsp[-1].select_stmt))); }
#line 3614 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 157:
#line 883 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 3620 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 158:
#line 884 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 3626 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 159:
#line 885 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpNotEquals, (yyvsp[0].expr)); }
#line 3632 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 160:
#line 886 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLess, (yyvsp[0].expr)); }
#line 3638 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 161:
#line 887 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreater, (yyvsp[0].expr)); }
#line 3644 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 162:
#line 888 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLessEq, (yyvsp[0].expr)); }
#line 3650 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 163:
#line 889 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreaterEq, (yyvsp[0].expr)); }
#line 3656 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 164:
#line 893 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-2].sval), new std::vector<Expr*>(), false); }
#line 3662 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 165:
#line 894 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-4].sval), (yyvsp[-1].expr_vec), (yyvsp[-2].bval)); }
#line 3668 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 166:
#line 898 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeExtract((yyvsp[-3].datetime_field), (yyvsp[-1].expr)); }
#line 3674 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 167:
#line 902 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.datetime_field) = kDatetimeSecond; }
#line 3680 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 168:
#line 903 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.datetime_field) = kDatetimeMinute; }
#line 3686 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 169:
#line 904 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.datetime_field) = kDatetimeHour; }
#line 3692 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 170:
#line 905 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.datetime_field) = kDatetimeDay; }
#line 3698 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 171:
#line 906 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.datetime_field) = kDatetimeMonth; }
#line 3704 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 172:
#line 907 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.datetime_field) = kDatetimeYear; }
#line 3710 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 173:
#line 910 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeArray((yyvsp[-1].expr_vec)); }
#line 3716 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 174:
#line 914 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeArrayIndex((yyvsp[-3].expr), (yyvsp[-1].expr)->ival); }
#line 3722 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 175:
#line 918 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeBetween((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3728 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 176:
#line 922 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeColumnRef((yyvsp[0].sval)); }
#line 3734 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 177:
#line 923 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeColumnRef((yyvsp[-2].sval), (yyvsp[0].sval)); }
#line 3740 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 178:
#line 924 "bison_parser.y" /* yacc.c:1648  */
    {
	    std::cout << "SQL::column_name::*" << std::endl;
	    (yyval.expr) = Expr::makeStar();


	    auto node = parser->ast()->createNodeObject();
        parser->pushStack(node);

        auto ast = parser->ast();
        auto variable = ast->scopes()->getVariable(TRI_CHAR_LENGTH_PAIR("ROW"), true);
        if (variable != nullptr) {
            // create a reference to the variable
            auto node = ast->createNodeReference(variable);
            parser->pushObjectElement(TRI_CHAR_LENGTH_PAIR("ROW"), node);
        }
	 }
#line 3761 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 179:
#line 940 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeStar((yyvsp[-2].sval)); }
#line 3767 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 184:
#line 951 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].sval)); }
#line 3773 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 185:
#line 956 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].fval)); }
#line 3779 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 187:
#line 961 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].ival)); }
#line 3785 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 188:
#line 965 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.expr) = Expr::makeNullLiteral(); }
#line 3791 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 189:
#line 969 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.expr) = Expr::makeParameter(yylloc.total_column);
			(yyval.expr)->ival2 = yyloc.param_list.size();
			yyloc.param_list.push_back((yyval.expr));
		}
#line 3801 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 191:
#line 982 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
			auto tbl = new TableRef(kTableCrossProduct);
			tbl->list = (yyvsp[-2].table_vec);
			(yyval.table) = tbl;
		}
#line 3812 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 195:
#line 998 "bison_parser.y" /* yacc.c:1648  */
    {
			auto tbl = new TableRef(kTableSelect);
			tbl->select = (yyvsp[-2].select_stmt);
			tbl->alias = (yyvsp[0].alias_t);
			(yyval.table) = tbl;
		}
#line 3823 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 196:
#line 1007 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.table_vec) = new std::vector<TableRef*>(); (yyval.table_vec)->push_back((yyvsp[0].table)); }
#line 3829 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 197:
#line 1008 "bison_parser.y" /* yacc.c:1648  */
    { (yyvsp[-2].table_vec)->push_back((yyvsp[0].table)); (yyval.table_vec) = (yyvsp[-2].table_vec); }
#line 3835 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 198:
#line 1013 "bison_parser.y" /* yacc.c:1648  */
    {
			auto tbl = new TableRef(kTableName);
			tbl->schema = (yyvsp[-1].table_name).schema;
			tbl->name = (yyvsp[-1].table_name).name;
			tbl->alias = (yyvsp[0].alias_t);
			(yyval.table) = tbl;
		}
#line 3847 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 199:
#line 1024 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.table) = new TableRef(kTableName);
			(yyval.table)->schema = (yyvsp[0].table_name).schema;
			(yyval.table)->name = (yyvsp[0].table_name).name;
		}
#line 3857 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 200:
#line 1033 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.table_name).schema = nullptr; (yyval.table_name).name = (yyvsp[0].sval);}
#line 3863 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 201:
#line 1034 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.table_name).schema = (yyvsp[-2].sval); (yyval.table_name).name = (yyvsp[0].sval); }
#line 3869 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 203:
#line 1040 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.alias_t) = new Alias((yyvsp[-3].sval), (yyvsp[-1].str_vec)); }
#line 3875 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 205:
#line 1046 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.alias_t) = nullptr; }
#line 3881 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 206:
#line 1050 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 3887 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 207:
#line 1051 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 3893 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 209:
#line 1057 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.alias_t) = nullptr; }
#line 3899 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 210:
#line 1066 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.table) = new TableRef(kTableJoin);
			(yyval.table)->join = new JoinDefinition();
			(yyval.table)->join->type = kJoinNatural;
			(yyval.table)->join->left = (yyvsp[-3].table);
			(yyval.table)->join->right = (yyvsp[0].table);
		}
#line 3911 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 211:
#line 1074 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.table) = new TableRef(kTableJoin);
			(yyval.table)->join = new JoinDefinition();
			(yyval.table)->join->type = (JoinType) (yyvsp[-4].uval);
			(yyval.table)->join->left = (yyvsp[-5].table);
			(yyval.table)->join->right = (yyvsp[-2].table);
			(yyval.table)->join->condition = (yyvsp[0].expr);
		}
#line 3924 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 212:
#line 1084 "bison_parser.y" /* yacc.c:1648  */
    {
			(yyval.table) = new TableRef(kTableJoin);
			(yyval.table)->join = new JoinDefinition();
			(yyval.table)->join->type = (JoinType) (yyvsp[-6].uval);
			(yyval.table)->join->left = (yyvsp[-7].table);
			(yyval.table)->join->right = (yyvsp[-4].table);
			auto left_col = Expr::makeColumnRef(strdup((yyvsp[-1].expr)->name));
			if ((yyvsp[-1].expr)->alias != nullptr) left_col->alias = strdup((yyvsp[-1].expr)->alias);
			if ((yyvsp[-7].table)->getName() != nullptr) left_col->table = strdup((yyvsp[-7].table)->getName());
			auto right_col = Expr::makeColumnRef(strdup((yyvsp[-1].expr)->name));
			if ((yyvsp[-1].expr)->alias != nullptr) right_col->alias = strdup((yyvsp[-1].expr)->alias);
			if ((yyvsp[-4].table)->getName() != nullptr) right_col->table = strdup((yyvsp[-4].table)->getName());
			(yyval.table)->join->condition = Expr::makeOpBinary(left_col, kOpEquals, right_col);
			delete (yyvsp[-1].expr);
		}
#line 3944 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 213:
#line 1102 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = kJoinInner; }
#line 3950 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 214:
#line 1103 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = kJoinLeft; }
#line 3956 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 215:
#line 1104 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = kJoinLeft; }
#line 3962 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 216:
#line 1105 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = kJoinRight; }
#line 3968 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 217:
#line 1106 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = kJoinRight; }
#line 3974 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 218:
#line 1107 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = kJoinFull; }
#line 3980 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 219:
#line 1108 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = kJoinFull; }
#line 3986 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 220:
#line 1109 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = kJoinFull; }
#line 3992 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 221:
#line 1110 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = kJoinCross; }
#line 3998 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 222:
#line 1111 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.uval) = kJoinInner; }
#line 4004 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 226:
#line 1131 "bison_parser.y" /* yacc.c:1648  */
    { (yyval.str_vec) = new std::vector<char*>(); (yyval.str_vec)->push_back((yyvsp[0].sval)); }
#line 4010 "bison_parser.cpp" /* yacc.c:1648  */
    break;

  case 227:
#line 1132 "bison_parser.y" /* yacc.c:1648  */
    { (yyvsp[-2].str_vec)->push_back((yyvsp[0].sval)); (yyval.str_vec) = (yyvsp[-2].str_vec); }
#line 4016 "bison_parser.cpp" /* yacc.c:1648  */
    break;


#line 4020 "bison_parser.cpp" /* yacc.c:1648  */
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
#line 1135 "bison_parser.y" /* yacc.c:1907  */

/*********************************
 ** Section 4: Additional C code
 *********************************/

/* empty */
