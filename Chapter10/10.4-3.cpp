/**
 * Escreva um procedimento não-recursivo de tempo O(n) que, dada uma árvore binária de N nós, imprima a chave de cada nó da árvore.
 */

#include <stdio.h>
#include "../Chapter12/Trees/binary_tree.h"

using namespace Chapter12;

int main(void)
{
    int first = 1;
    int second = 3;
    int third = 10;
    IterativeBinaryTree *tree = new IterativeBinaryTree();
    tree->insert(&first);
    tree->insert(&second);
    tree->insert(&third);
    tree->inOrder();
};
