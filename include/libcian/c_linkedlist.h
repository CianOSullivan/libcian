#ifndef C_LINKEDLIST_H
#define C_LINKEDLIST_H
#include <stddef.h> // NULL

typedef struct node {
    int data;
    struct node * next;
} node;

node* head = NULL;   // Pointer to head of linked list
int count = 0;       // Keeps track of number of items in list

void c_ll_init();
void c_ll_print();
void c_ll_add(int data);
void c_ll_remove();

#endif
