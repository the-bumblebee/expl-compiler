%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "exprtree.h"
	#include "reglib.h"
	#include "y.tab.h"
	#include "auxlib.h"
	#include "classlib.h"

	#include "tablelib.h"

	#define TYPE_SIZE 8

	FILE *yyin;
	FILE *out_file;

	int line_no;
	int decl_flag, class_flag;
	int yylex(void);
	void yyerror(char const *s);

	struct Methodlist *funcTempEntry;
	struct Typetable *Tentry;
	struct Fieldlist *Fhead = NULL;
	struct type_node *thead = NULL;
	struct arglist *arghead = NULL;

%}

%union{
	struct tnode *no;
	char *name;
	int number;
	char* literal;
}
%type <no> expr program Slist Stmt AsgStmt InputStmt OutputStmt RtnStmt Ifstmt Whilestmt BREAK CONTINUE Fdef MainBlock Body Field InitFunc FieldFunction
%token RETURN MAIN NUM COL PLUS MINUS MUL DIV MOD END BEGINI READI WRITEI ID EQUAL IF then Else ENDIF WHILE DO ENDWHILE BREAK CONTINUE STRLIT DECL ENDDECL INT STR ERROR TYPE ENDTYPE ALLOC FREE NULLV INITIALIZE CLASS ENDCLASS SELF NEW DELETE
%type <number> NUM
%type <name> ID
%type <literal> STRLIT
%nonassoc LT GT LE GE NE EQ
%left PLUS MINUS
%left MUL DIV MOD

%%

program 		: TypeDefBlock ClassDefBlock GDeclBlock	FDefBlock MainBlock	{exit(1);}
				| TypeDefBlock ClassDefBlock GDeclBlock MainBlock			{exit(1);}
				;

Slist 			: Slist Stmt 				{$$ = createTree(0, "void", NULL, 8, $1, $2);}
	  			| Stmt;

Stmt 			: InputStmt
				| OutputStmt
				| AsgStmt
				| Ifstmt
				| Whilestmt
				| RtnStmt
				| CONTINUE COL				{$$ = createTree(0, "void", NULL, 17, NULL, NULL);}
				| BREAK COL					{$$ = createTree(0, "void", NULL, 18, NULL, NULL);}
				;

RtnStmt 		: RETURN expr COL			{$$ = createTree(0, "void", NULL, 21, $2, NULL);};

InputStmt 		: READI'('ID')' COL
				{
					struct tnode* t; t = createTree(0, NULL, $3, none, NULL, NULL);
					$$ = createTree(0, "void", NULL, 6, t, NULL);
				}

				| READI'('ID'['expr']'')' COL
				{
					struct tnode* t = createTree(0, NULL, $3, 19, $5, NULL);
					$$ = createTree(0, "void", NULL, 6, t, NULL);
				}

				| READI'('Field')' COL
				{
					$$ = createTree(0, "void", NULL, 6, $3, NULL);
				}
				;

InitFunc		: INITIALIZE '(' ')'		{$$ = createTree(0, "int", NULL, 28, NULL, NULL);};

OutputStmt		: WRITEI'('expr')' COL		{$$ = createTree(0, "void", NULL, 7, $3, NULL);};

AsgStmt			: ID EQUAL expr COL
				{
					struct tnode* t; t = createTree(0, NULL, $1, none, NULL, NULL);
					$$ = createTree(0, "void", NULL, 5, t, $3);
				}

				| ID'['expr']' EQUAL expr COL
				{
					struct tnode* t = createTree(0, NULL, $1, 19, $3, NULL);
					$$ = createTree(0, "void", NULL, 5, t, $6);
				}

				| Field EQUAL expr COL
				{
					$$ = createTree(0, "void", NULL, 5, $1, $3);
				}
				;

Ifstmt			: IF '('expr')' then Slist Else Slist ENDIF COL
				{
					struct tnode* t; t = createTree(0, "void", NULL, 8, $6, $8);
					$$ = createTree(0, "void", NULL, 15, $3, t);
				}

				| IF '('expr')' then Slist ENDIF COL
				{
					struct tnode* t; t = createTree(0, "void", NULL, 8, $6, NULL);
					$$ = createTree(0, "void", NULL, 15, $3, t);
				}
				;

