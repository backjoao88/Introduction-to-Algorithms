/**
 *
 * 2.1-4
 * Consider the searching problem:
 *
 * Input: A sequence of n numbers a1,a2,an stored in array A[1:n] and a
 * value x.
 *
 * Output: An index i such that x equals A[1:n] or the special value NIL if x does not
 * appear in A.
 *
 * Write pseudocode for linear search, which scans through the array from beginning to end, looking for x. Using a loop invariant, prove that your algorithm is
 * correct. Make sure that your loop invariant fulfills the three necessary properties.
 *
 * R:
 * 1) Loop Invariant: In case the value of the A[i] in the ith iteration is equal to X, idx assumes the value of i.
 *
 */

#include <stdio.h>

int search(int *A, int N, int x)
{
    int idx = -1;
    for (auto i = 0; i < N; i++)
    {
        if (A[i] == x)
        {
            idx = i;
            return idx;
        };
    }
    return idx;
};

int main(void)
{

    int A[] = {10,
               12,
               02,
               13,
               14,
               50,
               01,
               05,
               06};
    int idx = search(A, sizeof(A) / sizeof(A[0]), 5);

    printf("%d \n", idx);

    return 0;
}