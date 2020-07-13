#include "c_linkedlist.h"

node* c_ll_init() {
    count = 0;
    //head = NULL;          // Pointer to head of linked list

    //head = NULL;
    head = (node*) malloc(sizeof(node));
    //if (head == NULL) {
    //    fprintf(stderr, "Couldn't load linked list.");
    //    return NULL;
    //}
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

void c_ll_remove_last(node* list) {
    //decrement count
    // do nothing if count < 0

    if (count == 0) {
        fprintf(stderr, "Can't remove element from empty list.");
        return;
    }

    node* current = list;

    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    count -= 1;
    printf("Removed element");
}

void c_ll_print(node* list) {
    printf("Printing list\n");
    int i = 0;
    node* current = list->next;    // Always skip head node
    while (current != NULL) {
        printf("Element %d: %d\n", i, current->data);
        current = current->next;
        i++;
    }
    printf("Finished printing list\n");
}
