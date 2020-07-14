#include "c_linkedlist.h"

c_ll* c_ll_init() {
    list = (c_ll*) malloc(sizeof(c_ll));
    list->count = 0;

    list->head = (node*) malloc(sizeof(node));
    list->head->data = 1;
    list->head->next = NULL;

    return list;
}

void c_ll_add(c_ll* list, int data) {
    node* current = list->head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (node*) malloc(sizeof(node));
    current->next->data = data;
    current->next->next = NULL;
    list->count += 1;
}


void c_ll_remove_front(c_ll* list) {
    node* current = list->head->next; // Skip first node

    if (list->count == 0) {
        fprintf(stderr, "Can't remove element from empty list.");
        return;
    }

    list->head->next = current->next;
    free(current);
    list->count -= 1;
}

void c_ll_remove_end(c_ll* list) {
    if (list->count == 0) {
        fprintf(stderr, "Can't remove element from empty list.");
        return;
    }

    node* current = list->head;

    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    list->count -= 1;
}

void c_ll_remove_at(c_ll* list, int index) {
    node* current = list->head->next; // Skip head node

    if (index == 0) {
        c_ll_remove_front(list);
        return;
    } else if (index == list->count) {
        c_ll_remove_end(list);
        return;
    }

    for (int i = 0; i < index-1; i++) {
        if (current->next == NULL) {
            fprintf(stderr, "IndexError: Can't remove element at index from linked list.");
            return;
        }
        current = current->next;
    }

    node* temp = current->next;
    current->next = temp->next;
    free(temp);
    list->count -= 1;

}

void c_ll_print(c_ll* list) {
    int i = 0;
    node* current = list->head->next;    // Always skip head node
    while (current != NULL) {
        printf("Element %d: %d\n", i, current->data);
        current = current->next;
        i++;
    }
}

int c_ll_size(c_ll* list) {
    return list->count;
}
