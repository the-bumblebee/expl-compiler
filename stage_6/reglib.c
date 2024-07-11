#include <stdio.h>
#include <stdlib.h>
//MOD:::
#include <string.h>
#include "exprtree.h"
#include "reglib.h"

int n_params;

int reg_count = -1;

//MOD:::
int label_count = -1;

int n_p = 0;

struct Gsymbol *funcGentry = NULL;

struct while_node *while_head = NULL;

int getLabel() {
    label_count += 1;
    return label_count;
}

int getReg() {
    if (reg_count >= 19) {
        fprintf(stderr, "Compiler Error: Out of registers.\n");
        return reg_count;
    }
    reg_count += 1;
    return reg_count;
}

void freeReg() {
    if (reg_count <= -1) {
        fprintf(stderr, "No register to be released.\n");
        return;
    }
    reg_count -= 1;
}

int getIDAddress(struct tnode *t) {
    //Check for ID node
    if ((t->varname == NULL || t->nodetype == 22 || t->nodetype == 23) && (t->nodetype != 24)) {
        fprintf(stderr, "Error: The node passed is not an ID node.\n");
        exit(1);
    }

    int p_reg = getReg();

    if (t->nodetype == 24) {
        struct tnode *temp;
        temp = t->left;
        int q_reg = getReg();
        struct Lsymbol *Ltemp;
        Ltemp = Llookup(Lhead, temp->varname);
        if (Ltemp == NULL) {
            struct Gsymbol *Gentry;
            Gentry = Glookup(Ghead, temp->varname);
            if (Gentry == NULL) {
                fprintf(stderr, "Compiler Error: nodetype 24, field, in getIDAddress, %s;\n", temp->varname);
                exit(1);
            }
            fprintf(target_file, "MOV R%d, %d\n", p_reg, Gentry->binding);
        }
        else {
            fprintf(target_file, "MOV R%d, BP\n", p_reg);
            fprintf(target_file, "MOV R%d, %d\n", q_reg, Ltemp->binding);
            fprintf(target_file, "ADD R%d, R%d\n", p_reg, q_reg);
        }
        while (temp->left != NULL) {
                struct Fieldlist *Flist;
                Flist = FLookup(temp->type->fields, temp->left->varname);
                fprintf(target_file, "MOV R%d, [R%d]\n", p_reg, p_reg);
                fprintf(target_file, "MOV R%d, %d\n", q_reg, Flist->fieldIndex);
                fprintf(target_file, "ADD R%d, R%d\n", p_reg, q_reg);
                temp = temp->left;
            }
            freeReg();
            return p_reg;
        }

    else if (t->left != NULL) {
        if (t->Gentry == NULL) {
            fprintf(stderr, "Compiler Error: The variable %s not declared.\n", t->varname);
            exit(1);
        }
        else if (t->Gentry->size < 1) {
            fprintf(stderr, "Compiler Error: '%s' is not an array to be indexed.\n", t->varname);
            exit(1);
        }
        int q_reg = codeGen(t->left);
        fprintf(target_file, "MOV R%d, %d\n", p_reg, t->Gentry->binding);
        fprintf(target_file, "ADD R%d, R%d\n", p_reg, q_reg);
        freeReg();
    }
    else {
        struct Lsymbol *Ltemp;
        Ltemp = Llookup(Lhead, t->varname);
        if (Ltemp == NULL) {
            if (t->Gentry == NULL) {
                fprintf(stderr, "Compiler Error: The variable %s not declared.\n", t->varname);
                exit(1);
            }
            else {
                if (t->Gentry->size < 1) {
                    fprintf(stderr, "Compiler Error: '%s' is not a variable.\n", t->varname);
                    exit(1);
                }
                fprintf(target_file, "MOV R%d, %d\n", p_reg, t->Gentry->binding);
            }
        }
        else {
            int q_reg = getReg();
            fprintf(target_file, "MOV R%d, BP\n", p_reg);
            fprintf(target_file, "MOV R%d, %d\n", q_reg, Ltemp->binding);
            fprintf(target_file, "ADD R%d, R%d\n", p_reg, q_reg);
            freeReg();
        }
    }
    return p_reg;
}

