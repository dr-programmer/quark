%{
#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "expr.h"

#define YYSTYPE struct expr *

struct expr *parserResult;

extern int yylex();
extern char *yytext;
void yyerror(char *s);
extern const int line;
extern struct expr * expr_create(expr_t kind, 
                            struct expr *left, 
                            struct expr *right);
extern struct expr * expr_create_value(float value);
extern struct expr * expr_create_ident(char *ident);
extern char * currentIdent;
%}

%token TOKEN_NUMBER
%token TOKEN_IDENT
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_MUL
%token TOKEN_DIV
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_SEMI
%token TOKEN_ERROR

%%
program: expr TOKEN_SEMI               { parserResult = $1; };

expr: expr TOKEN_PLUS term              { $$ = expr_create(EXPR_ADD, $1, $3); }
    | expr TOKEN_MINUS term             { $$ = expr_create(EXPR_SUBTRACT, $1, $3); }
    | term                              { $$ = $1; }
    ;

term: term TOKEN_MUL factor             { $$ = expr_create(EXPR_MULTIPLY, $1, $3); }
    | term TOKEN_DIV factor             { $$ = expr_create(EXPR_DIVIDE, $1, $3); }
    | factor                            { $$ = $1; }
    ;

factor: TOKEN_MINUS factor              
        { $$ = expr_create(EXPR_SUBTRACT, expr_create_value(0), $2); }
      | TOKEN_LPAREN expr TOKEN_RPAREN      { $$ = $2; }
      | TOKEN_NUMBER                        { $$ = expr_create_value(atof(yytext)); }
      | TOKEN_IDENT TOKEN_LPAREN expr TOKEN_RPAREN  
        { $$ = expr_create(EXPR_FUNC, expr_create_ident(currentIdent), $3); }
      ;
%%

void yyerror(char *s) {
    fprintf(stderr, RED "Error" RESET \
        MAG" |%s|"RESET"->"YEL"|%s|"RESET" on line %d \n", s, yytext, line);
}