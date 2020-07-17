#include <c_str.h>
#include <c_log.h>
#include <c_linkedlist.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void find_str(char const* str, char const* substr)
{
    const char* pos = c_strstr(str, substr);
    if(pos) {
        printf("found the string '%s' in '%s' at position: %ld\n", substr, str, pos - str);
    } else {
        printf("the string '%s' was not found in '%s'\n", substr, str);
    }
}

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
    printf("Size: %d\n", c_ll_size(list));
    c_ll_add_start(list, 3);

    c_ll_first(list);
    for (int i = 0; i < c_ll_size(list); i++) {
        printf("Node %d: %d\n", i, c_ll_next(list)->data);
    }

    node* no = c_ll_get(list, 6);

    if (no != NULL)
        printf("Val: %d", no->data);

    char string1[] = "This is cool!";
    if (contains(string1, "is")) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    char* str = "one two three";
    find_str(str, "two");


    return 0;
}
