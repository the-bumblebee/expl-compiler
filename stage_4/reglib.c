typedef struct while_node {
   int l1,l2;
   struct while_node* next;
}while_node;

struct while_node *while_head;

void pushNode(struct while_node **head_ptr, int l1, int l2) {
    struct while_node *temp;
    temp = (struct while_node*)malloc(sizeof(struct while_node));
    temp->l1 = l1;
    temp->l2 = l2;  //allocates and stores from str
    if (*head_ptr == NULL) {
        *head_ptr = temp;
    }
    else {
        temp->next = *head_ptr;
        *head_ptr = temp;
    }

}

void removeNode(struct while_node **head_ptr) {
    if (*head_ptr != NULL) {
        struct while_node *temp;
        temp = *head_ptr;
        *head_ptr = (*head_ptr)->next;
        free(temp);
    }
}

int getLabel() {
    label_count += 1;
    return label_count;
}

int getReg() {
    if (reg_count >= 19) {
        printf("Out of registers.\n");
        return reg_count;
    }
    reg_count += 1;
    return reg_count;
}

void freeReg() {
    if (reg_count <= -1) {
        printf("No register to be released.\n");
        return;
    }
    reg_count -= 1;
}

int codeGen(struct tnode *t) {
    if (t == NULL) {
        return;
    }
    //checks for ID, NUM, STRLIT leaf nodes (other leaf nodes- break, continue nodes)

    else if (t->left == NULL && (t->type == inttype || t->type == strtype)) {
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
            int var_memory = t->Gentry->binding;//4096 + (*(t->varname) - 'a');
            fprintf(target_file, "MOV R%d, [%d]\n", reg, var_memory);
            return reg;
        }
    }

    //Arithmetic expressions
    //Filtering array node out.
    else if (t->type == inttype && t->nodetype != 19) {
        int p = codeGen(t->left);
        int q = codeGen(t->right);

        switch(t->nodetype) {

            //Addition
            case 1:   fprintf(target_file, "ADD R%d, R%d\n", p, q);
                        break;

            //Subtraction
            case 2:   fprintf(target_file, "SUB R%d, R%d\n", p, q);
                        break;

            //Multiplication
            case 3:   fprintf(target_file, "MUL R%d, R%d\n", p, q);
                        break;

            //Division
            case 4:   fprintf(target_file, "DIV R%d, R%d\n", p, q);
                        break;

            //Mod
            case 20:   fprintf(target_file, "MOD R%d, R%d\n", p, q);
                        break;

        }
        freeReg();
        return p;
    }

    else if (t->type == booltype) {
        int p = codeGen(t->left);
        int q = codeGen(t->right);

        switch(t->nodetype) {

            //Less than
            case 9:   fprintf(target_file, "LT R%d, R%d\n", p, q);
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

        }
        freeReg();
        return p;
    }
    //Statements
    else {
        int p_reg, q_reg;
        int var_memory;
        int label_1, label_2;

        switch (t->nodetype) {

            //Assignment
            case 5:     p_reg = codeGen(t->right);
                        var_memory = t->left->Gentry->binding;//4096 + (*(t->left->varname) - 'a');
                        //For array node
                        if (t->left->left != NULL) {
                            //Checks if ID is an array or not
                            if (t->left->Gentry->size == 1) {
                                printf("Error: Variable '%s' is not an array to be indexed.\n", t->left->varname);
                                exit(1);
                            }
                            q_reg = codeGen(t->left->left);
                            fprintf(target_file, "ADD R%d, %d\n", q_reg, var_memory);
                            fprintf(target_file, "MOV [R%d], R%d\n", q_reg, p_reg);
                            freeReg();
                        }
                        //For variable
                        else fprintf(target_file, "MOV [%d], R%d\n", var_memory, p_reg);
                        freeReg();
                        break;

            //Read
            case 6:     p_reg = getReg();
                        var_memory = t->left->Gentry->binding;//4096 + (*(t->left->varname) - 'a');
                        //For array node
                        if (t->left->left != NULL) {
                            //Checks if array
                            if (t->left->Gentry->size == 1) {
                                printf("Error: Variable '%s' is not an array to be indexed.\n", t->left->varname);
                                exit(1);
                            }
                            q_reg = codeGen(t->left->left);
                            fprintf(target_file, "ADD R%d, %d\n", q_reg, var_memory);
                        }
                        else {
                            q_reg = getReg();
                            fprintf(target_file, "MOV R%d, %d\n", q_reg, var_memory);
                        }
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
            case 15:
                        if (t->left->type != booltype) {
                            printf("Type mismatch! Expected 'booltype'.\n");
                            exit(1);
                        }
                        p_reg = codeGen(t->left);
                        label_1 = getLabel();
                        label_2 = label_1;
                        fprintf(target_file, "JZ R%d, L%d\n", p_reg, label_1);
                        codeGen(t->right->left);
                        if (t->right->right != NULL) {
                            label_2 = getLabel();
                            fprintf(target_file, "JMP L%d\n", label_2);
                            fprintf(target_file, "L%d:\n", label_1);
                            codeGen(t->right->right);
                        }
                        fprintf(target_file, "L%d:\n", label_2);
                        freeReg();
                        break;

            //while
            case 16:
                        if (t->left->type != booltype) {
                            printf("Type mismatch! Expected 'booltype'.\n");
                            exit(1);
                        }
                        label_1 = getLabel();
                        label_2 = getLabel();
                        pushNode(&while_head, label_1, label_2);
                        fprintf(target_file, "L%d:\n", label_1);
                        p_reg = codeGen(t->left);
                        fprintf(target_file, "JZ R%d, L%d\n", p_reg, label_2);
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
            case 19:    var_memory = t->Gentry->binding;//4096 + (*(t->varname) - 'a');
                        if (t->Gentry->size == 1) {
                            printf("Error: Variable '%s' is not an array to be indexed.\n", t->varname);
                            exit(1);
                        }
                        p_reg = codeGen(t->left);
                        q_reg = getReg();
                        fprintf(target_file, "MOV R%d, %d\n", q_reg, var_memory);
                        fprintf(target_file, "ADD R%d, R%d\n", p_reg, q_reg);
                        fprintf(target_file, "MOV R%d, [R%d]\n", p_reg, p_reg);
                        freeReg();
                        return p_reg;
                        break;

            }

        return -2;

    }
}


void writeCode() {
    fprintf(target_file, "MOV SP, 4097\n");
    int routine_reg = getReg();
    int result_reg = routine_reg - 1;
    fprintf(target_file, "MOV [4096], R%d\n", result_reg);
    fprintf(target_file, "MOV R%d, 5\nPUSH R%d\n", routine_reg, routine_reg);
    fprintf(target_file, "MOV R%d, -2\nPUSH R%d\n", routine_reg, routine_reg);
    fprintf(target_file, "PUSH R%d\n", result_reg);
    fprintf(target_file, "PUSH R%d\n", result_reg);
    fprintf(target_file, "PUSH R%d\n", result_reg);
    fprintf(target_file, "INT 7\n");
    int discard_reg = getReg();
    fprintf(target_file, "POP R%d\n", routine_reg);
    fprintf(target_file, "POP R%d\n", discard_reg);
    fprintf(target_file, "POP R%d\n", discard_reg);
    fprintf(target_file, "POP R%d\n", discard_reg);
    fprintf(target_file, "POP R%d\n", discard_reg);
    freeReg();
}
