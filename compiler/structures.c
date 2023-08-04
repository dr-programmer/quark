#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "colors.h"
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
        print_tabs(number_of_tabs);
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

static void print_error(const char *error, const char *name) {
    fprintf(stderr, RED "Error" RESET \
        MAG" |%s|"RESET"->"YEL"|%s|"RESET" \n", error, name);
}

static void print_error_formated() {
    
}

void decl_resolve(struct decl *d) {
    if(d == NULL)return;

    symbol_t kind = scope_level() > 1 ? SYMBOL_LOCAL : SYMBOL_GLOBAL;

    d->symbol = symbol_create(kind, d->type, d->name);

    expr_resolve(d->value);
    if(scope_lookup_current(d->name)) print_error("variable already exists", d->name);
    else scope_bind(d->symbol);

    if(d->code) {
        scope_enter();
        param_list_resolve(d->type->params);
        stmt_resolve(d->code);
        scope_exit();
    }

    decl_resolve(d->next);
}
void stmt_resolve(struct stmt *s) {
    if(s == NULL)return;

    switch(s->kind) {
        case STMT_DECL: decl_resolve(s->decl); break;
        case STMT_EXPR: expr_resolve(s->expr); break;
        case STMT_IF_ELSE: expr_resolve(s->expr); stmt_resolve(s->body);
                                stmt_resolve(s->else_body); break;
        case STMT_FOR: expr_resolve(s->init_expr); expr_resolve(s->expr);
                            expr_resolve(s->next_expr); stmt_resolve(s->body); break;
        case STMT_GIVE: expr_resolve(s->expr); break;
        case STMT_BLOCK: scope_enter(); stmt_resolve(s->body); scope_exit(); break;
    }

    stmt_resolve(s->next);
}
void expr_resolve(struct expr *e) {
    if(e == NULL)return;

    if(e->kind == EXPR_NAME) {
        e->symbol = scope_lookup(e->name);
        if(e->symbol == NULL) {
            print_error("no declaration found", e->name);
            struct type *temp = type_create(TYPE_INTEGER, 0, 0, 0);
            e->symbol = symbol_create(SYMBOL_LOCAL, temp, NULL);
        }
    }
    else {
        expr_resolve(e->left);
        expr_resolve(e->right);
    }
}
void param_list_resolve(struct param_list *p) {
    if(p == NULL)return;

    p->symbol = symbol_create(SYMBOL_PARAM, p->type, p->name);
    if(scope_lookup_current(p->name)) print_error("parameter already exists"
                                            " in function", p->name);
    else scope_bind(p->symbol);

    param_list_resolve(p->next);
}

unsigned short type_equals(struct type *a, struct type *b) {
    if(a->kind == b->kind) {
        if(a->kind == TYPE_ARRAY) {
            return type_equals(a->subtype, b->subtype);
        }
        else if(a->kind == TYPE_FUNCTION) {
            return type_equals(a->subtype, b->subtype) 
                && param_list_equals(a->params, b->params);
        }
        else return 1;
    }
    else return 0;
}
unsigned short param_list_equals(struct param_list *a, struct param_list *b) {
    if(a == NULL && b == NULL)return 1;
    if(a == NULL || b == NULL)return 0;
    if(type_equals(a->type, b->type)) {
        return param_list_equals(a->next, b->next);
    }
    else return 0;
}
struct type *type_copy(struct type *t) {
    if(t == NULL) return NULL;

    struct type *result = type_create(t->kind, NULL, NULL, t->number_of_subtypes);
    result->subtype = type_copy(t->subtype);
    result->params = param_list_copy(t->params);

    return result;
}
struct param_list *param_list_copy(struct param_list *p) {
    if(p == NULL) return NULL;

    struct param_list *result = param_list_create(NULL, type_copy(p->type), 
                                                    param_list_copy(p->next));
    result->name = (char *)calloc(strlen(p->name), sizeof(char));
    strcpy(result->name, p->name);

