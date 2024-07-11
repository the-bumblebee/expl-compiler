#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listdef.h"
#include "classlib.h"
#include "tablelib.h"

int decl_flag, class_flag;
FILE *target_file;

struct Gsymbol *Glookup(struct Gsymbol *head, char* name) {
    while(head != NULL) {
        if(strcmp(head->name, name) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

void Ginstall(struct Gsymbol **head_ptr, char* name, char *typename, int size, struct Paramstruct **Phead_ptr) {
    struct Gsymbol *temp;
    temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    if (Glookup(*head_ptr, name) != NULL) {
        printf("Error: The variable/function '%s' was declared earlier.\n", name);
        exit(1);
    }
    temp->name = strdup(name);
    temp->flabel = NULL;
    temp->type = Tlookup(typename);
    temp->ctype = CLookup(typename, Chead);
    temp->size = size;

    if (temp->size != 1 && temp->ctype != NULL) {
        fprintf(stderr, "Error: Syntax for declaring a '%s' object is incorrect.\n", temp->ctype->name);
        exit(1);
    }
    //if-else required to avoid segmentation fault when variables are declared.
    //For variables Phead_ptr = NULL.
    //For functions Phead_ptr != NULL.
    if (Phead_ptr == NULL) {
        temp->paramlist = NULL;
    }
    else {
        temp->paramlist = *Phead_ptr;
    }

    if(*head_ptr == NULL) {
        temp->binding = 4096;
        *head_ptr = temp;
        (*head_ptr)->next = NULL;
    }
    else {
        temp->binding = (*head_ptr)->binding + (*head_ptr)->size;
        temp->next = *head_ptr;
        *head_ptr = temp;
    }

}

struct Lsymbol *Llookup(struct Lsymbol *head, char* name) {
    while(head != NULL) {
        if(strcmp(head->name, name) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

void Linstall(struct Lsymbol **head_ptr, char* name, struct Typetable *type) {
    struct Lsymbol *temp;
    temp = malloc(sizeof(struct Gsymbol));
    if (Llookup(*head_ptr, name) != NULL) {
        printf("Error: The variable/function '%s' was declared earlier in the function.\n", name);
        exit(1);
    }
    temp->name = strdup(name);
    temp->type = type;
    if (temp->type == NULL) {
        fprintf(stderr, "Error: Local variables cannot be instances of a class (variable name: '%s').\n", name);
        exit(1);
    }
    if(*head_ptr == NULL) {
        if (decl_flag == 0 && class_flag == 0) {
            temp->binding = -3;
        }
        else if (decl_flag == 0 && class_flag == 1) {
            temp->binding = -4;
        }
        else {
            temp->binding = 1;
        }
        *head_ptr = temp;
        (*head_ptr)->next = NULL;
    }
    else {
        if (decl_flag == 0) {
            temp->binding = (*head_ptr)->binding - 1;
        }
        else if ((*head_ptr)->binding < 0) {
            temp->binding = 1;
        }
        else {
            temp->binding = (*head_ptr)->binding + 1;
        }
        temp->next = *head_ptr;
        *head_ptr = temp;
    }
}

void deallocateLTable() {
    struct Lsymbol *Ltemp;
    while (Lhead != NULL) {
        Ltemp = Lhead;
        Lhead = Lhead->next;
        free(Ltemp);
    }
}

void Pinstall(struct Paramstruct **head_ptr, char* name, struct Typetable *type) {
    struct Paramstruct *temp;
    temp = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
    temp->name = strdup(name);
    temp->type = type;
    if (temp->type == NULL) {
        fprintf(stderr, "Error: Functions do not support class objects as arguments (arg: '%s').\n", name);
        exit(1);
    }
    if(*head_ptr == NULL) {
        *head_ptr = temp;
        (*head_ptr)->next = NULL;
    }
    else {
        temp->next = *head_ptr;
        *head_ptr = temp;
    }
}

void TypeTableCreate(struct Typetable **head_ptr) {
    Thead = (struct Typetable*)malloc(sizeof(struct Typetable));
    Thead->name = strdup("void");
    Thead->size = 0;
    Thead->fields = NULL;
    Thead->next = NULL;
    char tlist[3][5] = {"bool", "str", "int"};
    struct Typetable *temp;
    for (int i = 0; i < 3; i++) {
        temp = (struct Typetable*)malloc(sizeof(struct Typetable));
        temp->name = strdup(tlist[i]);
        temp->size = 1;
        temp->fields = NULL;
        temp->next = Thead;
        Thead = temp;
    }
    fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
    fprintf(target_file, "JMP <main>\n");
}

struct Typetable *Tlookup(char* name) {
    struct Typetable *head;
    head = Thead;
    while(head != NULL) {
        if(strcmp(head->name, name) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

void TInstall(char *name,int size, struct Fieldlist *fields) {
    struct Typetable *temp;
    temp = (struct Typetable *)malloc(sizeof(struct Typetable));
    if (Tlookup(name) !=NULL) {
        fprintf(stderr, "Error: The type '%s' is already defined.\n", name);
        exit(1);
    }
    temp->name = strdup(name);
    temp->size = size;
    temp->fields = fields;
    temp->next = Thead;
    Thead = temp;
}

void TFieldUpdate(struct Fieldlist **Fhead_ptr) {
    if (Thead->fields != NULL) {
        printf("Compiler Error: Assigning a Fieldlist pointer to a non-NULL fields member of '%s' type.", Thead->name);
        exit(1);
    }
    Thead->fields = *Fhead_ptr;
    *Fhead_ptr = NULL;
}

int GetSize(struct Typetable *type) {
    int size = 0;
    struct Fieldlist *field;
    field = type->fields;
    while (field != NULL) {
        size += field->type->size;
        field = field->next;
    }
    type->size = size;
    return size;
}

void FInstall(struct Fieldlist **head_ptr, char* name, struct Typetable *type) {
    struct Fieldlist *temp;
    temp = (struct Fieldlist *)malloc(sizeof(struct Fieldlist));
    if (FLookup (*head_ptr, name) != NULL)
    {
        fprintf (stderr, "Error: The field with name '%s' already exists.\n", name);
        exit(1);
    }
    if (*head_ptr != NULL && (*head_ptr)->fieldIndex >= Thead->size - 1) {
        fprintf(stderr, "Error: Total size of the field numbers exceeds %d (Maximum allowed size) for '%s' user-defined type.\n", Thead->size, Thead->name);
        exit(1);
    }
    temp->name = strdup(name);
    temp->type = type;
    temp->ctype = NULL;
    temp->next = *head_ptr;
    if ((*head_ptr) == NULL)
        temp->fieldIndex = 0;
    else
        temp->fieldIndex = (*head_ptr)->fieldIndex + 1;
    *head_ptr = temp;
}

struct Fieldlist* FLookup(struct Fieldlist *head, char *name) {
    struct Fieldlist *field;
    field = head;
    while (field != NULL) {
        if (strcmp(field->name, name) == 0)
            return field;
        field = field->next;
    }
    return NULL;
}
