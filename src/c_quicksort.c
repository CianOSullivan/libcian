#include "c_quicksort.h"
#include "c_util.h" // C_ARR_SIZE
#include <stdio.h>

// Swaps the two given integers in the array
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
   This function takes last element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot .
*/
int partition (int arr[], int low, int high) {
    int pivot = arr[high];    // Set last element as pivot
    int index = (low - 1);        // Index of smaller element

    // Swap
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            index++;           // increment index of smaller element
            swap(&arr[index], &arr[j]);
        }
    }

    swap(&arr[index + 1], &arr[high]);

    return (++index);
}

void c_quicksort(int arr[], int start, int end) {
    if (start < end) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, start, end);

        // Separately sort elements before
        // partition and after partition
        c_quicksort(arr, start, pi - 1);
        c_quicksort(arr, pi + 1, end);
    }
}
