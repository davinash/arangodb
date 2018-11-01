%{
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

%}
/*********************************
 ** Section 2: Bison Parser Declarations
 *********************************/


// Specify code that is included in the generated .h and .c files
%code requires {
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
}

// Define the names of the created files (defined in Makefile)
// %output  "bison_parser.cpp"
// %defines "bison_parser.h"

// Tell bison to create a reentrant parser
%define api.pure full

// Prefix the parser
%define api.prefix {hsql_}
%define api.token.prefix {SQL_}

%define parse.error verbose
%locations

%initial-action {
	// Initialize
	@$.first_column = 0;
	@$.last_column = 0;
	@$.first_line = 0;
	@$.last_line = 0;
	@$.total_column = 0;
	@$.string_length = 0;
};


// Define additional parameters for yylex (http://www.gnu.org/software/bison/manual/html_node/Pure-Calling.html)
%lex-param   { yyscan_t scanner }

// Define additional parameters for yyparse
%parse-param { hsql::SQLParser* parser }
%parse-param { yyscan_t scanner }

%union {
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
}

/*********************************
 ** Token Definition
 *********************************/
%token <ival> INTVAL
%token <sval> IDENTIFIER STRING
%token <fval> FLOATVAL

/* SQL Keywords */
%token DEALLOCATE PARAMETERS INTERSECT TEMPORARY TIMESTAMP
%token DISTINCT NVARCHAR RESTRICT TRUNCATE ANALYZE BETWEEN
%token CASCADE COLUMNS CONTROL DEFAULT EXECUTE EXPLAIN
%token HISTORY INTEGER NATURAL PREPARE PRIMARY SCHEMAS
%token SPATIAL VIRTUAL BEFORE COLUMN CREATE DELETE DIRECT
%token DOUBLE ESCAPE EXCEPT EXISTS EXTRACT GLOBAL HAVING IMPORT
%token INSERT ISNULL OFFSET RENAME SCHEMA SELECT SORTED
%token TABLES UNIQUE UNLOAD UPDATE VALUES AFTER ALTER CROSS
%token DELTA GROUP INDEX INNER LIMIT LOCAL MERGE MINUS ORDER
%token OUTER RIGHT TABLE UNION USING WHERE CALL CASE DATE
%token DESC DROP ELSE FILE FROM FULL HASH HINT INTO JOIN
%token LEFT LIKE LOAD NULL PLAN SHOW TEXT THEN TIME
%token VIEW WHEN WITH ADD ALL AND ASC CSV END FOR INT KEY
%token NOT OFF SET TBL TOP AS BY IF IN IS OF ON OR TO
%token ARRAY CONCAT ILIKE SECOND MINUTE HOUR DAY MONTH YEAR

/******************************
 ** Token Precedence and Associativity
 ** Precedence: lowest to highest
 ******************************/
%left		OR
%left		AND
%right		NOT
%nonassoc	'=' EQUALS NOTEQUALS LIKE ILIKE
%nonassoc	'<' '>' LESS GREATER LESSEQ GREATEREQ

%nonassoc	NOTNULL
%nonassoc	ISNULL
%nonassoc	IS				/* sets precedence for IS NULL, etc */
%left		'+' '-'
%left		'*' '/' '%'
%left		'^'
%left		CONCAT

/* Unary Operators */
%right  UMINUS
%left		'[' ']'
%left		'(' ')'
%left		'.'
%left   JOIN

%%
/*********************************
 ** Section 3: Grammar Definition
 *********************************/

// Defines our general input.
input:
    statement_list opt_semicolon {
    }
    ;

statement_list:
    statement {
    }
	|
	statement_list ';' statement {
    }
	;

statement:
    preparable_statement {
    }
	;

preparable_statement:
	select_statement {
	}
    ;

select_statement:
    select_with_paren
	|
	select_no_paren
	|
	select_with_paren set_operator select_paren_or_clause opt_order opt_limit {
    }
	;

select_with_paren:
    '(' select_no_paren ')' {
    }
	|
	'(' select_with_paren ')' {
	}
	;

select_no_paren:
    select_clause opt_order opt_limit {
    }
	|	select_clause set_operator select_paren_or_clause opt_order opt_limit {
	}
	;

select_clause:
    SELECT opt_top opt_distinct select_list opt_from_clause opt_where opt_group {
    }
	;

select_paren_or_clause:
		select_with_paren
	|	select_clause
	;

set_operator:
		set_type opt_all
	;

set_type:
		UNION
	|	INTERSECT
	|	EXCEPT
	;

opt_all:
		ALL
	|	/* empty */
	;

opt_group:
		GROUP BY expr_list opt_having {
		}
	|	/* empty */ {}
	;

opt_having:
		HAVING expr {}
	|	/* empty */ {}

opt_top:
	TOP int_literal {}
	|	/* empty */ {}
	;

opt_where:
		WHERE expr {}
	|	/* empty */ {}
	;

select_list:
		expr_list
	;

opt_from_clause:
        from_clause  {
        }
    |   /* empty */  {}

from_clause:
		FROM table_ref {
		}
	;

opt_limit:
    LIMIT int_literal {
    }

int_literal:
    INTVAL {
    }
	;

opt_order:
    ORDER BY order_list {
    }
	|
	/* empty */ {
	}
	;

order_list:
    order_desc {
    }
	|
	order_list ',' order_desc {
	}
	;

order_desc:
    expr opt_order_type {
    }
	;

opt_order_type:
    ASC {
    }
	|
	DESC {
	}
	|
	/* empty */ {
	}
	;

/******************************
 * Expressions
 ******************************/
expr_list:
    expr_alias {}
	|	expr_list ',' expr_alias {}
	;

