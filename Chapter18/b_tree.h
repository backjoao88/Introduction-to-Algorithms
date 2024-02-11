// Btree implementation
#include <stdio.h>
#include "b_node.h"
#include "b_tree_utils.h"
#define T 2

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
            this->root->keys[this->root->keyCount] = key;
            ++this->root->keyCount;
#ifdef DEBUG
            printf("> inserting root value %d at pos %d\n", key, this->root->keyCount - 1);
            show_values(this->root);
#endif

            return;
        }

        BNode<KeyType> *node = root;
        BNode<KeyType> *parent = nullptr;

        if (!node->isLeaf)
        {
            return;
        }

        insert_key(node->keys, node->keyCount, key);
        ++node->keyCount;
#ifdef DEBUG
        show_values(node);
#endif

        if (node->is_full())
        {
            split_node<KeyType>(node, parent);
        }
    };
};