    return result;
}
void type_delete(struct type *t) {
    if(t == NULL)return;

    type_delete(t->subtype);
    param_list_delete(t->params);

    free(t);
}
void param_list_delete(struct param_list *p) {
    if(p == NULL)return;

    free(p->name);
    type_delete(p->type);
    param_list_delete(p->next);

    free(p);
}

unsigned int error_count;

void decl_typecheck(struct decl *d) {
    if(d == NULL)return;

    if(d->value) {
        struct type *t = expr_typecheck(d->value);
        if(!assignment_typecheck(d->symbol->type, t)) {
            printf(RED"Error ");
            printf(MAG"|cannot assign "BLU);
            type_print(t);
            printf(MAG" to "BLU);
            type_print(d->symbol->type);
            printf(MAG"|"RESET);
            printf("->"YEL"|%s", d->name);
            type_print(d->type);
            printf(" = ");
            if(d->symbol->type->kind == TYPE_ARRAY)printf("{");
            expr_print(d->value);
            if(d->symbol->type->kind == TYPE_ARRAY)printf("}");
            printf(";| \n"RESET);
            error_count++;
        }
        type_delete(t);
    }
    if(d->code) {
        struct type *current_function_type = type_copy(d->symbol->type->subtype);
        stmt_typecheck(d->code, current_function_type);
        type_delete(current_function_type);
    }

    decl_typecheck(d->next);
}
void stmt_typecheck(struct stmt *s, struct type *current_function_type) {
    if(s == NULL)return;

    struct type *t;
    switch(s->kind) {
        case STMT_DECL:
            decl_typecheck(s->decl);
            break;
        case STMT_EXPR:
            t = expr_typecheck(s->expr);
            type_delete(t);
            break;
        case STMT_IF_ELSE:
            t = expr_typecheck(s->expr);
            if(t->kind == TYPE_VOID) {
                printf(RED"Error "MAG"|if-statement is void| \n"RESET);
                error_count++;
            }
            type_delete(t);
            stmt_typecheck(s->body, current_function_type);
            stmt_typecheck(s->else_body, current_function_type);
            break;
        case STMT_FOR:
            t = expr_typecheck(s->init_expr);
            type_delete(t);
            t = expr_typecheck(s->expr);
            type_delete(t);
            t = expr_typecheck(s->next_expr);
            type_delete(t);
            stmt_typecheck(s->body, current_function_type);
            break;
        case STMT_GIVE:
            t = expr_typecheck(s->expr);
            if(!assignment_typecheck(current_function_type, t)) {
                printf(RED"Error "MAG"|cannot give type to function| \n"RESET);
                error_count++;
            }
            type_delete(t);
            break;
        case STMT_BLOCK:
            stmt_typecheck(s->body, current_function_type);
            break;
    }

    stmt_typecheck(s->next, current_function_type);
}
struct type *expr_typecheck(struct expr *e) {
    if(e == NULL) return NULL;

    struct type *left = expr_typecheck(e->left);
    struct type *right = expr_typecheck(e->right);

    struct type *result;

