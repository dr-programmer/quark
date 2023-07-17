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
    TOKEN_ALLOCATE = 258,          /* TOKEN_ALLOCATE  */
    TOKEN_NOT = 259,               /* TOKEN_NOT  */
    TOKEN_UNKNOWN = 260,           /* TOKEN_UNKNOWN  */
    TOKEN_GIVE = 261,              /* TOKEN_GIVE  */
    TOKEN_CHAR = 262,              /* TOKEN_CHAR  */
    TOKEN_INT = 263,               /* TOKEN_INT  */
    TOKEN_FLOAT = 264,             /* TOKEN_FLOAT  */
    TOKEN_BOOL = 265,              /* TOKEN_BOOL  */
    TOKEN_VOID = 266,              /* TOKEN_VOID  */
    TOKEN_INTEGER_LITERAL = 267,   /* TOKEN_INTEGER_LITERAL  */
    TOKEN_FLOATING_POINT_LITERAL = 268, /* TOKEN_FLOATING_POINT_LITERAL  */
    TOKEN_IDENT = 269,             /* TOKEN_IDENT  */
    TOKEN_STRING_LITERAL = 270,    /* TOKEN_STRING_LITERAL  */
    TOKEN_PLUS = 271,              /* TOKEN_PLUS  */
    TOKEN_MINUS = 272,             /* TOKEN_MINUS  */
    TOKEN_MUL = 273,               /* TOKEN_MUL  */
    TOKEN_DIV = 274,               /* TOKEN_DIV  */
    TOKEN_ASSIGN = 275,            /* TOKEN_ASSIGN  */
    TOKEN_EQUAL = 276,             /* TOKEN_EQUAL  */
    TOKEN_NOT_EQUAL = 277,         /* TOKEN_NOT_EQUAL  */
    TOKEN_GREATER = 278,           /* TOKEN_GREATER  */
    TOKEN_GREATER_EQUAL = 279,     /* TOKEN_GREATER_EQUAL  */
    TOKEN_LESS = 280,              /* TOKEN_LESS  */
    TOKEN_LESS_EQUAL = 281,        /* TOKEN_LESS_EQUAL  */
    TOKEN_INCREMENT = 282,         /* TOKEN_INCREMENT  */
    TOKEN_DECREMENT = 283,         /* TOKEN_DECREMENT  */
    TOKEN_ADD_WITH = 284,          /* TOKEN_ADD_WITH  */
    TOKEN_SUB_WITH = 285,          /* TOKEN_SUB_WITH  */
    TOKEN_MUL_WITH = 286,          /* TOKEN_MUL_WITH  */
    TOKEN_DIV_WITH = 287,          /* TOKEN_DIV_WITH  */
    TOKEN_LPAREN = 288,            /* TOKEN_LPAREN  */
    TOKEN_RPAREN = 289,            /* TOKEN_RPAREN  */
    TOKEN_LCRBR = 290,             /* TOKEN_LCRBR  */
    TOKEN_RCRBR = 291,             /* TOKEN_RCRBR  */
    TOKEN_LSQBR = 292,             /* TOKEN_LSQBR  */
    TOKEN_RSQBR = 293,             /* TOKEN_RSQBR  */
    TOKEN_COMMA = 294,             /* TOKEN_COMMA  */
    TOKEN_COLON = 295,             /* TOKEN_COLON  */
    TOKEN_SEMI = 296,              /* TOKEN_SEMI  */
    TOKEN_ERROR = 297              /* TOKEN_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

    struct decl *decl;
    struct stmt *stmt;
    struct expr *expr;
    struct type *type;
    struct param_list *params;
    char *name;
    int integer;

#line 116 "token.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TOKEN_H_INCLUDED  */
