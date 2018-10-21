cmake_minimum_required(VERSION 3.11)
project(sql-parser)

set(CMAKE_CXX_STANDARD 14)

include_directories(benchmark)
include_directories(src)
include_directories(src/parser)
include_directories(src/sql)
include_directories(src/util)
include_directories(test)
include_directories(test/thirdparty)
include_directories(test/thirdparty/microtest)

add_library(sql-parser
        STATIC
        src/parser/bison_parser.cpp
        src/parser/bison_parser.h
        src/parser/flex_lexer.cpp
        src/parser/flex_lexer.h
        src/parser/parser_typedef.h
        src/sql/CreateStatement.h
        src/sql/DeleteStatement.h
        src/sql/DropStatement.h
        src/sql/ExecuteStatement.h
        src/sql/Expr.cpp
        src/sql/Expr.h
        src/sql/ImportStatement.h
        src/sql/InsertStatement.h
        src/sql/PrepareStatement.cpp
        src/sql/PrepareStatement.h
        src/sql/SelectStatement.h
        src/sql/ShowStatement.h
        src/sql/SQLStatement.cpp
        src/sql/SQLStatement.h
        src/sql/statements.cpp
        src/sql/statements.h
        src/sql/Table.h
        src/sql/UpdateStatement.h
        src/util/sqlhelper.cpp
        src/util/sqlhelper.h
        src/SQLParser.cpp
        src/SQLParser.h
        src/SQLParserResult.cpp
        src/SQLParserResult.h
        src/aql/SQLStatementToAQL.cpp
        src/aql/SQLStatementToAQL.h
        src/aql/AQLSelectStatement.cpp
        src/aql/AQLSelectStatement.h)

