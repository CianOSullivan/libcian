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

    // if c_bt_lookup returns true then the element already exists so dont add

    if (tree->count == 0) {
        tree->root->data = data;
        tree->count += 1;
    } else {
        while (true) {
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
    }
}

void print_preorder(c_bt_node * tree) {
    if (tree) {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}

void print_inorder(c_bt_node * tree) {
    if (tree) {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(c_bt_node * tree) {
    if (tree) {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

void c_bt_pretty_print(c_bt_node* tree, int level) {
    // Base case
    if (tree == NULL)
        return;

    // Increase distance between levels
    level += 10;

    // Process right child first
    c_bt_pretty_print(tree->right, level);

    // Print current node after space count
    printf("\n");
    for (int i = 10; i < level; i++)
        printf(" ");
    printf("%d\n", tree->data);

    // Process left child
    c_bt_pretty_print(tree->left, level);
}

bool c_bt_lookup(c_bt* tree, int data) {
    c_bt_node* current = tree->root;
    while (true) {
        if (data == current->data) {
            return true;
        } else if (data > current->data) {
            //right
            if (current->right != NULL) {
                current = current->right;
            } else {
                break;
            }
        } else {
            //left
            if (current->left != NULL) {
                current = current->left;
            } else {
                break;
            }
        }
    }
    return false;
}


int c_bt_size(c_bt* tree) {
    return tree->count;
}
