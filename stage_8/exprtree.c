#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "classlib.h"
#include "tablelib.h"
#include "exprtree.h"

struct type_node *thead;

int decl_flag;
int line_no;

struct tnode* createTree(int val, char *typename, char* name, int nodetype, struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    if (typename == NULL) {
        temp->type = NULL;
        temp->ctype = NULL;
    }
    else {
        temp->type = Tlookup(typename);
        temp->ctype = CLookup(typename, Chead);
    }
    temp->nodetype = nodetype;
    temp->left = l;
    temp->right = r;
    temp->str_literal = NULL;

    if(name == NULL) {
        temp->name = NULL;
    }
    else {
        temp->name = strdup(name);
    }

    setType(temp);
    typeCheck(temp);
    return temp;
}

struct tnode* createFieldVar(char *parentTypeName, char *name, struct tnode *l, struct tnode *r) {
    struct tnode *temp = createTree(0, "void", name, none, l, r);
    struct Fieldlist *Ftemp;
    struct Classtable *parentClass;
    struct Typetable *parentType = Tlookup(parentTypeName);
    if (parentType == NULL) {
        parentClass = CLookup(parentTypeName, Chead);
        if (parentClass == NULL) {
            fprintf(stderr, "Compiler Error: In createClassVar():\n\tNo class or user-defined type named '%s'.\n", parentTypeName);
            exit(1);
        }
        Ftemp = Class_Flookup(name, parentClass);
        if (Ftemp == NULL) {
            fprintf(stderr, "Error: The class '%s' has no field named '%s'.\n", parentClass->name, name);
            exit(1);
        }
        temp->type = NULL;
        temp->ctype = Ftemp->ctype;
    }
    else {
        Ftemp = FLookup(parentType->fields, name);
        if (Ftemp == NULL) {
            fprintf(stderr, "Error: The user-defined type '%s' has no field named '%s'.\n", parentType->name, name);
            exit(1);
        }
    }

    temp->type = Ftemp->type;
    temp->ctype = Ftemp->ctype;

    return temp;
}

void setType(struct tnode* temp) {

    if (temp->nodetype == 23) {
        temp->Gentry = Glookup(Ghead, temp->name);
        if (temp->Gentry == NULL) {
            fprintf(stderr, "Error: The function '%s' does not exist.\n", temp->name);
            exit(1);
        }
        temp->type = temp->Gentry->type;
    }

    else if (temp->type == NULL && temp->ctype == NULL) {

        temp->Gentry = Glookup(Ghead, temp->name);

        switch(temp->nodetype) {

            case 19:    if (temp->Gentry == NULL) {
                            fprintf(stderr, "Error: The function or array '%s' is not declared.\n", temp->name);
                            exit(1);
                        }
                        if (temp->Gentry->size <= 1) {
                            fprintf(stderr, "Error: '%s' is not an array to be indexed.\n", temp->name);
                            exit(1);
                        }
                        temp->type = temp->Gentry->type;
                        temp->ctype = temp->Gentry->ctype;
                        break;

            case 22:    if (temp->Gentry == NULL) {
                            fprintf(stderr, "Error: The function or array '%s' is not declared.\n", temp->name);
                            exit(1);
                        }
                        if (temp->Gentry->size != 0) {
                            fprintf(stderr, "Error: '%s' is not a function (function definiton).\n", temp->name);
                            exit(1);
                        }
                        if (temp->Gentry->flabel == NULL) {
                            fprintf(stderr, "Error: The function '%s' was already defined.\n", temp->name);
                            exit(1);
                        }
                        temp->type = temp->Gentry->type;
                        temp->ctype = temp->Gentry->ctype;
                        break;

            case none:  {
                            struct Lsymbol *Ltemp;
                            Ltemp = Llookup(Lhead, temp->name);
                            if (Ltemp != NULL){
                                temp->Gentry = NULL;
                                temp->type = Ltemp->type;
                                temp->ctype = NULL;
                            }
                            else {
                                if (temp->Gentry == NULL) {
                                    fprintf(stderr, "Error: The variable '%s' is not declared.\n", temp->name);
                                    exit(1);
                                }
                                else if (temp->Gentry->size == 1 || temp->Gentry->size == 2) {
                                    temp->type = temp->Gentry->type;
                                    temp->ctype = temp->Gentry->ctype;
                                }
                                else {
                                    fprintf(stderr, "Compiler Error : '%s' has unusual properties\n", temp->name);
                                    exit(1);
                                }
                            }
                            break;
                        }

            default:    fprintf(stderr, "Compiler Error : '%s' has unusual properties\n", temp->name);
                        exit(1);

        }

    }
}

