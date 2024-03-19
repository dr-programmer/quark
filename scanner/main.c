#include <stdio.h>
#include <stdlib.h>
#include "token.h"

extern FILE *yyin;
extern int yylex();
extern char *yytext;
extern const int line;

typedef struct {
    TokenT tokenType;
    char *literal;
    int line;
} Token;

int main(int argc, char **argv)
{
    if(argv[1] == "help") {
        //Future development
    }
    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    while(1) {
        TokenT tokenT = yylex();
        if(tokenT == TOKEN_EOF)break;
        Token token = {.tokenType = tokenT, .literal = yytext, .line = line};
        if(token.tokenType == TOKEN_ERROR)printf("Error on line %d with token |%s|. \n", \
                                                    token.line, token.literal);
        else printf("Token Type: %d, text: %s \n", tokenT, yytext);
    }

    return 0;
}