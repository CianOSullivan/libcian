#include <c_str.h>
#include <c_log.h>
#include <c_linkedlist.h>
#include <stdio.h>
#include <string.h>

int main() {
    c_set_logger(1);    // Set logging level to INFO
    char test[] = "Hello World!";

    int count = c_str_len(test);
    printf("Count: %d\n", count);

    c_reverse(test);
    printf("Reversed Word: %s\n", test);
    c_log_info("Reversed word");

    node* list = c_ll_init();
    c_log_info("Made linked list");

    c_ll_add(list, 3);
    c_log_info("Added first item");
    c_ll_add(list, 2);
    c_ll_print(list);

    return 0;
}
