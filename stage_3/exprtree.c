struct tnode* createTree(int val, int type, char* varname, int nodetype, struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    if(varname == NULL) {
        temp->varname = NULL;
    }
    else {
        temp->varname = malloc(sizeof(char));
        *(temp->varname) = *varname;
    }

    //Checking type for assignment node and arithmetic nodes
    if ((type == inttype || type == booltype || nodetype == 5)  && l != NULL) {
        if ((l->type != inttype || r->type != inttype)) {
            printf("Error: Type mismatch! Expected 'inttype'\n");
            exit(1);
        }
    }

    temp->type = type;
    temp->nodetype = nodetype;
    temp->left = l;
    temp->right = r;
    return temp;
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