Whilestmt		: WHILE '('expr')' DO Slist ENDWHILE COL
				{
					$$ = createTree(0, "void", NULL, 16, $3, $6);
				}
				;

GDeclBlock		: DECL GDeclList ENDDECL
				| DECL ENDDECL
				|
				;

GDeclList		: GDeclList GDecl
				| GDecl
				;

GDecl			: TypeName GidList COL	{tpop(&thead);}
				;

GidList			: GidList',' Gid
				| Gid
				;

Gid				: ID					{Ginstall(&Ghead, $1, thead->name, 1, NULL);}
				| ID'['NUM']'			{Ginstall(&Ghead, $1, thead->name, $3, NULL);}
				| ID'('ParamList')'
				{
					Ginstall(&Ghead, $1, thead->name, 0, &Phead);
					Phead = NULL;
				}
				;

FDefBlock		: FDefBlock Fdef
				| Fdef
				;

Fdef			: TypeName ID '(' ParamList ')' '{'LDeclBlock Body '}'
				{
					struct Methodlist *Mtemp;
					//Build AST for function.
					if (class_flag == 1) {
						Mtemp = Class_MLookup($2, Chead);
						$$ = createTree(0, "void", $2, 22, $8, NULL);
						$$->type = Mtemp->type;
						cmpPara(&Phead, &(Mtemp->paramList));											//Compare Phead and fun->paramlist for name equivalence and deallocate Phead.
						funcTempEntry = Mtemp;
					}
					else {
						$$ = createTree(0, NULL, $2, 22, $8, NULL);
						cmpPara(&Phead, &($$->Gentry->paramlist));										//Compare Phead and fun->paramlist for name equivalence and deallocate Phead.

						//Function entry saved to be used in codeGen. (For checking return type for return node.)
						funcTempEntry = (struct Methodlist *)malloc(sizeof(struct Methodlist));
						funcTempEntry->name = $$->name;
						funcTempEntry->type = $$->type;
						funcTempEntry->flabel = $$->Gentry->flabel;
						funcTempEntry->paramList = $$->Gentry->paramlist;
						funcTempEntry->next = NULL;
						funcTempEntry->funcIndex = -1;
					}
					//Compare function types in both function declaration and function definition.
					if ($$->type != Tlookup(thead->name)) {
						fprintf(stderr, "Error: Function return type shows conflicts in function declaration and function definiton.(%s, %s)\n", thead->name, $2);
						exit(1);
					}

					if (funcTempEntry->flabel != NULL) {
						if (class_flag == 1){
							fprintf(stderr, "Error: Method '%s' already defined within '%s' class.\n", funcTempEntry->name, Chead->name);
							exit(1);
						}
						else {
							fprintf(stderr, "Error: Function '%s' already defined.\n", funcTempEntry->name);
							exit(1);
						}
					}

					if (class_flag == 1){
						funcTempEntry->flabel = (char *)malloc(sizeof(char) * (strlen(Chead->name) + strlen(funcTempEntry->name) + 1));
						strcpy(funcTempEntry->flabel, Chead->name);
						strcat(funcTempEntry->flabel, ".");
						strcat(funcTempEntry->flabel, funcTempEntry->name);
					}
					else {
						funcTempEntry->flabel = strdup(funcTempEntry->name);
					}

					tpop(&thead);
					//codeGen for function.
					codeGen($$);
					//print_Ltable($2, Lhead);
					//Deallocate Lhead and AST.
					deallocateLTable();
					deallocateAST($$);
					if (class_flag == 0) {
						free(funcTempEntry);
						funcTempEntry = NULL;
					}
			 	}
				;

MainBlock		: INT MAIN '(' ')' '{' LDeclBlock Body '}'
				{
					//Adding global entry.
					Ginstall(&Ghead, "main", "int", 0, NULL);
					//Build AST for function.
					$$ = createTree(0, "int", "main", 22, $7, NULL);
					$$->Gentry = Ghead;

					funcTempEntry = (struct Methodlist *)malloc(sizeof(struct Methodlist));
					funcTempEntry->name = $$->name;
					funcTempEntry->type = $$->type;
					funcTempEntry->flabel = $$->Gentry->flabel;
					funcTempEntry->paramList = $$->Gentry->paramlist;
					funcTempEntry->next = NULL;
					funcTempEntry->funcIndex = -1;

					if (funcTempEntry->flabel != NULL) {
						fprintf(stderr, "Error: Function '%s' already defined.\n", funcTempEntry->name);
						exit(1);
					}

					funcTempEntry->flabel = strdup("main");

					codeGen($$);
					//print_Ltable("main", Lhead);
					deallocateLTable();
					deallocateAST($$);
					tpop(&thead);
					free(funcTempEntry);
					funcTempEntry = NULL;
				}
				;