void typeCheck(struct tnode* temp) {
    switch(temp->nodetype) {

        case 5:     if (temp->left->type != NULL) {
                        //primitive
                        if (temp->left->type->fields == NULL) {
                            //left->type == right->type
                            if (temp->right->type == NULL || temp->left->type != temp->right->type) {
                                fprintf(stderr, "Error: Type mismatch! Expected '%s'.\n", temp->left->type->name);
                                exit(1);
                            }
                        }

                        //user-defined
                        else {
                            //check right user-defined or class
                            if (temp->right->type == NULL) {
                                fprintf(stderr, "Error: Type mismatch! Expected '%s' user-defined type.\n", temp->left->type->name);
                                exit(1);
                            }

                            //left = null, alloc() ["void" type] {free(expr) is "int"}
                            if (temp->right->type == Tlookup("void")) {
                                switch(temp->right->nodetype) {

                                    //alloc
                                    case 25:    break;

                                    //null
                                    case 27:    break;

                                    default:    fprintf(stderr, "Error: Type mismatch! Expected '%s' user-defined type.\n", temp->left->type->name);
                                                exit(1);

                                }
                            }

                            //left->type == right->type
                            else if (temp->left->type != temp->right->type) {
                                fprintf(stderr, "Error: Type mismatch! Expected '%s' user-defined type.\n", temp->left->type->name);
                                exit(1);
                            }
                        }
                    }

                    if (temp->left->ctype != NULL) {
                        if (temp->left->ctype != temp->right->ctype) {
                            if (temp->right->ctype->parentPtr != NULL) {
                                struct Classtable *parent = temp->right->ctype->parentPtr;
                                while(parent!=NULL) {
                                    if (temp->left->ctype == parent) {
                                        break;
                                    }
                                    parent = parent->parentPtr;
                                }
                                if (parent == NULL) {
                                    fprintf(stderr, "Error at line %d: Expected '%s' class or its child object.\n", line_no, temp->left->ctype->name);
                                    exit(1);
                                }
                            }
                            else {
                                if (temp->left->ctype != temp->right->ctype) {
                                    fprintf(stderr, "Error at line %d: Expected '%s' class or its child object.\n", line_no, temp->left->ctype->name);
                                    exit(1);
                                }
                            }
                        }
                    }

                    break;

        case 6:
        case 7:     if (temp->left->ctype != NULL) {
                        fprintf(stderr, "Error at line %d: Expected a primitive type but was given a class object.\n", line_no);
                        exit(1);
                    }
                    else if (temp->left->type != NULL && temp->left->type->fields != NULL) {
                        fprintf(stderr, "Error at line %d: Expected a primitive type but was given a user-defined type object.\n", line_no);
                        exit(1);
                    }
                    break;

        case 19:    if (temp->left->type != Tlookup("int")) {
                        fprintf(stderr, "Error: Array indices should be of type 'int'.\n");
                        exit(1);
                    }

        case 15:
        case 16:    if (temp->left->type != Tlookup("bool")) {
                        fprintf(stderr, "Error: Type mismatch! Expected 'bool' type.\n");
                        exit(1);
                    }
                    break;

        case 26:    if (temp->left->type != NULL) {
                        if (temp->left->type->fields == NULL) {
                            fprintf(stderr, "Error: '%s' is a primitive type and cannot be freed.\n", temp->left->name);
                            exit(1);
                        }
                    }
                    break;
        case 30:    break;

        default:    //Checking type for arithmetic and boolean nodes.
                    //that is nodetype = {1, 2, 3, 4, 9, 10, 11, 12, 13, 14}
                    //checks for right child to filter out array nodes.
                    if ((temp->type == Tlookup("int") || temp->type == Tlookup("bool"))  && temp->right != NULL) {
                        if (temp->type == Tlookup("bool") && temp->right->type == Tlookup("void"));
                        else if ((temp->left->type != Tlookup("int") || temp->right->type != Tlookup("int"))) {
                            printf("Error: Type mismatch! Expected 'int' type.\n");
                            exit(1);
                        }
                    }
                    break;
    }
}

struct tnode* makeStringNode(char* literal) {
    struct tnode *temp;
    //temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp = createTree(0, "str", NULL, none, NULL, NULL);
    temp->str_literal = strdup(literal);
    return temp;
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
    struct arglist *arghead_b;
    arghead_b = *arghead_ptr;
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
            argAST = createTree(0, "void", NULL, 8, argAST, (*arghead_ptr)->t);
        }
        temp = *arghead_ptr;
        *arghead_ptr = (*arghead_ptr)->next;
        temp = NULL;
        para = para->next;
    }

    if(para != NULL) {
        para = *Fpara_ptr;
        while(para != NULL) {
            printf("%s\n", para->name);
            para = para->next;
        }
        while(arghead_b != NULL) {
            printf("\n%s\n", arghead_b->t->str_literal);
            arghead_b = arghead_b->next;
        }
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

void initialCode(FILE *target_file) {
    initFuncTable();
    if (Ghead != NULL) {
        int SP;
        SP = Ghead->binding + Ghead->size;
        if (SP != Ghead->binding)
            SP = SP - 1;
        fprintf(target_file, "MOV SP, %d\n", SP);
    }
    else {
        fprintf(target_file, "MOV SP, 4096\n");
    }
}
