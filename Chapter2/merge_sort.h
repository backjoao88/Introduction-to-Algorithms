#pragma once

#include <stdio.h>

#define ARRAY_SIZE 999
#define SENTINELA 99999
#define DIVISION 2

namespace Chapter2
{
    /**
     * Merge Sort implementation
     */
    void printArr(int *array, int size)
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    class MergeSort
    {
    public:
        void merge(int *A, int start, int middle, int end)
        {
            int leftLength = middle - start + 1;
            int rightLength = end - middle;

            int L[leftLength + 1];
            int R[rightLength + 1];

            L[leftLength] = SENTINELA;
            R[rightLength] = SENTINELA;

            for (int i = 0; i < leftLength; i++)
            {
                L[i] = A[start + i];
            }
            for (int i = 0; i < rightLength; i++)
            {
                R[i] = A[middle + 1 + i];
            }

            int l = 0;
            int r = 0;
            for (int k = start; k <= end; k++)
            {
                if (L[l] <= R[r])
                {
                    A[k] = L[l];
                    l++;
                }
                else
                {
                    A[k] = R[r];
                    r++;
                }
            }
        }
        void sort(int *A, int start, int end)
        {
            if (start < end)
            {
                int middle = (end + start) / DIVISION;
                sort(A, start, middle);
                sort(A, middle + 1, end);
                merge(A, start, middle, end);
            }
        }
    };
};