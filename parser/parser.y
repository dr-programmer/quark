%{
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "colors.h"

extern int yylex();
extern char *yytext;
extern int line;

void yyerror(char *s);

struct decl *parser_result;
%}

%union {
    struct decl *decl;
    struct stmt *stmt;
    struct expr *expr;
    struct type *type;
    struct param_list *params;
    char *name;
    int integer;
};

%type <decl> program decl_list decl
%type <stmt> stmt_list stmt
%type <expr> expr expr_list next_expr term
%type <type> type
%type <params> parameters parameter list_of_parameters

%type <name> name string_literal
%type <integer> allocation_size

%token TOKEN_ALLOCATE

%token TOKEN_NOT
%token TOKEN_UNKNOWN

%token TOKEN_GIVE
%token TOKEN_IF
%token TOKEN_ELSE
%token TOKEN_WHILE
%token TOKEN_FOR
%token TOKEN_DO

%token TOKEN_CHAR
%token TOKEN_INT
%token TOKEN_FLOAT
%token TOKEN_BOOL
%token TOKEN_VOID

%token TOKEN_INTEGER_LITERAL
%token TOKEN_FLOATING_POINT_LITERAL
%token TOKEN_IDENT
%token TOKEN_STRING_LITERAL

%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_MUL
%token TOKEN_DIV

%token TOKEN_ASSIGN
%token TOKEN_EQUAL
%token TOKEN_NOT_EQUAL
%token TOKEN_GREATER
%token TOKEN_GREATER_EQUAL
%token TOKEN_LESS
%token TOKEN_LESS_EQUAL
%token TOKEN_INCREMENT
%token TOKEN_DECREMENT
%token TOKEN_ADD_WITH
%token TOKEN_SUB_WITH
%token TOKEN_MUL_WITH
%token TOKEN_DIV_WITH

%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_LCRBR
%token TOKEN_RCRBR
%token TOKEN_LSQBR
%token TOKEN_RSQBR

%token TOKEN_COMMA
%token TOKEN_COLON
%token TOKEN_SEMI

%token TOKEN_ERROR

%%

program : decl_list {parser_result = $1;}
        ;

decl    : name TOKEN_LSQBR type TOKEN_RSQBR TOKEN_SEMI
            { $$ = decl_create($1, $3, 0, 0, 0); }
        | name TOKEN_LSQBR type TOKEN_RSQBR TOKEN_ASSIGN expr TOKEN_SEMI
            { $$ = decl_create($1, $3, $6, 0, 0); }
        | name TOKEN_LSQBR type TOKEN_RSQBR TOKEN_ALLOCATE allocation_size TOKEN_SEMI
            {
                struct type *temp = type_create(TYPE_ARRAY, $3, 0, $6);
                $$ = decl_create($1, temp, 0, 0, 0); 
            }
        | name TOKEN_LSQBR type TOKEN_RSQBR TOKEN_ALLOCATE 
            allocation_size TOKEN_ASSIGN string_literal TOKEN_SEMI
            {
                struct type *temp = type_create(TYPE_STRING, $3, 0, $6);
                struct expr *e = expr_create_string_literal($8);
                $$ = decl_create($1, temp, e, 0, 0); 
            }
        | name TOKEN_LSQBR type TOKEN_RSQBR TOKEN_ALLOCATE allocation_size 
            TOKEN_ASSIGN TOKEN_LCRBR expr_list TOKEN_RCRBR TOKEN_SEMI
            {
                struct type *temp = type_create(TYPE_ARRAY, $3, 0, $6);
                $$ = decl_create($1, temp, $9, 0, 0); 
            }
        | name TOKEN_LSQBR type TOKEN_RSQBR TOKEN_LPAREN parameters TOKEN_RPAREN 
            TOKEN_LCRBR stmt_list TOKEN_RCRBR
            {
                struct type *temp = type_create(TYPE_FUNCTION, $3, $6, 0);
                $$ = decl_create($1, temp, 0, $9, 0); 
            }
        ;

