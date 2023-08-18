/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TOKEN_H_INCLUDED
# define YY_YY_TOKEN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_PRINT_IN = 258,          /* TOKEN_PRINT_IN  */
    TOKEN_STDIN = 259,             /* TOKEN_STDIN  */
    TOKEN_ALLOCATE = 260,          /* TOKEN_ALLOCATE  */
    TOKEN_SUBSCRIPT = 261,         /* TOKEN_SUBSCRIPT  */
    TOKEN_UP = 262,                /* TOKEN_UP  */
    TOKEN_AND = 263,               /* TOKEN_AND  */
    TOKEN_OR = 264,                /* TOKEN_OR  */
    TOKEN_NOT = 265,               /* TOKEN_NOT  */
    TOKEN_UNKNOWN = 266,           /* TOKEN_UNKNOWN  */
    TOKEN_GIVE = 267,              /* TOKEN_GIVE  */
    TOKEN_IF = 268,                /* TOKEN_IF  */
    TOKEN_ELSE = 269,              /* TOKEN_ELSE  */
    TOKEN_WHILE = 270,             /* TOKEN_WHILE  */
    TOKEN_FOR = 271,               /* TOKEN_FOR  */
    TOKEN_DO = 272,                /* TOKEN_DO  */
    TOKEN_CHAR = 273,              /* TOKEN_CHAR  */
    TOKEN_INT = 274,               /* TOKEN_INT  */
    TOKEN_FLOAT = 275,             /* TOKEN_FLOAT  */
    TOKEN_BOOL = 276,              /* TOKEN_BOOL  */
    TOKEN_VOID = 277,              /* TOKEN_VOID  */
    TOKEN_TRUE = 278,              /* TOKEN_TRUE  */
    TOKEN_FALSE = 279,             /* TOKEN_FALSE  */
    TOKEN_CHAR_LITERAL = 280,      /* TOKEN_CHAR_LITERAL  */
    TOKEN_INTEGER_LITERAL = 281,   /* TOKEN_INTEGER_LITERAL  */
    TOKEN_FLOATING_POINT_LITERAL = 282, /* TOKEN_FLOATING_POINT_LITERAL  */
    TOKEN_IDENT = 283,             /* TOKEN_IDENT  */
    TOKEN_STRING_LITERAL = 284,    /* TOKEN_STRING_LITERAL  */
    TOKEN_PLUS = 285,              /* TOKEN_PLUS  */
    TOKEN_MINUS = 286,             /* TOKEN_MINUS  */
    TOKEN_MUL = 287,               /* TOKEN_MUL  */
    TOKEN_DIV = 288,               /* TOKEN_DIV  */
    TOKEN_MODULUS = 289,           /* TOKEN_MODULUS  */
    TOKEN_ASSIGN = 290,            /* TOKEN_ASSIGN  */
    TOKEN_EQUAL = 291,             /* TOKEN_EQUAL  */
    TOKEN_NOT_EQUAL = 292,         /* TOKEN_NOT_EQUAL  */
    TOKEN_GREATER = 293,           /* TOKEN_GREATER  */
    TOKEN_GREATER_EQUAL = 294,     /* TOKEN_GREATER_EQUAL  */
    TOKEN_LESS = 295,              /* TOKEN_LESS  */
    TOKEN_LESS_EQUAL = 296,        /* TOKEN_LESS_EQUAL  */
    TOKEN_INCREMENT = 297,         /* TOKEN_INCREMENT  */
    TOKEN_DECREMENT = 298,         /* TOKEN_DECREMENT  */
    TOKEN_ADD_WITH = 299,          /* TOKEN_ADD_WITH  */
    TOKEN_SUB_WITH = 300,          /* TOKEN_SUB_WITH  */
    TOKEN_MUL_WITH = 301,          /* TOKEN_MUL_WITH  */
    TOKEN_DIV_WITH = 302,          /* TOKEN_DIV_WITH  */
    TOKEN_LPAREN = 303,            /* TOKEN_LPAREN  */
    TOKEN_RPAREN = 304,            /* TOKEN_RPAREN  */
    TOKEN_LCRBR = 305,             /* TOKEN_LCRBR  */
    TOKEN_RCRBR = 306,             /* TOKEN_RCRBR  */
    TOKEN_LSQBR = 307,             /* TOKEN_LSQBR  */
    TOKEN_RSQBR = 308,             /* TOKEN_RSQBR  */
    TOKEN_COMMA = 309,             /* TOKEN_COMMA  */
    TOKEN_COLON = 310,             /* TOKEN_COLON  */
    TOKEN_SEMI = 311,              /* TOKEN_SEMI  */
    TOKEN_ERROR = 312              /* TOKEN_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

    struct decl *decl;
    struct stmt *stmt;
    struct expr *expr;
    struct type *type;
    struct param_list *params;
    char *name;
    int integer;

#line 131 "token.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TOKEN_H_INCLUDED  */