Body			: BEGINI Slist RtnStmt END				{$$ = createTree(0, "void", NULL, 8, $2, $3);};
				| BEGINI RtnStmt END					{$$ = $2;}

ParamList		: ParamList',' Param
				{
					if (decl_flag == 0) {
						Linstall(&Lhead, Phead->name, Phead->type);
					}
				}

				| Param
				{
					if (decl_flag == 0 && Phead != NULL) {
						Linstall(&Lhead, Phead->name, Phead->type);
					}
				}
				;

Param			: TypeName ID
				{
					/*if (class_flag == 1 && Phead == NULL)
						Pinstall(&Phead, "self", Tlookup("void"));*/
					Pinstall(&Phead, $2, Tlookup(thead->name)); tpop(&thead);
				}

				|
				{/*if (class_flag == 1) Pinstall(&Phead, "self", Tlookup("void"));*/}
				;

LDeclBlock		: DECL LDeclList ENDDECL
				| DECL ENDDECL
				|
				;

LDeclList		: LDeclList LDecl
				| LDecl;

LDecl			: TypeName IdList COL	{tpop(&thead);};

IdList			: IdList',' ID		{Linstall(&Lhead, $3, Tlookup(thead->name));}
				| ID				{Linstall(&Lhead, $1, Tlookup(thead->name));}
				;

TypeDefBlock  	: TYPE TypeDefList ENDTYPE
              	|
              	;

TypeDefList		: TypeDefList TypeDef
    			| TypeDef
        		;

TypeDef			: TypeDecl '{' FieldDeclList '}'		{TFieldUpdate(&Fhead);}

TypeDecl		: ID			{TInstall($1, TYPE_SIZE, NULL);};

FieldDeclList	: FieldDeclList FieldDecl
				| FieldDecl
				;

FieldDecl		: TypeName ID COL		{FInstall(&Fhead, $2, Tlookup(thead->name)); tpop(&thead);};

TypeName		: INT					{tpush(&thead, "int");}
				| STR					{tpush(&thead, "str");}
				| ID
				{
					if (Tlookup($1) == NULL && CLookup($1, Chead) == NULL) {
						fprintf(stderr, "Error: '%s' is neither a class nor a user-defined type.\n", $1);
						exit(1);
					}
					tpush(&thead, $1);
				}
				;

