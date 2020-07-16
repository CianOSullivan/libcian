#include "c_linkedlist.h"

c_ll* c_ll_init() {
    // Initialise a new list and set number of items to 0
    c_ll* list = (c_ll*) malloc(sizeof(c_ll));
    list->count = 0;

    // Make the head node (head node is treated as the pointer to the list)
    list->head = (node*) malloc(sizeof(node));


    list->head->data = -1;
    list->head->next = NULL;

    list->currentPos = 0;
    list->currentNode = (node*) malloc(sizeof(node));

    return list;
}

void c_ll_add(c_ll* list, int data) {
    node* current = list->head;

    // Move to the end of the list
    while (current->next != NULL) {
        current = current->next;
    }

    // Add a new node with the given data to the list
    current->next = (node*) malloc(sizeof(node));
    current->next->data = data;
    current->next->next = NULL;

    list->count += 1;
}

void c_ll_add_start(c_ll* list, int data) {
    node* current = list->head;

    // Make the new node and rejig the pointers
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;

    list->count += 1;
}


void c_ll_remove_front(c_ll* list) {
    // Skip if list is empty
    if (list->count == 0) {
        fprintf(stderr, "Can't remove element from empty list.\n");
        return;
    }
    node* current = list->head->next; // Always skip head node

    //Rejig pointers and free floating pointer
    list->head->next = current->next;
    free(current);

    list->count -= 1;
}

void c_ll_remove_end(c_ll* list) {
    // Skip if list is empty
    if (list->count == 0) {
        fprintf(stderr, "Can't remove element from empty list.\n");
        return;
    }

    // Skip to second last element in list
    node* current = list->head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Reassign next element to null
    free(current->next);
    current->next = NULL;

    list->count -= 1;
}

node* c_ll_get(c_ll* list, int index) {
    node* current = list->head->next; // Skip head node

    // Iterate through list until index
    for (int i = 0; i < index; i++) {
        if (current->next == NULL) {
            fprintf(stderr, "IndexError: Can't remove element at index from linked list.\n");
            return NULL;
        }
        current = current->next;
    }

    return current;
}

void c_ll_remove_at(c_ll* list, int index) {
    node* current = list->head->next; // Skip head node

    // Run specific remove methods if applicable
    if (index == 0) {
        c_ll_remove_front(list);
        return;
    } else if (index == list->count) {
        c_ll_remove_end(list);
        return;
    }

    // Iterate through list until the index
    for (int i = 0; i < index-1; i++) {
        if (current->next == NULL) {
            fprintf(stderr, "IndexError: Can't remove element at index from linked list.\n");
            return;
        }
        current = current->next;
    }

    // Remove node and rejig pointers
    node* temp = current->next;
    current->next = temp->next;
    free(temp);

    list->count -= 1;
}

void c_ll_print(c_ll* list) {
    node* current = list->head->next;    // Always skip head node

    // Iterate through list and print the data
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int c_ll_size(c_ll* list) {
    return list->count;
}

void c_ll_first(c_ll* list) {
    // Reset the position to the head node
    list->currentPos = 0;
    list->currentNode = list->head;
}

node* c_ll_next(c_ll* list) {
    // Exit if the next node is out of index
    if (list->currentPos > list->count) {
        fprintf(stderr, "Reached end of list.\n");
        exit(EXIT_FAILURE);
    }

    // Set the current node to the next node
    list->currentPos += 1;
    list->currentNode = list->currentNode->next;

    return list->currentNode; // Return the next node in the list
}
