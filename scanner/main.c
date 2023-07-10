#include <stdio.h>
#include <stdlib.h>
#include "token.h"

extern FILE *yyin;
extern int yylex();
extern char *yytext;

int main(int argc, char **argv)
{
    if(argv[1] == "help") {

    }
    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    while(1) {
        Token token = yylex();
        if(token == TOKEN_EOF)break;
        printf("Token: %d, text: %s \n", token, yytext);
    }

    return 0;
}