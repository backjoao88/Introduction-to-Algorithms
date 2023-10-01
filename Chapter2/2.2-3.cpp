/***
 *
 * 2.2-3
 * Consider linear search again (see Exercise 2.1-4). How many elements of the input
 * array need to be checked on the average, assuming that the element being searched
 * for is equally likely to be any element in the array? How about in the worst case?
 * 34 Chapter 2 Getting Started
 * Using the Big Onotation, give the average-case and worst-case running times of linear
 * search. Justify your answers.
 *
 * R: Average case probably is going to go for half of the array (n/2) what keeps it's time compelxity inside O(n).
 * Worst case is going to go for all the array (because it will not be found). The number of comparisons (fundamental operation)
 * will be equal to the size of the array, so O(n).
 * The best case is O(1), only one comparison is evaluated because the first element is in the first position.
 */

namespace Chapter2
{

#define ARRAY_SIZE 10000
#include <stdio.h>

    class LinearSearch
    {
    public:
        LinearSearch(){};
        ~LinearSearch(){};
        int search(int *array, int value, int arrSize, int *comparison)
        {
            for (auto i = 0; i < arrSize; i++)
            {
                (*comparison)++;
                if (array[i] == value)
                {
                    return i;
                }
            }
            return -1;
        };
    };
}

using namespace Chapter2;

int main(void)
{
    int comparison = 0;
    int data[] = {2, 3, 10, 17, 28, 40, 23, 100, 1823, 23, 523, 12, 32, 12, 23};
    LinearSearch *linearSearch = new LinearSearch();
    int idx = linearSearch->search(data, 2222, sizeof(data) / sizeof(data[0]), &comparison);
    printf("found/comparisons %d/%d\n", idx, comparison);
    return 0;
}