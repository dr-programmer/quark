#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "colors.h"
#include "expr.h"

extern FILE *yyin;
extern int yyparse();
extern struct expr * parserResult;
extern float expr_evaluate(struct expr *e);
extern void expr_print(struct expr *e);
extern void free_ast(struct expr *e);

int main(int argc, char **argv)
{
    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    if(yyparse() == 0){
        printf("Parse "GRN"successful"RESET"! Result = %.2f \n", expr_evaluate(parserResult));
        printf("^~~->From expression: "BLU);
        expr_print(parserResult);
        printf(RESET);
        free_ast(parserResult);
    }
    else {
        printf("Parse "RED"failed"RESET". \n");
    }

    return 0;
}