#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"

struct type_node *thead;

int decl_flag;

struct tnode* createTree(int val, int type, char* varname, int nodetype, struct tnode *l, struct tnode *r)
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
        if (type == none) {
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
        if (l->type == strtype) {
            if (r->type != strtype) {
                printf("Error: Type mismatch! Expected 'strtype'.\n");
                exit(1);
            }
        }
        else if (l->type == inttype) {
            if (r->type != inttype) {
                printf("Error: Type mismatch! Expected 'inttype'.\n");
                exit(1);
            }
        }
    }

    //Checking type for arithmetic and boolean nodes.
    //that is nodetype = {1, 2, 3, 4, 9, 10, 11, 12, 13, 14}
    //checks for right child to filter out array nodes.
    else if ((type == inttype || type == booltype)  && r != NULL) {
        if ((l->type != inttype || r->type != inttype)) {
            printf("Error: Type mismatch! Expected 'inttype'.\n");
            exit(1);
        }
    }

    else if (nodetype == 19) {
        //Checking type of array index.
        if (l->type != inttype) {
            printf("Error: Array indices should be 'inttype'.\n");
            exit(1);
        }
        //Checking array bounds ==> implement in assembly
        //else if (temp->val < 0 || temp->val >= temp->Gentry->size) {
        //    printf("Error: Array out of bounds.\n", );
        //}
    }

    else if (nodetype == 15 || nodetype == 16) {
        if (l->type != booltype) {
            fprintf(stderr, "Type mismatch! Expected 'booltype'.\n");
            exit(1);
        }
    }
    return temp;
}

struct tnode* makeStringNode(char* literal) {
    struct tnode *temp;
    //temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp = createTree(0, strtype, NULL, none, NULL, NULL);
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

void Ginstall(struct Gsymbol **head_ptr, char* name, int type, int size, struct Paramstruct **Phead_ptr) {
    struct Gsymbol *temp;
    temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    if (Glookup(*head_ptr, name) != NULL) {
        printf("Error: The variable/function '%s' was declared earlier.\n", name);
        exit(1);
    }
    temp->name = strdup(name);
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

void Linstall(struct Lsymbol **head_ptr, char* name, int type) {
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

void Pinstall(struct Paramstruct **head_ptr, char* name, int type) {
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
        printf("Name: %s Type: %d Size: %d Binding: %d flabel: %d\n", Gtemp->name, Gtemp->type, Gtemp->size, Gtemp->binding, Gtemp->flabel);
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
        printf("Name: %s Type: %d Binding: %d\n", Ltemp->name, Ltemp->type, Ltemp->binding);
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
    fprintf(stderr, "type = %d\n", t->type);
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
