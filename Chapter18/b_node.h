#pragma once
#define DEBUG
#define T 2

// Represents a node from a B tree

template <typename KeyType>
class BNode
{
public:
    BNode(bool isLeaf)
    {
        this->isLeaf = isLeaf;
        this->keyCount = 0;
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
    bool is_full()
    {
#ifdef DEBUG
        printf("> checking if is full. curr key count: %d\n", this->keyCount);
#endif
        return this->keyCount >= (2 * T);
    }
    BNode **children;
    KeyType *keys;
    unsigned int keyCount;
    bool isLeaf;
};
