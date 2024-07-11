#ifndef TABLELIB_H
#define TABLELIB_H

struct Gsymbol *Ghead;

struct Lsymbol *Lhead;

struct Paramstruct *Phead;

struct Typetable *Thead;


struct Gsymbol *Glookup(struct Gsymbol *head, char* name);

void Ginstall(struct Gsymbol **head_ptr, char* name, char *typename, int size, struct Paramstruct **Phead);


struct Lsymbol *Llookup(struct Lsymbol *head, char* name);

void Linstall(struct Lsymbol **head_ptr, char* name, struct Typetable *type);

void deallocateLTable();


void Pinstall(struct Paramstruct **head_ptr, char* name, struct Typetable *type);


void TypeTableCreate();

struct Typetable *Tlookup(char* name);

void TInstall(char *name,int size, struct Fieldlist *fields);

void TFieldUpdate(struct Fieldlist **Fhead_ptr);

int GetSize(struct Typetable *type);

void FInstall(struct Fieldlist **head_ptr, char* name, struct Typetable *type);

struct Fieldlist* FLookup(struct Fieldlist *head, char *name);

#endif
