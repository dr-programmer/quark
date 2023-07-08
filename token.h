#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    TOKEN_EOF = 0,
    TOKEN_ADD,
    TOKEN_IDENT,
    TOKEN_EQUAL,
    TOKEN_ASSIGN,
    TOKEN_ERROR
} Token;

#endif