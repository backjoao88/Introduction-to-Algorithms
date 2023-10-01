/**
 *
 * 2.3-5
 * You can also think of insertion sort as a recursive algorithm. In order to sort
 * A[1:n], recursively sort the subarray A[1:n-1] and then insert A[n] into the
 * sorted subarray A[1:n-1]. Write pseudocode for this recursive version of insertion sort.
 * Give a recurrence for its worst-case running time.
 *
 */

namespace Chapter2
{
    class InsertionSortRecursive
    {
    public:
        void sort(int *A, int N)
        {
            if (N == 1)
            {
                return;
            }

            this->sort(A, N - 1);

            int curr = A[N];
            int currIdx = N - 1;
            while (curr < A[currIdx])
            {
                // A[currIdx + 1] = A[index];
                currIdx--;
            }
            return;
        };
    };
};

using namespace Chapter2;

int main(void)
{
    int A[] = {2, 3, 10, 17, 28, 40, 23, 100, 1823, 23, 523, 12, 32, 12, 23};
    InsertionSortRecursive *insertionSort = new InsertionSortRecursive();

    insertionSort->sort(A, sizeof(A) / sizeof(A[0]));

    return 0;
}