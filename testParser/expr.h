#ifndef EXPR_H
#define EXPR_H

typedef enum {
    EXPR_ADD,
    EXPR_SUBTRACT,
    EXPR_DIVIDE,
    EXPR_MULTIPLY,
    EXPR_VALUE,
    EXPR_FUNC,
    EXPR_IDENT
} expr_t;

struct expr {
    expr_t kind;
    struct expr *left;
    struct expr *right;
    float value;
    char *literal;
};

#endif