#ifndef LISTDEF_H
#define LISTDEF_H

struct Paramstruct {
    char* name;
    struct Typetable *type;
    struct Paramstruct *next;
};

struct Gsymbol {
    char* name;
    struct Typetable *type;
    struct Classtable *ctype;
    int size;
    int binding;
    struct Paramstruct *paramlist;
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

typedef struct arglist {
    struct tnode *t;
    struct arglist *next;
} arglist;

typedef struct type_node {
    char *name;
    struct type_node *next;
} type_node;

typedef struct while_node {
   int l1,l2;
   struct while_node* next;
}while_node;

#endif
