#define inttype 0
#define booltype 1
#define none -1

 typedef struct tnode {
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.
    //+(1), -(2), *(3), /(4), assign(5), read(6), write(7), connector(8)
	struct tnode *left, *right;	//left and right branches
}tnode;

struct tnode* createTree(int val, int type, char* varname, int nodetype, struct tnode *l, struct tnode *r);

/*Make a leaf tnode and set the value of val field*/
/*struct tnode* makeLeafNode(int n);

struct tnode* makeVarNode(char c);

struct tnode* makeAssignNode(struct tnode *l, struct tnode *r);

struct tnode* makeConnectorNode(struct tnode *l, struct tnode *r);

struct tnode* makeReadNode(struct tnode *l);

struct tnode* makeWriteNode(struct tnode *l);*/

/*Make a tnode with opertor, left and right branches set
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);

To evaluate an expression tree
int evaluate(struct tnode *t);
*/
