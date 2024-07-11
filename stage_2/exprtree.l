%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "exprtree.h"

	int number;
	char var_name;

%}

%%

"begin"	{return BEGINI;}
"end"	{return END;}
"read"	{return READI;}
"write"	{return WRITEI;}
[a-z]	{var_name = yytext[0]; yylval.no = makeVarNode(var_name); return ID;}

[0-9]+	{number = atoi(yytext); yylval.no = makeLeafNode(number); return NUM;}
"=" {return EQUAL;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
[ \t]	{}
[()]	{return *yytext;}
.	{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}
