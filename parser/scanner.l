%{
#include "token.h"

int line = 1;
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
{DIGITS}+\.{DIGITS}+   {return TOKEN_FLOATING_POINT_LITERAL;}
{DIGITS}+   {return TOKEN_INTEGER_LITERAL;}
{LETTERS}+  {return TOKEN_IDENT;}
\(          {return TOKEN_LPAREN;}
\)          {return TOKEN_RPAREN;}
;           {return TOKEN_SEMI;}
.           {return TOKEN_ERROR;}

%%

int yywrap() {return 1;}