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

void c_reverse(char *str) {
    char *start = str;
    char *end = str + c_str_len(str) - 1;

    // Skip empty string
    if (str == 0) {
        return;
    }

    // Skip empty string
    if (*str == 0) {
        return;
    }

    // Until end of string reached
    while (start < end) {
        char tmp = *start; // store str[start]
        *start++ = *end;   // set str[start] = str[end]
        *end-- = tmp;      // set str[end] = str[start - 1]
    }
}

int c_strcmp(const char* s1, const char* s2) {
    // Iterate through s1 and s2 until \0
    while (*s1 && *s2) {
		if (*s1++ != *s2++)
			return 0;
	}

	return (*s2 == '\0');
}

const char* c_strstr(const char* s1, const char* s2) {
    // Iterate through s1 until end of string
	while (*s1 != '\0') {
		if ((*s1 == *s2) && (c_strcmp(s1, s2)))
			return s1;
		s1++; // Progress through s1
	}

	return NULL; // No match found
}

bool contains(const char s1[], const char s2[]) {
    // Check if s2 is in s1
    if (c_strstr(s1, s2) != NULL) {
        return true;
    }
    return false;
}
