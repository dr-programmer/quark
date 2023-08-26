%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
%type <expr> expr expr_list next_expr term factor starting_expr
%type <expr> assignment_algebra algebra logical_algebra comparison_algebra
%type <type> type
%type <params> parameters parameter list_of_parameters

%type <name> name string_literal
%type <integer> allocation_size boolean_literal char_literal

%token TOKEN_PRINT_IN
%token TOKEN_STDIN

%token TOKEN_ALLOCATE
%token TOKEN_SUBSCRIPT
%token TOKEN_UP

%token TOKEN_AND
%token TOKEN_OR
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

%token TOKEN_TRUE
%token TOKEN_FALSE
%token TOKEN_CHAR_LITERAL

%token TOKEN_INTEGER_LITERAL
%token TOKEN_FLOATING_POINT_LITERAL
%token TOKEN_IDENT
%token TOKEN_STRING_LITERAL

%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_MUL
%token TOKEN_DIV
%token TOKEN_MODULUS

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
                struct type *temp = type_create(TYPE_ARRAY, $3, 0, $6);
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
                { $$ = stmt_create(STMT_BLOCK, 0, 0, 0, 0, $2, 0, 0); }
        | decl  { $$ = stmt_create(STMT_DECL, $1, 0, 0, 0, 0, 0, 0); }
        | expr TOKEN_SEMI
                { $$ = stmt_create(STMT_EXPR, 0, 0, $1, 0, 0, 0, 0); }
        | TOKEN_GIVE expr TOKEN_SEMI
                { $$ = stmt_create(STMT_GIVE, 0, 0, $2, 0, 0, 0, 0); }
        | TOKEN_GIVE TOKEN_UP TOKEN_SEMI
                { $$ = stmt_create(STMT_GIVE, 0, 0, 0, 0, 0, 0, 0); }
        | TOKEN_GIVE expr TOKEN_PRINT_IN TOKEN_STDIN TOKEN_SEMI
                { 
                        $$ = stmt_create(STMT_GIVE, 0, 0, $2, 0, 0, 0, 0); 
                        $$->print = 1; 
                }
        ;

stmt_list
        : stmt stmt_list        { $$ = $1; $1->next = $2; }
        |                       { $$ = 0; }
        ;

term    : term TOKEN_MUL factor { $$ = expr_create(EXPR_MUL, $1, $3); }
        | term TOKEN_DIV factor { $$ = expr_create(EXPR_DIV, $1, $3); }
        | term TOKEN_MODULUS factor
                                { $$ = expr_create(EXPR_MODULUS, $1, $3); }
        | factor                { $$ = $1; }
        ;

assignment_algebra
        : name TOKEN_ASSIGN algebra
                                { $$ = expr_create(EXPR_ASSIGN, expr_create_name($1), $3); }
        | name TOKEN_ADD_WITH algebra
                                { $$ = expr_create(EXPR_ADD_WITH, expr_create_name($1), $3); }
        | name TOKEN_SUB_WITH algebra
                                { $$ = expr_create(EXPR_SUB_WITH, expr_create_name($1), $3); }
        | name TOKEN_MUL_WITH algebra
                                { $$ = expr_create(EXPR_MUL_WITH, expr_create_name($1), $3); }
        | name TOKEN_DIV_WITH algebra
                                { $$ = expr_create(EXPR_DIV_WITH, expr_create_name($1), $3); }
        | name TOKEN_INCREMENT  { $$ = expr_create(EXPR_INCREMENT, expr_create_name($1), 0); }
        | name TOKEN_DECREMENT  { $$ = expr_create(EXPR_DECREMENT, expr_create_name($1), 0); }
        | TOKEN_INCREMENT name  { $$ = expr_create(EXPR_INCREMENT, 0, expr_create_name($2)); }
        | TOKEN_DECREMENT name  { $$ = expr_create(EXPR_DECREMENT, 0, expr_create_name($2)); }
        ;

