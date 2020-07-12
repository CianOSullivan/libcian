#include "c_linkedlist.h"

node* c_ll_init() {
    count = 0;
    //head = NULL;
    head = (node*) malloc(sizeof(node));
    if (head == NULL) {
        fprintf(stderr, "Couldn't load linked list.");
        return NULL;
    }
    printf("Returning head\n");
    head->data = 1;
    head->next = NULL;
    return head;
}

void c_ll_add(node* list, int data) {
    printf("Inside add\n");
    node* current = list;
    printf("Set current\n");

    while (current->next != NULL) {
        current = current->next;
    }
    printf("Reached end of list\n");

    current->next = (node*) malloc(sizeof(node));
    current->next->data = data;
    current->next->next = NULL;
    count += 1;
}

void c_ll_remove() {
    //decrement count
    // do nothing if count < 0
}

void c_ll_print(node* list) {
    printf("Printing list\n");
    int i = 0;
    node* current = list;
    while (current != NULL) {
        printf("Element %d: %d\n", i, current->data);
        current = current->next;
        i++;
    }
    printf("Finished printing list\n");
}
