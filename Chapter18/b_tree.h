// Btree implementation
#include <stdio.h>
#include "b_tree_utils.h"
#define T 2

// Represents a node from a B tree
template <typename KeyType>
class BNode
{
public:
    BNode(bool isLeaf)
    {
        this->isLeaf = isLeaf;
        this->keyCount = -1;
        this->keys = new KeyType[2 * T];
        this->children = new BNode *[2 * T + 1];
    };
    ~BNode()
    {
        for (auto child : this->children)
        {
            delete child;
        };
    };
    BNode **children;
    KeyType *keys;
    unsigned int keyCount;
    bool isLeaf;
};

// Represents a Btree
template <typename KeyType>
class BTree
{
public:
    BNode<KeyType> *root;
    void insert(KeyType &key)
    {
        if (root == nullptr)
        {
            this->root = new BNode<KeyType>(true);
            int keyCount = ++this->root->keyCount;
            this->root->keys[keyCount] = key;
            return;
        }

        BNode<KeyType> *refs = root;

        if (!refs->isLeaf)
        {
            return;
        }
        ++this->root->keyCount;
        insert_key(this->root->keys, this->root->keyCount, key);

        return;
    };
};