decl_list
        : decl decl_list    { $$ = $1; $1->next = $2; }
        |                   { $$ = 0; }
        ;

stmt    : TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt
                { $$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, 0, 0); }
        | TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt TOKEN_ELSE stmt
                { $$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, $7, 0); }
        | TOKEN_FOR TOKEN_LPAREN expr_list TOKEN_SEMI expr TOKEN_SEMI 
                expr_list TOKEN_RPAREN stmt
                { $$ = stmt_create(STMT_FOR, 0, $3, $5, $7, $9, 0, 0); }
        | TOKEN_LCRBR stmt_list TOKEN_RCRBR
                { $$ = $2; }
        | decl  { $$ = stmt_create(STMT_DECL, $1, 0, 0, 0, 0, 0, 0); }
        | expr TOKEN_SEMI
                { $$ = stmt_create(STMT_EXPR, 0, 0, $1, 0, 0, 0, 0); }
        | TOKEN_GIVE expr TOKEN_SEMI
                { $$ = stmt_create(STMT_GIVE, 0, 0, $2, 0, 0, 0, 0); }
        ;

stmt_list
        : stmt stmt_list        { $$ = $1; $1->next = $2; }
        |                       { $$ = 0; }
        ;

term    : name                  { $$ = expr_create_name($1); }
        | TOKEN_INTEGER_LITERAL { $$ = expr_create_integer_literal(atoi(yytext)); }
        | TOKEN_FLOATING_POINT_LITERAL
                                { $$ = expr_create_floating_point_literal(atof(yytext)); }
        | TOKEN_NOT term        { $$ = expr_create(EXPR_NOT, $2, 0); }
        | TOKEN_LPAREN expr TOKEN_RPAREN
                                { $$ = $2; }
        ;

expr    : expr TOKEN_EQUAL term { $$ = expr_create(EXPR_EQUAL, $1, $3); }
        | name TOKEN_ASSIGN term
                                { $$ = expr_create(EXPR_ASSIGN, expr_create_name($1), $3); }
        | name TOKEN_LPAREN expr_list TOKEN_RPAREN
                                { $$ = expr_create(EXPR_CALL, expr_create_name($1), $3); }
        | term                  { $$ = $1; }
        ;

expr_list
        : expr next_expr        { $$ = expr_create(EXPR_ARG, $1, $2); }
        |                       { $$ = 0; }
        ;

next_expr
        : TOKEN_COMMA expr_list { $$ = $2; }
        |                       { $$ = 0; }
        ;

name    : TOKEN_IDENT   { $$ = yytext; }
        ;

string_literal
        : TOKEN_STRING_LITERAL { $$ = yytext; }
        ;

allocation_size
        : TOKEN_INTEGER_LITERAL { $$ = atoi(yytext); }
        | TOKEN_UNKNOWN         { $$ = 0; }
        ;

parameter
        : name TOKEN_LSQBR type TOKEN_RSQBR 
            { $$ = param_list_create($1, $3, 0); }
        ;

parameters
        : parameter list_of_parameters 
            { $$ = $1; $1->next = $2; }
        |   { $$ = 0; }
        ;

list_of_parameters
        : TOKEN_COMMA parameters    { $$ = $2; }
        |                           { $$ = 0; }
        ;

type    : TOKEN_INT     { $$ = type_create(TYPE_INTEGER, 0, 0, 0); }
        | TOKEN_CHAR    { $$ = type_create(TYPE_CHARACTER, 0, 0, 0); }
        | TOKEN_BOOL    { $$ = type_create(TYPE_BOOLEAN, 0, 0, 0); }
        | TOKEN_FLOAT   { $$ = type_create(TYPE_FLOATING_POINT, 0, 0, 0); }
        | TOKEN_VOID    { $$ = type_create(TYPE_VOID, 0, 0, 0); }
        ;

%%

void yyerror(char *s) {
    fprintf(stderr, RED "Error" RESET \
        MAG" |%s|"RESET"->"YEL"|%s|"RESET" on line %d \n", s, yytext, line);
}