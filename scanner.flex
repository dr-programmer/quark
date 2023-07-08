%{
#include "token.h"
%}
DIGITS [0-9]
LETTERS [a-zA-Z]
%%
(" "|\n|\t)
\+          {return TOKEN_ADD;}
{LETTERS}+  {return TOKEN_IDENT;}
==          {return TOKEN_EQUAL;}
=           {return TOKEN_ASSIGN;}
.           {return TOKEN_ERROR;}
%%
int yywrap() {return 1;}