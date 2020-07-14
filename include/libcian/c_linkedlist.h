#ifndef C_LINKEDLIST_H
#define C_LINKEDLIST_H
#include <stddef.h> // NULL
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node * next;
} node;

typedef struct c_ll {
    struct node* head;
    int count;
} c_ll;

c_ll* list;
//int count;       // Keeps track of number of items in list

c_ll* c_ll_init();
void c_ll_print(c_ll* list);
void c_ll_add(c_ll* list, int data);
void c_ll_remove_front(c_ll* list);
void c_ll_remove_end(c_ll* list);
int c_ll_size(c_ll* list);

#endif