    switch(e->kind) {
        case EXPR_INTEGER_LITERAL: result = type_create(TYPE_INTEGER, 0, 0, 0); break;
        case EXPR_FLOATING_POINT_LITERAL: result = type_create(TYPE_FLOATING_POINT, 0, 0, 0); 
                                                break;
        case EXPR_STRING_LITERAL: struct type *temp = type_create(TYPE_CHARACTER, 0, 0, 0);
                                    result = type_create(TYPE_ARRAY, temp, 0, 0); break;
        case EXPR_NAME: result = type_copy(e->symbol->type); break;
        case EXPR_ADD_WITH ... EXPR_DIV_WITH:
        case EXPR_ASSIGN:
            if(!assignment_typecheck(left, right)) {
                printf(RED"Error "MAG"|cannot assign expression| \n"RESET);
                error_count++;
            }
            result = type_copy(left);
            break;
        case EXPR_ADD ... EXPR_DIV:
            if(left->kind >= TYPE_VOID || right->kind >= TYPE_VOID) {
                printf(RED"Error "MAG"|cannot add expression| \n"RESET);
                error_count++;
            }
            result = left->kind > right->kind ? type_copy(left) : type_copy(right);
            break;
        case EXPR_MODULUS:
            if(!(left->kind == right->kind && left->kind == TYPE_INTEGER)) {
                printf(RED"Error "MAG"|cannot use binary %%| \n"RESET);
                error_count++;
            }
            result = type_create(TYPE_INTEGER, 0, 0, 0);
            break;
        case EXPR_AND ... EXPR_NOT:
        case EXPR_EQUAL ... EXPR_LESS_EQUAL:
            if(right == NULL) {
                if(left->kind == TYPE_VOID) {
                    printf(RED"Error "MAG"|cannot compare or logic-test| \n"RESET);
                    error_count++;
                }
            }
            else if(left->kind == TYPE_VOID || right->kind == TYPE_VOID) {
                printf(RED"Error "MAG"|cannot compare or logic-test| \n"RESET);
                error_count++;
            }
            result = type_create(TYPE_BOOLEAN, 0, 0, 0);
            break;
        case EXPR_INCREMENT ... EXPR_DECREMENT:
            temp = left == NULL ? right : left;
            if(temp->kind > TYPE_FLOATING_POINT) {
                printf(RED"Error "MAG"|cannot incr/decr| \n"RESET);
                error_count++;
            }
            result = type_copy(temp);
            break;
        case EXPR_SUBSCRIPT:
            if(left->kind == TYPE_ARRAY) {
                if(right->kind != TYPE_INTEGER) {
                    printf(RED"Error "MAG"|array index not an integer| \n"RESET);
                    error_count++;
                }
                result = type_copy(left->subtype);
            }
            else {
                printf(RED"Error "MAG"|attempt to subscript a noniterable| \n"RESET);
                error_count++;
                result = type_copy(left);
            }
            break;
        case EXPR_CALL:
            if(left->kind != TYPE_FUNCTION) {
                printf(RED"Error "MAG"|attempt to call a nonfunction| \n"RESET);
                error_count++;
                result = type_copy(left);
            }
            else result = type_copy(left->subtype);
            if(!param_list_typecheck(left->params, e->right)) {
                printf(RED"Error "MAG"|inappropriate arguments to function| \n"RESET);
                error_count++;
            }
            break;
        case EXPR_ARG:
            if(!right) result = type_create(TYPE_ARRAY, type_copy(left), NULL, 0);
            else result = left->kind > right->kind 
                ? type_create(TYPE_ARRAY, type_copy(left->subtype), NULL, 0) 
                : type_create(TYPE_ARRAY, type_copy(right->subtype), NULL, 0);
            break;
    }

    type_delete(left);
    type_delete(right);

    return result;
}
unsigned short param_list_typecheck(struct param_list *p, 
                                        struct expr *e)
{
    if(p == NULL && e == NULL)return 1;
    if(p == NULL || e == NULL)return 0;
    struct type *check = expr_typecheck(e->left);
    if(assignment_typecheck(p->type, check)) {
        type_delete(check);
        return param_list_typecheck(p->next, e->right);
    }
    else {
        type_delete(check);
        return 0;
    }
}
unsigned short assignment_typecheck(struct type *left, struct type *right) {
    if(left->kind == TYPE_BOOLEAN || left->kind == TYPE_CHARACTER) {
        if(right->kind < TYPE_FLOATING_POINT) {
            return 1;
        }
    }
    else if(left->kind < TYPE_VOID && left->kind >= right->kind) {
        return 1;
    }
    else if(left->kind == TYPE_ARRAY && right->kind == TYPE_ARRAY) {
        return assignment_typecheck(left->subtype, right->subtype);
    }
    return 0;
}