#include <stdio.h>
#include <string.h>

#include "codegen.h"

unsigned int r_count = 0;

unsigned int register_create() {
    return r_count++;
}
const char *register_name(unsigned int r) {
    unsigned int size = 1;
    char *name = (char *)calloc(2, sizeof(char));
    name[0] = '%';

    unsigned int i = 1, temp = r;
    while(temp > 9) {
        temp /= 10;
        i *= 10;
    }
    while(i) {
        size++;
        name = (char *)realloc(name, size * sizeof(char));
        name[size-1] = '0' + (r / i);
        r %= i;
        i /= 10;
    }
    return name;
}

const char *symbol_irgen(struct symbol *s) {
    char *name = (char *)calloc(strlen(s->name) + 1, sizeof(char));

    if(s->kind == SYMBOL_GLOBAL) name[0] = '@';
    else name[0] = '%';

    strcat(name, s->name);
    return name;
}

const char *type_irgen(struct type *t) {
    char *name = NULL;

    switch(t->kind) {
        case TYPE_BOOLEAN:
            name = (char *)calloc(3, sizeof(char));
            strcpy(name, "i1");
            break;
        case TYPE_CHARACTER:
            name = (char *)calloc(3, sizeof(char));
            strcpy(name, "i8");
            break;
        case TYPE_INTEGER:
            name = (char *)calloc(4, sizeof(char));
            strcpy(name, "i32");
            break;
        case TYPE_FLOATING_POINT:
            name = (char *)calloc(6, sizeof(char));
            strcpy(name, "float");
            break;
        case TYPE_VOID:
            name = (char *)calloc(5, sizeof(char));
            strcpy(name, "void");
            break;
    }

    return name;
}

extern FILE *result_file;

void decl_irgen(struct decl *d) {
    if(d == NULL)return;

    if(d->code) {
        r_count = 0;
        fprintf(result_file, ".%s_body:\n", d->name);
        stmt_irgen(d->code, d->symbol);
    }

    decl_irgen(d->next);
}
void stmt_irgen(struct stmt *s, struct symbol *function_symbol) {
    if(s == NULL)return;

    int temp;
    switch(s->kind) {
        case STMT_EXPR:
            expr_irgen(s->expr);
            break;
        case STMT_BLOCK:
            temp = r_count;
            r_count = 0;
            stmt_irgen(s->body, function_symbol);
            r_count = temp;
            break;
    }

    stmt_irgen(s->next, function_symbol);
}
void expr_irgen(struct expr *e) {
    if(e == NULL)return;

    switch(e->kind) {
        case EXPR_NAME:
            e->reg = register_create();
            fprintf(result_file, "%s = load %s, ptr %s\n", register_name(e->reg), 
                        type_irgen(e->type), 
                        symbol_irgen(e->symbol));
            break;
        case EXPR_ASSIGN:
            expr_irgen(e->right);
            fprintf(result_file, "store %s %s, ptr %s\n", type_irgen(e->right->type), 
                        register_name(e->right->reg), 
                        symbol_irgen(e->left->symbol));
            e->reg = e->right->reg;
            break;
    }
}