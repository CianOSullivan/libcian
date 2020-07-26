#ifndef C_BINTREE_H
#define C_BINTREE_H
#include <stdio.h>
#include <stdlib.h>
/**
   @file c_bintree.h
   @brief Binary tree data structure.

   Binary tree data structure used by libcian for integer data storage.
*/

/**
   A single item in the tree containing the data and pointers to the left and
   right nodes.
 */
typedef struct c_bt_node {
    int data;
    struct c_bt_node * left;
    struct c_bt_node * right;
} c_bt_node;

/**
   Make the binary tree structure containing the root node and number of items in
   the tree.
*/
typedef struct c_bt {
    struct c_bt_node* root;
    int count;
} c_bt;

/**
   Make a new linked list and return the list.

   @returns a pointer to the linked list
*/
c_bt* c_bt_init();

void c_bt_insert(c_bt* tree, int data);

/**
   Tree print method in the preorder format.

   @param tree the root node of the tree
 */
void print_preorder(c_bt_node * tree);
void print_inorder(c_bt_node * tree);
void print_postorder(c_bt_node * tree);

int c_bt_size(c_bt* tree);


#endif
