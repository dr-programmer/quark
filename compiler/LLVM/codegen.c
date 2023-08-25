#include <stdio.h>
#include <string.h>

#include "codegen.h"

typedef union {
    int ivalue;
    float fvalue;
    char *svalue;
} Value;

Value current_constant;

unsigned int r_count = 0;

unsigned int register_create() {
    return r_count++;
}
const char *register_name(int r) {
    unsigned int size = 1;
    char *name = (char *)calloc(2, sizeof(char));

    unsigned int i = 1, temp = r;
    while(temp > 9) {
        temp /= 10;
        i *= 10;
    }

    if(r == -1) {
        name = (char *)realloc(name, sizeof(char) * i);
        sprintf(name, "%d", current_constant.ivalue);
        return name;
    }
    else if(r == -2) {
        name = (char *)realloc(name, sizeof(char) * i + 7);
        sprintf(name, "%f", current_constant.fvalue);
        return name;
    }
    else if(r == -3) {
        return current_constant.svalue;
    }
    else name[0] = '%';

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
            name = (char *)calloc(7, sizeof(char));
            strcpy(name, "double");
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
        case STMT_DECL:
            decl_irgen(s->decl);
            break;
        case STMT_EXPR:
            expr_irgen(s->expr);
            break;
        case STMT_IF_ELSE:
        {
            expr_irgen(s->expr);
            int if_label = label_create();
            int else_label = label_create();
            int done_label = label_create();
            fprintf(result_file, "br %s %s, label %%%s, label %%%s\n", 
                        type_irgen(s->expr->type), 
                        register_name(s->expr->reg), 
                        label_name(if_label), 
                        label_name(else_label));
            fprintf(result_file, "%s:\n", label_name(if_label));
            stmt_irgen(s->body, function_symbol);
            fprintf(result_file, "br label %%%s\n", label_name(done_label));
            fprintf(result_file, "%s:\n", label_name(else_label));
            stmt_irgen(s->else_body, function_symbol);
            fprintf(result_file, "br label %%%s\n", label_name(done_label));
            fprintf(result_file, "%s:\n", label_name(done_label));
            break;
        }
        case STMT_GIVE:
            expr_irgen(s->expr);
            fprintf(result_file, "ret %s %s\n", type_irgen(function_symbol->type->subtype), 
                        register_name(s->expr->reg));
            break;
        case STMT_BLOCK:
            stmt_irgen(s->body, function_symbol);
            break;
    }

    stmt_irgen(s->next, function_symbol);
}

#define ANNUL_CURRENT_CONSTANT current_constant.ivalue = 0; \
                                current_constant.fvalue = 0; \
                                current_constant.svalue = 0;

static char check_for_float(struct type *t) {
    if(t->kind == TYPE_FLOATING_POINT) {
        return 'f';
    }
    return ' ';
}

