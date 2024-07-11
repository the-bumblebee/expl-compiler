%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "exprtree.h"
	#include "reglib.h"
	#include "y.tab.h"
	#include "auxlib.h"

	FILE *yyin;
	FILE *out_file;

	int compile_flag = 1;
	int n_params = 0;
	int decl_flag;
	int yylex(void);
	void yyerror(char const *s);

	struct Gsymbol *funcGentry;
	struct type_node *thead = NULL;
	struct arglist *arghead = NULL;

%}

%union{
	struct tnode *no;
	char *varname;
	int number;
	char* literal;
}
%type <no> expr program Slist Stmt AsgStmt InputStmt OutputStmt RtnStmt Ifstmt Whilestmt BREAK CONTINUE Fdef MainBlock
%token RETURN MAIN NUM COL PLUS MINUS MUL DIV MOD END BEGINI READI WRITEI ID EQUAL IF then Else ENDIF WHILE DO ENDWHILE BREAK CONTINUE STRLIT DECL ENDDECL INT STR ERROR
%type <number> NUM
%type <varname> ID
%type <literal> STRLIT
%nonassoc LT GT LE GE NE EQ
%left PLUS MINUS
%left MUL DIV MOD

%%

program : BEGINI END					{exit(1);}
			| GDeclBlock FDefBlock MainBlock
			{
				/*print_Gtable();*/
				exit(1);
			}

			| GDeclBlock MainBlock					{/*print_Gtable(); fprintf(stderr, "Success\n");*/ exit(1);}
			;

Slist : Slist Stmt 				{$$ = createTree(0, none, NULL, 8, $1, $2);}
	  | Stmt;

Stmt : InputStmt
	 | OutputStmt
	 | AsgStmt
	 | Ifstmt
	 | Whilestmt
	 | RtnStmt
	 | CONTINUE COL		{$$ = createTree(0, none, NULL, 17, NULL, NULL);}
	 | BREAK COL		{$$ = createTree(0, none, NULL, 18, NULL, NULL);}
	 ;

RtnStmt : RETURN expr COL	{$$ = createTree(0, none, NULL, 21, $2, NULL);}
		;

InputStmt : READI'('ID')' COL
			{
				struct tnode* t; t = createTree(0, none, $3, none, NULL, NULL);
				$$ = createTree(0, none, NULL, 6, t, NULL);
			}

		| READI'('ID'['expr']'')' COL
		{
			struct tnode* t = createTree(0, none, $3, 19, $5, NULL);
			 $$ = createTree(0, none, NULL, 6, t, NULL);
		 }
		;

OutputStmt : WRITEI'('expr')' COL		{$$ = createTree(0, none, NULL, 7, $3, NULL);};

AsgStmt : ID EQUAL expr COL
		{
			struct tnode* t; t = createTree(0, none, $1, none, NULL, NULL);
			$$ = createTree(0, none, NULL, 5, t, $3);
		}

		| ID'['expr']' EQUAL expr COL
		{
			struct tnode* t = createTree(0, none, $1, 19, $3, NULL);
			$$ = createTree(0, none, NULL, 5, t, $6);
		}
		;

Ifstmt : IF '('expr')' then Slist Else Slist ENDIF COL
		{
			struct tnode* t; t = createTree(0, none, NULL, 8, $6, $8);
			$$ = createTree(0, none, NULL, 15, $3, t);
		}

		| IF '('expr')' then Slist ENDIF COL
		{
			struct tnode* t; t = createTree(0, none, NULL, 8, $6, NULL);
			$$ = createTree(0, none, NULL, 15, $3, t);
		}
		;

Whilestmt : WHILE '('expr')' DO Slist ENDWHILE COL
			{
				$$ = createTree(0, none, NULL, 16, $3, $6);
			}
			;

GDeclBlock : DECL GDeclList ENDDECL
			{
				fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
				int SP;
				SP = Ghead->binding + Ghead->size;
				if (SP != Ghead->binding)
					SP = SP - 1;
				fprintf(target_file, "MOV SP, %d\n", SP);
				fprintf(target_file, "JMP L0\n");
			}
			| DECL ENDDECL
			{
				fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
				fprintf(target_file, "MOV SP, 4096\n");
			}
			;

GDeclList : GDeclList GDecl
			| GDecl
			;

GDecl : Type GidList COL	{tpop(&thead);}
	  ;

GidList : GidList',' Gid
		| Gid
		;

Gid : ID					{Ginstall(&Ghead, $1, thead->type, 1, NULL);}
	| ID'['NUM']'			{Ginstall(&Ghead, $1, thead->type, $3, NULL);}
	| ID'('ParamList')'
	{
		Ginstall(&Ghead, $1, thead->type, 0, &Phead);
		Phead = NULL;}
	;

FDefBlock : FDefBlock Fdef
			| Fdef
			;

