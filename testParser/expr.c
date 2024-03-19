#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "expr.h"
#include "colors.h"

#define PI 3.1415926535

static void error_evaluate(char *s) {
    printf(RED "Error" RESET MAG" |%s|"RESET" \n", s);
}

struct expr * expr_create(expr_t kind, 
                            struct expr *left, 
                            struct expr *right) 
{
    struct expr *e = (struct expr *)malloc(sizeof(struct expr));
    e->kind = kind;
    e->value = 0;
    e->left = left;
    e->right = right;
    return e;
}

struct expr * expr_create_value(float value) {
    struct expr *e = expr_create(EXPR_VALUE, NULL, NULL);
    e->value = value;
    return e;
}

struct expr * expr_create_ident(char *ident) {
    struct expr *e = expr_create(EXPR_IDENT, NULL, NULL);
    e->literal = ident;
    return e;
}

float expr_evaluate(struct expr *e) {
    if (e == NULL) return 0;

    float left = expr_evaluate(e->left);
    float right = expr_evaluate(e->right);

    switch(e->kind) {
        case EXPR_VALUE: return e->value;
        case EXPR_ADD: return left + right;
        case EXPR_SUBTRACT: return left - right;
        case EXPR_MULTIPLY: return left * right;
        case EXPR_DIVIDE: 
            if (right == 0) {
                error_evaluate("division by zero");
                exit(1);
            }
            return left / right;
        case EXPR_FUNC: 
            if (!strcmp(e->left->literal, "sin")){
                return sin(right*PI/180);
            }
            else if (!strcmp(e->left->literal, "cos")) {
                return cos(right*PI/180);
            }
            else if (!strcmp(e->left->literal, "sqrt")) return sqrt(right);
            else {
                char error[] = "Undefined function \'";
                strcat(error, e->left->literal);
                strcat(error, "\'");
                error_evaluate(error);
                exit(2);
            }
    }
}

void expr_print(struct expr *e) {
    if (e == NULL) return;

    if(e->kind == EXPR_ADD || e->kind == EXPR_SUBTRACT)printf("(");
    expr_print(e->left);

    switch(e->kind) {
        case EXPR_VALUE: printf("%.2f", e->value); break;
        case EXPR_ADD: printf("+"); break;
        case EXPR_SUBTRACT: printf("-"); break;
        case EXPR_MULTIPLY: printf("*"); break;
        case EXPR_DIVIDE: printf("/"); break;
        case EXPR_FUNC: 
            if(!strcmp(e->left->literal, "sin"))printf("sin(");
            else if(!strcmp(e->left->literal, "cos"))printf("cos(");
            else if(!strcmp(e->left->literal, "sqrt"))printf("sqrt(");
            break;
    }

    expr_print(e->right);
    if(e->kind == EXPR_ADD || e->kind == EXPR_SUBTRACT || e->kind == EXPR_FUNC)printf(")");
}

void free_ast(struct expr *e) {
    if (e == NULL) return;

    if(e->kind == EXPR_IDENT)free(e->literal);

    if(e->left == NULL && e->right == NULL){
        free(e);
        return;
    }
    free_ast(e->left);
    free_ast(e->right);
}