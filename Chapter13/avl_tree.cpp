#include "avl_tree.h"

using namespace Chapter13;

int main()
{
    {
        int v1 = 3;
        int v2 = 2;
        int v3 = 1;
        AvlTree *avlTree = new AvlTree();
        avlTree->insert(&v1);
        avlTree->insert(&v2);
        avlTree->insert(&v3);
        printf(":: SIMPLY ROTATE TO THE LEFT ::\n");
        printf("Nodes: ");
        avlTree->preOrder();
        printf("Heights (unbalanced): ");
        avlTree->preOrderHeights();
        AvlNode *nodeToBeRotatedToTheRight = static_cast<AvlNode *>(avlTree->search(avlTree->root, &v1));
        AvlNode *rotatedNode = avlTree->simplyRotateFromLeft(nodeToBeRotatedToTheRight);
        avlTree->transplant(nodeToBeRotatedToTheRight, rotatedNode);
        printf("Nodes: ");
        avlTree->preOrder();
        printf("Heights (balanced): ");
        avlTree->preOrderHeights();
    }
    {
        int v1 = 1;
        int v2 = 2;
        int v3 = 3;
        AvlTree *avlTree = new AvlTree();
        avlTree->insert(&v1);
        avlTree->insert(&v2);
        avlTree->insert(&v3);
        printf(":: SIMPLY ROTATE TO THE RIGHT ::\n");
        printf("Nodes: ");
        avlTree->preOrder();
        printf("Heights (unbalanced): ");
        avlTree->preOrderHeights();
        AvlNode *nodeToBeRotatedToTheLeft = static_cast<AvlNode *>(avlTree->search(avlTree->root, &v1));
        AvlNode *rotatedNode = avlTree->simplyRotateFromRight(nodeToBeRotatedToTheLeft);
        avlTree->transplant(nodeToBeRotatedToTheLeft, rotatedNode);
        printf("Nodes: ");
        avlTree->preOrder();
        printf("Heights (balanced): ");
        avlTree->preOrderHeights();
    }
    return 0;
}