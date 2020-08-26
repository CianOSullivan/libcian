#ifndef C_QUICKSORT_H
#define C_QUICSORT_H
/**
   @file c_quicksort.h
   @brief Quicksort algorithm.

   Sorts integer arrays using the quicksort algorithm. This implementation sets
   the last element of the given array as the pivot. Other pivot selection
   may be preferable depending on the given array.
*/

/**
   The quicksort sorting algorithm for an array of integers.

   @param arr the array to be sorted
   @param start  the array starting index
   @param end the array ending index
*/
void c_quicksort(int arr[], int start, int end);

#endif
