#include "c_bintree.h"

c_bt* c_bt_init() {
    c_bt* tree = (c_bt*) malloc(sizeof(c_bt));
    tree->root = (c_bt_node*) malloc(sizeof(c_bt_node));
    tree->count = 0;
    return tree;
}

void c_bt_insert(c_bt* tree, int data) {
    if (tree->count == 0) {
        printf("Inserting root");
        tree->root->data = data;
        tree->count += 1;
    } else {
        c_bt_node* current = tree->root;
        while (1) {
            if (data > current->data) {
                //right
                if (current->right != NULL) {
                    current = current->right;
                } else {
                    current->right = (c_bt_node*) malloc(sizeof(c_bt_node));
                    current->right->data = data;
                    break;
                }
            } else {
                //left
                if (current->left != NULL) {
                    current = current->left;
                } else {
                    current->left = (c_bt_node*) malloc(sizeof(c_bt_node));
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
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}
