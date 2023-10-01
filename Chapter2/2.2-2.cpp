#define N 14
#include <stdio.h>

namespace Chapter2
{
    class SelectionSort
    {
    public:
        void sort(int *A)
        {
            for (auto i = 0; i < N; i++)
            {
                int minor = i;
                for (auto j = i + 1; j < N; j++)
                {
                    if (A[j] < A[minor])
                    {
                        /* No pior caso, essa linha tende a ser n^2, no melhor caso é O(1). */
                        minor = j; // essa linha define o número de trocas que irão acontecer.
                    }
                }
                int swap = A[i];
                A[i] = A[minor];
                A[minor] = swap;
            }
        }
    };
}

int main(void)
{
    int A[] = {1000000, 10000, 1000, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, -1};

    for (auto i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    Chapter2::SelectionSort *selectionSort = new Chapter2::SelectionSort();
    selectionSort->sort(A);
    for (auto i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
