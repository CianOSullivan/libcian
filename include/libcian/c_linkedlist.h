#ifndef C_LINKEDLIST_H
#define C_LINKEDLIST_H
#include <stddef.h> // NULL
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node * next;
} node;

node* head;          // Pointer to head of linked list
int count;       // Keeps track of number of items in list

node* c_ll_init();
void c_ll_print(node* list);
void c_ll_add(node* list, int data);
void c_ll_remove();

#endif
