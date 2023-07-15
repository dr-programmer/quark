#ifndef STRUCTURES_H
#define STRUCTURES_H

struct decl {
    char *name;
    struct type *type;
    struct expr *value;
    struct stmt *code;
    struct decl *next;
};

struct stmt {
    stmt_t kind;
    struct decl *decl;
    struct expr *init_expr;
    struct expr *expr;
    struct expr *next_expr;
    struct stmt *body;
    struct stmt *else_body;
    struct stmt *next;
};

typedef enum {
    STMT_DECL,
    STMT_EXPR,
    STMT_IF_ELSE,
    STMT_FOR,
    STMT_PRINT,
    STMT_RETURN,
    STMT_BLOCK
} stmt_t;

struct expr {
    expr_t kind;
    struct expr *left;
    struct expr *right;

    const char *name;
    int integer_value;
    float floating_point_value;
    const char *string_literal;
};

typedef enum {
    EXPR_NOT,
    EXPR_CALL,
    EXPR_SUBSCRIPT,

    EXPR_ADD,
    EXPR_SUB,
    EXPR_MUL,
    EXPR_DIV,
    EXPR_ASSIGN,
    EXPR_EQUAL,
    EXPR_NOT_EQUAL,
    EXPR_GREATER,
    EXPR_GREATER_EQUAL,
    EXPR_LESS,
    EXPR_LESS_EQUAL,
    EXPR_INCREMENT,
    EXPR_DECREMENT,
    EXPR_ADD_WITH,
    EXPR_SUB_WITH,
    EXPR_MUL_WITH,
    EXPR_DIV_WITH,

    EXPR_NAME,
    EXPR_INTEGER_LITERAL,
    EXPR_FLOATING_POINT_LITERAL,
    EXPR_STRING_LITERAL
} expr_t;

struct decl *decl_create(char *name, 
                            struct type *type, 
                            struct expr *value, 
                            struct stmt *code, 
                            struct decl *next);

struct stmt *stmt_create(stmt_t kind, 
    struct decl *decl, struct expr *init_expr, 
    struct expr *expr, struct expr *next_expr, 
    struct stmt *body, struct stmt *else_body, 
    struct stmt *next);

struct expr *expr_create(expr_t kind, 
                            struct expr *left,
                            struct expr *right);

struct expr *expr_create_name(const char *name);
struct expr *expr_create_integer_literal(int i);
struct expr *expr_create_boolean_literal(int i);
struct expr *expr_create_char_literal(int i);
struct expr *expr_create_foating_point_literal(float f);
struct expr *expr_create_string_literal(const char *string);

#endif