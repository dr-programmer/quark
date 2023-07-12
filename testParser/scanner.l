%{
#include "token.h"

int line = 1;
%}

DIGITS [0-9]

%%

(" "|\t)
"\n"        {line++;}
\+          {return TOKEN_PLUS;}
\-          {return TOKEN_MINUS;}
\*          {return TOKEN_MUL;}
\/          {return TOKEN_DIV;}
{DIGITS}+   {return TOKEN_INT;}
{DIGITS}+\.{DIGITS}+    {return TOKEN_FLOAT;}
\(          {return TOKEN_LPAREN;}
\)          {return TOKEN_RPAREN;}
;           {return TOKEN_SEMI;}
.           {return TOKEN_ERROR;}

%%

int yywrap() {return 1;}