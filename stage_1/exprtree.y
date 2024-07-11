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
%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END READ WRITE
%left PLUS MINUS
%left MUL DIV

%%

program : expr END	{
				$$ = $1;
				printf("Answer : %d\n",evaluate($1));
				fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
				codeGen($1);
				writeCode();
				fprintf(target_file, "INT 10\n");
				exit(1);
			}
		;

expr : expr PLUS expr		{$$ = makeOperatorNode('+',$1,$3);}
	 | expr MINUS expr  	{$$ = makeOperatorNode('-',$1,$3);}
	 | expr MUL expr		{$$ = makeOperatorNode('*',$1,$3);}
	 | expr DIV expr		{$$ = makeOperatorNode('/',$1,$3);}
	 | '(' expr ')'			{$$ = $2;}
	 | NUM					{$$ = $1;}
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
