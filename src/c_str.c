#include "c_str.h"
#include <stdbool.h>  // true, false
#include <stdlib.h>   // NULL
#include <string.h>   // strdup

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
    while(*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

const char* c_strstr(const char *str, const char *substr) {
    while (*str) {
        char *Begin = strdup(str);
        char *pattern = strdup(substr);

        // If first character of sub string match, check for whole string
        while (*str && *pattern && *str == *pattern) {
            str++;
            pattern++;
        }

        // If complete sub string match, return starting address
        if (!*pattern)
            return Begin;

        str = Begin + 1;	// Increment main string
    }
    return NULL;
    }

bool c_contains(const char s1[], const char s2[]) {
    // Check if s2 is in s1
    if (c_strstr(s1, s2) != NULL) {
        return true;
    }
    return false;
}

int c_word_count(const char* s1) {
    int i = 0;
    int count = 0;

    if (s1 == NULL || c_strcmp(s1, "") == 0) {
        return 0;
    }

    while (s1[i] != '\0') {
        if (s1[i] == ' ' && s1[i+1] != ' ') {
            count++;
        }
        i++;
    }
    return count + 1;
}
