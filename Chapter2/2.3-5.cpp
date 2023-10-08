/**
 *
 * 2.3-5
 * You can also think of insertion sort as a recursive algorithm. In order to sort
 * A[1:n], recursively sort the subarray A[1:n-1] and then insert A[n] into the
 * sorted subarray A[1:n-1]. Write pseudocode for this recursive version of insertion sort.
 * Give a recurrence for its worst-case running time.
 *
 */

#include <stdio.h>

namespace Chapter2
{

    class InsertionSortRecursive
    {
    public:
        void sort(int *A, int N)
        {
            if (N == 0)
            {
                // if zero, doesn't make the comparisons.
                return;
            }
            this->sort(A, N - 1);

            int j = A[N];
            printf("checking %d [idx: %d].. ", j, N);
            printf("[ ");
            while (N > 0 && j < A[N - 1])
            {
                A[N] = A[N - 1];
                N--;
                printf("%d ", N);
            };
            printf(" ]");
            A[N] = j;
            printf("\n");
        };

        void show(int *A, int N)
        {
            for (auto i = 0; i < N; i++)
            {
                printf("%d ", A[i]);
            }
            printf("\n");
        };
    };
};

using namespace Chapter2;

int main()
{
    // int A[] = {1, 2, 3, 10, 8, 12, 9};
    int A[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int N = sizeof(A) / sizeof(A[0]);
    InsertionSortRecursive *insertion = new InsertionSortRecursive();
    insertion->sort(A, N - 1);
    insertion->show(A, N);
    return 0;
}