/**
 * 2.3-6
 * Referring back to the searching problem (see Exercise 2.1-4), observe that if the
 * subarray being searched is already sorted, the searching algorithm can check the
 * midpoint of the subarray against v and eliminate half of the subarray from further
 * consideration. The binary search algorithm repeats this procedure, halving the
 * size of the remaining portion of the subarray each time. Write pseudocode, either
 * iterative or recursive, for binary search. Argue that the worst-case running time of
 * binary search is lg(n).
 *
 * R: It is lg(n) because of the number of the division that occurs.
 * The function that may represent the worst case is (N/2^k) = (n/2)+(n/4)+(n/8)....
 *
 */

#include <math.h>
#include "recursive_insertion_sort.h" // for sorting

namespace Chapter2
{
    class BinarySearch
    {
    public:
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
                    return this->search(A, K, min, mid);
                }
                else
                {
                    return this->search(A, K, mid + 1, max);
                }
            }
            return -1;
        };

        int searchIterative(int *A, int K, int min, int max)
        {
            while (max > min)
            {
                int mid = floor((max + min) / 2);
                if (A[mid] == K)
                {
                    return mid;
                }
                if (K < A[mid])
                {
                    max = mid;
                }
                else
                {
                    min = mid + 1;
                }
            }
            return -1;
        }
    };
};

using namespace Chapter2;

int search(int *A, int N);

int search(int *A, int K, int N)
{
    BinarySearch *binarySearch = new BinarySearch();
    int idx = binarySearch->searchIterative(A, K, 0, N - 1);
    return idx;
}

int main()
{
    int A[] = {500,
               672,
               1,
               0,
               432,
               231,
               674,
               123,
               45,
               43,
               938,
               120,
               432,
               81,
               1032,
               40543,
               987};
    int N = sizeof(A) / sizeof(A[0]);
    printf("size of arr: %d\n", N);
    sort(A, N);
    int idx = search(A, 43, N);
    printf("idx found: %d\n", idx);
    idx = search(A, 432, N);
    printf("idx found: %d\n", idx);
    idx = search(A, 1, N);
    printf("idx found: %d\n", idx);
    idx = search(A, 0, N);
    printf("idx found: %d\n", idx);
    idx = search(A, 40543, N);
    printf("idx found: %d\n", idx);
    idx = search(A, 33, N);
    printf("idx found: %d\n", idx);
    idx = search(A, 22, N);
    printf("idx found: %d\n", idx);
    idx = search(A, 23232, N);
    printf("idx found: %d\n", idx);
    idx = search(A, 674, N);
    printf("idx found: %d\n", idx);
    return 0;
}