#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "colors.h"

extern FILE *yyin;
extern int yyparse();
extern const float parserResult;

int main(int argc, char **argv)
{
    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    if(yyparse() == 0){
        printf("Parse "GRN"successful"RESET"! Result = %.2f \n", parserResult);
    }
    else {
        printf("Parse "RED"failed"RESET". \n");
    }

    return 0;
}