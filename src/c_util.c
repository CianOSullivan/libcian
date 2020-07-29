#include "c_util.h"

int c_count_digits(int i) {
    int ret = 1;
    while (i /= 10) ret++;
    return ret;
}
