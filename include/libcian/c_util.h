#ifndef C_UTIL_H
#define C_UTIL_H
#include <stdio.h> // frprintf, FILE...
#include <stdlib.h> // exit, malloc...
/**
   @file c_util.h
   @brief Libcian utilities.

   Various utilities required to complete basic tasks using C.
*/

/**
   Get the number of elements in the given array. Type agnostic.

   @returns the number of elements in the array
*/
#define C_ARR_SIZE(arr) (((arr) == NULL) ? 0 : (sizeof(arr) / sizeof(arr[0])))

/**
   Count the number of digits in a number.

   @param i the number to count the digits of
   @returns the number of digits in i
*/
int c_count_digits(int i);

/**
   Split the given number into an array of digits.

   Must be freed to prevent memory leaks.

   @param num the number to split into digits
   @param size the size of the number to split
   @returns the integer array
*/
int* c_split_digits(int num, int size);

/**
   Simple file opener helper. Provides error handling.

   @param name the name of the file to open
   @param mode the mode to open the file in
   @returns pointer to the file
*/
FILE* c_fopen(char* name, char* mode);

#endif