Field			: Field '.' ID
				{
					struct tnode *temp;
					if ($1->ctype != NULL) {
						fprintf(stderr, "Error: Fields of a class cannot be accessed in other classes.\n");
						exit(1);
					}

					struct tnode *tn = $1;
					while(tn->left != NULL) {
						tn = tn->left;
					}

					if (tn->type != NULL)
						temp = createFieldVar(tn->type->name, $3, NULL, NULL);
					else if (tn->ctype != NULL)
						temp = createFieldVar(tn->ctype->name, $3, NULL, NULL);
					tn->left = temp;
					$1->type = temp->type;
					$1->ctype = temp->ctype;
				}

				| ID '.' ID
				{
					struct Typetable *type;
					struct Fieldlist *Ftemp;
					struct Gsymbol *Gentry = Glookup(Ghead, $1);
					struct Lsymbol *Ltemp = Llookup(Lhead, $1);

					if (Ltemp == NULL) {
						if (Gentry == NULL) {
							fprintf(stderr, "Error: The class or user-defined type variable '%s' is not declared.\n", $1);
							exit(1);
						}

						if (Gentry->ctype != NULL) {
							fprintf(stderr, "Error: Fields of classes cannot be accessed outside class methods.\n");
							exit(1);
						}

						if (Gentry->type->fields == NULL) {
							fprintf(stderr, "Error: '%s' is neither a user-defined type nor a class object.\n", $1);
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
					struct tnode *temp = createTree(0, Ftemp->type->name, $3, none, NULL, NULL);
					struct tnode *temp2 = createTree(0, type->name, $1, none, temp, NULL);
					$$ = createTree(0, Ftemp->type->name, NULL, 24, temp2, NULL);
				}

				| SELF '.' ID
				{
					if (class_flag == 0) {
						fprintf(stderr, "Error: 'self' is a reserved keyword and cannot occur outside class methods.\n");
						exit(1);
					}
					struct tnode *temp = createFieldVar(Chead->name, $3, NULL, NULL);
					struct tnode *temp2 = createTree(0, Chead->name, NULL, 29, temp, NULL);
					$$ = createTree(0, "void", NULL, 24, temp2, NULL);
					$$->type = temp->type;
					$$->ctype = temp->ctype;
				}
				;

ClassDefBlock	: CLASS ClassDefList ENDCLASS
				|
				;

ClassDefList	: ClassDefList ClassDef
				| ClassDef
				;

ClassDef		: Cname '{' DECL Fieldlists MethodDecl ENDDECL MethodDefns '}'
				;

Cname			: ID       		{Chead = CInstall($1 ,NULL, Chead);}
				;

Fieldlists 		: Fieldlists Fld
				|
				;

Fld         	: TypeName ID COL				{Class_FInstall($2, thead->name, Chead); tpop(&thead);}
				;

MethodDecl 		: MethodDecl MDecl
	   			| MDecl
				;

MDecl      		: TypeName ID '(' ParamList ')' COL {Class_MInstall($2, Tlookup(thead->name), Phead, Chead); tpop(&thead); Phead = NULL;}
				;

MethodDefns		: MethodDefns Fdef
        		| Fdef
				;

FieldFunction	: SELF '.' ID '(' ArgList ')'
				{
					//if class flag
					//push bp -3
					struct Methodlist *Mtemp = Class_MLookup($3, Chead);

					if (class_flag == 0) {
						fprintf(stderr, "Error: 'self' is a reserved keyword and cannot occur outside class methods.\n");
						exit(1);
					}

					if (Mtemp == NULL) {
						fprintf(stderr, "Error: The class '%s' has no method named '%s'.\n", Chead->name, $3);
						exit(1);
					}

					struct tnode *self_node = createTree(0, Chead->name, NULL, 29, NULL, NULL);
					struct tnode *field_node = createTree(0, self_node->ctype->name, NULL, 24, self_node, NULL);
					struct tnode *func_node = createTree(0, Mtemp->type->name, Mtemp->name, none, NULL, NULL);
					if (arghead != NULL) {
						struct tnode *arg = cmpArg(&arghead, &(Mtemp->paramList));
						func_node->left = arg;
					}
					$$ = createTree(0, Mtemp->type->name, NULL, 30, field_node, func_node);

				}

                |ID '.' ID '(' ArgList ')'
				{
					//id1-.gebtry n id1->gentry->ctype
					//push id1->binding

					struct Gsymbol *Gentry = Glookup(Ghead, $1);

					if (Gentry == NULL) {
						fprintf(stderr, "Error: There is no class object named '%s'.\n", $1);
						exit(1);
					}

					if (Gentry->ctype == NULL) {
						fprintf(stderr, "Error: '%s' is not a class object and thus, doesn't have any methods.\n", $1);
						exit(1);
					}

					struct Methodlist *Mtemp = Class_MLookup($3, Gentry->ctype);

					if (Mtemp == NULL) {
						fprintf(stderr, "Error: '%s' ('%s' class) has no method named '%s'.\n", $1, Chead->name, $3);
						exit(1);
					}

					struct tnode *id_node = createTree(0, Gentry->ctype->name, $1, none, NULL, NULL);
					struct tnode *field_node = createTree(0, Gentry->ctype->name, NULL, 24, id_node, NULL);
					struct tnode *func_node = createTree(0, Mtemp->type->name, Mtemp->name, none, NULL, NULL);
					if (arghead != NULL) {
						struct tnode *arg = cmpArg(&arghead, &(Mtemp->paramList));
						func_node->left = arg;
					}
					$$ = createTree(0, Mtemp->type->name, NULL, 30, field_node, func_node);

				}//This will not occur inside a class.

				|Field '.' ID '(' ArgList ')'
				{
					//if(field->ctype)
					//push getIDAddress(field)

					if ($1->ctype == NULL) {
						fprintf(stderr, "Error at line %d: The object doesn't have methods as it is not a class object.\n", line_no);
						exit(1);
					}

					struct Methodlist *Mtemp = Class_MLookup($3, $1->ctype);

					if (Mtemp == NULL) {
						fprintf(stderr, "Error at line %d: The class '%s' has no method named '%s'.\n", line_no, $1->ctype->name);
					}

					//struct tnode *id_node = createTree(0, Gentry->ctype->name, NULL, none, NULL, NULL);
					//struct tnode *field_node = createTree(0, "void", NULL, 24, id_node, NULL);
					struct tnode *func_node = createTree(0, Mtemp->type->name, Mtemp->name, none, NULL, NULL);
					if (arghead != NULL) {
						struct tnode *arg = cmpArg(&arghead, &(Mtemp->paramList));
						func_node->left = arg;
					}
					$$ = createTree(0, Mtemp->type->name, NULL, 30, $1, func_node);
				}
				;

expr			: expr PLUS expr		{$$ = createTree(0, "int", NULL, 1, $1, $3);}
			 	| expr MINUS expr  		{$$ = createTree(0, "int", NULL, 2, $1, $3);}
			 	| expr MUL expr			{$$ = createTree(0, "int", NULL, 3, $1, $3);}
			 	| expr DIV expr			{$$ = createTree(0, "int", NULL, 4, $1, $3);}
				| expr MOD expr			{$$ = createTree(0, "int", NULL, 20, $1, $3);}
				| expr LT expr			{$$ = createTree(0, "bool", NULL, 9, $1, $3);}
				| expr GT expr			{$$ = createTree(0, "bool", NULL, 10, $1, $3);}
				| expr LE expr			{$$ = createTree(0, "bool", NULL, 11, $1, $3);}
				| expr GE expr			{$$ = createTree(0, "bool", NULL, 12, $1, $3);}
				| expr NE expr			{$$ = createTree(0, "bool", NULL, 13, $1, $3);}
				| expr EQ expr			{$$ = createTree(0, "bool", NULL, 14, $1, $3);}
			  //  | ID '(' ')'			{$$ = createTree(0, NULL, $1, 23, NULL, NULL);}
				| ID '(' ArgList ')'
				{
					struct tnode *tn;
					$$ = createTree(0, NULL, $1, 23, NULL, NULL);
					if (arghead != NULL) {
						tn = cmpArg(&arghead, &($$->Gentry->paramlist));
						$$->left = tn;
					}
				}
				| '(' expr ')'			{$$ = $2;}
				| FieldFunction			{$$ = $1;}
				| Field					{$$ = $1;}
				| InitFunc				{$$ = $1;}
				| ALLOC '(' ')'			{$$ = createTree(0, "void", NULL, 25, NULL, NULL);}
				| FREE '(' expr ')'		{$$ = createTree(0, "int", NULL, 26, $3, NULL);}
				| NULLV					{$$ = createTree(0, "void", NULL, 27, NULL, NULL);}

				| NEW '(' ID ')'
				{
					if (CLookup($3, Chead) == NULL) {
						fprintf(stderr, "Error at line %d: '%s' is not a class.\n", line_no, $3);
						exit(1);
					}
					$$ = createTree(0, $3, NULL, 25, NULL, NULL);
				}

				| DELETE '(' expr ')'
				{
					if ($3->ctype == NULL) {
						fprintf(stderr, "Error at line %d: Expected a class object.\n", line_no);
						exit(1);
					}
					$$ = createTree(0, "int", NULL, 26, $3, NULL);
				}

				| NUM					{$$ = createTree($1, "int", NULL, none, NULL, NULL);}
				| ID'['expr']'			{$$ = createTree(0, NULL, $1, 19, $3, NULL);}
				| ID					{$$ = createTree(0, NULL, $1, none, NULL, NULL);}
				| STRLIT				{$$ = makeStringNode($1);}
				;

ArgList 		: ArgList ',' expr	{argpush(&arghead, $3);}
				| expr				{argpush(&arghead, $1);}
				|
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
