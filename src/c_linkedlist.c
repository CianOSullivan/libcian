#include "c_linkedlist.h"

c_ll* c_ll_init() {

    //head = NULL;          // Pointer to head of linked list

    //head = NULL;
    list = (c_ll*) malloc(sizeof(c_ll));
    list->count = 0;
    list->head = (node*) malloc(sizeof(node));
    //if (head == NULL) {
    //    fprintf(stderr, "Couldn't load linked list.");
    //    return NULL;
    //}
    printf("Returning head\n");
    list->head->data = 1;
    list->head->next = NULL;
    return list;
}

void c_ll_add(c_ll* list, int data) {
    printf("Inside add\n");
    node* current = list->head;
    printf("Set current\n");

    while (current->next != NULL) {
        current = current->next;
    }
    printf("Reached end of list\n");

    current->next = (node*) malloc(sizeof(node));
    current->next->data = data;
    current->next->next = NULL;
    list->count += 1;
}


void c_ll_remove_front(c_ll* head) {
    printf("Removed first item\n");
    //node* current = head->next; // Skip first node
}

void c_ll_remove_end(c_ll* list) {
    if (list->count == 0) {
        fprintf(stderr, "Can't remove element from empty list.");
        return;
    }

    node* current = list->head;

    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    list->count -= 1;
    printf("Removed element");
}

void c_ll_print(c_ll* list) {
    printf("Printing list\n");
    int i = 0;
    node* current = list->head->next;    // Always skip head node
    while (current != NULL) {
        printf("Element %d: %d\n", i, current->data);
        current = current->next;
        i++;
    }
    printf("Finished printing list\n");
}

int c_ll_size(c_ll* list) {
    return list->count;
}
