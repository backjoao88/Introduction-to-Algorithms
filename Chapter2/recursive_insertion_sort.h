#include <stdio.h>

void sort(int *A, int N);

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
            while (N > 0 && j < A[N - 1])
            {
                A[N] = A[N - 1];
                N--;
            };
            A[N] = j;
        };

        void show(int *A, int N)
        {
            for (auto i = 0; i < N; i++)
            {
                printf("%d ", A[i]);
            }
        };
    };
};

using namespace Chapter2;

void sort(int *A, int N)
{
    InsertionSortRecursive *insertion = new InsertionSortRecursive();
    insertion->sort(A, N - 1);
    printf("sorted: [ ");
    insertion->show(A, N);
    printf("]");
    printf("\n");
};