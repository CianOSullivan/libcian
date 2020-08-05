#ifndef C_UTIL_H
#define C_UTIL_H
#include <stdlib.h>
/**
   @file c_util.h
   @brief Libcian utilities.

   Various utilities required to complete basic tasks using C.
*/

/**
   Count the number of digits in a number.

   @param i the number to count the digits of
   @returns the number of digits in i
*/
int c_count_digits(int i);

/**
   Split the given number into an array of digits.

   Must be freed to prevent memory leaks.

   @returns the integer array
   @param num the number to split into digits
   @param size the size of the number to split
*/
int* c_split_digits(int num, int size);

#endif
