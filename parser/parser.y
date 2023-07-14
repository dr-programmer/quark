%{
#include <stdio.h>

extern int yylex();
extern char *yytext;

void yyerror(char *s);
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

%%

void yyerror(char *s) {
    fprintf(stderr, RED "Error" RESET \
        MAG" |%s|"RESET"->"YEL"|%s|"RESET" on line %d \n", s, yytext, line);
}