Fdef : Type ID '(' ParamList ')' '{'LDeclBlock BEGINI Slist RtnStmt END'}'
		{
			n_params = 0;
			//Build AST for function.
			struct tnode* temp_node;
			temp_node = createTree(0, none, NULL, 8, $9, $10);
			$$ = createTree(0, none, $2, 22, temp_node, NULL);
			$$->Gentry->flabel = getLabel();
			//Compare Phead and fun->paramlist for name equivalence and deallocate Phead.
			cmpPara(&Phead, &($$->Gentry->paramlist));
			//Compare function types in both function declaration and function definition.
			if (thead->type != $$->Gentry->type) {
				fprintf(stderr, "Error: Function return type shows conflicts in function declaration and function definiton.\n");
				exit(1);
			}
			//Function entry saved to be used in codeGen. (For checking return type for return node.)
			funcGentry = $$->Gentry;
			tpop(&thead);
			//print_Ltable($2);
			//codeGen for function.
			codeGen($$);
			//Deallocate Lhead and AST.
			struct Lsymbol *Ltemp;
			while(Lhead != NULL) {
				Ltemp = Lhead;
				Lhead = Lhead->next;
				free(Ltemp);
			}
			deallocateAST($$);
	 	}


	;

MainBlock : INT MAIN '(' ')' '{' LDeclBlock BEGINI Slist RtnStmt END'}'
	{
		//Adding global entry.
		Ginstall(&Ghead, "main", inttype, 0, NULL);
		//Build AST for function.
		struct tnode* temp_node;
		temp_node = createTree(0, none, NULL, 8, $8, $9);
		$$ = createTree(0, none, "main", 22, temp_node, NULL);
		$$->Gentry = Ghead;
		$$->Gentry->flabel = 0;
		funcGentry = $$->Gentry;

		codeGen($$);
		//print_Ltable("main");
		struct Lsymbol *Ltemp;
		while(Lhead != NULL) {
			Ltemp = Lhead;
			Lhead = Lhead->next;
			free(Ltemp);
		}
		deallocateAST($$);
	}
	;

ParamList : ParamList',' Param
		{
			if (decl_flag == 0) {
				n_params += 1;
				Linstall(&Lhead, Phead->name, Phead->type);
			}
		}

		| Param
		{
			if (decl_flag == 0) {
				n_params = 1;
				Linstall(&Lhead, Phead->name, Phead->type);
			}
		}

		|
		{n_params = 0;}
		;

Param : Type ID			{Pinstall(&Phead, $2, thead->type); tpop(&thead);}
		;

LDeclBlock : DECL LDeclList ENDDECL
			{
				tpop(&thead);
			}
			| DECL ENDDECL
			|
			;

LDeclList: LDeclList LDecl | LDecl;

LDecl : Type IdList COL;

IdList : IdList',' ID		{Linstall(&Lhead, $3, thead->type);}
		| ID				{Linstall(&Lhead, $1, thead->type);}
		;

Type : INT					{tpush(&thead, inttype);}
	| STR					{tpush(&thead, strtype);}
	;

expr : expr PLUS expr		{$$ = createTree(0, inttype, NULL, 1, $1, $3);}
	 | expr MINUS expr  	{$$ = createTree(0, inttype, NULL, 2, $1, $3);}
	 | expr MUL expr		{$$ = createTree(0, inttype, NULL, 3, $1, $3);}
	 | expr DIV expr		{$$ = createTree(0, inttype, NULL, 4, $1, $3);}
	 | expr MOD expr		{$$ = createTree(0, inttype, NULL, 20, $1, $3);}
	 | expr LT expr			{$$ = createTree(0, booltype, NULL, 9, $1, $3);}
	 | expr GT expr			{$$ = createTree(0, booltype, NULL, 10, $1, $3);}
	 | expr LE expr			{$$ = createTree(0, booltype, NULL, 11, $1, $3);}
	 | expr GE expr			{$$ = createTree(0, booltype, NULL, 12, $1, $3);}
	 | expr NE expr			{$$ = createTree(0, booltype, NULL, 13, $1, $3);}
	 | expr EQ expr			{$$ = createTree(0, booltype, NULL, 14, $1, $3);}
     | ID '(' ')'			{$$ = createTree(0, none, $1, 23, NULL, NULL);}
	 | ID '(' ArgList ')'
	 {
		 struct tnode *tn;
		 $$ = createTree(0, none, $1, 23, NULL, NULL);
		 tn = cmpArg(&arghead, &($$->Gentry->paramlist));
		 $$->left = tn;
	 }
	 | '(' expr ')'			{$$ = $2;}
	 | NUM					{$$ = createTree($1, inttype, NULL, none, NULL, NULL);}
	 | ID'['expr']'			{$$ = createTree(0, none, $1, 19, $3, NULL);}
	 | ID					{$$ = createTree(0, none, $1, none, NULL, NULL);}
	 | STRLIT				{$$ = makeStringNode($1);}
	 ;

ArgList : ArgList ',' expr	{argpush(&arghead, $3);}
		| expr				{argpush(&arghead, $1);}
		;

%%

void yyerror(char const *s) {
    printf("yyerror %s\n", s);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage:\n ./a.out <input_file>\n\n");
		printf("Output:\n out_label.xsm\n");
		exit(0);
	}
	target_file = fopen("out_label.xsm", "w");
	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);
	fclose(target_file);
	return 0;
}
