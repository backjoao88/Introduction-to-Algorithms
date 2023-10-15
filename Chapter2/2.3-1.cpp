/***
 *
 * 2.3-1
 * Using Figure 2.4 as a model, illustrate the operation of merge sort on an array
 * initially containing the sequence h3; 41; 52; 26; 38; 57; 9; 49i.
 *
 */

#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <cstdlib>

#include "merge_sort.h"

using namespace Chapter2;

int main()
{
    srand((unsigned)time(0));

    assert(ARRAY_SIZE > 1);

    int *A = new int[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        A[i] = (rand() % 10000);
    }
    printf("> array of size %d\n", ARRAY_SIZE);
    printf("> performing merge sort...\n");

    MergeSort *sort = new MergeSort();
    sort->sort(A, 0, ARRAY_SIZE - 1);

    printArr(A, ARRAY_SIZE);
    printf("> finished\n");

    return 0;
}