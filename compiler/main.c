#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "error.h"
#include "colors.h"
#include "scope.h"

extern FILE *yyin;
extern int yyparse();
extern struct decl *parser_result;
extern Stack symbol_table;

int main(int argc, char **argv)
{
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("Cannot open file \n");
        exit(ERROR_OPENING_FILE);
    }
    if(yyparse() == 0) {
        printf("Parse "GRN"successful"RESET"! \n");
        decl_print(parser_result, 0);

        symbol_table = initStack();
        scope_enter();
        decl_resolve(parser_result);
        scope_exit();
        decl_typecheck(parser_result);
        printf("Program compiled with %d error/s \n", error_count);
    }
    else {
        printf("Parse "RED"failed"RESET". \n");
    }

    return 0;
}