algebra : algebra TOKEN_PLUS term       { $$ = expr_create(EXPR_ADD, $1, $3); }
        | algebra TOKEN_MINUS term      { $$ = expr_create(EXPR_SUB, $1, $3); }
        | comparison_algebra            { $$ = $1; }
        | term                          { $$ = $1; }
        ;

starting_expr
        : assignment_algebra    { $$ = $1; }
        | logical_algebra       { $$ = $1; }
        | name TOKEN_ASSIGN assignment_algebra
                                { $$ = expr_create(EXPR_ASSIGN, expr_create_name($1), $3); }
        ;

factor  : name                  { $$ = expr_create_name($1); }
        | TOKEN_INTEGER_LITERAL { $$ = expr_create_integer_literal(atoi(yytext)); }
        | TOKEN_FLOATING_POINT_LITERAL
                                { $$ = expr_create_floating_point_literal(atof(yytext)); }
        | string_literal        { $$ = expr_create_string_literal($1); }
        | boolean_literal       { $$ = expr_create_boolean_literal($1); }
        | char_literal          { $$ = expr_create_char_literal($1); }
        | TOKEN_MINUS factor
                { $$ = expr_create(EXPR_MUL, expr_create_integer_literal(-1), $2); }
        | TOKEN_NOT factor      { $$ = expr_create(EXPR_NOT, $2, 0); }
        | name TOKEN_LPAREN expr_list TOKEN_RPAREN
                                { $$ = expr_create(EXPR_CALL, expr_create_name($1), $3); }
        | name TOKEN_SUBSCRIPT factor
                                { $$ = expr_create(EXPR_SUBSCRIPT, expr_create_name($1), $3); }
        | TOKEN_LPAREN expr TOKEN_RPAREN
                                { $$ = $2; }
        ;

comparison_algebra
        : algebra TOKEN_EQUAL term         { $$ = expr_create(EXPR_EQUAL, $1, $3); }
        | algebra TOKEN_NOT_EQUAL term     { $$ = expr_create(EXPR_NOT_EQUAL, $1, $3); }
        | algebra TOKEN_LESS term          { $$ = expr_create(EXPR_LESS, $1, $3); }
        | algebra TOKEN_GREATER term       { $$ = expr_create(EXPR_GREATER, $1, $3); }
        | algebra TOKEN_LESS_EQUAL term    { $$ = expr_create(EXPR_LESS_EQUAL, $1, $3); }
        | algebra TOKEN_GREATER_EQUAL term { $$ = expr_create(EXPR_GREATER_EQUAL, $1, $3); }
        ;

logical_algebra
        : expr TOKEN_AND algebra   { $$ = expr_create(EXPR_AND, $1, $3); }
        | expr TOKEN_OR algebra    { $$ = expr_create(EXPR_OR, $1, $3); }
        ;

expr    : starting_expr         { $$ = $1; }
        | algebra               { $$ = $1; }
        ;

expr_list
        : expr next_expr        { $$ = expr_create(EXPR_ARG, $1, $2); }
        |                       { $$ = 0; }
        ;

next_expr
        : TOKEN_COMMA expr_list { $$ = $2; }
        |                       { $$ = 0; }
        ;

name    : TOKEN_IDENT   {
                                char *temp = (char *)malloc(strlen(yytext)*sizeof(char));
                                strcpy(temp, yytext);
                                $$ = temp; 
                        }
        ;

string_literal
        : TOKEN_STRING_LITERAL  { 
                                char *temp = (char *)malloc(strlen(yytext)*sizeof(char));
                                strcpy(temp, yytext);
                                $$ = temp; 
                                }
        ;

boolean_literal
        : TOKEN_TRUE            { $$ = 1; }
        | TOKEN_FALSE           { $$ = 0; }
        ;

char_literal
        : TOKEN_CHAR_LITERAL    {
                                char *temp = (char *)malloc(sizeof(char));
                                *temp = yytext[1];
                                $$ = *temp;
                                }
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