int codeGen(struct tnode *t) {
    if (t == NULL) {
        fprintf(stderr, "Compiler Error: The passed node to codeGen() is NULL.\n");
        exit(1);
    }

    //checks for ID, NUM, STRLIT leaf nodes (other leaf nodes- break, continue nodes)
    else if (t->nodetype == none) {
        int reg = getReg();
        //NUM or STRLIT node
        if(t->varname == NULL) {
            //NUM node
            if(t->str_literal == NULL) {
                fprintf(target_file, "MOV R%d, %d\n", reg, t->val);
                return reg;
            }
            //STRLIT node
            else {
                fprintf(target_file, "MOV R%d, %s\n", reg, t->str_literal);
                return reg;
            }
        }

        //ID node
        else {
            int mem_reg = getIDAddress(t);
            fprintf(target_file, "MOV R%d, [R%d]\n", reg, mem_reg);
            freeReg();//frees mem_reg
            return reg;
            }
    }

    //Arithmetic expressions
    //Filtering array nod(19), function def node(22) and function call node(23), Field(24), Free(26), Initialize(28).
    else if (t->type == Tlookup("int") && (t->nodetype != 19 && t->nodetype != 22 && t->nodetype != 23 && t->nodetype != 24 && t->nodetype != 26 && t->nodetype != 28)) {
        int p = codeGen(t->left);
        int q = codeGen(t->right);

        switch(t->nodetype) {

            //Addition
            case 1:     fprintf(target_file, "ADD R%d, R%d\n", p, q);
                        break;

            //Subtraction
            case 2:     fprintf(target_file, "SUB R%d, R%d\n", p, q);
                        break;

            //Multiplication
            case 3:     fprintf(target_file, "MUL R%d, R%d\n", p, q);
                        break;

            //Division
            case 4:     fprintf(target_file, "DIV R%d, R%d\n", p, q);
                        break;

            //Mod
            case 20:    fprintf(target_file, "MOD R%d, R%d\n", p, q);
                        break;

            default:    fprintf(stderr, "Compiler Error: Unknown nodetype inside arithmetic block in codeGen().\n");
                        print_properties(t, -1);
                        exit(1);

        }
        freeReg();
        return p;
    }

    else if (t->type == Tlookup("bool")) {
        int p = codeGen(t->left);
        int q = codeGen(t->right);

        switch(t->nodetype) {

            //Less than
            case 9:     fprintf(target_file, "LT R%d, R%d\n", p, q);
                        break;

            //Greater than
            case 10:   fprintf(target_file, "GT R%d, R%d\n", p, q);
                        break;

            //Less than/Equal to
            case 11:   fprintf(target_file, "LE R%d, R%d\n", p, q);
                        break;

            //Greater than/Equal to
            case 12:   fprintf(target_file, "GE R%d, R%d\n", p, q);
                        break;

            //Not Equal to
            case 13:   fprintf(target_file, "NE R%d, R%d\n", p, q);
                        break;

            //Equal to
            case 14:   fprintf(target_file, "EQ R%d, R%d\n", p, q);
                        break;

            default:    fprintf(stderr, "Compiler Error: Unknown nodetype inside logical block in codeGen().\n");
                        print_properties(t, -1);
                        exit(1);

        }
        freeReg();
        return p;
    }
    //Statements
    else {
        int p_reg, q_reg;
        int label_1, label_2;
        int used_reg;
        struct Lsymbol *Ltemp;

        switch (t->nodetype) {

            //Assignment
            case 5:     q_reg = codeGen(t->right);
                        p_reg = getIDAddress(t->left);
                        fprintf(target_file, "MOV [R%d], R%d\n", p_reg, q_reg);
                        freeReg();
                        freeReg();
                        break;

            //Read
            case 6:     p_reg = getReg();
                        q_reg = getIDAddress(t->left);
                        fprintf(target_file, "MOV R%d, [R%d]\n", p_reg, p_reg);
                        fprintf(target_file, "MOV R%d, \"Read\"\n", p_reg);
                        fprintf(target_file, "PUSH R%d\n", p_reg);
                        fprintf(target_file, "MOV R%d, -1\n", p_reg);
                        fprintf(target_file, "PUSH R%d\n", p_reg);
                        fprintf(target_file, "MOV R%d, R%d\n", p_reg, q_reg);
                        fprintf(target_file, "PUSH R%d\n", p_reg);
                        fprintf(target_file, "PUSH R%d\n", p_reg);
                        fprintf(target_file, "PUSH R%d\n", p_reg);
                        fprintf(target_file, "CALL 0\n");
                        fprintf(target_file, "POP R%d\n", p_reg);
                        fprintf(target_file, "POP R%d\n", p_reg);
                        fprintf(target_file, "POP R%d\n", p_reg);
                        fprintf(target_file, "POP R%d\n", p_reg);
                        fprintf(target_file, "POP R%d\n", p_reg);
                        freeReg();
                        freeReg();
                        break;

            //Write
            case 7:     p_reg = codeGen(t->left);
                        q_reg = getReg();
                        fprintf(target_file, "MOV R%d, \"Write\"\n", q_reg);
                        fprintf(target_file, "PUSH R%d\n", q_reg);
                        fprintf(target_file, "MOV R%d, -2\n", q_reg);
                        fprintf(target_file, "PUSH R%d\n", q_reg);
                        fprintf(target_file, "MOV R%d, R%d\n", q_reg, p_reg);
                        fprintf(target_file, "PUSH R%d\n", q_reg);
                        fprintf(target_file, "PUSH R%d\n", q_reg);
                        fprintf(target_file, "PUSH R%d\n", q_reg);
                        fprintf(target_file, "CALL 0\n");
                        fprintf(target_file, "POP R%d\n", q_reg);
                        fprintf(target_file, "POP R%d\n", q_reg);
                        fprintf(target_file, "POP R%d\n", q_reg);
                        fprintf(target_file, "POP R%d\n", q_reg);
                        fprintf(target_file, "POP R%d\n", q_reg);
                        freeReg();
                        freeReg();
                        break;

            //Connector
            case 8:     codeGen(t->left);
                        codeGen(t->right);
                        break;

            //if-else
            case 15:    p_reg = codeGen(t->left);
                        label_1 = getLabel();
                        label_2 = label_1;
                        fprintf(target_file, "JZ R%d, L%d\n", p_reg, label_1);
                        freeReg();
                        codeGen(t->right->left);
                        if (t->right->right != NULL) {
                            label_2 = getLabel();
                            fprintf(target_file, "JMP L%d\n", label_2);
                            fprintf(target_file, "L%d:\n", label_1);
                            codeGen(t->right->right);
                        }
                        fprintf(target_file, "L%d:\n", label_2);
                        break;

            //while
            case 16:    label_1 = getLabel();
                        label_2 = getLabel();
                        pushNode(&while_head, label_1, label_2);
                        fprintf(target_file, "L%d:\n", label_1);
                        p_reg = codeGen(t->left);
                        fprintf(target_file, "JZ R%d, L%d\n", p_reg, label_2);
                        freeReg();
                        codeGen(t->right);
                        fprintf(target_file, "JMP L%d\n", label_1);
                        fprintf(target_file, "L%d:\n", label_2);
                        removeNode(&while_head);
                        break;

            //continue
            case 17:   if(while_head != NULL) fprintf(target_file, "JMP L%d\n", while_head->l1);
                        break;

            //break
            case 18:    if(while_head != NULL) fprintf(target_file, "JMP L%d\n", while_head->l2);
                        break;

            //array
            case 19:    p_reg = getIDAddress(t);
                        fprintf(target_file, "MOV R%d, [R%d]\n", p_reg, p_reg);
                        return p_reg;
                        break;

            //return
            case 21:    p_reg = getReg();
                        if (t->left->type != funcGentry->type) {
                            fprintf(stderr, "Error: In function '%s': The return statement type is incorrect.\n", funcGentry->name);
                            exit(1);
                        }
                        Ltemp = Lhead;
                        while(Ltemp != NULL) {
                            if (Ltemp->binding > 0)
                            fprintf(target_file, "POP R%d\n", p_reg);
                            Ltemp = Ltemp->next;
                        }
                        q_reg = codeGen(t->left);
                        //MOD:::
                        if (strcmp(funcGentry->flabel, "main") != 0) {
                            fprintf(target_file, "MOV R%d, BP\n", p_reg);
                            fprintf(target_file, "ADD R%d, -2\n", p_reg);
                            fprintf(target_file, "MOV [R%d], R%d\n", p_reg, q_reg);
                            fprintf(target_file, "POP BP\n");
                            fprintf(target_file, "RET\n");
                        }
                        else {
                            fprintf(target_file, "PUSH R%d\n", q_reg);
                            fprintf(target_file, "INT 10\n");
                        }
                        freeReg();
                        freeReg();
                        break;

            //func declaration
            //MOD:::
            case 22:    fprintf(target_file, "\n.%s:\n", t->Gentry->flabel);
                        if (strcmp(t->Gentry->flabel, "main") != 0)
                            fprintf(target_file, "PUSH BP\n");
                        fprintf(target_file, "MOV BP, SP\n");
            			Ltemp = Lhead;
                        while(Ltemp != NULL) {
            		        if (Ltemp->binding > 0)
                            fprintf(target_file, "PUSH R0\n");
            		        Ltemp = Ltemp->next;
                        }
                        codeGen(t->left);
                        break;

            //func caller
            case 23:    used_reg = reg_count;
                        //Saving used registers to stack before function call.
                        while(used_reg > -1) {
                            fprintf(target_file, "PUSH R%d\n", used_reg);
                            used_reg -= 1;
                        }
                        //Arguments stored in stack.
                        if (t->left != NULL) {
                            n_p = argCode(t->left);
                        }
                        //Allocating a space in stack to store return value.
                        fprintf(target_file, "PUSH R0\n");
                        //Calling the function.
                        //MOD:::
                        fprintf(target_file, "CALL <%s>\n", t->Gentry->flabel);
                        //Popping the return value stored in stack to p_reg.
                        p_reg = getReg();
                        fprintf(target_file, "POP R%d\n", p_reg);
                        //Discarding arguments from the stack.
                        for (int i = 0; i < n_p; i++) {
                            fprintf(target_file, "POP R%d\n", p_reg + 1);
                        }
                        used_reg = 0;
                        //Retriveing used register values from the stack.
                        while (used_reg < reg_count) {
                            fprintf(target_file, "POP R%d\n", used_reg);
                            used_reg += 1;
                        }
                        return p_reg;

            case 24:    p_reg = getIDAddress(t);
                        fprintf(target_file, "MOV R%d, [R%d]\n", p_reg, p_reg);
                        return p_reg;

            case 25:    p_reg = getReg();
                        q_reg = getReg();
                        fprintf(target_file, "MOV R%d, \"Alloc\"\n", q_reg);
                        fprintf(target_file, "PUSH R%d\n", q_reg);
                        fprintf(target_file, "PUSH R%d\n", q_reg);
                        fprintf(target_file, "PUSH R%d\n", q_reg);
                        fprintf(target_file, "PUSH R%d\n", q_reg);
                        fprintf(target_file, "PUSH R%d\n", q_reg);
                        fprintf(target_file, "CALL 0\n");
                        fprintf(target_file, "POP R%d\n", p_reg);
                        fprintf(target_file, "POP R%d\n", q_reg);
                        fprintf(target_file, "POP R%d\n", q_reg);
                        fprintf(target_file, "POP R%d\n", q_reg);
                        fprintf(target_file, "POP R%d\n", q_reg);
                        freeReg();
                        q_reg = getIDAddress(t->left);
                        fprintf(target_file, "MOV [R%d], R%d\n", q_reg, p_reg);
                        freeReg();
                        freeReg();
                        break;

            case 26:    p_reg = getIDAddress(t->left);
                        q_reg = getReg();
                        fprintf(target_file, "MOV R%d, [R%d]\n", p_reg, p_reg);
                        fprintf(target_file, "MOV R%d, \"Free\"\n", q_reg);
                        fprintf(target_file, "PUSH R%d\n", q_reg);
                        fprintf(target_file, "PUSH R%d\n", p_reg);
                        fprintf(target_file, "PUSH R%d\n", q_reg);
                        fprintf(target_file, "PUSH R%d\n", q_reg);
                        fprintf(target_file, "PUSH R%d\n", q_reg);
                        fprintf(target_file, "CALL 0\n");
                        fprintf(target_file, "POP R%d\n", p_reg);
                        fprintf(target_file, "POP R%d\n", q_reg);
                        fprintf(target_file, "POP R%d\n", q_reg);
                        fprintf(target_file, "POP R%d\n", q_reg);
                        fprintf(target_file, "POP R%d\n", q_reg);
                        freeReg();
                        q_reg = getIDAddress(t->left);
                        fprintf(target_file, "MOV [R%d], -1\n", q_reg);
                        freeReg();
                        freeReg();
                        break;

            case 27:    p_reg = getReg();
                        fprintf(target_file, "MOV R%d, -1\n", p_reg);
                        return p_reg;

            case 28:    p_reg = getReg();
                        fprintf(target_file, "MOV R0, \"Heapset\"\n");
                        fprintf(target_file, "PUSH R0\n");
                        fprintf(target_file, "PUSH R0\n");
                        fprintf(target_file, "PUSH R0\n");
                        fprintf(target_file, "PUSH R0\n");
                        fprintf(target_file, "PUSH R0\n");
                        fprintf(target_file, "CALL 0\n");
                        fprintf(target_file, "POP R0\n");
                        fprintf(target_file, "POP R0\n");
                        fprintf(target_file, "POP R0\n");
                        fprintf(target_file, "POP R0\n");
                        fprintf(target_file, "POP R0\n");
                        fprintf(target_file, "MOV R%d, 1\n", p_reg);
                        return p_reg;

            default:    fprintf(stderr, "Compiler Error: Unknown nodetype inside statement block in codeGen().\n");
                        print_properties(t, -1);
                        exit(1);

            }

        return -2;

    }
}

int argCode(struct tnode *t) {
    int n_p1 = 0;
    if(t == NULL) {
        fprintf(stderr, "Compiler Error: The passed node to argCode() is NULL.\n");
        exit(1);
    }
    if(t->nodetype != 8) {
        n_p1 += 1;
        int p_reg = codeGen(t);
        fprintf(target_file, "PUSH R%d\n", p_reg);
        freeReg();
    }
    else {
        n_p1 += argCode(t->left);
        n_p1 += argCode(t->right);
    }
    return n_p1;
}
