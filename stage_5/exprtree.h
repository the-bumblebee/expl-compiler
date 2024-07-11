#ifndef EXPRTREE_H
#define EXPRTREE_H

#define inttype 0
#define booltype 1
#define strtype 2
#define none -1

#include "listdef.h"

FILE *target_file;

struct Paramstruct {
    char* name;
    int type;
    struct Paramstruct *next;
};

//stage-5 - paramlist, flabel
struct Gsymbol {
    char* name;
    int type;
    int size;
    int binding;
    struct Paramstruct *paramlist;
    int flabel;
    struct Gsymbol *next;
};

struct Lsymbol {
    char* name;
    int type;
    int binding;
    struct Lsymbol *next;
};

struct Gsymbol *Ghead;

struct Lsymbol *Lhead;

struct Paramstruct *Phead;

typedef struct tnode {
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable.
    char* str_literal;  //Field only used for string literals.
	char* varname;	//name of a variable for ID nodes.
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.
    struct Gsymbol *Gentry;
	struct tnode *left, *right;	//left and right branches
}tnode;

struct tnode* createTree(int val, int type, char* varname, int nodetype, struct tnode *l, struct tnode *r);

struct tnode* makeStringNode(char* literal);

void print_properties(struct tnode *t, int i);

void deallocateAST(struct tnode *t);

struct tnode* cmpArg(struct arglist **arghead_ptr, struct Paramstruct **Fpara_ptr);

void cmpPara(struct Paramstruct **Phead_ptr, struct Paramstruct **Fpara_ptr);

struct Gsymbol *Glookup(struct Gsymbol *head, char* name);

void Ginstall(struct Gsymbol **head_ptr, char* name, int type, int size, struct Paramstruct **Phead);

struct Lsymbol *Llookup(struct Lsymbol *head, char* name);

void Linstall(struct Lsymbol **head_ptr, char* name, int type);

void Pinstall(struct Paramstruct **head_ptr, char* name, int type);

void print_Gtable();

void print_Ltable();

#endif
/*Make a leaf tnode and set the value of val field*/
/*struct tnode* makeLeafNode(int n);

struct tnode* makeVarNode(char c);

struct tnode* makeAssignNode(struct tnode *l, struct tnode *r);

struct tnode* makeConnectorNode(struct tnode *l, struct tnode *r);

struct tnode* makeReadNode(struct tnode *l);

struct tnode* makeWriteNode(struct tnode *l);*/

/*Make a tnode with opertor, left and right branches set
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);

To evaluate an expression tree
int evaluate(struct tnode *t);
*/
