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
"if"	{return IF;}
"else"	{return Else;}
"then"	{return then;}
"endif"	{return ENDIF;}
"while"	{return WHILE;}
"do"	{return DO;}
"endwhile"	{return ENDWHILE;}
"break"		{return BREAK;}
"continue"	{return CONTINUE;}
";"			{return COL;}

[a-z]	{/*var_name = yytext;*/ yylval.no = createTree(0, inttype, yytext, none, NULL, NULL); return ID;}

[0-9]+	{
			number = atoi(yytext);
			yylval.no = createTree(number, inttype, NULL, none, NULL, NULL);
			return NUM;
		}
"=" 	{return EQUAL;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
"<"		{return LT;}
">"		{return GT;}
"<="	{return LE;}
">="	{return GE;}
"!="	{return NE;}
"=="	{return EQ;}
[ \t]	{}
[()]	{return *yytext;}
.		{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}
