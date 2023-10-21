/**
 * 12.2-2
 * Write recursive versions of TREE-MINIMUM and TREE-MAXIMUM.
 */

#include "Trees/binary_tree.h"

using namespace Chapter12;

TNode *minimum(TNode *root);
TNode *maximum(TNode *root);

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

    printf("minimum value of tree is %d\n", (*(int *)minimum(tree->root)->info));
    printf("maximum value of tree is %d\n", (*(int *)maximum(tree->root)->info));

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

TNode *minimum(TNode *root)
{
    if (root->leftChild == nullptr)
    {
        return root;
    }
    return minimum(root->leftChild);
}