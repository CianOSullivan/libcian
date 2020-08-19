#ifndef C_STR_H
#define C_STR_H
#include <stdbool.h>  // true, false
/**
   @file c_str.h
   @brief String methods.

   Common string operations and some standard library replacement functions.
*/

/**
   Determine length of character pointer.

   @returns length of char pointer
   @param pointer pointer to characters
*/
int c_str_len(char *pointer);

/**
   Reverse the given character array in place.

   Note: Character pointers are immutable, don't give me one.

   @param str the character array to reverse
*/
void c_reverse(char *s);

/**
   Compares two null-terminated strings.

   @returns <0 if s1<s2,
   0 if s1==s2,
   >0 if s1>s2
   @param s1 the string to compare against
   @param s2 the string to check for
*/
int c_strcmp(const char* s1, const char* s2);

/**
   Finds first occurence of a needle in a haystack.
   Taken from:
   http://www.firmcodes.com/write-c-code-to-implement-the-strstr-function-to-search-for-a-substring/
   I'm sure I'll understand this someday ;)
   @returns pointer to the string that is the first byte of the substring or
   null pointer if no match was found
   @param s1 the haystack
   @param s2 the needle
*/
const char* c_strstr(const char* s1, const char* s2);

/**
   Checks if one string is contained in another.

   @param s1 the string to compare against
   @param s2 the string to check for in s1
   @returns true if s2 is in s1, false otherwise
*/
bool c_contains(const char s1[], const char s2[]);

/**
   Counts the number of words in the given string.

   @param s1 the string to count the number of words
   @returns the number of words in s1
*/
int c_word_count(const char* s1);

#endif
