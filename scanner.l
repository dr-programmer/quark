%{
#include "token.h"

void literalClean();
%}
DIGITS [0-9]
LETTERS [a-zA-Z]
%%
(" "|\n|\t)
give        {return TOKEN_GIVE;}
\+          {return TOKEN_ADD;}
\[          {return TOKEN_SQBROPEN;}
\]          {return TOKEN_SQBRCLOSE;}
\(          {return TOKEN_BROPEN;}
\)          {return TOKEN_BRCLOSE;}
\{          {return TOKEN_CRBROPEN;}
\}          {return TOKEN_CRBRCLOSE;}
\".*\"      {literalClean(); return TOKEN_LITERAL;}
{LETTERS}+  {return TOKEN_IDENT;}
{DIGITS}+\.{DIGITS}+    {return TOKEN_FLOAT;}
{DIGITS}+   {return TOKEN_INT;}
;           {return TOKEN_END;}
,           {return TOKEN_COMMA;}
==          {return TOKEN_EQUAL;}
!=          {return TOKEN_NOTEQUAL;}
=           {return TOKEN_ASSIGN;}
.           {return TOKEN_ERROR;}
%%
int yywrap() {return 1;}
void literalClean() {
    yytext++;
    for(int i = 0; yytext[i] != '\0'; i++) {
        if(yytext[i] == '"') {
            yytext[i] = '\0';
            break;
        }
    }
}