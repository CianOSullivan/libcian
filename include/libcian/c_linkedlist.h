#ifndef C_LINKEDLIST_H
#define C_LINKEDLIST_H
#include <stdlib.h>   // malloc(), NULL
#include <stdio.h>    // fprintf(), printf()
#include <stdbool.h>  // true, false
/**
   @file c_linkedlist.h
   @brief Linked list data structure.

   Singly linked list implementation. Only simple methods implemented to allow
   basic usage of a linked list.
*/

/**
   A single item in the list containing the data and a pointer to the next node.
*/
typedef struct c_ll_node {
    int data;
    struct c_ll_node * next;
} c_ll_node;

/**
   Make the linked list structure containing the head node and number of items in
   the list.
*/
typedef struct c_ll {
    struct c_ll_node* head;
    int count;
    struct c_ll_node* currentNode;
    int currentPos;
} c_ll;

/**
   Make a new linked list and return the list.

   @returns a pointer to the linked list
*/
c_ll* c_ll_init();

/**
   Destroy the given linked list.

   Resets the list to the default setup.

   @param list the list to destroy
*/
void c_ll_destroy(c_ll* list);


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
c_ll_node* c_ll_get(c_ll* list, int index);

/**
   Get the number of items in the given list.

   @returns the number of items in the list
   @param list the list to return the size of
*/
int c_ll_size(c_ll* list);

/**
   Reset the current position of the list

   @param list the list to go to the start of
*/
void c_ll_first(c_ll* list);

/**
   Get the next node in the linked list.

   @returns the next node in the list
   @param list the list to get the next node from
*/
c_ll_node* c_ll_next(c_ll* list);

bool c_ll_done(c_ll* list);

#endif
