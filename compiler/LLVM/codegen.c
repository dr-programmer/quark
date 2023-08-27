#include <stdio.h>
#include <string.h>
#include <math.h>

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
    char *name;
    int size = 3 + strlen(s->name) + (log10(s->which) + 1);

    if(s->kind == SYMBOL_GLOBAL) {
        name = (char *)calloc(strlen(s->name) + 2, sizeof(char));
        sprintf(name, "@%s", s->name);
    }
    else {
        name = (char *)calloc(size, sizeof(char));
        sprintf(name, "%%.%d%s", s->which, s->name);
    }

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

void type_cast(struct expr *e) {
    int old_register;
    struct expr *expr;

    if(e->type->kind == TYPE_BOOLEAN) {
        if(e->left->type->kind != e->right->type->kind) {
            expr = e->left->type->kind < e->right->type->kind ? e->left : e->right;
            struct expr *higher_expr = e->left->type->kind > e->right->type->kind 
                                            ? e->left : e->right;
            old_register = expr->reg;
            expr->reg = register_create();
            if(higher_expr->type->kind <= TYPE_INTEGER) 
                fprintf(result_file, "%s = zext %s %s to %s\n", register_name(expr->reg), 
                            type_irgen(expr->type), 
                            register_name(old_register), 
                            type_irgen(higher_expr->type));
            else if(higher_expr->type->kind == TYPE_FLOATING_POINT) 
                fprintf(result_file, "%s = sitofp %s %s to %s\n", register_name(expr->reg), 
                            type_irgen(expr->type), 
                            register_name(old_register), 
                            type_irgen(higher_expr->type));
        }
        return;
    }

    if(e->left->type->kind != e->type->kind) expr = e->left;
    else if(e->right->type->kind != e->type->kind) expr = e->right;
    else return;

    old_register = expr->reg;
    expr->reg = register_create();
    if(e->type->kind <= TYPE_INTEGER) {
        fprintf(result_file, "%s = zext %s %s to %s\n", register_name(expr->reg), 
                    type_irgen(expr->type), 
                    register_name(old_register), 
                    type_irgen(e->type));
    }
    else if(e->type->kind == TYPE_FLOATING_POINT) {
        fprintf(result_file, "%s = sitofp %s %s to %s\n", register_name(expr->reg), 
                    type_irgen(expr->type), 
                    register_name(old_register), 
                    type_irgen(e->type));
    }
}

int exit_count;

void decl_irgen(struct decl *d) {
    if(d == NULL)return;

    if(d->code) {
        r_count = 0;
        exit_count = 0;
        fprintf(result_file, "define %s %s (", type_irgen(d->type->subtype), 
                    symbol_irgen(d->symbol));
        struct param_list *p = d->type->params;
        while(p != NULL) {
            p->reg = register_create();
            fprintf(result_file, "%s %s", type_irgen(p->type), register_name(p->reg));
            if(p->next != NULL)fprintf(result_file, ", ");
            p = p->next;
        }
        fprintf(result_file, ") {\n");
        fprintf(result_file, ".%s_body:\n", d->name);
        p = d->type->params;
        while(p != NULL) {
            fprintf(result_file, "%s = alloca %s\n", symbol_irgen(p->symbol), 
                        type_irgen(p->type));
            fprintf(result_file, "store %s %s, ptr %s\n", type_irgen(p->type), 
                        register_name(p->reg), 
                        symbol_irgen(p->symbol));
            p = p->next;
        }
        stmt_irgen(d->code, d->symbol);
        fprintf(result_file, "unreachable\n");
        fprintf(result_file, "}\n");
    }
    else {
        if(d->symbol->kind == SYMBOL_LOCAL) {
            fprintf(result_file, "%s = alloca %s\n", symbol_irgen(d->symbol), 
                        type_irgen(d->type));
            if(d->value) {
                expr_irgen(d->value);
                fprintf(result_file, "store %s %s, ptr %s\n", type_irgen(d->type), 
                            register_name(d->value->reg), 
                            symbol_irgen(d->symbol));
            }
        }
        else {
            if(d->value) {
                expr_irgen(d->value);
                fprintf(result_file, "%s = global %s %s\n", symbol_irgen(d->symbol), 
                            type_irgen(d->type), 
                            register_name(d->value->reg));
            }
            else {
                fprintf(result_file, "%s = global %s 0\n", symbol_irgen(d->symbol), 
                            type_irgen(d->type));
            }
        }
    }

    decl_irgen(d->next);
}

