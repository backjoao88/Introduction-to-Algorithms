/**
 *
 * 12.2-3
 * Write the TREE-PREDECESSOR procedure.
 *
 */

#include "Trees/binary_tree.h"

using namespace Chapter12;

TNode *maximum(TNode *root);
TNode *predecessor(TNode *root);

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

    // Running tests
    int teste = 0;
    TNode *el;

    teste = 31;
    el = tree->search(tree->root, &teste);
    if (el != nullptr)
    {
        TNode *predecessorOf = predecessor(el);
        printf("predecessor of %d is %d\n", teste, tree->get_el_as_int(predecessorOf->info));
    }
    teste = 18;
    el = tree->search(tree->root, &teste);
    if (el != nullptr)
    {
        TNode *predecessorOf = predecessor(el);
        printf("predecessor of %d is %d\n", teste, tree->get_el_as_int(predecessorOf->info));
    }
    teste = 2;
    el = tree->search(tree->root, &teste);
    if (el != nullptr)
    {
        TNode *predecessorOf = predecessor(el);
        printf("predecessor of %d is %d\n", teste, tree->get_el_as_int(predecessorOf->info));
    }
    teste = 19;
    el = tree->search(tree->root, &teste);
    if (el != nullptr)
    {
        TNode *predecessorOf = predecessor(el);
        printf("predecessor of %d is %d\n", teste, tree->get_el_as_int(predecessorOf->info));
    }
    teste = 7;
    el = tree->search(tree->root, &teste);
    if (el != nullptr)
    {
        TNode *predecessorOf = predecessor(el);
        printf("predecessor of %d is %d\n", teste, tree->get_el_as_int(predecessorOf->info));
    }
    teste = 21;
    el = tree->search(tree->root, &teste);
    if (el != nullptr)
    {
        TNode *predecessorOf = predecessor(el);
        printf("predecessor of %d is %d\n", teste, tree->get_el_as_int(predecessorOf->info));
    }
    teste = 51;
    el = tree->search(tree->root, &teste);
    if (el != nullptr)
    {
        TNode *predecessorOf = predecessor(el);
        printf("predecessor of %d is %d\n", teste, tree->get_el_as_int(predecessorOf->info));
    }
    teste = -1;
    el = tree->search(tree->root, &teste);
    if (el != nullptr)
    {
        TNode *predecessorOf = predecessor(el);
        printf("predecessor of %d is %d\n", teste, tree->get_el_as_int(predecessorOf->info));
    }

    return 0;
}

TNode *maximum(TNode *root)
{
    if (root->rightChild == nullptr)
    {
        return root;
    }
    return maximum(root->rightChild);
};

TNode *predecessor(TNode *node)
{
    if (node->leftChild != nullptr)
    {
        return maximum(node->leftChild);
    }
    else
    {
        TNode *aux = node;
        while (aux->parent != nullptr && aux->parent->leftChild == aux)
        {
            aux = aux->parent;
        }
        if (aux->parent == nullptr)
            return node;
        return aux->parent;
    }
}