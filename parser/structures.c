#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
// Constructing the AST
struct decl *decl_create(char *name, 
                            struct type *type, 
                            struct expr *value, 
                            struct stmt *code, 
                            struct decl *next)
{
    struct decl *d = (struct decl *)malloc(sizeof(struct decl));
    d->name = name;
    d->type = type;
    d->value = value;
    d->code = code;
    d->next = next;
    return d;
}

struct stmt *stmt_create(stmt_t kind, 
    struct decl *decl, struct expr *init_expr, 
    struct expr *expr, struct expr *next_expr, 
    struct stmt *body, struct stmt *else_body, 
    struct stmt *next)
{
    struct stmt *s = (struct stmt *)malloc(sizeof(struct stmt));
    s->kind = kind;
    s->decl = decl;
    s->init_expr = init_expr;
    s->expr = expr;
    s->next_expr = next_expr;
    s->body = body;
    s->else_body = else_body;
    s->next = next;
    return s;
}

struct expr *expr_create(expr_t kind, 
                            struct expr *left,
                            struct expr *right)
{
    struct expr *e = (struct expr *)malloc(sizeof(struct expr));
    e->kind = kind;
    e->left = left;
    e->right = right;
    return e;
}

struct expr *expr_create_name(const char *name) {
    struct expr *e = expr_create(EXPR_NAME, NULL, NULL);
    e->name = name;
    return e;
}
struct expr *expr_create_integer_literal(int i) {
    struct expr *e = expr_create(EXPR_INTEGER_LITERAL, NULL, NULL);
    e->integer_value = i;
    return e;
}
struct expr *expr_create_boolean_literal(int i) {
    struct expr *e = expr_create(EXPR_INTEGER_LITERAL, NULL, NULL);
    e->integer_value = i;
    return e;
}
struct expr *expr_create_char_literal(int i) {
    struct expr *e = expr_create(EXPR_INTEGER_LITERAL, NULL, NULL);
    e->integer_value = i;
    return e;
}
struct expr *expr_create_floating_point_literal(float f) {
    struct expr *e = expr_create(EXPR_FLOATING_POINT_LITERAL, NULL, NULL);
    e->floating_point_value = f;
    return e;
}
struct expr *expr_create_string_literal(const char *string) {
    struct expr *e = expr_create(EXPR_STRING_LITERAL, NULL, NULL);
    e->string_literal = string;
    return e;
}

struct type *type_create(type_t kind, 
                            struct type *subtype, 
                            struct param_list *params, 
                            int number_of_subtypes)
{
    struct type *t = (struct type *)malloc(sizeof(struct type));
    t->kind = kind;
    t->subtype = subtype;
    t->params = params;
    t->number_of_subtypes = number_of_subtypes;
    return t;
}

struct param_list *param_list_create(char *name, 
                                    struct type *type, 
                                    struct param_list *next)
{
    struct param_list *p = (struct param_list *)malloc(sizeof(struct param_list));
    p->name = name;
    p->type = type;
    p->next = next;
    return p;
}

