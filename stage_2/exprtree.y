%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "exprtree.h"
	#include "exprtree.c"
	#include "reglib.h"

	int yylex(void);
	FILE *target_file;

	#include "reglib.c"
%}

%union{
	struct tnode *no;

}
%type <no> expr NUM program END Slist Stmt AsgStmt InputStmt OutputStmt ID BEGINI
%token NUM PLUS MINUS MUL DIV END BEGINI READI WRITEI ID EQUAL
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

		| BEGINI END	{exit(1);}
		;

Slist : Slist Stmt 				{$$ = makeConnectorNode($1, $2);}
	  | Stmt;

Stmt : InputStmt
	 | OutputStmt
	 | AsgStmt
	 ;

InputStmt : READI'('ID')'		{$$ = makeReadNode($3);};

OutputStmt : WRITEI'('expr')'	{$$ = makeWriteNode($3);};

AsgStmt : ID EQUAL expr			{$$ = makeAssignNode($1, $3);};

expr : expr PLUS expr		{$$ = makeOperatorNode('+',$1,$3);}
	 | expr MINUS expr  	{$$ = makeOperatorNode('-',$1,$3);}
	 | expr MUL expr		{$$ = makeOperatorNode('*',$1,$3);}
	 | expr DIV expr		{$$ = makeOperatorNode('/',$1,$3);}
	 | '(' expr ')'			{$$ = $2;}
	 | NUM					{$$ = $1;}
	 | ID					{$$ = $1;}
	 ;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(int argc, char *argv[]) {
	target_file = fopen(argv[1], "w");
	yyparse();

	return 0;
}
