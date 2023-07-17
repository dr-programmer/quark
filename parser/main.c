#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "colors.h"

extern FILE *yyin;
extern int yyparse();

int main(int argc, char **argv)
{
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("Cannot open file \n");
        exit(ERROR_OPENING_FILE);
    }
    if(yyparse() == 0) {
        printf("Parse "GRN"successful"RESET"! \n");
    }
    else {
        printf("Parse "RED"failed"RESET". \n");
    }

    return 0;
}