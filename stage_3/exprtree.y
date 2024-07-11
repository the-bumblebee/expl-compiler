%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "exprtree.h"
	#include "exprtree.c"
	#include "reglib.h"

	int yylex(void);
	FILE *target_file, *yyin;

	#include "reglib.c"
%}

%union{
	struct tnode *no;

}
%type <no> expr NUM program Slist Stmt AsgStmt InputStmt OutputStmt ID Ifstmt Whilestmt BREAK CONTINUE
%token NUM COL PLUS MINUS MUL DIV END BEGINI READI WRITEI ID EQUAL IF then Else ENDIF WHILE DO ENDWHILE BREAK CONTINUE
%nonassoc LT GT LE GE NE EQ
%left PLUS MINUS
%left MUL DIV

%%

program : BEGINI Slist END 		{
									$$ = $2;
									//printf("Answer : %d\n",evaluate($1));
									fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
									fprintf(target_file, "MOV SP, 4121\n");
									codeGen($2);
									//writeCode();
									fprintf(target_file, "INT 10\n");
									exit(1);
								}

		| BEGINI END			{exit(1);}
		;

Slist : Slist Stmt 				{$$ = createTree(0, none, NULL, 8, $1, $2);}
	  | Stmt;

Stmt : InputStmt
	 | OutputStmt
	 | AsgStmt
	 | Ifstmt
	 | Whilestmt
	 | CONTINUE COL		{$$ = createTree(0, none, NULL, 17, NULL, NULL);}
	 | BREAK COL		{$$ = createTree(0, none, NULL, 18, NULL, NULL);}
	 ;

InputStmt : READI'('ID')' COL		{$$ = createTree(0, none, NULL, 6, $3, NULL);};

OutputStmt : WRITEI'('expr')' COL	{$$ = createTree(0, none, NULL, 7, $3, NULL);};

AsgStmt : ID EQUAL expr COL 		{$$ = createTree(0, none, NULL, 5, $1, $3);};

Ifstmt : IF '('expr')' then Slist Else Slist ENDIF	{struct tnode* t; t = createTree(0, none, NULL, 8, $6, $8); $$ = createTree(0, none, NULL, 15, $3, t);}
		| IF '('expr')' then Slist ENDIF			{struct tnode* t; t = createTree(0, none, NULL, 8, $6, NULL); $$ = createTree(0, none, NULL, 15, $3, t);}
		;

Whilestmt : WHILE '('expr')' DO Slist ENDWHILE		{$$ = createTree(0, none, NULL, 16, $3, $6);}
			;

expr : expr PLUS expr		{$$ = createTree(0, inttype, NULL, 1, $1, $3);}
	 | expr MINUS expr  	{$$ = createTree(0, inttype, NULL, 2, $1, $3);}
	 | expr MUL expr		{$$ = createTree(0, inttype, NULL, 3, $1, $3);}
	 | expr DIV expr		{$$ = createTree(0, inttype, NULL, 4, $1, $3);}
	 | expr LT expr		{$$ = createTree(0, booltype, NULL, 9, $1, $3);}
	 | expr GT expr		{$$ = createTree(0, booltype, NULL, 10, $1, $3);}
	 | expr LE expr		{$$ = createTree(0, booltype, NULL, 11, $1, $3);}
	 | expr GE expr		{$$ = createTree(0, booltype, NULL, 12, $1, $3);}
	 | expr NE expr		{$$ = createTree(0, booltype, NULL, 13, $1, $3);}
	 | expr EQ expr		{$$ = createTree(0, booltype, NULL, 14, $1, $3);}
	 | '(' expr ')'			{$$ = $2;}
	 | NUM					{$$ = $1;}
	 | ID					{$$ = $1;}
	 ;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}

int main() {
	target_file = fopen("out.xsm", "w");
	yyin = fopen("in.file", "r");
	yyparse();

	return 0;
}
