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

    c_ll* list = c_ll_init();

    for (int i = 0; i < 10; i++) {
        c_ll_add(list, i);
    }

    c_ll_print(list);
    c_ll_remove_end(list);
    c_ll_add(list, 5);
    c_ll_print(list);

    c_ll_remove_front(list);
    c_ll_remove_at(list, 0);
    c_ll_print(list);
    printf("Size: %d", c_ll_size(list));

    return 0;
}
