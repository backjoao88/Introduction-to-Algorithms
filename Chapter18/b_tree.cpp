#include "b_tree.h"
#include "b_tree_utils.h"

void test_bnode_creation()
{
    BNode<int> *node = new BNode<int>(true);
    node->children[0] = new BNode<int>(true);
    node->children[0]->keys[0] = 2;
    node->children[0]->keys[1] = 2;
    node->children[0]->keys[2] = 2;
    node->children[0]->keys[3] = 2;
    node->keys[0] = 2;
    node->keys[1] = 2;
    node->keys[2] = 2;
    node->keys[3] = 2;
}

void test_btree_print_node(BNode<int> *root)
{
    int keyCount = root->keyCount;
    int *keys = root->keys;
    int index = 0;
    printf("%d \n", keyCount);
    while (index <= keyCount)
    {
        printf("%d ", keys[index]);
        index++;
    }
    printf("\n");
}

void test_btree_creation()
{
    int first = 5;
    int second = 6;
    int third = 3;
    int fourth = 1;
    int fiveth = 2;
    int sixth = 50;
    BTree<int> *tree = new BTree<int>();
    tree->insert(first);
    tree->insert(second);
    tree->insert(third);
    tree->insert(fourth);
}

int main()
{
    test_btree_creation();
    return 0;
}