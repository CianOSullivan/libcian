#ifndef C_STR_H
#define C_STR_H
#include <stdbool.h>  // true, false

/**
Determine length of character pointer.

@returns length of char pointer
@param pointer pointer to characters
 */
int c_str_len(char *pointer);

/**
Reverse the given character pointer.

@param s pointer to characters to reverse
*/
void c_reverse(char *s);

int c_strcmp(const char* s1, const char* s2);

bool contains(char s1[], char s2[]);

const char* c_strstr(const char* X, const char* Y);


#endif
