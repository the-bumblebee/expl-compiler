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

/*int codeGen(struct tnode *t) {
    if(t->op == NULL) {
        int p = getReg();
        fprintf(target_file, "MOV R%d, %d\n", p, t->val);
        return p;
    }
    else {
        int p = codeGen(t->left);
        int q = codeGen(t->right);
        switch(*(t->op)) {
            case '+':   fprintf(target_file, "ADD R%d, R%d\n", p, q);
                        break;
            case '-':   fprintf(target_file, "SUB R%d, R%d\n", p, q);
                        break;
            case '*':   fprintf(target_file, "MUL R%d, R%d\n", p, q);
                        break;
            case '/':   fprintf(target_file, "DIV R%d, R%d\n", p, q);
                        break;
        }
        freeReg();
        return p;
    }
}*/

int codeGen(struct tnode *t) {
    if(t->left == NULL) {

        if(t->varname == NULL) {
            int reg = getReg();
            fprintf(target_file, "MOV R%d, %d\n", reg, t->val);
            return reg;
        }

        else {
            int reg = getReg();
            int var_memory = 4096 + (*(t->varname) - 'a');
            fprintf(target_file, "MOV R%d, [%d]\n", reg, var_memory);
            return reg;
        }
    }

    //Statements
    else if(t->nodetype > 4) {
        int p_reg, q_reg;
        int var_memory;

        switch (t->nodetype) {

            //Assignment
            case 5:     p_reg = codeGen(t->right);
                        var_memory = 4096 + (*(t->left->varname) - 'a');
                        fprintf(target_file, "MOV [%d], R%d\n", var_memory, p_reg);
                        freeReg();
                        break;

            //Read
            case 6:     p_reg = getReg();
                        var_memory = 4096 + (*(t->left->varname) - 'a');
                        fprintf(target_file, "MOV R%d, \"Read\"\n", p_reg);
                        fprintf(target_file, "PUSH R%d\n", p_reg);
                        fprintf(target_file, "MOV R%d, -1\n", p_reg);
                        fprintf(target_file, "PUSH R%d\n", p_reg);
                        fprintf(target_file, "MOV R%d, %d\n", p_reg, var_memory);
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
            }

        return -2;

    }

    //Arithmetic operations
    else {
        int p = codeGen(t->left);
        int q = codeGen(t->right);

        switch(t->nodetype) {

            //Addition
            case 1:   fprintf(target_file, "ADD R%d, R%d\n", p, q);
                        break;

            case 2:   fprintf(target_file, "SUB R%d, R%d\n", p, q);
                        break;

            case 3:   fprintf(target_file, "MUL R%d, R%d\n", p, q);
                        break;

            case 4:   fprintf(target_file, "DIV R%d, R%d\n", p, q);
                        break;

        }
        freeReg();
        return p;
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
