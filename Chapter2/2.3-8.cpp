/***
 *
 * 2.3-8
 * Describe an algorithm that, given a set S of n integers and another integer x,
 * determines whether S contains two elements that sum to exactly x. Your algorithm
 * should take n lg(n) time in the worst case.
 *
 */

#include "merge_sort.h"
#include <cmath>
#include <stdio.h>

namespace Chapter2
{

    int search(int *A, int K, int min, int max)
    {
        if (max > min)
        {
            int mid = floor((max + min) / 2);
            if (K == A[mid])
            {
                return mid;
            }
            if (K < A[mid])
            {
                return search(A, K, min, mid);
            }
            else
            {
                return search(A, K, mid + 1, max);
            }
        }
        return -1;
    };

    void show(int *A, int N)
    {
        for (auto i = 0; i < N; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
    }

    void findMatchSumOf(int *A, int N, int target)
    {
        auto merge = new MergeSort();
        merge->sort(A, 0, N - 1);
        auto idx = -1;
        auto i = -1;
        show(A, N);
        for (i = 0; i < N; i++)
        {
            int searchFor = target - A[i];
            printf("search for %d\n", searchFor);
            idx = search(A, searchFor, 0, N);
            if (idx != -1)
            {
                break;
            }
        }
        if (A[idx] + A[i] == target)
        {
            printf("found indexes: %d, %d\n", i, idx);
        }
    };
};

using namespace Chapter2;

int main()
{
    int A[] = {1,
               3,
               7,
               3,
               14,
               50,
               4,
               5,
               100};
    int N = sizeof(A) / sizeof(A[0]);
    findMatchSumOf(A, N, 10);
    return 0;
}