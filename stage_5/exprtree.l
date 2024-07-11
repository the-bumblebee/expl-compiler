%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "exprtree.h"

	void yyerror(char const *s);

	int decl_flag = 0;

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
"decl"		{decl_flag = 1; return DECL;}
"enddecl"	{decl_flag = 0; return ENDDECL;}
"int"		{return INT;}
"str"		{return STR;}
"main"		{return MAIN;}
"return"	{return RETURN;}
";"			{return COL;}
\".+\"		{
				yylval.literal = strdup(yytext);
				return STRLIT;
			}

[0-9]+	{
			yylval.number = atoi(yytext);
			return NUM;
		}

[a-zA-Z][0-9a-zA-Z]*		{
								yylval.varname = strdup(yytext);
								return ID;
							}

"=" 	{return EQUAL;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
"%"		{return MOD;}
"<"		{return LT;}
">"		{return GT;}
"<="	{return LE;}
">="	{return GE;}
"!="	{return NE;}
"=="	{return EQ;}
[ \t]	{}
[(),\[\]{}]	{return *yytext;}
.		{yyerror("unknown character."); printf("%s", yytext);exit(1);}

%%

int yywrap(void) {
	return 1;
}
