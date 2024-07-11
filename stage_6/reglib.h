#ifndef REGLIB_H
#define REGLIB_H

#include "listdef.h"

int getReg();

void freeReg();

int codeGen(struct tnode *t);

void pushNode(struct while_node **head_ptr, int l1, int l2);

void removeNode(struct while_node **head_ptr);

int getLabel();

int getIDAddress(struct tnode *t);

int argCode(struct tnode *t);

#endif
