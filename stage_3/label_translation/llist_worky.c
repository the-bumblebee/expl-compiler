#include<stdio.h>

typedef struct lnode {
   int address;
   char* label;
   struct lnode* next;
}lnode;

int getAddress(struct lnode *root, char* l) {
    if(strcmp(root->label, l) == 0) {
        return root->address;
    }
    else if (!(root)) {
        return 1;
    }
    else {
        return -1;//getAddress(root->next, char* l);
    }
}

char* label(char* s) {
    char t[strlen(s)];
    //t = malloc(strlen(s) - 1);
    /*for(int i = 0; i < strlen(s) - 1; i++) {
        t[i] = s[i];
    }*/
    //t[strlen(s) - 1] = 0;
    strcpy(t, s);
    t[strlen(s) - 1] = 0;
    //printf("%s %d %d\n", t, strlen(t), strlen(s));
    return t;
}


void pushNode(struct lnode **head_ptr, char* l, int address) {
    if (!*head_ptr) {
        struct lnode *temp;
        char str[strlen(l)];        //array to store label without colon
        temp = (struct lnode*)malloc(sizeof(struct lnode));
        temp->address = address;
        //printf("%s\n", l);
        for(int i = 0; i < strlen(l) - 1; i++) {
            str[i] = l[i];
        }
        str[strlen(l) - 1] = '\0';  //end character
        //str = label(l);
        //temp->label = malloc(strlen(str) + 1);
        //strcpy(temp->label, l);
        //strcpy(temp->label, l);
        temp->label = strdup(str);  //allocates and stores from str
        temp->next = NULL;
        //return temp;
        *(head_ptr) = temp;
    }
    else {
        pushNode(&((*head_ptr)->next), l, address);
    }

}

/*
int main() {
    struct lnode *head=NULL;
    //root = (struct lnode*)malloc(sizeof(struct lnode));
    char src[] = "L0:";
    char src1[] = "L1:";
    pushNode(&head, src, 23);
    pushNode(&head, src1, 54);
    printf("%d\n", head->address);
    printf("%s\n", head->next->label);
    return 1;
}
*/
