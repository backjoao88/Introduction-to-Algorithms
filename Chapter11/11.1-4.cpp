/***
 * 11.1-4
 * Suppose that you want to implement a dictionary by using direct addressing on
 * a huge array. That is, if the array size is m and the dictionary contains at most
 * n elements at any one time, then m >> n. At the start, the array entries may
 * contain garbage, and initializing the entire array is impractical because of its size.
 * Describe a scheme for implementing a direct-address dictionary on a huge array.
 * Each stored object should use O(1) space; the operations SEARCH, I NSERT, and
 * DELETE should take O(1) time each; and initializing the data structure should take
 * O(1) time. (Hint: Use an additional array, treated somewhat like a stack whose size
 * is the number of keys actually stored in the dictionary, to help determine whether
 * a given entry in the huge array is valid or not.)
 *
 * R: The problem here is that we aren't allowed to initialize the array. So we need to create an additional array to validate
 * the entries in the main direct table.
 *
 */

#include <stdio.h>

#define M 1000

// the object is in form <int, float>

void insert(float *T, int key, float value);
float search(float *T, int key);
void remove(float *T, int key);

int main(void)
{
    float T[M]; // not initialized - random values inside
    float value = search(T, 0);
    printf("%.2f", value);
    return 0;
};

float search(float *T, int key)
{
    // if not inserted in the additional array, then return default value 0.0f
    // if found, then return T[A[key]]
    return T[key];
};

void insert(float *T, int key, float value)
{
    T[key] = value;
};

void remove(float *T, int key)
{
    T[key] = 0.0f;
}

void printKeyValue(float *T, int key)
{
    printf("%.2f\n", T[key]);
}