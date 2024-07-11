#ifndef EXPRTREE_H
#define EXPRTREE_H

#define none -1

#include "listdef.h"

FILE *target_file;

typedef struct tnode {
	int val;	// value of a number for NUM nodes.
	struct Typetable *type;	//type of variable.
	struct Classtable *ctype;
    char* str_literal;  //Field only used for string literals.
	char* name;	//name of a variable for ID nodes.
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.
    struct Gsymbol *Gentry;
	struct tnode *left, *right;	//left and right branches
}tnode;

struct tnode* createTree(int val, char *typename, char* name, int nodetype, struct tnode *l, struct tnode *r);

struct tnode* createFieldVar(char *typename, char *name, struct tnode *l, struct tnode *r);

void setType(struct tnode *temp);

void typeCheck(struct tnode *temp);

struct tnode* makeStringNode(char* literal);

void deallocateAST(struct tnode *t);

void initialCode(FILE *target_file);

struct tnode* cmpArg(struct arglist **arghead_ptr, struct Paramstruct **Fpara_ptr);

void cmpPara(struct Paramstruct **Phead_ptr, struct Paramstruct **Fpara_ptr);

#endif
