#include "c_str.h"
#include <stdbool.h>  // true, false
#include <stdlib.h>   // NULL

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
        char tmp = *start; // store str[start]
        *start++ = *end;   // set str[start] = str[end]
        *end-- = tmp;      // set str[end] = str[start - 1]
    }
}

/** Returns <0 if s1<s2, 0 if s1==s2, >0 if s1>s2 */
int c_strcmp(const char* s1, const char* s2) {
    // Iterate through
    while (*s1 && *s2) {
		if (*s1++ != *s2++)
			return 0;

		//s1++;
		//s2++;
	}

	return (*s2 == '\0');
}

const char* c_strstr(const char* X, const char* Y) {
	while (*X != '\0')
	{
		if ((*X == *Y) && (c_strcmp(X, Y)))
			return X;
		X++;
	}

	return NULL;
}

bool contains(char s1[], char s2[]) {
    if (c_strstr(s1, s2) != NULL) {
        return true;
    }
    return false;


}
