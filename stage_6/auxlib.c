#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxlib.h"
#include "exprtree.h"

void argpush(struct arglist **arghead_ptr, struct tnode *t) {
    struct arglist *temp = (struct arglist*)malloc(sizeof(struct arglist));
    temp->t = t;
    temp->next = *arghead_ptr;
    *arghead_ptr = temp;
}

void print_arg() {
    struct arglist *argtemp;
    argtemp = arghead;
    while(argtemp != NULL) {
        printf("Node: %d Type: %d\n", argtemp->t->nodetype, argtemp->t->type);
        argtemp = argtemp->next;
    }
}

void tpush (struct type_node **thead_ptr, struct Typetable *type) {
    struct type_node *temp = (struct type_node*)malloc(sizeof(struct type_node));
    temp->type = type;
    temp->next = *thead_ptr;
    *thead_ptr = temp;
}

void tpop (struct type_node **thead_ptr) {
    if (*thead_ptr != NULL) {
        struct type_node *temp;
        temp = *thead_ptr;
        *thead_ptr = (*thead_ptr)->next;
        free(temp);
    }
}

void pushNode(struct while_node **whead_ptr, int l1, int l2) {
    struct while_node *temp;
    temp = (struct while_node*)malloc(sizeof(struct while_node));
    temp->l1 = l1;
    temp->next = *whead_ptr;
    *whead_ptr = temp;
}

void removeNode(struct while_node **head_ptr) {
    if (*head_ptr != NULL) {
        struct while_node *temp;
        temp = *head_ptr;
        *head_ptr = (*head_ptr)->next;
        free(temp);
    }
}
