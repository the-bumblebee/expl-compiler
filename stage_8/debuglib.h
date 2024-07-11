#ifndef DEBUGLIB_H
#define DEBUGLIB_H

#include <stdio.h>
#include "classlib.h"
#include "exprtree.h"

void print_Ctable(struct Classtable *Cptr);

void print_Gtable(struct Gsymbol *Gtemp);

void print_Ltable(char *fname, struct Lsymbol *Ltemp);

void print_properties(struct tnode *t, int i);

void print_Ttable(struct Typetable *Ttemp);

void print_Tlist(struct type_node *thead);

void print_Flist(struct Fieldlist *Ftemp);

#endif
