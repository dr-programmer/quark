%{
#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

extern int yylex();
extern char *yytext;
void yyerror(char *s);
extern const int line;

float parserResult;
%}

%token TOKEN_INT
%token TOKEN_FLOAT
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

expr: expr TOKEN_PLUS term              { $$ = $1 + $3; }
    | expr TOKEN_MINUS term             { $$ = $1 - $3; }
    | term                              { $$ = $1; }
    ;

term: term TOKEN_MUL factor             { $$ = $1 * $3; }
    | term TOKEN_DIV factor             { $$ = $1 / $3; }
    | factor                            { $$ = $1; }
    ;

factor: TOKEN_MINUS factor              { $$ = -$2; }
      | TOKEN_LPAREN expr TOKEN_RPAREN  { $$ = $2; }
      | TOKEN_INT                       { $$ = atoi(yytext); }
      | TOKEN_FLOAT                     { $$ = atof(yytext); }
      ;
%%

void yyerror(char *s) {
    fprintf(stderr, RED "Error" RESET \
        MAG" |%s|"RESET"->"YEL"|%s|"RESET" on line %d \n", s, yytext, line);
}