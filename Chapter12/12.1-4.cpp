/**
 *
 * 12.1-4
 * Give recursive algorithms that perform preorder and postorder tree walks in O(n)
 * time on a tree of n nodes.
 */

#include <stdio.h>

#define MAX_CHILD_NODES 10

struct TNode
{
    void *info;
    struct TNode *children[MAX_CHILD_NODES];

    TNode(void *info)
    {
        this->info = info;
        for (auto i = 0; i < MAX_CHILD_NODES; i++)
        {
            children[i] = nullptr;
        };
    }
};

struct NthTree
{
    struct TNode *root;
    NthTree()
    {
        this->root = nullptr;
    }

    void preOrder()
    {
        printf("pre order\n");
        preOrderRecursive(this->root);
        printf("\n");
    }

    void preOrderRecursive(TNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        printf("%d ", (*(int *)root->info));
        for (auto i = 0; i < MAX_CHILD_NODES; i++)
        {
            preOrderRecursive(root->children[i]);
        }
    }
    void posOrder()
    {
        printf("pos order\n");
        posOrderRecursive(this->root);
        printf("\n");
    }

    void posOrderRecursive(TNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        for (auto i = 0; i < MAX_CHILD_NODES; i++)
        {
            preOrderRecursive(root->children[i]);
        }
        printf("%d ", (*(int *)root->info));
    }
};

int main()
{
    int root = 0;
    NthTree *tree = new NthTree();
    tree->root = new TNode(&root);
    int first = 5;
    int second = 4;
    int third = 41;
    int fourth = 43;
    int fiveth = 4321;

    tree->root->children[0] = new TNode(&first);
    tree->root->children[0]->children[0] = new TNode(&second);
    tree->root->children[1] = new TNode(&third);
    tree->root->children[2] = new TNode(&fourth);
    tree->root->children[3] = new TNode(&fiveth);

    tree->preOrder();
    tree->posOrder();

    return 0;
}