void decl_print(struct decl *d, int number_of_tabs) {
    if(d == NULL) return;

    print_tabs(number_of_tabs);

    printf("%s", d->name);
    type_print(d->type);
    if(d->value != NULL){
        printf(" = ");
        if(d->type->kind == TYPE_ARRAY || d->type->kind == TYPE_STRING) printf("{");
        expr_print(d->value);
        if(d->type->kind == TYPE_ARRAY || d->type->kind == TYPE_STRING) printf("}");
        printf(";");
    }
    else if(d->code != NULL){
        printf(" { \n");
        stmt_print(d->code, number_of_tabs+1);
        printf("}");
    }
    else printf(";");
    printf("\n");

    decl_print(d->next, number_of_tabs);
}
void stmt_print(struct stmt *s, int number_of_tabs) {
    if(s == NULL)return;

    switch(s->kind) {
        case STMT_DECL: decl_print(s->decl, number_of_tabs); break;
        case STMT_EXPR: print_tabs(number_of_tabs); expr_print(s->expr); printf(";\n"); break;
        case STMT_IF_ELSE:
            print_tabs(number_of_tabs);
            printf("if(");
            expr_print(s->expr);
            printf(") ");
            stmt_print(s->body, number_of_tabs);
            if(s->else_body != NULL) {
                print_tabs(number_of_tabs);
                printf("else ");
                stmt_print(s->else_body, number_of_tabs);
            }
            break;
        case STMT_FOR:
            print_tabs(number_of_tabs);
            printf("for(");
            expr_print(s->init_expr);
            printf("; ");
            expr_print(s->expr);
            printf("; ");
            expr_print(s->next_expr);
            printf(") ");
            stmt_print(s->body, number_of_tabs);
            break;
        case STMT_GIVE:
            print_tabs(number_of_tabs);
            printf("give ");
            expr_print(s->expr);
            printf(";\n");
            break;
        case STMT_BLOCK:
            printf("{\n");
            stmt_print(s->body, number_of_tabs+1);
            print_tabs(number_of_tabs);
            printf("}\n");
            break;
    }

    stmt_print(s->next, number_of_tabs);
}
void expr_print(struct expr *e) {
    if(e == NULL)return;

    switch(e->kind) {
        case EXPR_NAME: printf("%s", e->name); break;
        case EXPR_INTEGER_LITERAL: printf("%d", e->integer_value); break;
        case EXPR_FLOATING_POINT_LITERAL: printf("%f", e->floating_point_value); break;
        case EXPR_STRING_LITERAL: printf("%s", e->string_literal); break;
        case EXPR_AND: printf("("); expr_print(e->left); printf(" && "); 
                            expr_print(e->right); printf(")"); break;
        case EXPR_OR: printf("("); expr_print(e->left); printf(" || "); 
                            expr_print(e->right); printf(")"); break;
        case EXPR_NOT: printf("!"); expr_print(e->left); break;
        case EXPR_SUBSCRIPT: expr_print(e->left); printf("->"); printf("(");
                                expr_print(e->right); printf(")"); break;
        case EXPR_CALL: expr_print(e->left); printf("("); expr_print(e->right); 
                                printf(")"); break;
        case EXPR_ARG: expr_print(e->left); 
                            if(e->right != NULL) {
                                printf(", "); expr_print(e->right);
                            }
                            break;
        case EXPR_ADD: printf("("); expr_print(e->left); printf(" + "); 
                                expr_print(e->right); printf(")"); break;
        case EXPR_SUB: printf("("); expr_print(e->left); printf(" - "); 
                                expr_print(e->right); printf(")"); break;
        case EXPR_MUL: printf("("); expr_print(e->left); printf(" * "); 
                            expr_print(e->right); printf(")"); break;
        case EXPR_DIV: printf("("); expr_print(e->left); printf(" / "); 
                            expr_print(e->right); printf(")"); break;
        case EXPR_MODULUS: printf("("); expr_print(e->left); printf(" %% "); 
                            expr_print(e->right); printf(")"); break;
        case EXPR_ASSIGN: expr_print(e->left); printf(" = "); expr_print(e->right); break;
        case EXPR_EQUAL: expr_print(e->left); printf(" == "); expr_print(e->right); break;
        case EXPR_NOT_EQUAL: expr_print(e->left); printf(" != "); expr_print(e->right); break;
        case EXPR_GREATER: expr_print(e->left); printf(" > "); expr_print(e->right); break;
        case EXPR_GREATER_EQUAL: expr_print(e->left); printf(" >= "); 
                                    expr_print(e->right); break;
        case EXPR_LESS: expr_print(e->left); printf(" < "); expr_print(e->right); break;
        case EXPR_LESS_EQUAL: expr_print(e->left); printf(" <= "); 
                                expr_print(e->right); break;
        case EXPR_INCREMENT: expr_print(e->left); printf("++"); expr_print(e->right); break;
        case EXPR_DECREMENT: expr_print(e->left); printf("--"); expr_print(e->right); break;
        case EXPR_ADD_WITH: expr_print(e->left); printf(" += "); 
                                expr_print(e->right); break;
        case EXPR_SUB_WITH: expr_print(e->left); printf(" -= "); 
                                expr_print(e->right); break;
        case EXPR_MUL_WITH: expr_print(e->left); printf(" *= "); 
                                expr_print(e->right); break;
        case EXPR_DIV_WITH: expr_print(e->left); printf(" /= "); 
                                expr_print(e->right); break;
    }
}
void type_print(struct type *t) {
    if(t == NULL)return;

    switch(t->kind) {
        case TYPE_VOID: printf("[void]"); break;
        case TYPE_BOOLEAN: printf("[bool]"); break;
        case TYPE_CHARACTER: printf("[char]"); break;
        case TYPE_INTEGER: printf("[int]"); break;
        case TYPE_FLOATING_POINT: printf("[float]"); break;
        case TYPE_STRING:
            type_print(t->subtype);
            switch(t->number_of_subtypes) {
                case 0: printf("^?"); break;
                default: printf("^%d", t->number_of_subtypes); break;
            }
            break;
        case TYPE_ARRAY:
            type_print(t->subtype);
            switch(t->number_of_subtypes) {
                case 0: printf("^?"); break;
                default: printf("^%d", t->number_of_subtypes); break;
            }
            break;
        case TYPE_FUNCTION:
            type_print(t->subtype);
            printf("(");
            param_list_print(t->params);
            printf(")");
            break;
    }
}
void param_list_print(struct param_list *p) {
    if(p == NULL)return;

    printf("%s", p->name);
    type_print(p->type);
    if(p->next != NULL)printf(", ");
    param_list_print(p->next);
}

void print_tabs(int number_of_tabs) {
    for(unsigned char i = 0; i < number_of_tabs; i++) {
        printf("    ");
    }
}
// Semantic analysis
struct symbol *symbol(symbol_t kind, 
                        struct type *type, 
                        char *name)
{
    struct symbol *s = (struct symbol *)malloc(sizeof(struct symbol));
    s->kind = kind;
    s->type = type;
    s->name = name;
    return s;
}

void scope_enter() {

}
void scope_exit() {

}
int scope_level() {

}
void scope_bind(struct symbol *symbol) {

}
struct symbol *scope_lookup(const char *name) {

}
struct symbol *scope_lookup_current(const char *name) {

}