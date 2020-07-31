#include <libcian/c_str.h>
#include <libcian/c_log.h>
#include <libcian/c_linkedlist.h>
#include <libcian/c_ut.h>
#include <libcian/c_bintree.h>
#include <libcian/c_util.h>
#include <libcian/c_math.h>
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
    c_log_info("Reversed word"); // Example of logging usage
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

    // Free the entire linked list
    c_ll_destroy(list);
    C_ASSERT("LinkedList destroy method incorrect", c_ll_size(list) == 0);

    return 0;
}

char* test_binarytree() {
    printf("\n*** Testing Binary Tree ***\n");

    c_bt* tree = c_bt_init();
    c_bt_insert(tree, 5);
    c_bt_insert(tree, 8);
    c_bt_insert(tree, 10);
    c_bt_insert(tree, 2);
    printf("Size: %d\n", c_bt_size(tree));
    print_preorder(tree->root);
    //C_ASSERT("NO", 1==1);
    return 0;
}

char* test_util() {
    printf("\n*** Testing Utilities ***\n");

    C_ASSERT("Incorrect digit count: -1", c_count_digits(-1) == 1);
    C_ASSERT("Incorrect digit count: 0", c_count_digits(0) == 1);
    C_ASSERT("Incorrect digit count: 12345", c_count_digits(12345) == 5);

    return 0;
}

char* test_math() {
    printf("\n*** Testing Math ***\n");

    C_ASSERT("is_prime method not functioning correctly", is_prime(92831) == true);
    C_ASSERT("is_prime method not functioning correctly", is_prime(92832) == false);

    return 0;
}

char* test_suite(void) {
    C_RUN_TEST(test_string);
    C_RUN_TEST(test_linkedlist);
    C_RUN_TEST(test_binarytree);
    C_RUN_TEST(test_util);
    C_RUN_TEST(test_math);


    return 0;
}

int main() {
    printf("*** STARTING UNIT TESTS ***\n");
    c_set_logger(1);    // Set logging level to INFO

    char* result = test_suite();

    if (result != 0)
        printf("ERROR: %s\n", result);
    else
        printf("\n*** ALL TESTS PASSED ***\n");
    printf("*** %d TEST SETS RUN ***\n", tests_run);

    return 0;
}