void expr_irgen(struct expr *e) {
    if(e == NULL)return;

    switch(e->kind) {
        case EXPR_INTEGER_LITERAL:
            ANNUL_CURRENT_CONSTANT;
            current_constant.ivalue = e->integer_value;
            e->reg = -1;
            break;
        case EXPR_FLOATING_POINT_LITERAL:
            ANNUL_CURRENT_CONSTANT;
            current_constant.fvalue = e->floating_point_value;
            e->reg = -2;
            break;
        case EXPR_NAME:
            e->reg = register_create();
            if(e->symbol->kind != SYMBOL_GLOBAL) {
                fprintf(result_file, "%s = load %s, ptr %s\n", register_name(e->reg), 
                            type_irgen(e->type), 
                            symbol_irgen(e->symbol));
            }
            else {
                fprintf(result_file, "%s = %s %s\n", register_name(e->reg), 
                            type_irgen(e->type), 
                            symbol_irgen(e->symbol));
            }
            break;
        case EXPR_ADD:
            expr_irgen(e->left);
            expr_irgen(e->right);
            e->reg = register_create();
            fprintf(result_file, "%s = %cadd %s %s, %s\n", register_name(e->reg), 
                        check_for_float(e->type), 
                        type_irgen(e->type), 
                        register_name(e->left->reg), 
                        register_name(e->right->reg));
            break;
        case EXPR_SUB:
            expr_irgen(e->left);
            expr_irgen(e->right);
            e->reg = register_create();
            fprintf(result_file, "%s = %csub %s %s, %s\n", register_name(e->reg), 
                        check_for_float(e->type), 
                        type_irgen(e->type), 
                        register_name(e->left->reg), 
                        register_name(e->right->reg));
            break;
        case EXPR_MUL:
            expr_irgen(e->left);
            expr_irgen(e->right);
            e->reg = register_create();
            fprintf(result_file, "%s = %cmul %s %s, %s\n", register_name(e->reg), 
                        check_for_float(e->type), 
                        type_irgen(e->type), 
                        register_name(e->left->reg), 
                        register_name(e->right->reg));
            break;
        case EXPR_DIV:
        {
            expr_irgen(e->left);
            expr_irgen(e->right);
            char temp = check_for_float(e->type) == 32 ? 's' : 'f';
            e->reg = register_create();
            fprintf(result_file, "%s = %cdiv %s %s, %s\n", register_name(e->reg), 
                        temp, 
                        type_irgen(e->type), 
                        register_name(e->left->reg), 
                        register_name(e->right->reg));
            break;
        }
        case EXPR_MODULUS:
        {
            expr_irgen(e->left);
            expr_irgen(e->right);
            char temp = check_for_float(e->type) == 32 ? 's' : 'f';
            e->reg = register_create();
            fprintf(result_file, "%s = %crem %s %s, %s\n", register_name(e->reg), 
                        temp, 
                        type_irgen(e->type), 
                        register_name(e->left->reg), 
                        register_name(e->right->reg));
            break;
        }
        case EXPR_ASSIGN:
            expr_irgen(e->right);
            if(e->left->symbol->kind != SYMBOL_GLOBAL) {
                fprintf(result_file, "store %s %s, ptr %s\n", type_irgen(e->right->type), 
                                        register_name(e->right->reg), 
                                        symbol_irgen(e->left->symbol));
            }
            else {
                fprintf(result_file, "%s = %s %s\n", symbol_irgen(e->left->symbol), 
                            type_irgen(e->type), 
                            register_name(e->right->reg));
            }
            e->reg = e->right->reg;
            break;
        case EXPR_EQUAL ... EXPR_LESS_EQUAL:
        {
            expr_irgen(e->left);
            expr_irgen(e->right);
            char temp = check_for_float(e->left->type) == 'f' 
                        ? 'f' : check_for_float(e->right->type);
            if(temp == ' ') temp = 'i';
            char operation_temp = temp == 'f' ? 'o' : ' ';
            struct type *temp_type = e->left->type->kind > e->left->type->kind 
                        ? e->left->type : e->right->type;
            e->reg = register_create();
            switch(e->kind) {
                case EXPR_EQUAL:
                    fprintf(result_file, "%s = %ccmp %ceq %s %s, %s\n", register_name(e->reg), 
                        temp, 
                        operation_temp, 
                        type_irgen(temp_type), 
                        register_name(e->left->reg), 
                        register_name(e->right->reg));
                    break;
                case EXPR_NOT_EQUAL:
                    fprintf(result_file, "%s = %ccmp %cne %s %s, %s\n", register_name(e->reg), 
                        temp, 
                        operation_temp, 
                        type_irgen(temp_type), 
                        register_name(e->left->reg), 
                        register_name(e->right->reg));
                    break;
                case EXPR_GREATER:
                    if(operation_temp == ' ') operation_temp = 's';
                    fprintf(result_file, "%s = %ccmp %cgt %s %s, %s\n", register_name(e->reg), 
                        temp, 
                        operation_temp, 
                        type_irgen(temp_type), 
                        register_name(e->left->reg), 
                        register_name(e->right->reg));
                    break;
                case EXPR_GREATER_EQUAL:
                    if(operation_temp == ' ') operation_temp = 's';
                    fprintf(result_file, "%s = %ccmp %cge %s %s, %s\n", register_name(e->reg), 
                        temp, 
                        operation_temp, 
                        type_irgen(temp_type), 
                        register_name(e->left->reg), 
                        register_name(e->right->reg));
                    break;
                case EXPR_LESS:
                    if(operation_temp == ' ') operation_temp = 's';
                    fprintf(result_file, "%s = %ccmp %clt %s %s, %s\n", register_name(e->reg), 
                        temp, 
                        operation_temp, 
                        type_irgen(temp_type), 
                        register_name(e->left->reg), 
                        register_name(e->right->reg));
                    break;
                case EXPR_LESS_EQUAL:
                    if(operation_temp == ' ') operation_temp = 's';
                    fprintf(result_file, "%s = %ccmp %cle %s %s, %s\n", register_name(e->reg), 
                        temp, 
                        operation_temp, 
                        type_irgen(temp_type), 
                        register_name(e->left->reg), 
                        register_name(e->right->reg));
                    break;
            }
            break;
        }
    }
}