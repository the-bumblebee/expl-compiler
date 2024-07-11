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
    struct Typetable *type;
    struct Paramstruct *next;
};

struct Gsymbol {
    char* name;
    struct Typetable *type;
    int size;
    int binding;
    struct Paramstruct *paramlist;
    //MOD:::
    char* flabel;
    struct Gsymbol *next;
};

struct Lsymbol {
    char* name;
    struct Typetable *type;
    int binding;
    struct Lsymbol *next;
};

struct Typetable{
    char *name;                 //type name
    int size;                   //size of the type
    struct Fieldlist *fields;   //pointer to the head of fields list
    struct Typetable *next;     // pointer to the next type table entry
};

struct Fieldlist{
  char *name;              //name of the field
  int fieldIndex;          //the position of the field in the field list
  struct Typetable *type;  //pointer to type table entry of the field's type
  struct Fieldlist *next;  //pointer to the next field
};

struct Gsymbol *Ghead;

struct Lsymbol *Lhead;

struct Paramstruct *Phead;

struct Typetable *Thead;

typedef struct tnode {
	int val;	// value of a number for NUM nodes.
	struct Typetable *type;	//type of variable.
    char* str_literal;  //Field only used for string literals.
	char* varname;	//name of a variable for ID nodes.
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.
    struct Gsymbol *Gentry;
	struct tnode *left, *right;	//left and right branches
}tnode;

struct tnode* createTree(int val, struct Typetable *type, char* varname, int nodetype, struct tnode *l, struct tnode *r);

struct tnode* makeStringNode(char* literal);

void print_properties(struct tnode *t, int i);

void deallocateAST(struct tnode *t);

struct tnode* cmpArg(struct arglist **arghead_ptr, struct Paramstruct **Fpara_ptr);

void cmpPara(struct Paramstruct **Phead_ptr, struct Paramstruct **Fpara_ptr);

struct Gsymbol *Glookup(struct Gsymbol *head, char* name);

void Ginstall(struct Gsymbol **head_ptr, char* name, struct Typetable *type, int size, struct Paramstruct **Phead);

struct Lsymbol *Llookup(struct Lsymbol *head, char* name);

void Linstall(struct Lsymbol **head_ptr, char* name, struct Typetable *type);

void Pinstall(struct Paramstruct **head_ptr, char* name, struct Typetable *type);

void TypeTableCreate();

struct Typetable *Tlookup(char* name);

void TInstall(char *name,int size, struct Fieldlist *fields);

void print_Typetable (struct Typetable **head_ptr);

int GetSize(struct Typetable *type);

void FInstall(struct Fieldlist **head_ptr, char* name, struct Typetable *type);

struct Fieldlist* FLookup(struct Fieldlist *head, char *name);

int typeCheck(struct Typetable *ltype, struct Typetable *rtype);

void print_Flist(struct Fieldlist **head_ptr);

void print_Gtable();

void print_Ltable();

void print_Ttable();

void print_Tlist();

#endif
