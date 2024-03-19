%{
#include "token.h"

void stringClean();

int line = 0;
%}
DIGITS [0-9]
LETTERS [a-zA-Z]
%%
(" "|\t)
(\n)        {line++;}
give        {return TOKEN_GIVE;}
include     {return TOKEN_INCLUDE;}
\+          {return TOKEN_ADD;}
\-          {return TOKEN_SUBTRACT;}
\*          {return TOKEN_MULTIPLY;}
\/          {return TOKEN_DIVIDE;}
\[          {return TOKEN_SQBROPEN;}
\]          {return TOKEN_SQBRCLOSE;}
\(          {return TOKEN_BROPEN;}
\)          {return TOKEN_BRCLOSE;}
\{          {return TOKEN_CRBROPEN;}
\}          {return TOKEN_CRBRCLOSE;}
\^          {return TOKEN_ALLOCATE;}
\".*\"      {stringClean(); return TOKEN_STRING;}
{LETTERS}+  {return TOKEN_IDENT;}
{DIGITS}+\.{DIGITS}+    {return TOKEN_FLOAT;}
{DIGITS}+   {return TOKEN_INT;}
;           {return TOKEN_END;}
,           {return TOKEN_COMMA;}
==          {return TOKEN_EQUAL;}
!=          {return TOKEN_NOTEQUAL;}
!           {return TOKEN_NOT;}
=           {return TOKEN_ASSIGN;}
.           {return TOKEN_ERROR;}
%%
int yywrap() {return 1;}
void stringClean() {
    yytext++;
    for(int i = 0; yytext[i] != '\0'; i++) {
        if(yytext[i] == '"') {
            yytext[i] = '\0';
            break;
        }
    }
}