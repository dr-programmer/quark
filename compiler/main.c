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

FILE *result_file;

int main(int argc, char **argv)
{
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("Cannot open file \n");
        exit(ERROR_OPENING_FILE);
    }
    char *name_of_file = "a.s";
    if(argc > 3) {
        if(argv[2][0] == '-' && argv[2][1] == 'o') {
            name_of_file = argv[3];
        }
    }
    printf("Name of result file = "CYN"%s"RESET" \n", name_of_file);
    result_file = fopen(name_of_file, "w");
    if(yyparse() == 0) {
        printf("Parse "GRN"successful"RESET"! \n");
        decl_print(parser_result, 0);

        symbol_table = initStack();
        scope_enter();
        decl_resolve(parser_result);
        scope_exit();
        decl_typecheck(parser_result);
        if(!error_count) {
            decl_codegen(parser_result);
        }
        printf("Program compiled with %d error/s \n", error_count);
    }
    else {
        printf("Parse "RED"failed"RESET". \n");
    }

    fclose(result_file);
    fclose(yyin);

    return 0;
}