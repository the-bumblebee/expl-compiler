#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classlib.h"
#include "tablelib.h"

struct Classtable* CInstall(char *name, char *parentClassName, struct Classtable *Cptr) {
    if (name == NULL) {
        fprintf(stderr, "Compiler Error: 'name' passed to CInstall() is NULL.\n");
        exit(1);
    }
    if (Tlookup(name) != NULL) {
        fprintf(stderr, "Error: Cannot create class. A user-defined type with same name '%s' exists.\n", name);
        exit(1);
    }
    if (CLookup(name, Chead) != NULL) {
        fprintf(stderr, "Error: Cannot create class. A class with same name '%s' exists.\n", name);
        exit(1);
    }
    struct Classtable *Ctemp = (struct Classtable*)malloc(sizeof(struct Classtable));
    Ctemp->name = strdup(name);
    Ctemp->fieldPtr = NULL;
    Ctemp->methodPtr = NULL;
    Ctemp->fieldCount = 0;
    Ctemp->methodCount = 0;

    if (parentClassName == NULL) {
        Ctemp->parentPtr = NULL;
    }
    else {
        Ctemp->parentPtr = CLookup(parentClassName, Cptr);
    }

    if (Cptr == NULL) {
        Ctemp->classIndex = 0;
        Ctemp->next = NULL;
    }
    else {
        Ctemp->classIndex = Chead->classIndex + 1;
        Ctemp->next = Cptr;
    }
    Cptr = Ctemp;
    return Cptr;
}

struct Classtable* CLookup(char *name, struct Classtable *Cptr) {
    struct Classtable *Ctemp;
    Ctemp = Cptr;
    while(Ctemp != NULL) {
        if (strcmp(Ctemp->name, name) == 0)
            return Ctemp;
        Ctemp = Ctemp->next;
    }
    return NULL;
}

void Class_FInstall(char *name, char *typename, struct Classtable *Cptr) {
    struct Fieldlist *Ftemp = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
    if (Class_Flookup(name, Cptr) != NULL) {
        fprintf(stderr, "Error: '%s' field exists within the '%s' class\n", name, Cptr->name);
        exit(1);
    }
    if (Cptr->fieldCount >= 8) {
        fprintf(stderr, "Error: The number of fields exceeds 8.\n");
        exit(1);
    }
    Ftemp->name = strdup(name);
    Ftemp->type = Tlookup(typename);
    Ftemp->ctype = CLookup(typename, Cptr);
    Ftemp->next = Cptr->fieldPtr;
    if (Cptr->fieldPtr == NULL)
        Ftemp->fieldIndex = 0;
    else
        Ftemp->fieldIndex = Cptr->fieldPtr->fieldIndex + 1;
    Cptr->fieldPtr = Ftemp;
    Cptr->fieldCount += 1;
}

void Class_MInstall(char *name, struct Typetable *type, struct Paramstruct *paramList, struct Classtable *Cptr) {
    struct Methodlist *Mtemp = (struct Methodlist*)malloc(sizeof(struct Methodlist));
    if (Class_MLookup(name, Cptr) != NULL) {
        fprintf(stderr, "Error: '%s' method exists within the '%s' class\n", name, Cptr->name);
        exit(1);
    }
    if (Cptr->methodCount >= 8) {
        fprintf(stderr, "Error: The number of methods exceeds 8.\n");
        exit(1);
    }
    Mtemp->name = strdup(name);
    Mtemp->type = type;
    Mtemp->paramList = paramList;
    Mtemp->flabel = NULL;
    Mtemp->next = Cptr->methodPtr;
    if (Cptr->methodPtr == NULL)
        Mtemp->funcIndex = 0;
    else
        Mtemp->funcIndex = Cptr->methodPtr->funcIndex + 1;
    Cptr->methodPtr = Mtemp;
    Cptr->methodCount += 1;
}

struct Methodlist* Class_MLookup(char* name, struct Classtable *Cptr) {
    struct Methodlist *Mtemp;
    Mtemp = Cptr->methodPtr;
    while (Mtemp != NULL) {
        if (strcmp(Mtemp->name, name) == 0)
            return Mtemp;
        Mtemp = Mtemp->next;
    }
    return NULL;
}

struct Fieldlist* Class_Flookup(char *name, struct Classtable *Cptr) {
    struct Fieldlist *Ftemp;
    Ftemp = Cptr->fieldPtr;
    while (Ftemp != NULL) {
        if (strcmp(Ftemp->name, name) == 0)
            return Ftemp;
        Ftemp = Ftemp->next;
    }
    return NULL;
}
