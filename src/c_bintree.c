#include "c_bintree.h"

c_bt_node* new_node() {
    c_bt_node* newnode = (c_bt_node*) malloc(sizeof(c_bt_node));
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

c_bt* c_bt_init() {
    c_bt* tree = (c_bt*) malloc(sizeof(c_bt));
    tree->root = new_node();
    tree->count = 0;
    return tree;
}

void c_bt_insert(c_bt* tree, int data) {
    c_bt_node* current = tree->root;
    if (tree->count == 0) {
        printf("Inserting root");
        tree->root->data = data;
        tree->count += 1;
    } else {

        while (1) {
            if (data > current->data) {
                //right
                if (current->right != NULL) {
                    current = current->right;
                } else {
                    current->right = new_node();
                    current->right->data = data;
                    break;
                }
            } else {
                //left
                if (current->left != NULL) {
                    current = current->left;
                } else {
                    current->left = new_node();
                    current->left->data = data;
                    break;
                }
            }
        }
        tree->count += 1;
        printf("Adding second");
    }
}

void print_preorder(c_bt_node * tree) {
    if (tree)
    {
        printf("Data: %d\n", tree->data);
        if (tree->left != NULL)
            print_preorder(tree->left);
        else if (tree->right != NULL)
            print_preorder(tree->right);
    }
}

int c_bt_size(c_bt* tree) {
    return tree->count;
}
