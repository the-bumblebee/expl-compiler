%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
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
	struct Typetable *Tentry;
	struct Fieldlist *Fhead = NULL;
	struct type_node *thead = NULL;
	struct arglist *arghead = NULL;

%}

%union{
	struct tnode *no;
	char *varname;
	int number;
	char* literal;
}
%type <no> expr program Slist Stmt AsgStmt InputStmt OutputStmt RtnStmt Ifstmt Whilestmt AllocStmt FreeStmt BREAK CONTINUE Fdef MainBlock Field InitFunc
%token RETURN MAIN NUM COL PLUS MINUS MUL DIV MOD END BEGINI READI WRITEI ID EQUAL IF then Else ENDIF WHILE DO ENDWHILE BREAK CONTINUE STRLIT DECL ENDDECL INT STR ERROR TYPE ENDTYPE ALLOC FREE NULLV INITIALIZE
%type <number> NUM
%type <varname> ID
%type <literal> STRLIT
%nonassoc LT GT LE GE NE EQ
%left PLUS MINUS
%left MUL DIV MOD

%%

program : BEGINI END										{exit(1);}
		| MainBlock											{exit(1);}
		| TypeDefBlock GDeclBlock FDefBlock MainBlock		{exit(1);}
		| TypeDefBlock GDeclBlock MainBlock					{exit(1);}
		;

Slist : Slist Stmt 				{$$ = createTree(0, Tlookup("void"), NULL, 8, $1, $2);}
	  | Stmt;

Stmt : InputStmt
	 | OutputStmt
	 | AsgStmt
	 | Ifstmt
	 | Whilestmt
	 | AllocStmt
	 | FreeStmt
	 | RtnStmt
	 | CONTINUE COL		{$$ = createTree(0, Tlookup("void"), NULL, 17, NULL, NULL);}
	 | BREAK COL		{$$ = createTree(0, Tlookup("void"), NULL, 18, NULL, NULL);}
	 ;

RtnStmt : RETURN expr COL	{$$ = createTree(0, Tlookup("void"), NULL, 21, $2, NULL);}
		;

InputStmt : READI'('ID')' COL
			{
				struct tnode* t; t = createTree(0, NULL, $3, none, NULL, NULL);
				$$ = createTree(0, Tlookup("void"), NULL, 6, t, NULL);
			}

			| READI'('ID'['expr']'')' COL
			{
				struct tnode* t = createTree(0, NULL, $3, 19, $5, NULL);
				$$ = createTree(0, Tlookup("void"), NULL, 6, t, NULL);
			 }
			;

AllocStmt : ID EQUAL ALLOC '(' ')' COL
			{
				struct tnode *IDNode = createTree(0, NULL, $1, none, NULL, NULL);
				if (IDNode->type->fields == NULL) {
					fprintf(stderr, "Error: Allocation failed. '%s' is a primtive type.\n", IDNode->varname);
					exit(1);
				}
				$$ = createTree(0, Tlookup("void"), NULL, 25, IDNode, NULL);
			}

			| Field EQUAL ALLOC '(' ')' COL
			{
				struct tnode *IDNode = $1;
				while (IDNode->left != NULL) {
					IDNode = IDNode->left;
				}
				if ($1->type->fields == NULL) {
					fprintf(stderr, "Error: Allocation failed. '%s' is a primtive type.\n", IDNode->varname);
					exit(1);
				}
				$$ = createTree(0, Tlookup("void"), NULL, 25, $1, NULL);
			}
			;

FreeStmt	: FREE '(' ID ')' COL
			{
				struct tnode *IDNode = createTree(0, NULL, $3, none, NULL, NULL);
				if (IDNode->type->fields == NULL) {
					fprintf(stderr, "Error: Cannot free '%s'. It is a primtive type.\n", IDNode->varname);
					exit(1);
				}
				$$ = createTree(0, Tlookup("int"), NULL, 26, IDNode, NULL);
			}

			| FREE '(' Field ')' COL
			{
				struct tnode *IDNode = $3;
				while (IDNode->left != NULL) {
					IDNode = IDNode->left;
				}
				if ($3->type->fields == NULL) {
					fprintf(stderr, "Error: Cannot free '%s'. It is a primtive type.\n", IDNode->varname);
					exit(1);
				}
				$$ = createTree(0, Tlookup("int"), NULL, 26, $3, NULL);
			}
			;

InitFunc	: INITIALIZE '(' ')'
			{
				$$ = createTree(0, Tlookup("int"), NULL, 28, NULL, NULL);
			}
			;

OutputStmt	: WRITEI'('expr')' COL		{$$ = createTree(0, Tlookup("void"), NULL, 7, $3, NULL);};

