#ifndef C_MATH_H
#define C_MATH_H
#include <stdbool.h>  // true, false
#include <c_util.h> // c_count_digits, c_split_digits
/**
   @file c_math.h
   @brief Mathematics methods.

   Common maths operations and some standard library replacement functions.
*/

/**
   Returns true if given number is a prime number. False otherwise.

   @returns true if num is prime
   @param num a positive integer to test for
*/
bool is_prime(unsigned int num);

/**
   Returns true if given number is a palindrome. False otherwise.

   @returns true if num is palindrome
   @param num the integer to test for
*/
bool is_palindrome(int num);

/**
   Returns true if the given number is even. False otherwise.

   @returns true if num is even
   @param num the integer to test for
*/
bool is_even(int num);

/**
   Returns the number of factors of the given number.

   @returns the number of factors of num
   @param num the number to factorise
 */
int num_of_factors(int num);

/**
   Print the factors of the given number.

   @param num the number to factorise
 */
void print_factors(int num);
#endif
