#include <libcian/c_str.h>
#include <libcian/c_log.h>
#include <libcian/c_linkedlist.h>
#include <libcian/c_ut.h>
#include <libcian/c_bintree.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int tests_run = 0;

char* test_string() {
    printf("\n*** Testing string ***\n");
    char hello[] = "Hello World!";

    // String length
    int count = c_str_len(hello);
    C_ASSERT("String length != 12", count == 12);

    // String reversal
    c_reverse(hello);
    c_log_info("Reversed word");
    C_ASSERT("Reversed string incorrect", strcmp(hello, "!dlroW olleH") == 0);

    // String contains
    char cool[] = "This is cool!";
    C_ASSERT("Contains method incorrect", contains(cool, "cool!"));

    return 0;
}

char* test_linkedlist(void) {
    printf("\n*** Testing LinkedList ***\n");
    c_ll* list = c_ll_init(); // Initialise list

    // Add initial items to list
    for (int i = 0; i < 10; i++) {
        c_ll_add(list, i);
    }

    // Add / Remove method test
    c_ll_add_start(list, 3);
    c_ll_remove_front(list);
    c_ll_remove_end(list);
    c_ll_remove_at(list, 0);
    c_ll_print(list);

    // LinkedList size method
    C_ASSERT("LinkedList size incorrect", c_ll_size(list) == 8);

    // LinkedList iterator example
    c_ll_first(list); // Set the first list item
    for (int i = 0; !c_ll_done(list); i++)
        printf("Node %d: %d\n", i, c_ll_next(list)->data);

    // LinkedList get method
    C_ASSERT("LinkedList get method incorrect", c_ll_get(list, 6)->data == 7);

    return 0;
}

char* test_suite(void) {
    C_RUN_TEST(test_string);
    C_RUN_TEST(test_linkedlist);

    return 0;
}

int main() {
    c_bt* tree = c_bt_init();
    c_bt_insert(tree, 5);
    c_bt_insert(tree, 8);
    c_bt_insert(tree, 10);
    c_bt_insert(tree, 2);
    print_preorder(tree->root);



    printf("*** STARTING UNIT TESTS ***\n");
    c_set_logger(1);    // Set logging level to INFO

    char* result = test_suite();

    if (result != 0)
        printf("ERROR: %s\n", result);
    else
        printf("*** ALL TESTS PASSED ***\n");
    printf("*** %d TEST SETS RUN ***\n", tests_run);

    return 0;
}
