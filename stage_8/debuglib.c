#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classlib.h"
#include "exprtree.h"
#include "debuglib.h"

void print_Ctable(struct Classtable *Cptr) {
    printf("\nClasses------------------\n");
    while (Cptr != NULL) {
        printf("\n-----%d. %s-----\n", Cptr->classIndex, Cptr->name);
        printf("fieldCount: %d\n", Cptr->fieldCount);
        printf("methodCount: %d\n", Cptr->methodCount);
        if (Cptr->fieldPtr != NULL) {
            printf("\n\t--- Fields ---\n");
            struct Fieldlist *Ftemp;
            Ftemp = Cptr->fieldPtr;
            while (Ftemp != NULL) {
                if (Ftemp->type != NULL)
                    printf("    %d. Name: %s Type: %s\n", Ftemp->fieldIndex, Ftemp->name, Ftemp->type->name);
                else if (Ftemp->ctype != NULL)
                    printf("    %d. Name: %s ClassType: %s\n", Ftemp->fieldIndex, Ftemp->name, Ftemp->ctype->name);
                Ftemp = Ftemp->next;
            }
            printf("\t-----------\n");
        }
        if (Cptr->methodPtr != NULL) {
            printf("\n\t--- Methods ---\n");
            struct Methodlist *Mtemp;
            struct Paramstruct *Ptemp;
            Mtemp = Cptr->methodPtr;
            while (Mtemp != NULL) {
                Ptemp = Mtemp->paramList;
                printf("    %d. Name: %s Type: %s flabel: %s\n", Mtemp->funcIndex, Mtemp->name, Mtemp->type->name, Mtemp->flabel);
                while(Ptemp != NULL) {
                    printf("    ==> Name: %s Type: %s\n", Ptemp->name, Ptemp->type->name);
                    Ptemp = Ptemp->next;
                }
                Mtemp = Mtemp->next;
            }
            printf("\t-----------\n");
        }
        Cptr = Cptr->next;
    }
    printf("------------------------\n");
}

void print_Gtable(struct Gsymbol *Gtemp) {
    printf("\n----Contents of Global table----\n\n");
    if (Gtemp == NULL) {
        printf("Global table is empty.\n");
    }
    while (Gtemp != NULL) {
        if (Gtemp->type != NULL)
            printf("Name: %s Type: %s Size: %d Binding: %d ", Gtemp->name, Gtemp->type->name, Gtemp->size, Gtemp->binding);
        else if (Gtemp->ctype != NULL)
            printf("Name: %s ClassType: %s Size: %d Binding: %d ", Gtemp->name, Gtemp->ctype->name, Gtemp->size, Gtemp->binding);
        if (Gtemp->flabel == NULL)
            printf("flabel: %s\n", Gtemp->flabel);
        else
            printf("\n");
        if (Gtemp->paramlist != NULL) {
            struct Paramstruct *para;
            para = Gtemp->paramlist;
            while(para != NULL) {
                printf("==>Name: %s Type: %s \n", para->name, para->type->name);
                para = para->next;
            }
        }
        Gtemp = Gtemp->next;
    }
    printf("--------------------------------\n\n");
}

void print_Ltable(char *fname, struct Lsymbol *Ltemp) {
    printf("\n----Contents of local table----\n");
    printf("Function: %s\n", fname);
    if (Ltemp == NULL) {
        printf("Local table is empty.\n");
    }
    while (Ltemp != NULL) {
        printf("Name: %s Type: %s Binding: %d\n", Ltemp->name, Ltemp->type->name, Ltemp->binding);
        Ltemp = Ltemp->next;
    }
    printf("--------------------------------\n\n");
}

void print_properties(struct tnode *t, int i) {
    if (t == NULL) {
        fprintf(stderr, "Compiler Error: The node passed to print_properties() is NULL.\n");
        exit(1);
    }
    fprintf(stderr, "\nval = %d\n", t->val);

    if (t->type != NULL)
        fprintf(stderr, "type = %s\n", t->type->name);

    if (t->ctype != NULL)
        fprintf(stderr, "ctype = %s\n", t->ctype->name);

    if (t->name != NULL)
        fprintf(stderr, "name = %s\n", t->name);

    fprintf(stderr, "nodetype = %d\n", t->nodetype);

    if (t->str_literal != NULL)
        fprintf(stderr, "str_literal = %s\n", t->str_literal);

    if (t->left != NULL)
        fprintf(stderr, "left = True\n");

    if (t->right != NULL)
        fprintf(stderr, "right = True\n");

    if (t->Gentry != NULL) {
        fprintf(stderr, "Global table entry:\n");
        fprintf(stderr, "\tname = %s\n", t->Gentry->name);
        fprintf(stderr, "\ttype = %d\n", t->Gentry->type);
        fprintf(stderr, "\tsize = %d\n", t->Gentry->size);
        fprintf(stderr, "\tbinding = %d\n", t->Gentry->binding);
        fprintf(stderr, "\tflabel = %d\n", t->Gentry->flabel);
        if (t->Gentry->paramlist != NULL)
            fprintf(stderr, "paramlist = True\n");
    }

    if (i != 0) {
        if (t->left != NULL || t->right != NULL) {
            if (i > 0)
                i = i - 1;
            if (t->left != NULL) {
                fprintf(stderr, "\nLeft child (%d):\n", i);
                print_properties(t->left, i);
            }
            if (t->right != NULL) {
                fprintf(stderr, "\nRight child (%d):\n", i);
                print_properties(t->right, i);
            }
        }
    }
}

void print_Ttable(struct Typetable *Ttemp) {
    printf("-----------Type Table-----------\n");
    if (Ttemp == NULL) {
        printf("Type table is empty.\n");
    }
    else {
        while(Ttemp != NULL) {
            printf ("%s\n", Ttemp->name);
            Ttemp = Ttemp->next;
        }
    }
    printf("--------------------------------\n");
}

void print_Tlist(struct type_node *thead) {
    printf("-----------Type List------------\n");
    if (thead == NULL) {
        printf("No type in type list.\n");
    }
    else {
        while(thead != NULL) {
            printf ("%s\n", thead->name);
            thead = thead->next;
        }
    }
    printf("--------------------------------\n");
}

void print_Flist(struct Fieldlist *Ftemp) {
    printf("\n----------Field List----------\n");
    while(Ftemp != NULL) {
        printf("%s %d\n", Ftemp->name, Ftemp->fieldIndex);
        Ftemp = Ftemp->next;
    }
    printf("--------------------------------\n");
}
