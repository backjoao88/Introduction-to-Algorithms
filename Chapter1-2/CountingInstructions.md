## Complexidade de Tempo

#### Contagem do número básico de instruções

- A complexidade de tempo e o número de instruções básicas que aquele algoritmo executa (no modelo RAM por exemplo seria o número de instruções que a CPU realiza para rodar um determinado algoritmo).
- O algoritmo do <i>insertion sort</i> por meio da abordagem "ingênua" de identificação de complexidade do algoritmo está apresentado abaixo. Cada linha possui um custo (Ck), e também o número de vezes que será executada.
- O valor do número de execuções que serão realizados nas linhas enumeradas pela
variável <i>t</i> é indefinido, pois isso depende de como os valores de entrada estão arranjados no início. Por exemplo, caso demos como entrada um vetor já ordenado, o número de vezes que as linhas dentro do laço <i>while</i> serão executados será mínima. O contrário acontece para o pior caso, quando o vetor está totalmente desordenado.
- Isso acontece (eu imaginno), devido ao operador de comparação (>) que depende diretamente dos valores inseridos dentro do array.
```
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
```

- Realizando a soma de todas as operações, ficamos com a seguinte equação:
```
(c13*j) + c14*(j-1) + c15*(j-1) + c16*(j-1) + Sum(Tj) + Sum(Tj-1) + Sum(Tj-1) + Sum(Tj-1) + c22*(j-1);
```
- Em resumo, o número de operações irá depender da instância passada por parâmetro. Realizar uma análise de todas as instâncias seria impossível, pois são muitos casos. Geralmente o que acontece é uma análise do melhor caso, pior caso e as vezes o médio caso também.
- Para este algoritmo, em uma análise do melhor caso, podemos ficar com o tempo de uma função linear, já que podando a equação acima: ficamos sem a execução do laço while (já que não iremos precisar inserir nenhum valor no subvetor ordenado), assim ficamos somente com os valores das linhas restantes, que podem ser interpretadas de forma mais abrangente como an + b.
- Em uma análise do pior caso, podemos ficar com o tempo de uma função quadrática, já que em todos os casos o <i>while</i> mais interno vai ser executado cerca de <i>j</j> vezes (teoricamente ele irá passar por todo o subvetor que é do tamanho do vetor -1, mais uma comparação para terminar), nesse caso, Tj é igual a j.
- De certa forma, no modelo RAM todas os valores para Cks serão constantes já que o tempo
para executar uma instrução nesse modelo é constante. Então poderíamos substituir todos os Cks por simplesmente <i>c</i>.