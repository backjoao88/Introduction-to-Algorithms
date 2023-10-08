/**
 *
 * 2.3-5
 * You can also think of insertion sort as a recursive algorithm. In order to sort
 * A[1:n], recursively sort the subarray A[1:n-1] and then insert A[n] into the
 * sorted subarray A[1:n-1]. Write pseudocode for this recursive version of insertion sort.
 * Give a recurrence for its worst-case running time.
 *
 */

#include "recursive_insertion_sort.h"

int main()
{
    // int A[] = {1, 2, 3, 10, 8, 12, 9};
    int A[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int N = sizeof(A) / sizeof(A[0]);
    sort(A, N);
    return 0;
}
