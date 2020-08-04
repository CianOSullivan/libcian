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
