#pragma once
#include <cmath>

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
        return min;
    };
}