AsgStmt	: ID EQUAL expr COL
		{
			struct tnode* t; t = createTree(0, NULL, $1, none, NULL, NULL);
			$$ = createTree(0, Tlookup("void"), NULL, 5, t, $3);
		}

		| ID'['expr']' EQUAL expr COL
		{
			struct tnode* t = createTree(0, NULL, $1, 19, $3, NULL);
			$$ = createTree(0, Tlookup("void"), NULL, 5, t, $6);
		}

		| Field EQUAL expr COL
		{
			$$ = createTree(0, Tlookup("void"), NULL, 5, $1, $3);
		}
		;

Ifstmt	: IF '('expr')' then Slist Else Slist ENDIF COL
		{
			struct tnode* t; t = createTree(0, Tlookup("void"), NULL, 8, $6, $8);
			$$ = createTree(0, Tlookup("void"), NULL, 15, $3, t);
		}

		| IF '('expr')' then Slist ENDIF COL
		{
			struct tnode* t; t = createTree(0, Tlookup("void"), NULL, 8, $6, NULL);
			$$ = createTree(0, Tlookup("void"), NULL, 15, $3, t);
		}
		;

Whilestmt	: WHILE '('expr')' DO Slist ENDWHILE COL
			{
				$$ = createTree(0, Tlookup("void"), NULL, 16, $3, $6);
			}
			;

GDeclBlock	: DECL GDeclList ENDDECL
			{
				fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
				int SP;
				SP = Ghead->binding + Ghead->size;
				if (SP != Ghead->binding)
					SP = SP - 1;
				fprintf(target_file, "MOV SP, %d\n", SP);
				fprintf(target_file, "JMP <main>\n");
			}
			| DECL ENDDECL
			{
				fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
				fprintf(target_file, "MOV SP, 4096\n");
			}
			;

GDeclList	: GDeclList GDecl
			| GDecl
			;

GDecl	: TypeName GidList COL	{tpop(&thead);}
		;

GidList	: GidList',' Gid
		| Gid
		;

Gid	: ID					{Ginstall(&Ghead, $1, thead->type, 1, NULL);}
	| ID'['NUM']'			{Ginstall(&Ghead, $1, thead->type, $3, NULL);}
	| ID'('ParamList')'
	{
		Ginstall(&Ghead, $1, thead->type, 0, &Phead);
		Phead = NULL;
	}
	;

FDefBlock	: FDefBlock Fdef
			| Fdef
			;

