/***
 * 2.1-5
 * Consider the problem of adding two n-bit binary integers, stored in two n-element arrays A and B.
 * The sum of the two integers should be stored in binary form in an (n + 1)-element array C.
 * State the problem formally and write pseudocode for adding the two integers.
 *
 * R:
 * Loop Invariant: The corresponding sum of two binary integers in a N iteration must correspond to the correct sum.
 * (1 or 0) = 1
 * (0 or 0) = 0
 * (1 or 1) = 1 (carry 1 over)
 * (0 or 1) = 1
 */

#include <stdio.h>

void add_binary_integers(int *A, int *B, int *C, int N)
{
    if (N == 0)
    {
        return;
    }
    add_binary_integers(A, B, C, N - 1); // needs to implement carry over one
    C[N] = A[N] || B[N];
    printf("%d\n", C[N]);
    return;
};

int main(void)
{
    int A[] = {0, 0, 1, 0, 1, 0};
    int B[] = {1,
               0,
               1,
               1,
               1,
               1};
    int N = sizeof(A) / sizeof(A[0]);
    int C[N + 1];
    add_binary_integers(A, B, C, N);
}