#include "c_util.h"

int c_count_digits(int i) {
    int val = 1;
    while (i /= 10)
        val++;

    return val;
}

int* c_split_digits(int num, int size) {
    int* arr = malloc(sizeof (int) * size);

    while (size--) {
        arr[size] = num % 10; // Get number at end of num
        num /= 10; // Remove last number
    }

    return arr;
}

FILE* c_fopen(char* name, char* mode) {
    FILE* file = fopen(name, mode);

    if (file == NULL) {
        fprintf(stderr, "File not found: %s\n", name);
        exit(1);
    }

    return file;
}
