/**
 * Escreva um procedimento não-recursivo de tempo O(n) que, dada uma árvore binária de N nós, imprima a chave de cada nó da árvore.
 */

#include <stdio.h>

#include <stack>

#include "./BinaryTree/Tree.h"

using namespace Chapter10;

/**
 *
 *                                  18
 *                          12              21
 *                  (10)      ()      ()      ()
 *             (1)        (7)
 *                      (2)
 *
 */

int main(void) {
    BinaryTree* tree = new BinaryTree();
    tree->m_root = new Node(18);
    tree->insert(12);
    tree->insert(10);
    tree->insert(21);
    tree->insert(1);
    tree->insert(7);
    tree->insert(2);
    tree->printNonRecursive();
};