static int give_type(struct type *t) {
    int temp_register = register_create();
    fprintf(result_file, "%s = alloca [5 x i8]\n", register_name(temp_register));
    if(t->kind == TYPE_FLOATING_POINT) {
        fprintf(result_file, "store [5 x i8] c\"%%lf\\0A\\00\", ptr %s\n", 
                    register_name(temp_register));
    }
    else {
        fprintf(result_file, "store [4 x i8] c\"%%d\\0A\\00\", ptr %s\n", 
                    register_name(temp_register));
    }
    return temp_register;
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
        case STMT_FOR:
        {
            int loop_label = label_create();
            int continue_label = label_create();
            int done_label = label_create();
            expr_irgen(s->init_expr);
            fprintf(result_file, "br label %%%s\n", label_name(loop_label));
            fprintf(result_file, "%s:\n", label_name(loop_label));
            if(s->expr) {
                expr_irgen(s->expr);
                fprintf(result_file, "br %s %s, label %%%s, label %%%s\n", 
                            type_irgen(s->expr->type), 
                            register_name(s->expr->reg), 
                            label_name(continue_label), 
                            label_name(done_label));
                fprintf(result_file, "%s:\n", label_name(continue_label));
            }
            stmt_irgen(s->body, function_symbol);
            expr_irgen(s->next_expr);
            fprintf(result_file, "br label %%%s\n", label_name(loop_label));
            fprintf(result_file, "%s:\n", label_name(done_label));
            break;
        }
        case STMT_GIVE:
            if(s->expr) {
                expr_irgen(s->expr);
                if(s->print) {
                    int text_register = give_type(function_symbol->type->subtype);
                    int call_register = register_create();
                    fprintf(result_file, 
                                "%s = call i32 (ptr, ...) @printf (ptr %s, %s %s)\n", 
                                            register_name(call_register), 
                                            register_name(text_register), 
                                            type_irgen(s->expr->type), 
                                            register_name(s->expr->reg));
                }
                fprintf(result_file, "ret %s %s\n", 
                            type_irgen(function_symbol->type->subtype), 
                            register_name(s->expr->reg));
            }
            else {
                fprintf(result_file, "ret void\n");
            }
            fprintf(result_file, ".retExit%d:\n", exit_count++);
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

static void arg_type_cast(struct param_list *p, struct expr *e) {
    if(p == NULL)return;

    if(p->type->kind != e->left->type->kind) {
        struct expr *expr = e->left;
        int old_register = expr->reg;
        expr->reg = register_create();
        if(p->type->kind <= TYPE_INTEGER) {
            fprintf(result_file, "%s = zext %s %s to %s\n", register_name(expr->reg), 
                        type_irgen(expr->type), 
                        register_name(old_register), 
                        type_irgen(p->type));
        }
        else if(p->type->kind == TYPE_FLOATING_POINT) {
            fprintf(result_file, "%s = sitofp %s %s to %s\n", register_name(expr->reg), 
                                    type_irgen(expr->type), 
                                    register_name(old_register), 
                                    type_irgen(p->type));
        }
    }

    return arg_type_cast(p->next, e->right);
}

static void arg_irgen(struct param_list *p, struct expr *e) {
    if(e == NULL)return;

    fprintf(result_file, "%s %s", type_irgen(p->type), 
                register_name(e->left->reg));
    if(e->right) fprintf(result_file, ", ");

    arg_irgen(p->next, e->right);
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
            fprintf(result_file, "%s = load %s, ptr %s\n", register_name(e->reg), 
                        type_irgen(e->type), 
                        symbol_irgen(e->symbol));
            break;
        case EXPR_ADD:
            expr_irgen(e->left);
            expr_irgen(e->right);
            type_cast(e);
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
            type_cast(e);
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
            type_cast(e);
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
            type_cast(e);
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
            type_cast(e);
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
            type_cast(e);
            fprintf(result_file, "store %s %s, ptr %s\n", type_irgen(e->type), 
                                    register_name(e->right->reg), 
                                    symbol_irgen(e->left->symbol));
            e->reg = e->right->reg;
            break;
        case EXPR_EQUAL ... EXPR_LESS_EQUAL:
        {
            expr_irgen(e->left);
            expr_irgen(e->right);
            type_cast(e);
            char temp = check_for_float(e->left->type) == 'f' 
                        ? 'f' : check_for_float(e->right->type);
            if(temp == ' ') temp = 'i';
            char operation_temp = temp == 'f' ? 'o' : ' ';
            struct type *temp_type = e->left->type->kind > e->right->type->kind 
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
        case EXPR_INCREMENT ... EXPR_DECREMENT:
            if(e->kind == EXPR_INCREMENT) e->kind = EXPR_ADD;
            else e->kind = EXPR_SUB;
            if(e->left) {
                e->right = expr_create_integer_literal(1);
                e->right->type = type_create(TYPE_INTEGER, NULL, NULL, 0);
                expr_irgen(e);
                fprintf(result_file, "store %s %s, ptr %s\n", type_irgen(e->type), 
                            register_name(e->reg), 
                            symbol_irgen(e->left->symbol));
                e->reg = e->left->reg;
            }
            else {
                e->left = expr_create_integer_literal(1);
                e->left->type = type_create(TYPE_INTEGER, NULL, NULL, 0);
                expr_irgen(e);
                fprintf(result_file, "store %s %s, ptr %s\n", type_irgen(e->type), 
                            register_name(e->reg), 
                            symbol_irgen(e->right->symbol));
            }
            break;
        case EXPR_ADD_WITH ... EXPR_DIV_WITH:
            switch(e->kind) {
                case EXPR_ADD_WITH: e->kind = EXPR_ADD; break;
                case EXPR_SUB_WITH: e->kind = EXPR_SUB; break;
                case EXPR_MUL_WITH: e->kind = EXPR_MUL; break;
                case EXPR_DIV_WITH: e->kind = EXPR_DIV; break;
            }
            expr_irgen(e);
            fprintf(result_file, "store %s %s, ptr %s\n", type_irgen(e->type), 
                        register_name(e->reg), 
                        symbol_irgen(e->left->symbol));
            break;
        case EXPR_AND ... EXPR_OR:
        {
            e->kind = e->kind == EXPR_AND ? EXPR_NOT_EQUAL : EXPR_EQUAL;
            struct type *check_expr_type = type_create(TYPE_INTEGER, 0, 0, 0);
            struct type *temp_expr_type = type_copy(e->type);

            struct expr *check_expr = expr_create_integer_literal(0);
            check_expr->type = check_expr_type;

            struct expr *temp_expr = expr_create(e->kind, e->left, check_expr);
            temp_expr->type = temp_expr_type;
            e->left = temp_expr;

            temp_expr = expr_create(e->kind, e->right, check_expr);
            temp_expr->type = temp_expr_type;
            e->right = temp_expr;

            e->kind = e->kind == EXPR_NOT_EQUAL ? EXPR_EQUAL : EXPR_NOT_EQUAL;
            expr_irgen(e);
            break;
        }
        case EXPR_NOT:
        {
            e->kind = EXPR_EQUAL;
            e->right = expr_create_integer_literal(0);
            e->right->type = type_create(TYPE_INTEGER, 0, 0, 0);
            expr_irgen(e);
            break;
        }
        case EXPR_CALL:
        {
            expr_irgen(e->right);
            arg_type_cast(e->left->type->params, e->right);
            e->reg = register_create();
            fprintf(result_file, "%s = call %s (", register_name(e->reg), 
                        type_irgen(e->left->type->subtype));
            struct param_list *p = e->left->type->params;
            while(p) {
                fprintf(result_file, "%s", type_irgen(p->type));
                if(p->next != NULL) fprintf(result_file, ", ");
                p = p->next;
            }
            fprintf(result_file, ") %s (", symbol_irgen(e->left->symbol));
            arg_irgen(e->left->type->params, e->right);
            fprintf(result_file, ")\n");
            break;
        }
        case EXPR_ARG:
            expr_irgen(e->left);
            expr_irgen(e->right);
            break;
    }
}