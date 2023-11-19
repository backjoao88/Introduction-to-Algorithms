/**
 *
 * 12.3-4
 * When TREE-DELETE calls TRANSPLANT, under what circumstances can the parameter v of TRANSPLANT be NIL?
 *
 * R: The V parameter, the element that is replacing U, can be NIL when we are deleting a node that has no children.
 */

#include "Trees/binary_tree.h"
#include "Trees/t_node.h"

using namespace Chapter12;

/***
 *
 *                                                          p
 *
 *
 *                                                          u                     v
 *
 *                                                      c1      c2            x1      x2
 *
 *
 *
 * Transplant: Must point v to p and p back to v, completely removing u from the tree.
 */

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

    TNode *eighthNode = tree->search(tree->root, &eighth);
    TNode *thirdNode = tree->search(tree->root, &third);

    tree->inOrder();
    tree->removeWithTransplant(tree->search(tree->root, &third));
    tree->inOrder();

    return 0;
}