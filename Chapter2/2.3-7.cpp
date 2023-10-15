/**
 *
 * 2.3-7
 * The while loop of lines 537 of the INSERTION-SORT procedure in Section 2.1
 * uses a linear search to scan (backward) through the sorted subarray A[1 : j - 1]
 * What if insertion sort used a binary search (see Exercise 2.3-6) instead of a linear
 * search? Would that improve the overall worst-case running time of insertion sort
 * to n lg n?
 */

#include <stdio.h>
#include <cmath>
#include "binary_sort.h"

namespace Chapter2
{

   void sort(int *A, int N)
   {
      for (auto i = 1; i < N; i++)
      {
         int key = A[i];
         int j = i - 1;
         int insertPos = search(A, key, 0, j + 1);
         while (j >= insertPos)
         {
            A[j + 1] = A[j];
            j--;
         }
         A[j + 1] = key;
      };
   }

   void show(int *A, int N)
   {
      for (auto i = 0; i < N; i++)
      {
         printf("%d ", A[i]);
      }
      printf("\n");
   }
};

using namespace Chapter2;

int main(void)
{

   int A[] = {10,
              12,
              2,
              13,
              14,
              50,
              1,
              5,
              6};
   int N = sizeof(A) / sizeof(A[0]);
   show(A, N);
   sort(A, N);
   show(A, N);
   return 0;
}