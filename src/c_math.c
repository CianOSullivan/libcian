#include "c_math.h"

bool is_prime(unsigned int num) {
    if (num <= 1)
        return false;

    for (unsigned int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool is_palindrome(int num) {
    bool status = true;
    int size = c_count_digits(num);
    int* digits = c_split_digits(num, size);
    int end = size - 1;

    for (int i = 0; i < end; i++) {
        if (digits[i] != digits[end--]) {
            status = false;
            break;
        }
    }

    free(digits);
    return status;
}

bool is_even(int num) {
    return num % 2 == 0 ? true : false;
}
