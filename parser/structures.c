#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

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
struct expr *expr_create_foating_point_literal(float f) {
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