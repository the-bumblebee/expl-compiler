struct tnode* createTree(int val, int type, char* varname, int nodetype, struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->type = type;

    if(varname == NULL) {
        temp->varname = NULL;
    }
    else {
        //temp->varname = malloc(sizeof(char));
        struct Gsymbol *var_ptr = lookup(Ghead, varname);
        if (var_ptr == NULL) {
            printf("Error: Variable '%s' is not declared.\n", varname);
            exit(1);
        }
        temp->varname = strdup(varname);
        temp->type = var_ptr->type;
        temp->Gentry = var_ptr;
        //free(var_ptr);
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


    temp->nodetype = nodetype;
    temp->left = l;
    temp->right = r;
    return temp;
}

struct tnode* makeStringNode(char* literal) {
    struct tnode *temp;
    //temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp = createTree(0, strtype, NULL, none, NULL, NULL);
    temp->str_literal = strdup(literal);
    return temp;
}

struct Gsymbol *lookup(struct Gsymbol *head, char* name) {
    while(head != NULL) {
        if(strcmp(head->name, name) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

void install(struct Gsymbol **head_ptr, char* name, int type, int size) {
    struct Gsymbol *temp;
    temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    if (lookup(*head_ptr, name) != NULL) {
        printf("Error: The variable '%s' was declared earlier.\n", name);
        exit(1);
    }
    temp->name = strdup(name);
    temp->type = type;
    temp->size = size;
    if(*head_ptr == NULL) {
        temp->binding = 4096;
        *head_ptr = temp;
    }
    else {
        temp->binding = (*head_ptr)->binding + (*head_ptr)->size;
        temp->next = *head_ptr;
        *head_ptr = temp;
    }
}
/*
struct tnode* makeLeafNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    temp->e = NULL;
    return temp;
}

struct tnode* makeVarNode(char c)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    *(temp->varname) = c;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c, struct tnode *l, struct tnode *r){
    int ntype;
    switch(c){
        case '+':   ntype = 1;
                    break;

        case '-':   ntype = 2;
                    break;

        case '*':   ntype = 3;
                    break;

        case '/':   ntype = 4;
                    break;
    }
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype = ntype;
    temp->varname = NULL;
    temp->left = l;
    temp->right = r;
    return temp;
}

struct tnode* makeAssignNode(struct tnode *l, struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype = 5;
    temp->varname = NULL;
    temp->left = l;
    temp->right = r;
    return temp;
}

struct tnode* makeConnectorNode(struct tnode *l, struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype = 8;
    temp->varname = NULL;
    temp->left = l;
    temp->right = r;
    return temp;
}

struct tnode* makeReadNode(struct tnode *l){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype = 6;
    temp->varname = NULL;
    temp->left = l;
    temp->right = NULL;
    return temp;
}

struct tnode* makeWriteNode(struct tnode *l){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype = 7;
    temp->varname = NULL;
    temp->left = l;
    temp->right = NULL;
    return temp;
}
*/

/*int evaluate(struct tnode *t){

    if(t->op == NULL)
    {
        return t->val;
    }
    else{
         switch(*(t->op)){
            case '+' : return evaluate(t->left) + evaluate(t->right);
                       break;
            case '-' : return evaluate(t->left) - evaluate(t->right);
                       break;
            case '*' : return evaluate(t->left) * evaluate(t->right);
                       break;
            case '/' : return evaluate(t->left) / evaluate(t->right);
                       break;
        }
    }
}
*/
