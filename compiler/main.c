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
unsigned short show_pcode;

#define BUFFER_SIZE 128

int main(int argc, char **argv)
{
    char *open_pipe = "llvm-config --host-target";
    FILE *pipe = popen(open_pipe, "r");
    char architecture[BUFFER_SIZE] = {0};
    if(pipe == NULL) {
        printf("Cannot open pipe!\n");
        exit(ERROR_OPENING_FILE);
    }
    fgets(architecture, BUFFER_SIZE, pipe);
    char *new_row_target = strchr(architecture, '\n');
    *new_row_target = '\0';
    pclose(pipe);
    char *name_of_file = "a.out";
    for(unsigned int i = 0; i < argc; i++) {
        if(!strcmp(argv[i], "--debug")) {
            debug = 1;
        }
        else if(!strcmp(argv[i], "-o")) {
            name_of_file = argv[i+1];
        }
        else if(!strcmp(argv[i], "--show-offset")) {
            show_stack_offset = 1;
        }
        else if(!strcmp(argv[i], "--show-pcode")) {
            show_pcode = 1;
        }
        else if(!strcmp(argv[i], "--help")) {
            char help_text[300];
            FILE *help_file = fopen("quark_help.txt", "r");
            while(fgets(help_text, 300, help_file)) {
                printf("%s", help_text);
            }
            fclose(help_file);
            exit(0);
        }
    }
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("Cannot open file \n");
        exit(ERROR_OPENING_FILE);
    }
    printf("Name of result file = "CYN"%s"RESET" \n", name_of_file);
    char *temp_file = (char *)calloc(strlen(name_of_file) + 3, sizeof(char));
    strcpy(temp_file, name_of_file);
    if(debug) strcat(temp_file, ".s");
    else strcat(temp_file, ".ll");
    if(yyparse() == 0) {
        printf("Parse "GRN"successful"RESET"! \n");
        if(show_pcode) decl_print(parser_result, 0);

        symbol_table = initStack();
        scope_enter();
        decl_resolve(parser_result);
        scope_exit();
        decl_typecheck(parser_result);
        if(!error_count) {
            result_file = fopen(temp_file, "w");
            if(debug) {
                decl_codegen(parser_result);
            }
            else {
                fprintf(result_file, "target triple = \"%s\"\n", architecture);
                fprintf(result_file, "declare i32 @printf (ptr, ...)\n");
                decl_irgen(parser_result);
            }
            fclose(result_file);
        }
        printf("Program compiled with %d error/s \n", error_count);
    }
    else {
        printf("Parse "RED"failed"RESET". \n");
    }

    fclose(yyin);

    if(!error_count) {
        char *temp_string = (char *)calloc(strlen(temp_file) + strlen(name_of_file) + 20, 
                                sizeof(char));
        if(debug) {
            sprintf(temp_string, "gcc %s -o %s -no-pie", temp_file, name_of_file);
            system(temp_string);
        }
        else {
            sprintf(temp_string, "clang %s -O2 -o %s", 
                        temp_file, name_of_file);
            system(temp_string);
        }
    }
    free(temp_file);

    return 0;
}