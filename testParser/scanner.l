%{
#include <stdlib.h>
#include <string.h>
#include "token.h"

int line = 1;
char *currentIdent;
%}

DIGITS [0-9]
LETTERS [a-zA-Z]

%%

(" "|\t)
"\n"        {line++;}
\+          {return TOKEN_PLUS;}
\-          {return TOKEN_MINUS;}
\*          {return TOKEN_MUL;}
\/          {return TOKEN_DIV;}
({DIGITS}+\.{DIGITS}+|{DIGITS}+)    {return TOKEN_NUMBER;}
{LETTERS}+  {currentIdent = (char *)malloc(strlen(yytext) * sizeof(char)); 
                strcpy(currentIdent, yytext);
                return TOKEN_IDENT;}
\(          {return TOKEN_LPAREN;}
\)          {return TOKEN_RPAREN;}
;           {return TOKEN_SEMI;}
.           {return TOKEN_ERROR;}

%%

int yywrap() {return 1;}