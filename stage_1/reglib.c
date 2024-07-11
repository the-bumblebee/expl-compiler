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

    if(t->op == NULL) {

        int reg = getReg();
        fprintf(target_file, "MOV R%d, %d\n", reg, t->val);
        return reg;

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
