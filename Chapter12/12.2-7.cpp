/**
 *
 * 12.2-7
 * An alternative method of performing an inorder tree walk of an n-node binary search tree finds the minimum element
 * in the tree by calling TREE-MINIMUM and
 * then making n - 1 calls to TREE-SUCCESSOR. Prove that this algorithm runs
 * in O(n) time.
 *
 */

#include "Trees/t_node.h"
#include "Trees/binary_tree.h"

using namespace Chapter12;

TNode *minimum(TNode *root);
TNode *successor(TNode *node);
void inOrder(TNode *root);

TNode *minimum(TNode *node)
{
    TNode *aux = node;
    while (aux->leftChild != nullptr)
    {
        aux = aux->leftChild;
    }
    return aux;
}

TNode *successor(TNode *node)
{
    if (node->rightChild != nullptr)
    {
        return minimum(node->rightChild);
    }
    else
    {
        TNode *aux = node;
        while (aux->parent != nullptr && aux->parent->rightChild == aux)
        {
            aux = aux->parent;
        }
        return aux->parent;
    }
}

void inOrder(TNode *root)
{
    TNode *min = minimum(root);
    TNode *aux = min;
    // This loop makes this function grows in O(n)
    while (aux != nullptr)
    {
        aux->printValue();
        aux = successor(aux);
    }
    printf("\n");
};

int main()
{
    int first = 19;
    int second = 20;
    int third = 11;
    int fourth = 2;
    int fiveth = 7;
    int sixth = 21;
    int seventh = 31;
    int eighth = 12;
    int nineth = 5;
    int ten = 18;
    int eleven = 15;

    RecursiveBinaryTree *tree = new RecursiveBinaryTree();
    tree->insert(&first);
    tree->insert(&second);
    tree->insert(&third);
    tree->insert(&fourth);
    tree->insert(&fiveth);
    tree->insert(&sixth);
    tree->insert(&seventh);
    tree->insert(&eighth);
    tree->insert(&nineth);
    tree->insert(&ten);
    tree->insert(&eleven);
    tree->inOrder();
    int teste;
    TNode *el;

    teste = 2;
    el = tree->search(tree->root, &teste);
    if (el != nullptr)
    {
        TNode *predecessorOf = successor(el);
        if (predecessorOf != nullptr)
        {
            printf("predecessor of %d is %d\n", teste, tree->get_el_as_int(predecessorOf->info));
        }
    }

    inOrder(tree->root);

    return 0;
}