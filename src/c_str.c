#include "libcian/c_str.h"

int c_str_len(char *pointer) {
    int c = 0;

    while( *(pointer + c) != '\0' ){
        c++;
    }
    
    return c;
}

/**
 * Reverse the given character array in place.
 *
 * Note: Character pointers are immutable, don't give me one.
 *
 * @param str the character array to reverse
 */
void c_reverse(char *str) {
    char *start = str;
    char *end = str + c_str_len(str) - 1;
 
    // skip null
    if (str == 0)
    {
        return;
    }

    // skip empty string
    if (*str == 0)
    {
        return;
    }

    // Until end of string reached
    while (start < end) {
        char tmp = *start; //
        *start++ = *end;    //
        *end-- = tmp;    // 
    }
}

