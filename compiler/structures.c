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
struct expr *expr_create_string_literal(char *string) {
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
    if(number_of_tabs > -1)printf("\n");

    if(number_of_tabs > -1)decl_print(d->next, number_of_tabs);
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
            if(number_of_tabs == -1)printf(";");
            else printf(";\n");
            break;
        case STMT_BLOCK:
            printf("{\n");
            stmt_print(s->body, number_of_tabs+1);
            print_tabs(number_of_tabs);
            printf("}\n");
            break;
    }

    if(number_of_tabs > -1)stmt_print(s->next, number_of_tabs);
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
        case EXPR_RENAME: printf("%s[%s->&]", e->name, e->string_literal); break;
        case EXPR_DEREFERENCE: printf("^"); expr_print(e->left); break;
        case EXPR_ADDRESS: expr_print(e->left); printf("->&"); break;
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
        case TYPE_POINTER:
            type_print(t->subtype);
            printf("^&");
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

#include <stdarg.h>

unsigned int error_count;
unsigned short show_stack_offset;

void print_error(const char *error, const char *name) {
    error_count++;
    fprintf(stderr, RED "Error" RESET \
        MAG" |%s|"RESET"->"YEL"|%s|"RESET" \n", error, name);
}

void print_error_formated(char *str, ...) {
    va_list argument;
    struct decl *d;
    struct stmt *s;
    struct expr *e;
    struct type *t;
    struct param_list *p;
    error_count++;
    va_start(argument, str);
    for(unsigned int i = 0; str[i] != '\0'; i++) {
        switch(str[i]) {
            case '%':
                switch(str[++i]) {
                    case 'D':
                        d = va_arg(argument, struct decl *);
                        decl_print(d, -1);
                        break;
                    case 'S':
                        s = va_arg(argument, struct stmt *);
                        stmt_print(s, -1);
                        break;
                    case 'E':
                        e = va_arg(argument, struct expr *);
                        expr_print(e);
                        break;
                    case 'T':
                        t = va_arg(argument, struct type *);
                        type_print(t);
                        break;
                    case 'P':
                        p = va_arg(argument, struct param_list *);
                        param_list_print(p);
                        break;
                    case '%':
                        putchar(str[i]);
                        break;
                    default: i--; break;
                }
                break;
            default: putchar(str[i]); break;
        }
    }
    va_end(argument);
}

unsigned int offset;

static void apply_offset(struct symbol *symbol, struct type *type, int number) {
    switch(type->kind) {
        case TYPE_INTEGER: symbol->which = offset += 8 * number; break;
        case TYPE_BOOLEAN: symbol->which = offset += 1 * number; break;
        case TYPE_CHARACTER: symbol->which = offset += 1 * number; break;
        case TYPE_FLOATING_POINT: symbol->which = offset += 8 * number; break;
        case TYPE_ARRAY:
            if(symbol->type->number_of_subtypes != 0) {
                apply_offset(symbol, symbol->type->subtype, symbol->type->number_of_subtypes);
            }
            break;
        case TYPE_POINTER: symbol->which = offset += 8 * number; break;
    }
}

