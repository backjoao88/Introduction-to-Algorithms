#include "Tree.h"

using namespace Chapter10;

int main(void) {
    BinaryTree* tree = new BinaryTree();

    tree->m_root = new Node(19);

    tree->insert(4);
    tree->insert(5);
    tree->insert(7);
    tree->insert(10);
    tree->insert(12130);
    tree->insert(44);
    tree->insert(123);
    tree->insert(444);
    tree->insert(1440);

    tree->printRecursive();

    return 0;
};