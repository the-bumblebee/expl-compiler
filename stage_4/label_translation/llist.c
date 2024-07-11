#include<stdio.h>

typedef struct lnode {
   int address;
   char* label;
   struct lnode* next;
}lnode;

int getAddress(struct lnode *root, char* l) {

    if(root == NULL) {
        return -1;
    }

    else if(strcmp(root->label, l) == 0) {
        return root->address;
    }

    else if(root->next != NULL){
        return getAddress(root->next, l);
    }

    else{
        return -2;
    }
}

void pushNode(struct lnode **head_ptr, char* l, int address) {
    struct lnode *temp;
    char str[strlen(l) - 1];        //array to store label without colon
    temp = (struct lnode*)malloc(sizeof(struct lnode));
    temp->address = address;
    for(int i = 0; i < strlen(l) - 1; i++) {
        str[i] = l[i];
    }
    str[strlen(l) - 2] = '\0';  //end character
    temp->label = strdup(str);  //allocates and stores from str
    if (*head_ptr == NULL) {
        *head_ptr = temp;
    }
    else {
        temp->next = *head_ptr;
        *head_ptr = temp;
    }

}