void decl_resolve(struct decl *d) {
    if(d == NULL)return;

    symbol_t kind = scope_level() > 1 ? SYMBOL_LOCAL : SYMBOL_GLOBAL;

    d->symbol = symbol_create(kind, d->type, d->name);

    expr_resolve(d->value);
    if(scope_lookup_current(d->name)) print_error("variable already exists", d->name);
    else {
        if(d->symbol->kind == SYMBOL_LOCAL) {
            apply_offset(d->symbol, d->symbol->type, 1);
        }
        else offset = 0;
        scope_bind(d->symbol);
    }

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

    if(e->kind == EXPR_NAME || e->kind == EXPR_RENAME) {
        if(e->kind == EXPR_RENAME) {
            struct symbol *parent = scope_lookup(e->string_literal);
            if(parent == NULL) goto ERROR;
            e->symbol = symbol_create(parent->kind, parent->type, (char *)e->name);
            e->symbol->which = parent->which;
            e->symbol->parent = parent;
            if(scope_lookup_current(e->name)) 
                print_error("variable already exists", e->name);
            else scope_bind(e->symbol);
        }
        else e->symbol = scope_lookup(e->name);
        if(e->symbol == NULL) {
            ERROR:
            print_error("no declaration found", e->name);
            struct type *temp = type_create(TYPE_INTEGER, 0, 0, 0);
            e->symbol = symbol_create(SYMBOL_LOCAL, temp, NULL);
        }
        if(show_stack_offset) {
            printf("Variable named %s has offset of %d bytes \n", e->name, e->symbol->which);
            printf("Variable named %s: %s \n", e->name, symbol_codegen(e->symbol));
        }
    }
    else {
        expr_resolve(e->left);
        expr_resolve(e->right);
        if(e->kind == EXPR_ADDRESS) e->symbol = e->left->symbol;
    }
}
void param_list_resolve(struct param_list *p) {
    if(p == NULL)return;

    p->symbol = symbol_create(SYMBOL_PARAM, p->type, p->name);
    if(scope_lookup_current(p->name)) print_error("parameter already exists"
                                            " in function", p->name);
    else {
        apply_offset(p->symbol, p->symbol->type, 1);
        scope_bind(p->symbol);
    }

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
        else if(a->kind == TYPE_POINTER) {
            return type_equals(a->subtype, b->subtype);
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
            printf("->"YEL"|");
            decl_print(d, -1);
            printf("| \n"RESET);
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
                print_error_formated(RED"Error "
                    MAG"|type "BLU"%T"MAG" in if-statement|"RESET"->"
                    YEL"|%S|\n"RESET, 
                    t, s);
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
            if(s->expr == NULL)break;
            t = expr_typecheck(s->expr);
            if(!assignment_typecheck(current_function_type, t)) {
                print_error_formated(RED"Error "
                    MAG"|cannot give type "BLU"%T "
                    MAG"to function of type "BLU"%T"
                    MAG"|"RESET"->"
                    YEL"|%S|\n"RESET, 
                    t, current_function_type, s);
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
        case EXPR_INTEGER_LITERAL:
            if(e->integer_value >= 0 && e->integer_value < 2)
                        result = type_create(TYPE_BOOLEAN, 0, 0, 0);
            else if(abs(e->integer_value) < 129)
                        result = type_create(TYPE_CHARACTER, 0, 0, 0);
            else result = type_create(TYPE_INTEGER, 0, 0, 0);
            break;
        case EXPR_FLOATING_POINT_LITERAL: result = type_create(TYPE_FLOATING_POINT, 0, 0, 0); 
                                                break;
        case EXPR_STRING_LITERAL: struct type *temp = type_create(TYPE_CHARACTER, 0, 0, 0);
                                    result = type_create(TYPE_ARRAY, temp, 0, 0); break;
        case EXPR_NAME: result = type_copy(e->symbol->type); break;
        case EXPR_ADD_WITH ... EXPR_DIV_WITH:
        case EXPR_ASSIGN:
            if(!assignment_typecheck(left, right)) {
                print_error_formated(RED"Error "
                    MAG"|cannot assign "BLU"%T "
                    MAG"to "BLU"%T"
                    MAG"|"RESET"->"
                    YEL"|%E;|\n"RESET, 
                    right, left, e);
            }
            result = type_copy(left);
            break;
        case EXPR_ADD ... EXPR_DIV:
            if(e->kind == EXPR_ADD) {
                if(left->kind > TYPE_ARRAY || right->kind > TYPE_ARRAY) {
                    print_error_formated(RED"Error "
                        MAG"|cannot apply binary operator "
                        "between "BLU"%T "
                        MAG"and "BLU"%T"
                        MAG"|"RESET"->"
                        YEL"|%E;|\n"RESET, 
                        left, right, e);
                }
            }
            else if(left->kind >= TYPE_VOID || right->kind >= TYPE_VOID) {
                print_error_formated(RED"Error "
                    MAG"|cannot apply binary operator "
                    "between "BLU"%T "
                    MAG"and "BLU"%T"
                    MAG"|"RESET"->"
                    YEL"|%E;|\n"RESET, 
                    left, right, e);
            }
            result = left->kind > right->kind ? type_copy(left) : type_copy(right);
            break;
        case EXPR_MODULUS:
            if(!(left->kind == right->kind && left->kind == TYPE_INTEGER)) {
                print_error_formated(RED"Error "
                    MAG"|cannot apply binary operator "BLU"("CYN"%%"BLU") "
                    MAG"between "BLU"%T "
                    MAG"and "BLU"%T"
                    MAG"|"RESET"->"
                    YEL"|%E;|\n"RESET, 
                    right, left, e);
            }
            result = type_create(TYPE_INTEGER, 0, 0, 0);
            break;
        case EXPR_AND ... EXPR_NOT:
        case EXPR_EQUAL ... EXPR_LESS_EQUAL:
            if(right == NULL) {
                if(left->kind == TYPE_VOID) {
                    print_error_formated(RED"Error "
                        MAG"|cannot negate "
                        BLU"%T"MAG"|"RESET"->"
                        YEL"|%E;|\n"RESET, 
                        left, e);
                }
            }
            else if(left->kind == TYPE_VOID || right->kind == TYPE_VOID) {
                print_error_formated(RED"Error "
                    MAG"|cannot compare or logic-test "
                    BLU"%T"MAG" and "BLU"%T"MAG"|"RESET"->"
                    YEL"|%E;|\n"RESET, 
                    left, right, e);
            }
            result = type_create(TYPE_BOOLEAN, 0, 0, 0);
            break;
        case EXPR_INCREMENT ... EXPR_DECREMENT:
            temp = left == NULL ? right : left;
            if(temp->kind > TYPE_FLOATING_POINT) {
                print_error_formated(RED"Error "
                    MAG"|cannot incr/decr "
                    BLU"%T"MAG"|"RESET"->"
                    YEL"|%E;|\n"RESET, 
                    temp, e);
            }
            result = type_copy(temp);
            break;
        case EXPR_SUBSCRIPT:
            if(left->kind == TYPE_ARRAY) {
                if(right->kind > TYPE_INTEGER) {
                    print_error_formated(RED"Error "
                        MAG"|array index not an integer|"RESET"->"
                        YEL"|%E;|\n"RESET, e);
                }
                result = type_copy(left->subtype);
            }
            else {
                print_error_formated(RED"Error "
                    MAG"|attempt to subscript a noniterable "
                    BLU"%T"MAG"|"RESET"->"
                    YEL"|%E;|\n"RESET, left, e);
                result = type_copy(left);
            }
            break;
        case EXPR_CALL:
            if(left->kind != TYPE_FUNCTION) {
                print_error_formated(RED"Error "
                    MAG"|attempt to call a nonfunction "
                    BLU"%T"MAG"|"RESET"->"
                    YEL"|%E;|\n"RESET, left, e);
                result = type_copy(left);
            }
            else result = type_copy(left->subtype);
            if(!param_list_typecheck(left->params, e->right)) {
                print_error_formated(RED"Error "
                    MAG"|inappropriate arguments to function-<<"
                    BLU"%T"MAG">> call|"RESET"->"
                    YEL"|%E;|\n"RESET, left, e);
            }
            break;
        case EXPR_ARG:
            if(!right) {
                if(left->kind == TYPE_ARRAY) {
                    result = left->subtype->kind == TYPE_CHARACTER
                    ? type_create(TYPE_ARRAY, type_copy(left->subtype), NULL, 0)
                    : type_create(TYPE_ARRAY, type_copy(left), NULL, 0);
                }
                else result = type_create(TYPE_ARRAY, type_copy(left), NULL, 0);
            }
            else result = left->kind > right->kind 
                ? type_create(TYPE_ARRAY, type_copy(left->subtype), NULL, 0) 
                : type_create(TYPE_ARRAY, type_copy(right->subtype), NULL, 0);
            break;
        case EXPR_RENAME:
            result = type_copy(e->symbol->type);
            break;
        case EXPR_DEREFERENCE:
            result = type_copy(left->subtype);
            break;
        case EXPR_ADDRESS:
            result = type_create(TYPE_POINTER, type_copy(left), 0, 0);
            break;
    }

    type_delete(left);
    type_delete(right);

    e->type = type_copy(result);

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
    else if(left->kind == TYPE_POINTER && right->kind == TYPE_POINTER) {
        return assignment_typecheck(left->subtype, right->subtype);
    }
    return 0;
}

// Generating IR / Assembly instructions

#define NUMBER_OF_SCRATCH_REGISTERS 7

unsigned short scratch_registers[NUMBER_OF_SCRATCH_REGISTERS];

unsigned short scratch_alloc() {
    for(unsigned int i = 0; i < NUMBER_OF_SCRATCH_REGISTERS; i++) {
        if(scratch_registers[i] == 0) {
            scratch_registers[i] = 1;
            return i;
        }
    }
    print_error_formated(RED"Error: "YEL"Codegen "MAG"|out of scratch registers|\n"RESET);
    return -1;
}
void scratch_free(int r) {
    if(r < 0)return;
    scratch_registers[r] = 0;
}
const char *scratch_name(int r) {
    char *name = (char *)malloc(5 * sizeof(char));
    switch(r) {
        case 0: strcpy(name, "%rbx"); break;
        case 1: strcpy(name, "%r10"); break;
        case 2: strcpy(name, "%r11"); break;
        case 3: strcpy(name, "%r12"); break;
        case 4: strcpy(name, "%r13"); break;
        case 5: strcpy(name, "%r14"); break;
        case 6: strcpy(name, "%r15"); break;
    }

    return name;
}

unsigned int label_create() {
    static unsigned int label;
    return label++;
}
const char *label_name(unsigned int label) {
    unsigned int size = 2;
    char *name = (char *)calloc(size, sizeof(char));
    name[0] = '.'; name[1] = 'L';

    unsigned int i = 1, temp = label;
    while(temp > 9) {
        temp /= 10;
        i *= 10;
    }
    while(i) {
        size++;
        name = (char *)realloc(name, size * sizeof(char));
        name[size-1] = '0' + (label / i);
        label %= i;
        i /= 10;
    }
    return name;
}

const char *symbol_codegen(struct symbol *s) {
    char *name = NULL;
    if(s->kind == SYMBOL_GLOBAL) {
        name = (char *)calloc(strlen(s->name), sizeof(char));
        strcpy(name, s->name);
        return name;
    }
    else {
        name = (char *)calloc(1, sizeof(char));
        name[0] = '-';
        unsigned int which = s->which;
        unsigned int i = 1, temp = which, size = 1;
        while(temp > 9) {
            temp /= 10;
            i *= 10;
        }
        while(i) {
            size++;
            name = (char *)realloc(name, size * sizeof(char));
            name[size-1] = '0' + (which / i);
            which %= i;
            i /= 10;
        }
        size += 7;
        name = (char *)realloc(name, size * sizeof(char));
        strcat(name, "(%rbp)");
        return name;
    }
}

extern FILE *result_file;

static char *argr_name(unsigned int arg) {
    char *name = (char *)calloc(5, sizeof(char));
    switch(arg) {
        case 0: strcpy(name, "%rdi"); break;
        case 1: strcpy(name, "%rsi"); break;
        case 2: strcpy(name, "%rdx"); break;
        case 3: strcpy(name, "%rcx"); break;
        case 4: strcpy(name, "%r8"); break;
        case 5: strcpy(name, "%r9"); break;
        default: free(name); name = NULL; break;
    }
    return name;
}
unsigned int alignment;
static void params_push(struct param_list *p, unsigned int arg) {
    if(p) {
        alignment++;
        fprintf(result_file, "PUSHQ %s\n", argr_name(arg));
        params_push(p->next, arg+1);
    }
}

static unsigned int local_var_count(struct stmt *s) {
    unsigned int result = 0;
    if(s) {
        if(s->decl) {
            result++;
        }
        result += local_var_count(s->next);
    }
    return result;
}

static void push_pop_callee_saved_regs(unsigned short action) {
    if(!action) {
        fprintf(result_file, "PUSHQ %%rbx\n");
        fprintf(result_file, "PUSHQ %%r12\n");
        fprintf(result_file, "PUSHQ %%r13\n");
        fprintf(result_file, "PUSHQ %%r14\n");
        fprintf(result_file, "PUSHQ %%r15\n");
    }
    else {
        fprintf(result_file, "POPQ %%r15\n");
        fprintf(result_file, "POPQ %%r14\n");
        fprintf(result_file, "POPQ %%r13\n");
        fprintf(result_file, "POPQ %%r12\n");
        fprintf(result_file, "POPQ %%rbx\n");
    }
}

void decl_codegen(struct decl *d) {
    if(d == NULL)return;

    if(d->code) {
        alignment = 0;
        fprintf(result_file, ".text\n");
        fprintf(result_file, ".global %s\n", d->name);
        fprintf(result_file, "%s:\n", d->name);
        fprintf(result_file, "PUSHQ %%rbp\n");
        fprintf(result_file, "MOVQ %%rsp, %%rbp\n");
        params_push(d->type->params, 0);
        unsigned int number_of_vars = local_var_count(d->code);
        alignment += number_of_vars;
        while((8 * alignment) % 16 != 0) {
            number_of_vars++;
            alignment += number_of_vars;
        }
        fprintf(result_file, "SUB $%u, %%rsp\n", number_of_vars * 8);
        push_pop_callee_saved_regs(0);
        stmt_codegen(d->code, d->name);
        fprintf(result_file, ".%s_epilogue:\n", d->name);
        push_pop_callee_saved_regs(1);
        fprintf(result_file, "MOVQ %%rbp, %%rsp\n");
        fprintf(result_file, "POPQ %%rbp\n");
        fprintf(result_file, "RET\n");
    }
    else {
        if(d->symbol->kind == SYMBOL_GLOBAL) {
            fprintf(result_file, ".data\n");
            fprintf(result_file, "%s: .quad ", d->name);
            if(d->value) {
                fprintf(result_file, "%d\n", d->value->integer_value);
            }
            else {
                fprintf(result_file, "0\n");
            }
        }
        else {
            expr_codegen(d->value);
            if(d->value->reg != -1) {
                fprintf(result_file, "MOV %s, %s\n", 
                            scratch_name(d->value->reg), 
                            symbol_codegen(d->symbol));
            }
        }
    }

    decl_codegen(d->next);
}
void stmt_codegen(struct stmt *s, const char *function_name) {
    if(s == NULL)return;

    switch(s->kind) {
        case STMT_DECL:
            decl_codegen(s->decl);
            break;
        case STMT_EXPR:
            expr_codegen(s->expr);
            scratch_free(s->expr->reg);
            break;
        case STMT_IF_ELSE:
        {
            int else_label = label_create();
            int done_label = label_create();
            expr_codegen(s->expr);
            fprintf(result_file, "CMP $0, %s\n", scratch_name(s->expr->reg));
            scratch_free(s->expr->reg);
            fprintf(result_file, "JE %s\n", label_name(else_label));
            stmt_codegen(s->body, function_name);
            fprintf(result_file, "JMP %s\n", label_name(done_label));
            fprintf(result_file, "%s:\n", label_name(else_label));
            stmt_codegen(s->else_body, function_name);
            fprintf(result_file, "%s:\n", label_name(done_label));
            break;
        }
        case STMT_FOR:
        {
            int top_label = label_create();
            int done_label = label_create();
            expr_codegen(s->init_expr);
            scratch_free(s->init_expr->reg);
            fprintf(result_file, "%s:\n", label_name(top_label));
            expr_codegen(s->expr);
            if(s->expr->reg != -1) {
                fprintf(result_file, "CMP $0, %s\n", scratch_name(s->expr->reg));
                scratch_free(s->expr->reg);
                fprintf(result_file, "JE %s\n", label_name(done_label));
            }
            stmt_codegen(s->body, function_name);
            expr_codegen(s->next_expr);
            scratch_free(s->next_expr->reg);
            fprintf(result_file, "JMP %s\n", label_name(top_label));
            fprintf(result_file, "%s:\n", label_name(done_label));
            break;
        }
        case STMT_GIVE:
            expr_codegen(s->expr);
            fprintf(result_file, "MOV %s, %%rax\n", scratch_name(s->expr->reg));
            if(s->print) {
                int string_label = label_create();
                fprintf(result_file, "MOV %%rax, %%rsi\n");
                fprintf(result_file, "%s: .string \"%%d\\n\"\n", label_name(string_label));
                fprintf(result_file, "MOV $%s, %%rdi\n", label_name(string_label));
                fprintf(result_file, "PUSHQ %%rax\n");
                fprintf(result_file, "PUSHQ %%rcx\n");
                fprintf(result_file, "PUSHQ %%r10\n");
                fprintf(result_file, "PUSHQ %%r11\n");
                fprintf(result_file, "XOR %%rax, %%rax\n");
                fprintf(result_file, "CALL printf\n");
                fprintf(result_file, "PUSHQ %%r11\n");
                fprintf(result_file, "PUSHQ %%r10\n");
                fprintf(result_file, "POPQ %%rcx\n");
                fprintf(result_file, "POPQ %%rax\n");
            }
            fprintf(result_file, "JMP .%s_epilogue\n", function_name);
            scratch_free(s->expr->reg);
            break;
        case STMT_BLOCK:
            stmt_codegen(s->body, function_name);
            break;
    }

    stmt_codegen(s->next, function_name);
}
void expr_codegen(struct expr *e) {
    if(e == NULL) {
        e->reg = -1;
        return;
    }

    switch(e->kind) {
        case EXPR_INTEGER_LITERAL:
            e->reg = scratch_alloc();
            fprintf(result_file, "MOV $%d, %s\n", e->integer_value, scratch_name(e->reg));
            break;
        case EXPR_NAME:
            e->reg = scratch_alloc();
            fprintf(result_file, "MOV %s, %s\n", 
                        symbol_codegen(e->symbol), 
                        scratch_name(e->reg));
            break;
        case EXPR_ADD:
            expr_codegen(e->left);
            expr_codegen(e->right);
            if(e->type->kind < TYPE_FLOATING_POINT) {
                fprintf(result_file, "ADD %s, %s\n", 
                            scratch_name(e->left->reg), 
                            scratch_name(e->right->reg));
            }
            else {

            }
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_SUB:
            expr_codegen(e->left);
            expr_codegen(e->right);
            if(e->type->kind < TYPE_FLOATING_POINT) {
                fprintf(result_file, "SUB %s, %s\n", 
                            scratch_name(e->right->reg), 
                            scratch_name(e->left->reg));
            }
            else {

            }
            e->reg = e->left->reg;
            scratch_free(e->right->reg);
            break;
        case EXPR_MUL:
            expr_codegen(e->left);
            expr_codegen(e->right);
            if(e->type->kind < TYPE_FLOATING_POINT) {
                fprintf(result_file, "MOV %s, %%rax\n", scratch_name(e->left->reg));
                fprintf(result_file, "IMUL %s\n", scratch_name(e->right->reg));
                fprintf(result_file, "MOV %%rax, %s\n", scratch_name(e->right->reg));
            }
            else {

            }
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_DIV:
            expr_codegen(e->left);
            expr_codegen(e->right);
            if(e->type->kind < TYPE_FLOATING_POINT) {
                fprintf(result_file, "MOV %s, %%rax\nCQO\n", scratch_name(e->left->reg));
                fprintf(result_file, "IDIV %s\n", scratch_name(e->right->reg));
                fprintf(result_file, "MOV %%rax, %s\n", scratch_name(e->right->reg));
            }
            else {

            }
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_EQUAL ... EXPR_LESS_EQUAL:
            int true_label = label_create();
            int done_label = label_create();
            expr_codegen(e->left);
            expr_codegen(e->right);
            fprintf(result_file, "CMP %s, %s\n", 
                        scratch_name(e->right->reg), 
                        scratch_name(e->left->reg));
            switch(e->kind) {
                case EXPR_EQUAL:
                    fprintf(result_file, "JE %s\n", label_name(true_label));
                    fprintf(result_file, "MOV $0, %s\n", scratch_name(e->right->reg));
                    fprintf(result_file, "JMP %s\n", label_name(done_label));
                    break;
                case EXPR_NOT_EQUAL:
                    fprintf(result_file, "JNE %s\n", label_name(true_label));
                    fprintf(result_file, "MOV $0, %s\n", scratch_name(e->right->reg));
                    fprintf(result_file, "JMP %s\n", label_name(done_label));
                    break;
                case EXPR_GREATER:
                    fprintf(result_file, "JG %s\n", label_name(true_label));
                    fprintf(result_file, "MOV $0, %s\n", scratch_name(e->right->reg));
                    fprintf(result_file, "JMP %s\n", label_name(done_label));
                    break;
                case EXPR_GREATER_EQUAL:
                    fprintf(result_file, "JGE %s\n", label_name(true_label));
                    fprintf(result_file, "MOV $0, %s\n", scratch_name(e->right->reg));
                    fprintf(result_file, "JMP %s\n", label_name(done_label));
                    break;
                case EXPR_LESS:
                    fprintf(result_file, "JL %s\n", label_name(true_label));
                    fprintf(result_file, "MOV $0, %s\n", scratch_name(e->right->reg));
                    fprintf(result_file, "JMP %s\n", label_name(done_label));
                    break;
                case EXPR_LESS_EQUAL:
                    fprintf(result_file, "JLE %s\n", label_name(true_label));
                    fprintf(result_file, "MOV $0, %s\n", scratch_name(e->right->reg));
                    fprintf(result_file, "JMP %s\n", label_name(done_label));
                    break;
            }
            fprintf(result_file, "%s:\n", label_name(true_label));
            fprintf(result_file, "MOV $1, %s\n", scratch_name(e->right->reg));
            fprintf(result_file, "%s:\n", label_name(done_label));
            scratch_free(e->left->reg);
            e->reg = e->right->reg;
            break;
        case EXPR_ASSIGN:
            expr_codegen(e->right);
            fprintf(result_file, "MOV %s, %s\n",
                        scratch_name(e->right->reg), 
                        symbol_codegen(e->left->symbol));
            e->reg = e->right->reg;
            break;
        case EXPR_CALL:
            expr_arggen(e->right, 0);
            fprintf(result_file, "PUSHQ %%r10\n");
            fprintf(result_file, "PUSHQ %%r11\n");
            fprintf(result_file, "CALL %s\n", e->left->name);
            e->reg = scratch_alloc();
            fprintf(result_file, "POPQ %%r11\n");
            fprintf(result_file, "POPQ %%r10\n");
            fprintf(result_file, "MOV %%rax, %s\n", scratch_name(e->reg));
            break;
    }
}

void expr_arggen(struct expr *e, unsigned int arg) {
    if(e == NULL)return;

    expr_arggen(e->right, arg+1);

    expr_codegen(e->left);
    char *name = argr_name(arg);
    if(name) {
        fprintf(result_file, "MOV %s, %s\n", 
                    scratch_name(e->left->reg), 
                    name);
        free(name);
    }
    else {
        fprintf(result_file, "PUSHQ %s\n", scratch_name(e->left->reg));
    }
    scratch_free(e->left->reg);
}