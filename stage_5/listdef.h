#ifndef LISTDEF_H
#define LISTDEF_H

typedef struct arglist {
    struct tnode *t;
    struct arglist *next;
} arglist;

typedef struct type_node {
    int type;
    struct type_node *next;
} type_node;

typedef struct while_node {
   int l1,l2;
   struct while_node* next;
}while_node;

#endif
