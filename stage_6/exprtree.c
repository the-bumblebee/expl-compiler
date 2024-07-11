#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"

struct type_node *thead;

int decl_flag;

struct tnode* createTree(int val, struct Typetable *type, char* varname, int nodetype, struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->type = type;
    temp->nodetype = nodetype;
    temp->left = l;
    temp->right = r;
    temp->str_literal = NULL;
    if(varname == NULL) {
        temp->varname = NULL;
        temp->Gentry = NULL;
    }

    else if (nodetype == 23) {;
        temp->varname = strdup(varname);
        temp->Gentry = Glookup(Ghead, temp->varname);
        if (temp->Gentry == NULL) {
            fprintf(stderr, "Error: The function '%s' does not exist.\n", temp->varname);
            exit(1);
        }
        temp->type = temp->Gentry->type;
    }

    else {
        temp->varname = strdup(varname);

        //Checks if ID declared or not.
        //If block checks if variable or function declared in local or global table.
        if (type == NULL) {
            //Checks in global table
            temp->Gentry = Glookup(Ghead, temp->varname);

            //Checks left to child for array and function declaration.
            if (temp->left != NULL && temp->right == NULL) {
                if (temp->Gentry == NULL) {
                    fprintf(stderr, "Error: The function or array '%s' is not declared.\n", temp->varname);
                    exit(1);
                }
                if (temp->nodetype == 19) {
                    if (temp->Gentry->size <= 1) {
                        fprintf(stderr, "Error: '%s' is not an array to be indexed.\n", temp->varname);
                        exit(1);
                    }
                    temp->type = temp->Gentry->type;
                }
                else if (temp->nodetype == 22) {
                    if (temp->Gentry->size != 0) {
                        fprintf(stderr, "Error: '%s' is not a function (function definiton).\n", temp->varname);
                        exit(1);
                    }
                    temp->type = temp->Gentry->type;
                    //MOD:::
                    if (temp->Gentry->flabel != NULL) {
                        fprintf(stderr, "Error: The function '%s' was already defined.\n", temp->varname);
                        exit(1);
                    }
                    else {
                        temp->Gentry->flabel = strdup(varname);
                    }
                }
                else {
                    fprintf(stderr, "Compiler Error : '%s' has unusual properties\n", temp->varname);
                    print_properties(temp, -1);
                    exit(1);
                }
            }
            else if (temp->right == NULL && temp->nodetype == none) {
                struct Lsymbol *Ltemp;
                Ltemp = Llookup(Lhead, temp->varname);
                if (Ltemp != NULL){
                    temp->Gentry = NULL;
                    temp->type = Ltemp->type;
                }
                else {
                    if (temp->Gentry == NULL) {
                        fprintf(stderr, "Error: The variable '%s' is not declared.\n", temp->varname);
                        exit(1);
                    }
                    else if (temp->Gentry->size == 1) {
                        temp->type = temp->Gentry->type;
                    }
                    else {
                        fprintf(stderr, "Compiler Error : '%s' has unusual properties\n", temp->varname);
                        print_properties(temp, -1);
                        exit(1);
                    }
                }
            }
            else {
                fprintf(stderr, "Compiler Error : '%s' has unusual properties\n", temp->varname);
                print_properties(temp, -1);
                exit(1);
            }

        }

    }

    //Checking types for Assignment node
    if (nodetype == 5) {
        if (r->type != Tlookup("void"))
        {
            if (typeCheck(l->type, r->type) != 0) {
                fprintf(stderr, "Error: Type mismatch! Expected '%s'.\n", l->type->name);
                exit(1);
            }
        }
    }

    //Checking type for arithmetic and boolean nodes.
    //that is nodetype = {1, 2, 3, 4, 9, 10, 11, 12, 13, 14}
    //checks for right child to filter out array nodes.
    else if ((type == Tlookup("int") || type == Tlookup("bool"))  && r != NULL) {
        if (type == Tlookup("bool") && r->type == Tlookup("void"));
        else if ((l->type != Tlookup("int") || r->type != Tlookup("int"))) {
            printf("Error: Type mismatch! Expected 'inttype'.\n");
            exit(1);
        }
    }

    else if (nodetype == 19) {
        //Checking type of array index.
        if (l->type != Tlookup("int")) {
            printf("Error: Array indices should be 'inttype'.\n");
            exit(1);
        }
        //Checking array bounds ==> implement in assembly
        //else if (temp->val < 0 || temp->val >= temp->Gentry->size) {
        //    printf("Error: Array out of bounds.\n", );
        //}
    }

    else if (nodetype == 15 || nodetype == 16) {
        if (l->type != Tlookup("bool")) {
            fprintf(stderr, "Type mismatch! Expected 'booltype'.\n");
            exit(1);
        }
    }
    return temp;
}

