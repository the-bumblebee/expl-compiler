%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "exprtree.h"

	void yyerror(char const *s);

	int decl_flag = 0;
	int class_flag = 0;
	int line_no = 1;

%}

%%

"begin"			{return BEGINI;}
"end"			{return END;}
"read"			{return READI;}
"write"			{return WRITEI;}
"if"			{return IF;}
"else"			{return Else;}
"then"			{return then;}
"endif"			{return ENDIF;}
"while"			{return WHILE;}
"do"			{return DO;}
"endwhile"		{return ENDWHILE;}
"break"			{return BREAK;}
"continue"		{return CONTINUE;}
"decl"			{decl_flag = 1; return DECL;}
"enddecl"		{decl_flag = 0; return ENDDECL;}
"type"			{return TYPE;}
"endtype"		{return ENDTYPE;}
"class"			{class_flag = 1; return CLASS;}
"endclass"		{class_flag = 0; return ENDCLASS;}
"self"			{return SELF;}
"int"			{return INT;}
"str"			{return STR;}
"main"			{return MAIN;}
"return"		{return RETURN;}
"alloc"			{return ALLOC;}
"free"			{return FREE;}
"null"			{return NULLV;}
"new"			{return NEW;}
"delete"		{return DELETE;}
"initialize"	{return INITIALIZE;}
"extends"		{return EXTENDS;}
";"				{return COL;}
\"[^"]+\"			{
					yylval.literal = strdup(yytext);
					return STRLIT;
				}

[0-9]+			{
					yylval.number = atoi(yytext);
					return NUM;
				}

[a-zA-Z][_0-9a-zA-Z]*		{
								yylval.name = strdup(yytext);
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
[(),\[\]{}"."]	{return *yytext;}
[\n]	{line_no++;}
.		{yyerror("unknown character."); printf("%s", yytext);exit(1);}

%%

int yywrap(void) {
	return 1;
}
