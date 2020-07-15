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

/**
Adds data to end of linked list.
 */
void c_ll_add(c_ll* list, int data);

/**
Adds data to start of linked list.
 */
void c_ll_add_start(c_ll* list, int data);

/**
Remove data at start of linked list.
 */
void c_ll_remove_front(c_ll* list);

/**
Remove data from end of linked list.
 */
void c_ll_remove_end(c_ll* list);

/**
Remove data at the given index.
 */
void c_ll_remove_at(c_ll* list, int index);

node* c_ll_get(c_ll* list, int index);

int c_ll_size(c_ll* list);

#endif
