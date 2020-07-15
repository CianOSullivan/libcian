#ifndef C_LINKEDLIST_H
#define C_LINKEDLIST_H
#include <stdlib.h>   // malloc(), NULL
#include <stdio.h>    // fprintf(), printf()

/**
A single item in the list containing the data and a pointer to the next node.
 */
typedef struct node {
    int data;
    struct node * next;
} node;

/**
Make the linked list structure containing the head node and number of items in
the list.
 */
typedef struct c_ll {
    struct node* head;
    int count;
} c_ll;

/**
Make a new linked list and return the list.

@returns a pointer to the linked list
 */
c_ll* c_ll_init();

/**
Print the contents of the linked list.

@param list the list to print
 */
void c_ll_print(c_ll* list);

/**
Adds data to end of linked list.

@param list the list to add the item to
@param data the data to add to the list
 */
void c_ll_add(c_ll* list, int data);

/**
Adds data to start of linked list.

@param list the list to add the item to
@param data the data to add to the list

 */
void c_ll_add_start(c_ll* list, int data);

/**
Remove data at start of linked list.

@param list the list to add the item to
 */
void c_ll_remove_front(c_ll* list);

/**
Remove data from end of linked list.

@param list the list to remove the item from
 */
void c_ll_remove_end(c_ll* list);

/**
Remove data at the given index.

@param list the list to remove the item from
@param index the location of the element to be removed

 */
void c_ll_remove_at(c_ll* list, int index);

/**
Get the node at the given index.

@returns the node in the list at the given index
@param list the list to get the node from
@param index the location in the list of the desired node
 */
node* c_ll_get(c_ll* list, int index);

/**
Get the number of items in the given list.

@returns the number of items in the list
@param list the list to return the size of
 */
int c_ll_size(c_ll* list);

/**
Reset the current position of the list
 */
void c_ll_first();

/**
Get the next node in the list.
 */
node* c_ll_next();

#endif
