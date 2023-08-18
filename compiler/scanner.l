%{
#include "token.h"

int line = 1;
%}

DIGITS [0-9]
LETTERS [a-zA-Z]

%x multiline_comment

%%

(" "|\t)
"\n"        {line++;}
\^          {return TOKEN_ALLOCATE;}
\-\>        {return TOKEN_SUBSCRIPT;}
\+{2}       {return TOKEN_INCREMENT;}
-{2}        {return TOKEN_DECREMENT;}
\+=         {return TOKEN_ADD_WITH;}
-=          {return TOKEN_SUB_WITH;}
\*=         {return TOKEN_MUL_WITH;}
\/=         {return TOKEN_DIV_WITH;}
\+          {return TOKEN_PLUS;}
\-          {return TOKEN_MINUS;}
\*          {return TOKEN_MUL;}
\/          {return TOKEN_DIV;}
\%          {return TOKEN_MODULUS;}
!=          {return TOKEN_NOT_EQUAL;}
!           {return TOKEN_NOT;}
\&\&        {return TOKEN_AND;}
\|\|        {return TOKEN_OR;}
\<\?        {BEGIN(multiline_comment);}
<multiline_comment>[^\?]*
<multiline_comment>\?+[^\?\>]*
<multiline_comment>\?\>     {BEGIN(INITIAL);}
\?\?.*"\n"
\?          {return TOKEN_UNKNOWN;}
==          {return TOKEN_EQUAL;}
=           {return TOKEN_ASSIGN;}
>=          {return TOKEN_GREATER_EQUAL;}
>           {return TOKEN_GREATER;}
"<"=        {return TOKEN_LESS_EQUAL;}
"<"         {return TOKEN_LESS;}
=">"        {return TOKEN_PRINT_IN;}
stdin       {return TOKEN_STDIN;}
give        {return TOKEN_GIVE;}
up          {return TOKEN_UP;}
if          {return TOKEN_IF;}
else        {return TOKEN_ELSE;}
while       {return TOKEN_WHILE;}
for         {return TOKEN_FOR;}
do          {return TOKEN_DO;}
char        {return TOKEN_CHAR;}
int         {return TOKEN_INT;}
float       {return TOKEN_FLOAT;}
bool        {return TOKEN_BOOL;}
void        {return TOKEN_VOID;}
true        {return TOKEN_TRUE;}
false       {return TOKEN_FALSE;}
{DIGITS}+\.{DIGITS}+   {return TOKEN_FLOATING_POINT_LITERAL;}
{DIGITS}+   {return TOKEN_INTEGER_LITERAL;}
({LETTERS}|_)({LETTERS}|{DIGITS}|_)*  {return TOKEN_IDENT;}
\".*\"      {return TOKEN_STRING_LITERAL;}
\'.\'       {return TOKEN_CHAR_LITERAL;}
\(          {return TOKEN_LPAREN;}
\)          {return TOKEN_RPAREN;}
\{          {return TOKEN_LCRBR;}
\}          {return TOKEN_RCRBR;}
\[          {return TOKEN_LSQBR;}
\]          {return TOKEN_RSQBR;}
,           {return TOKEN_COMMA;}
:           {return TOKEN_COLON;}
;           {return TOKEN_SEMI;}
.           {return TOKEN_ERROR;}

%%

int yywrap() {return 1;}