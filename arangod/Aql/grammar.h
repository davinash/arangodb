/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_AQL_AQL_GRAMMAR_HPP_INCLUDED
# define YY_AQL_AQL_GRAMMAR_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int Aqldebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_END = 0,
    T_FOR = 258,
    T_LET = 259,
    T_FILTER = 260,
    T_RETURN = 261,
    T_COLLECT = 262,
    T_SORT = 263,
    T_LIMIT = 264,
    FLOATVAL = 265,
    INTVAL = 266,
    T_ASC = 267,
    T_DESC = 268,
    T_IN = 269,
    T_WITH = 270,
    T_INTO = 271,
    T_AGGREGATE = 272,
    T_GRAPH = 273,
    T_SHORTEST_PATH = 274,
    T_DISTINCT = 275,
    T_REMOVE = 276,
    T_INSERT = 277,
    T_UPDATE = 278,
    T_REPLACE = 279,
    T_UPSERT = 280,
    T_NULL = 281,
    T_TRUE = 282,
    T_FALSE = 283,
    T_STRING = 284,
    T_QUOTED_STRING = 285,
    T_INTEGER = 286,
    T_DOUBLE = 287,
    T_PARAMETER = 288,
    T_DATA_SOURCE_PARAMETER = 289,
    T_ASSIGN = 290,
    T_NOT = 291,
    T_AND = 292,
    T_OR = 293,
    T_NIN = 294,
    T_REGEX_MATCH = 295,
    T_REGEX_NON_MATCH = 296,
    T_EQ = 297,
    T_NE = 298,
    T_LT = 299,
    T_GT = 300,
    T_LE = 301,
    T_GE = 302,
    T_LIKE = 303,
    T_PLUS = 304,
    T_MINUS = 305,
    T_TIMES = 306,
    T_DIV = 307,
    T_MOD = 308,
    T_QUESTION = 309,
    T_COLON = 310,
    T_SCOPE = 311,
    T_RANGE = 312,
    T_COMMA = 313,
    T_OPEN = 314,
    T_CLOSE = 315,
    T_OBJECT_OPEN = 316,
    T_OBJECT_CLOSE = 317,
    T_ARRAY_OPEN = 318,
    T_ARRAY_CLOSE = 319,
    T_OUTBOUND = 320,
    T_INBOUND = 321,
    T_ANY = 322,
    T_ALL = 323,
    T_NONE = 324,
    DEALLOCATE = 325,
    PARAMETERS = 326,
    INTERSECT = 327,
    TEMPORARY = 328,
    TIMESTAMP = 329,
    DISTINCT = 330,
    NVARCHAR = 331,
    RESTRICT = 332,
    TRUNCATE = 333,
    ANALYZE = 334,
    BETWEEN = 335,
    CASCADE = 336,
    COLUMNS = 337,
    CONTROL = 338,
    DEFAULT = 339,
    EXECUTE = 340,
    EXPLAIN = 341,
    HISTORY = 342,
    INTEGER = 343,
    NATURAL = 344,
    PREPARE = 345,
    PRIMARY = 346,
    SCHEMAS = 347,
    SPATIAL = 348,
    VIRTUAL = 349,
    BEFORE = 350,
    COLUMN = 351,
    CREATE = 352,
    DELETE = 353,
    DIRECT = 354,
    DOUBLE = 355,
    ESCAPE = 356,
    EXCEPT = 357,
    EXISTS = 358,
    EXTRACT = 359,
    GLOBAL = 360,
    HAVING = 361,
    IMPORT = 362,
    INSERT = 363,
    ISNULL = 364,
    OFFSET = 365,
    RENAME = 366,
    SCHEMA = 367,
    SELECT = 368,
    SORTED = 369,
    TABLES = 370,
    UNIQUE = 371,
    UNLOAD = 372,
    UPDATE = 373,
    VALUES = 374,
    AFTER = 375,
    ALTER = 376,
    CROSS = 377,
    DELTA = 378,
    GROUP = 379,
    INDEX = 380,
    INNER = 381,
    LIMIT = 382,
    LOCAL = 383,
    MERGE = 384,
    MINUS = 385,
    ORDER = 386,
    OUTER = 387,
    RIGHT = 388,
    TABLE = 389,
    UNION = 390,
    USING = 391,
    WHERE = 392,
    CALL = 393,
    CASE = 394,
    DATE = 395,
    DESC = 396,
    DROP = 397,
    ELSE = 398,
    FILE = 399,
    FROM = 400,
    FULL = 401,
    HASH = 402,
    HINT = 403,
    INTO = 404,
    JOIN = 405,
    LEFT = 406,
    LIKE = 407,
    LOAD = 408,
    NULL = 409,
    PLAN = 410,
    SHOW = 411,
    TEXT = 412,
    THEN = 413,
    TIME = 414,
    VIEW = 415,
    WHEN = 416,
    WITH = 417,
    ADD = 418,
    ALL = 419,
    AND = 420,
    ASC = 421,
    CSV = 422,
    END = 423,
    FOR = 424,
    INT = 425,
    KEY = 426,
    NOT = 427,
    OFF = 428,
    SET = 429,
    TBL = 430,
    TOP = 431,
    AS = 432,
    BY = 433,
    IF = 434,
    IN = 435,
    IS = 436,
    OF = 437,
    ON = 438,
    OR = 439,
    TO = 440,
    ARRAY = 441,
    CONCAT = 442,
    ILIKE = 443,
    SECOND = 444,
    MINUTE = 445,
    HOUR = 446,
    DAY = 447,
    MONTH = 448,
    YEAR = 449,
    UMINUS = 450,
    UPLUS = 451,
    FUNCCALL = 452,
    REFERENCE = 453,
    INDEXED = 454,
    EXPANSION = 455,
    EQUALS = 456,
    NOTEQUALS = 457,
    LESS = 458,
    GREATER = 459,
    LESSEQ = 460,
    GREATEREQ = 461,
    IDENTIFIER = 462,
    STRING = 463
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 34 "Aql/grammar.y" /* yacc.c:1909  */

  arangodb::aql::AstNode*  node;
  struct {
    char*                  value;
    size_t                 length;
  }                        strval;
  bool                     boolval;
  int64_t                  intval;

#line 274 "Aql/grammar.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int Aqlparse (arangodb::aql::Parser* parser);

#endif /* !YY_AQL_AQL_GRAMMAR_HPP_INCLUDED  */
