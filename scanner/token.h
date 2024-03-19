#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    TOKEN_EOF = 0,
    TOKEN_INCLUDE,
    TOKEN_ADD,
    TOKEN_SUBTRACT,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_IDENT,
    TOKEN_EQUAL,
    TOKEN_NOTEQUAL,
    TOKEN_NOT,
    TOKEN_ASSIGN,
    TOKEN_SQBROPEN,
    TOKEN_SQBRCLOSE,
    TOKEN_BROPEN,
    TOKEN_BRCLOSE,
    TOKEN_CRBROPEN,
    TOKEN_CRBRCLOSE,
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_GIVE,
    TOKEN_STRING,
    TOKEN_END,
    TOKEN_COMMA,
    TOKEN_ALLOCATE,
    TOKEN_ERROR
} TokenT;

#endif