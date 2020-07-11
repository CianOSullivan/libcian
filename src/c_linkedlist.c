#include "libcian/c_linkedlist.h"

void c_ll_init() {
    head = (node*) malloc(sizeof(node));
    if (head == NULL) {
        fprintf(stderr, "Couldn't load linked list.");
        return 1;
    }
}

void c_ll_add(int data) {

    if (head != NULL) {
        return;
    }

    node n;
    n.data = data;
    n.next = NULL;
    // increment count
}

void c_ll_remove() {
    //decrement count
    // do nothing if count < 0
}

void c_ll_print() {

}
