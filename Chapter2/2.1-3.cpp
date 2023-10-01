/***
 *
 * 2.1-3
 * Rewrite the INSERTION-SORT procedure to sort into monotonically decreasing instead of monotonically increasing order.
 *
 */

#include <stdio.h>

void sort(int *A, int N)
{
    for (auto i = 1; i < N; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && key > A[j])
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    };
}

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
    sort(A, sizeof(A) / sizeof(A[0]));

    for (auto i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}