expr_alias:
    expr opt_alias {
    }
	;

expr:
    operand
	|
	between_expr
	|
	logic_expr
	|
	exists_expr
	|
	in_expr
	;

operand:
    '(' expr ')' {
    }
	|
	array_index
	|
	scalar_expr
	|
	unary_expr
	|
	binary_expr
	|
	case_expr
	|
	function_expr
	|
	extract_expr
	|
	array_expr
	|
	'(' select_no_paren ')' {
	}
	;

scalar_expr:
    column_name
	|
	literal
	;

unary_expr:
    '-' operand {}
	|
	NOT operand {}
	|
	operand ISNULL {}
	|
	operand IS NULL {}
	|
	operand IS NOT NULL {}
	;

binary_expr:
    comp_expr
	|
	operand '-' operand	{
	}
	|
	operand '+' operand	{
	}
	|
	operand '/' operand	{
    }
	|
	operand '*' operand	{
    }
	|
	operand '%' operand	{
    }
	|
	operand '^' operand	{
    }
	|
	operand LIKE operand {
    }
	|
	operand NOT LIKE operand {
    }
	|
	operand ILIKE operand {
    }
	|
	operand CONCAT operand {
    }
	;

// CASE grammar based on: flex & bison by John Levine
// https://www.safaribooksonline.com/library/view/flex-bison/9780596805418/ch04.html#id352665
case_expr:
		CASE expr case_list END         	{}
	|	CASE expr case_list ELSE expr END	{}
	|	CASE case_list END			        {}
	|	CASE case_list ELSE expr END		{}
	;

array_expr:
	  	ARRAY '[' expr_list ']' {}
	;

extract_expr:
         EXTRACT '(' datetime_field FROM expr ')'    {}
    ;

datetime_field:
        SECOND {}
    |   MINUTE {}
    |   HOUR {}
    |   DAY {}
    |   MONTH {}
    |   YEAR {}

array_index:
	   	operand '[' int_literal ']' {}
	;

between_expr:
		operand BETWEEN operand AND operand {}
	;

case_list:
		WHEN expr THEN expr              {}
	|	case_list WHEN expr THEN expr    {}
	;

column_name:
	IDENTIFIER {}
	|	IDENTIFIER '.' IDENTIFIER {}
	|	'*' {}
	|	IDENTIFIER '.' '*' {}
	;
comp_expr:
	operand '=' operand			{}
	|	operand EQUALS operand			{}
	|	operand NOTEQUALS operand	{}
	|	operand '<' operand			{}
	|	operand '>' operand			{}
	|	operand LESSEQ operand		{}
	|	operand GREATEREQ operand	{}
	;

exists_expr:
    EXISTS '(' select_no_paren ')' {}
	|	NOT EXISTS '(' select_no_paren ')' {}
	;

function_expr:
               IDENTIFIER '(' ')' {}
       |       IDENTIFIER '(' opt_distinct expr_list ')' {}
       ;

in_expr:
		operand IN '(' expr_list ')'			{}
	|	operand NOT IN '(' expr_list ')'		{}
	|	operand IN '(' select_no_paren ')'		{}
	|	operand NOT IN '(' select_no_paren ')'	{}
	;

literal:
		string_literal
	|	num_literal
	|	null_literal
	|	param_expr
	;

logic_expr:
		expr AND expr	{}
	|	expr OR expr	{}
	;

null_literal:
    NULL {}
	;

num_literal:
		FLOATVAL {}
	|	int_literal
	;

string_literal:
		STRING {}
	;

alias:
		AS IDENTIFIER {}
	|	IDENTIFIER {}
	;

opt_alias:
		alias
	|	/* empty */ {}

opt_distinct:
		DISTINCT {}
	|	/* empty */ {}
	;

param_expr:
		'?' {
		}
	;

/******************************
 * Table
 ******************************/
table_ref:
		table_ref_atomic
	|	table_ref_commalist ',' table_ref_atomic {
		}
	;


table_ref_atomic:
		nonjoin_table_ref_atomic
	|	join_clause
	;

nonjoin_table_ref_atomic:
		table_ref_name
	|	'(' select_statement ')' opt_table_alias {
		}
	;

table_ref_commalist:
		table_ref_atomic { }
	|	table_ref_commalist ',' table_ref_atomic {}
	;


table_ref_name:
		table_name opt_table_alias {
		}
	;

table_name:
		IDENTIFIER                {
		}
	|	IDENTIFIER '.' IDENTIFIER {
	    }
	;

table_alias:
		alias
	|	AS IDENTIFIER '(' ident_commalist ')' {}
	;

opt_table_alias:
		table_alias
	|	/* empty */ {}

/******************************
 * Join Statements
 ******************************/

join_clause:
		table_ref_atomic NATURAL JOIN nonjoin_table_ref_atomic
		{
		}
	|	table_ref_atomic opt_join_type JOIN table_ref_atomic ON join_condition
		{
		}
	|
		table_ref_atomic opt_join_type JOIN table_ref_atomic USING '(' column_name ')'
		{
		}
	;

opt_join_type:
		INNER		{}
	|	LEFT OUTER	{}
	|	LEFT		{}
	|	RIGHT OUTER	{}
	|	RIGHT		{}
	|	FULL OUTER	{}
	|	OUTER		{}
	|	FULL		{}
	|	CROSS		{}
	|	/* empty, default */	{}
	;

join_condition:
		expr
		;


/******************************
 * Misc
 ******************************/

opt_semicolon:
		';'
	|	/* empty */
	;

ident_commalist:
		IDENTIFIER {}
	|	ident_commalist ',' IDENTIFIER {}
	;


%%