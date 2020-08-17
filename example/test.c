#include <libcian/c_str.h>
#include <libcian/c_log.h>
#include <libcian/c_linkedlist.h>
#include <libcian/c_ut.h>
#include <libcian/c_bintree.h>
#include <libcian/c_util.h>
#include <libcian/c_math.h>
#include <stdio.h>
#include <stdbool.h>

int tests_run = 0;

char* test_logging() {
    printf("\n*** Testing Logging ***\n");

    c_set_logger(1);    // Set logging level to INFO
    c_log_info("Log info message");
    c_set_logger(2);    // Set logging level to DEBUG
    c_log_info("This info message won't run");
    c_log_debug("Log debug message");

    return 0;
}

char* test_string() {
    printf("\n*** Testing string ***\n");
    char hello[] = "Hello World!";

    // String length
    int count = c_str_len(hello);
    C_ASSERT("String length != 12", count == 12);

    // String comparison
    C_ASSERT("Contains method incorrect", c_strcmp(hello, "Hello!") == -1);

    // String reversal
    c_reverse(hello);
    C_ASSERT("Reversed string incorrect", c_strcmp(hello, "!dlroW olleH") == 0);

    // String contains
    char cool[] = "This is cool!";
    C_ASSERT("Contains method incorrect", c_contains(cool, "cool!"));
    C_ASSERT("Contains method incorrect", c_contains(cool, "not") == false);

    // String count
    C_ASSERT("Word count method incorrect", c_word_count("This contains four words.") == 4);

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
    c_bt_insert(tree, 8);
    c_bt_insert(tree, 3);
    c_bt_insert(tree, 15);
    c_bt_insert(tree, 11);

    c_bt_insert(tree, 10);
    c_bt_insert(tree, 2);

    if (!c_bt_lookup(tree, 4)) {
        printf("Works\n");
    }

    printf("Size: %d\n", c_bt_size(tree));
    print_preorder(tree->root);

    c_bt_pretty_print(tree->root, 0);

    return 0;
}

char* test_util() {
    printf("\n*** Testing Utilities ***\n");

    C_ASSERT("Incorrect digit count: -1", c_count_digits(-1) == 1);
    C_ASSERT("Incorrect digit count: 0", c_count_digits(0) == 1);
    C_ASSERT("Incorrect digit count: 12345", c_count_digits(12345) == 5);
    int* arr = c_split_digits(9009, 4);
    C_ASSERT("Digit split not functioning correctly", arr[3] == 9);
    free(arr); // Never forget to free array!!

    return 0;
}

char* test_math() {
    printf("\n*** Testing Math ***\n");

    C_ASSERT("is_prime method not functioning correctly", is_prime(92831) == true);
    C_ASSERT("is_prime method not functioning correctly", is_prime(92832) == false);
    C_ASSERT("is_palindrome method not functioning correctly", is_palindrome(9009) == true);
    C_ASSERT("is_palindrome method not functioning correctly", is_palindrome(146) == false);
    C_ASSERT("is_even method not functioning correctly", is_even(104) == true);
    C_ASSERT("is_even method not functioning correctly", is_even(3) == false);
    C_ASSERT("num_of_factors method not functioning correctly", num_of_factors(28) == 6);
    C_ASSERT("factorial method not functioning correctly", factorial(12) == 479001600);
    C_ASSERT("c_pow method not functioning correctly", c_pow(4, 8) == 65536);

    printf("Factors: ");
    print_factors(104);

    return 0;
}

char* test_suite(void) {
    C_RUN_TEST(test_logging);
    C_RUN_TEST(test_string);
    C_RUN_TEST(test_linkedlist);
    C_RUN_TEST(test_binarytree);
    C_RUN_TEST(test_util);
    C_RUN_TEST(test_math);

    return 0;
}

int main() {
    printf("\n*** STARTING UNIT TESTS ***\n");

    char* result = test_suite();

    if (result != 0)
        printf("ERROR: %s\n", result);
    else
        printf("\n*** ALL TESTS PASSED ***\n");
    printf("*** %d TEST SETS RUN ***\n", tests_run);

    return 0;
}
