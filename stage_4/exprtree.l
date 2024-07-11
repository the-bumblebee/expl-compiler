%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "exprtree.h"
	int number;
	char* var_name;
	int var_size;

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
";"			{return COL;}
\".+\"		{
				//char *p;
				//p = strdup(yytext + 1);		//Stripping first " character
				//p[yyleng - 2] = 0;			//Stripping last " character
				yylval.no = makeStringNode(yytext);
				//free(p);
				return STRLIT;
			}

[0-9]+	{
			number = atoi(yytext);
			if (decl_flag == 0)
				yylval.no = createTree(number, inttype, NULL, none, NULL, NULL);
			else if (decl_flag == 1)
				var_size = number;
			return NUM;
		}

[a-zA-Z][0-9a-zA-Z]*		{
						if(decl_flag == 0) {
							//none is passed but the correct type will be assigned inside createTree.
							var_name = strdup(yytext);
							yylval.no = createTree(0, none, yytext, none, NULL, NULL);
							return ID;
						}
						else if(decl_flag == 1) {
							var_name = strdup(yytext);
							return IDdecl;
						}
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
[(),\[\]]	{return *yytext;}
.		{yyerror("unknown character");exit(1);}

%%

int yywrap(void) {
	return 1;
}
