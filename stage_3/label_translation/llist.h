typedef struct lnode {
   int address;
   char* label;
   struct lnode* next;
}lnode;

int getAddress(struct lnode *root, char* l);

void pushNode(struct lnode **head_ptr, char* l, int address);

struct lnode* makeNode(char* l, int address);
