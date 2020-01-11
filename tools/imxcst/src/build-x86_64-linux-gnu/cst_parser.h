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

#ifndef YY_YY_BUILD_X86_64_LINUX_GNU_CST_PARSER_H_INCLUDED
# define YY_YY_BUILD_X86_64_LINUX_GNU_CST_PARSER_H_INCLUDED
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
    NUMBER = 258,
    WORD = 259,
    FILENAME = 260,
    EQUALS = 261,
    OR = 262,
    EOL = 263,
    LBRACK = 264,
    RBRACK = 265,
    COMMA = 266,
    DOT = 267,
    exp = 268
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define WORD 259
#define FILENAME 260
#define EQUALS 261
#define OR 262
#define EOL 263
#define LBRACK 264
#define RBRACK 265
#define COMMA 266
#define DOT 267
#define exp 268

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "cst_parser.y" /* yacc.c:1909  */

    char *str;
    uint32_t  num;
    command_t *command;
    argument_t *argument;
    value_t value;
    pair_t *pair;
    block_t *block;
    number_t *number;
    keyword_t *keyword;

#line 92 "build-x86_64-linux-gnu/cst_parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BUILD_X86_64_LINUX_GNU_CST_PARSER_H_INCLUDED  */