struct tnode* makeStringNode(char* literal) {
    struct tnode *temp;
    //temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp = createTree(0, Tlookup("str"), NULL, none, NULL, NULL);
    temp->str_literal = strdup(literal);
    return temp;
}

struct Gsymbol *Glookup(struct Gsymbol *head, char* name) {
    while(head != NULL) {
        if(strcmp(head->name, name) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

void Ginstall(struct Gsymbol **head_ptr, char* name, struct Typetable *type, int size, struct Paramstruct **Phead_ptr) {
    struct Gsymbol *temp;
    temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    if (Glookup(*head_ptr, name) != NULL) {
        printf("Error: The variable/function '%s' was declared earlier.\n", name);
        exit(1);
    }
    temp->name = strdup(name);
    temp->flabel = NULL;
    temp->type = type;
    temp->size = size;

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
        printf("Error: The variable/function '%s' was declared earlierCin the function.\n", name);
        exit(1);
    }
    temp->name = strdup(name);
    temp->type = type;
    if(*head_ptr == NULL) {
        if (decl_flag == 0) {
            temp->binding = -3;
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

void Pinstall(struct Paramstruct **head_ptr, char* name, struct Typetable *type) {
    struct Paramstruct *temp;
    temp = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
    temp->name = strdup(name);
    temp->type = type;
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

void print_Typetable (struct Typetable **head_ptr) {
    struct Typetable *Ttemp;
    Ttemp = *head_ptr;
    printf("\n---------TypeTable---------\n");
    while(Ttemp != NULL) {
        printf("%s\n", Ttemp->name);
        Ttemp = Ttemp->next;
    }
    printf("---------------------------\n");
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
    temp->name = strdup(name);
    temp->type = type;
    temp->next = *head_ptr;
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

void print_Flist(struct Fieldlist **head_ptr) {
    struct Fieldlist *Ftemp;
    Ftemp = *head_ptr;
    printf("\n---------Fieldlist---------\n");
    while(Ftemp != NULL) {
        printf("%s %d\n", Ftemp->name, Ftemp->fieldIndex);
        Ftemp = Ftemp->next;
    }
    printf("---------------------------\n");
}

void cmpPara(struct Paramstruct **Phead_ptr, struct Paramstruct **Fpara_ptr) {
    struct Paramstruct *temp = NULL;
    struct Paramstruct *para = NULL;
    para = *Fpara_ptr;
    while(*Phead_ptr != NULL) {
        if (para == NULL) {
            fprintf(stderr, "Error: Number of parameters is incorrect in function definition.\n");
            exit(1);
        }
        if (strcmp(para->name, (*Phead_ptr)->name) != 0 || para->type != (*Phead_ptr)->type) {
            fprintf(stderr, "Error: Parameter names and/or types in function definiton shows conflicts.\n");
            exit(1);
        }
        temp = *Phead_ptr;
        *Phead_ptr = (*Phead_ptr)->next;
        para = para->next;
        free(temp);
    }

    //isnt it para??
    if(*Phead_ptr != NULL) {
        fprintf(stderr, "Error: Parameter lengths do not match up.\n");
        exit(1);
    }
}

struct tnode* cmpArg(struct arglist **arghead_ptr, struct Paramstruct **Fpara_ptr) {
    struct arglist *temp = NULL;
    struct Paramstruct *para = NULL;
    struct tnode *argAST = NULL;
    argAST = NULL;
    para = *Fpara_ptr;
    while(*arghead_ptr != NULL) {
        if (para == NULL) {
            fprintf(stderr, "Error: Number of arguments is incorrect.\n");
            exit(1);
        }
        if (para->type != (*arghead_ptr)->t->type) {
            fprintf(stderr, "Error: The given argument has different type (Arg name: '%s').\n", para->name);
            exit(1);
        }
        if (argAST == NULL) {
            argAST = (*arghead_ptr)->t;
        }
        else {
            argAST = createTree(0, inttype, NULL, 8, argAST, (*arghead_ptr)->t);
        }
        temp = *arghead_ptr;
        *arghead_ptr = (*arghead_ptr)->next;
        temp = NULL;
        para = para->next;
    }

    if(para != NULL) {
        fprintf(stderr, "Error: Too few arguments given %s %d.\n", para->name, para->type);
        exit(1);
    }

    return argAST;
}

void deallocateAST(struct tnode *t) {
    if (t == NULL)
        return;
    deallocateAST(t->left);
    deallocateAST(t->right);
    free(t);
    t = NULL;
}

void print_Gtable() {
    printf("\n----Contents of Global table----\n\n");
    struct Gsymbol *Gtemp;
    Gtemp = Ghead;
    if (Gtemp == NULL) {
        printf("Local table is empty.\n");
    }
    while (Gtemp != NULL) {
        printf("Name: %s Type: %s Size: %d Binding: %d flabel: %d\n", Gtemp->name, Gtemp->type->name, Gtemp->size, Gtemp->binding, Gtemp->flabel);
        if (Gtemp->paramlist != NULL) {
            struct Paramstruct *para;
            para = Gtemp->paramlist;
            while(para != NULL) {
                printf("==>Name: %s Type: %d \n", para->name, para->type);
                para = para->next;
            }
        }
        Gtemp = Gtemp->next;
    }
    printf("--------------------------------\n\n");
}

void print_Ltable(char *fname) {
    printf("\n----Contents of local table ----\n");
    printf("Function: %s\n", fname);
    struct Lsymbol *Ltemp;
    Ltemp = Lhead;
    if (Ltemp == NULL) {
        printf("Local table is empty.\n");
    }
    while (Ltemp != NULL) {
        printf("Name: %s Type: %s Binding: %d\n", Ltemp->name, Ltemp->type->name, Ltemp->binding);
        Ltemp = Ltemp->next;
    }
    printf("-------------------------------\n\n");
}

void print_properties(struct tnode *t, int i) {
    if (t == NULL) {
        fprintf(stderr, "Compiler Error: The node passed to print_properties() is NULL.\n");
        exit(1);
    }
    fprintf(stderr, "\nval = %d\n", t->val);
    fprintf(stderr, "type = %s\n", t->type->name);
    if (t->varname != NULL)
        fprintf(stderr, "varname = %s\n", t->varname);

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
            if (i > 0);
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

void print_Ttable() {
    if (Thead == NULL) {
        printf("Type table is empty.\n");
    }
    else {
        struct Typetable *temp;
        temp = Thead;
        while(temp != NULL) {
            printf ("%s\n", temp->name);
            temp = temp->next;
        }
    }
}

void print_Tlist() {
    if (thead == NULL) {
        printf("No type.\n");
    }
    else {
        struct type_node *temp;
        temp = thead;
        while(temp != NULL) {
            printf ("%s\n", temp->type->name);
            temp = temp->next;
        }
    }
}

int typeCheck(struct Typetable *ltype, struct Typetable *rtype) {
    if (ltype == rtype)
        return 0;
    else
        return 1;
}
