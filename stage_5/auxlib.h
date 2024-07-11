#ifndef AUXLIB_H
#define AUXLIB_H

#include "listdef.h"

struct type_node *thead;
struct arglist *arghead;
struct while_node *while_head;

void argpush(struct arglist **arghead_ptr, struct tnode *t);

void print_arg();

void tpush (struct type_node **thead_ptr, int type);

void tpop (struct type_node **thead_ptr);

void pushNode(struct while_node **head_ptr, int l1, int l2);

void removeNode(struct while_node **head_ptr);

#endif