Fdef	: TypeName ID '(' ParamList ')' '{'LDeclBlock BEGINI Slist RtnStmt END'}'
		{
			n_params = 0;
			//Build AST for function.
			struct tnode* temp_node;
			temp_node = createTree(0, Tlookup("void"), NULL, 8, $9, $10);
			$$ = createTree(0, NULL, $2, 22, temp_node, NULL);
			//Compare Phead and fun->paramlist for name equivalence and deallocate Phead.
			cmpPara(&Phead, &($$->Gentry->paramlist));
			//Compare function types in both function declaration and function definition.
			if (thead->type != $$->Gentry->type) {
				fprintf(stderr, "Error: Function return type shows conflicts in function declaration and function definiton.(%s, %s)\n", thead->type->name, $2);
				exit(1);
			}
			//Function entry saved to be used in codeGen. (For checking return type for return node.)
			funcGentry = $$->Gentry;
			tpop(&thead);
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

MainBlock	: INT MAIN '(' ')' '{' LDeclBlock BEGINI Slist RtnStmt END'}'
			{
				//Adding global entry.
				Ginstall(&Ghead, "main", Tlookup("int"), 0, NULL);
				//Build AST for function.
				struct tnode* temp_node;
				temp_node = createTree(0, Tlookup("void"), NULL, 8, $8, $9);
				$$ = createTree(0, Tlookup("int"), "main", 22, temp_node, NULL);
				$$->Gentry = Ghead;
				$$->Gentry->flabel = strdup("main");
				funcGentry = $$->Gentry;
				codeGen($$);
				struct Lsymbol *Ltemp;
				while(Lhead != NULL) {
					Ltemp = Lhead;
					Lhead = Lhead->next;
					free(Ltemp);
				}
				deallocateAST($$);
			}
			;

ParamList	: ParamList',' Param
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

Param	: TypeName ID			{Pinstall(&Phead, $2, thead->type); tpop(&thead);}
		;

LDeclBlock	: DECL LDeclList ENDDECL
			| DECL ENDDECL
			|
			;

LDeclList	: LDeclList LDecl
			| LDecl;

LDecl	: TypeName IdList COL	{tpop(&thead);};

IdList	: IdList',' ID		{Linstall(&Lhead, $3, thead->type);}
		| ID				{Linstall(&Lhead, $1, thead->type);}
		;

TypeDefBlock  : TYPE TypeDefList ENDTYPE
              |
              ;

TypeDefList	: TypeDefList TypeDef
    		| TypeDef
        	;

TypeDef	: TypeDecl '{' FieldDeclList '}'
		{
			if (Fhead->fieldIndex >= Thead->size) {
				fprintf(stderr, "Error: Total size of the field numbers exceeds %d (Maximum allowed size).\n", Thead->size);
				exit(1);
			}
			Thead->fields = Fhead;
			Fhead = NULL;
		}
    	;

TypeDecl	: ID
			{
				TInstall($1, 8, NULL);
			};

FieldDeclList	: FieldDeclList FieldDecl {Fhead->fieldIndex = Fhead->next->fieldIndex + 1;}
				| FieldDecl				{Fhead->fieldIndex = 0;}
				;

FieldDecl	:  TypeName ID COL	{FInstall(&Fhead, $2, thead->type); tpop(&thead);};

TypeName	: INT					{tpush(&thead, Tlookup("int"));}
			| STR					{tpush(&thead, Tlookup("str"));}
			| ID
			{
				struct Typetable *Ttemp;
				Ttemp = Tlookup($1);
				if (Ttemp == NULL) {
					fprintf(stderr, "Error: The user-defined type '%s' is not defined.\n", $1);
					exit(1);
				}
				tpush(&thead, Ttemp);
			}
			;

Field	: Field '.' ID
		{
			struct tnode *tn = $1;
			while(tn->left != NULL) {
				tn = tn->left;
			}
			struct Fieldlist *Ftemp = FLookup(tn->type->fields, $3);
			if (Ftemp == NULL) {
				fprintf(stderr, "Error: %s' type has no member field named '%s'.\n", tn->type->name, $3);
				exit(1);
			}
			struct tnode *temp = createTree(0, Ftemp->type, $3, none, NULL, NULL);
			tn->left = temp;
			$1->type = Ftemp->type;
		}

		| ID '.' ID
		{
			struct Typetable *type;
			struct Fieldlist *Ftemp;
			struct Lsymbol *Ltemp = Llookup(Lhead, $1);
			if (Ltemp == NULL) {
				struct Gsymbol *Gentry = Glookup(Ghead, $1);
				if (Gentry == NULL) {
					fprintf(stderr, "Error: The variable '%s' is not declared.\n", $1);
					exit(1);
				}
				Ftemp = FLookup(Gentry->type->fields, $3);
				type = Gentry->type;
			}
			else {
				Ftemp = FLookup(Ltemp->type->fields, $3);
				type = Ltemp->type;
			}
			if (Ftemp == NULL) {
				fprintf(stderr, "Error: '%s' ('%s' type) has no member named '%s'.\n", $1, type->name, $3);
				exit(1);
			}
			struct tnode *temp = createTree(0, Ftemp->type, $3, none, NULL, NULL);
			struct tnode *temp2 = createTree(0, type, $1, none, temp, NULL);
			$$ = createTree(0, Ftemp->type, NULL, 24, temp2, NULL);
		}
		;

expr : expr PLUS expr		{$$ = createTree(0, Tlookup("int"), NULL, 1, $1, $3);}
	 | expr MINUS expr  	{$$ = createTree(0, Tlookup("int"), NULL, 2, $1, $3);}
	 | expr MUL expr		{$$ = createTree(0, Tlookup("int"), NULL, 3, $1, $3);}
	 | expr DIV expr		{$$ = createTree(0, Tlookup("int"), NULL, 4, $1, $3);}
	 | expr MOD expr		{$$ = createTree(0, Tlookup("int"), NULL, 20, $1, $3);}
	 | expr LT expr			{$$ = createTree(0, Tlookup("bool"), NULL, 9, $1, $3);}
	 | expr GT expr			{$$ = createTree(0, Tlookup("bool"), NULL, 10, $1, $3);}
	 | expr LE expr			{$$ = createTree(0, Tlookup("bool"), NULL, 11, $1, $3);}
	 | expr GE expr			{$$ = createTree(0, Tlookup("bool"), NULL, 12, $1, $3);}
	 | expr NE expr			{$$ = createTree(0, Tlookup("bool"), NULL, 13, $1, $3);}
	 | expr EQ expr			{$$ = createTree(0, Tlookup("bool"), NULL, 14, $1, $3);}
     | ID '(' ')'			{$$ = createTree(0, NULL, $1, 23, NULL, NULL);}
	 | ID '(' ArgList ')'
	 {
		 struct tnode *tn;
		 $$ = createTree(0, NULL, $1, 23, NULL, NULL);
		 tn = cmpArg(&arghead, &($$->Gentry->paramlist));
		 $$->left = tn;
	 }
	 | '(' expr ')'			{$$ = $2;}
	 | Field				{$$ = $1;}
	 | InitFunc				{$$ = $1;}
	 | NULLV				{$$ = createTree(0, Tlookup("void"), NULL, 27, NULL, NULL);}
	 | NUM					{$$ = createTree($1, Tlookup("int"), NULL, none, NULL, NULL);}
	 | ID'['expr']'			{$$ = createTree(0, NULL, $1, 19, $3, NULL);}
	 | ID					{$$ = createTree(0, NULL, $1, none, NULL, NULL);}
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
	TypeTableCreate();
	yyparse();
	fclose(yyin);
	fclose(target_file);
	return 0;
}
