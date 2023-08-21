#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "error.h"
#include "colors.h"
#include "scope.h"
#include "LLVM/codegen.h"

extern FILE *yyin;
extern int yyparse();
extern struct decl *parser_result;
extern Stack symbol_table;

FILE *result_file;

unsigned short debug;

int main(int argc, char **argv)
{
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("Cannot open file \n");
        exit(ERROR_OPENING_FILE);
    }
    char *name_of_file = "a.s";
    for(unsigned int i = 0; i < argc; i++) {
        if(!strcmp(argv[i], "--debug")) {
            debug = 1;
        }
        else if(!strcmp(argv[i], "-o")) {
            name_of_file = argv[i+1];
        }
    }
    printf("Name of result file = "CYN"%s"RESET" \n", name_of_file);
    char *temp_file = (char *)calloc(strlen(name_of_file) + 3, sizeof(char));
    strcpy(temp_file, name_of_file);
    if(debug) strcat(temp_file, ".s");
    else strcat(temp_file, ".ll");
    result_file = fopen(temp_file, "w");
    if(yyparse() == 0) {
        printf("Parse "GRN"successful"RESET"! \n");
        decl_print(parser_result, 0);

        symbol_table = initStack();
        scope_enter();
        decl_resolve(parser_result);
        scope_exit();
        decl_typecheck(parser_result);
        if(!error_count) {
            if(debug) {
                decl_codegen(parser_result);
            }
            else {
                decl_irgen(parser_result);
            }
        }
        printf("Program compiled with %d error/s \n", error_count);
    }
    else {
        printf("Parse "RED"failed"RESET". \n");
    }

    fclose(result_file);
    fclose(yyin);

    if(debug) {
        char *temp_string = (char *)calloc(strlen(temp_file) + strlen(name_of_file) + 20, 
                                sizeof(char));
        sprintf(temp_string, "gcc %s -o %s -no-pie", temp_file, name_of_file);
        system(temp_string);
    }
    else {

    }
    free(temp_file);

    return 0;
}