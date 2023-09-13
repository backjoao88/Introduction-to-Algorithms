#include <stdio.h>

#define SIZEARR 9

class InsertionSort
{
public:
    void sort(int *A)
    {
        // ck = custo de execução da linha K
        // tj = número de vezes que a linha 17 na iteração J é executada

        for (auto j = 1; j < SIZEARR; j++) /*  c13       j                                       */
        {                                  /*  c14       j-1                                     */
            int i = j - 1;                 /*  c15       j-1                                     */
            int key = A[j];                /*  c16       j-1                                     */
            while (i >= 0 && A[i] > key)   /*  c17       tj,                                     */
            {                              /*  c18       somatório de (tj-1), de j = 2 ate n,    */
                A[i + 1] = A[i];           /*  c19       somatório de (tj-1), de j = 2 ate n,    */
                i = i - 1;                 /*  c20       somatório de (tj-1), de j = 2 ate n,    */
            }                              /*  c21       somatório de (tj-1), de j = 2 ate n,    */
            A[i + 1] = key;                /*  c22       j-1                                     */
        }
    }
};

int main()
{

    int A[] = {10,
               12,
               02,
               13,
               14,
               50,
               01,
               05,
               06};
    InsertionSort *insertionSort = new InsertionSort();
    insertionSort->sort(A);

    for (auto i = 0; i < SIZEARR; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}