#pragma once
#include "b_node.h"

template <typename KeyType>

void insert_key(KeyType *arrKeys, int keyCount, KeyType key)
{
#ifdef DEBUG
    printf("> inserting key %d in %p..\n", key, arrKeys);
#endif
    int index = 0;
    while (index < keyCount && key > arrKeys[index])
    {
        ++index;
    }
    int begin = keyCount + 1;
    while (begin > index)
    {
        arrKeys[begin] = arrKeys[begin - 1];
        begin--;
    }
    arrKeys[index] = key;
#ifdef DEBUG
    printf("> key %d inserted in %p at pos %d\n", key, arrKeys, index);
#endif
}

template <typename KeyType>
void erase_key(KeyType *arrKeys, int keyCount, KeyType key)
{
    int index = 0;
    while (index < keyCount && key > arrKeys[index])
    {
        ++index;
    }
    for (int i = index; i < keyCount; i++)
    {
        arrKeys[index] = arrKeys[index + 1];
    }
#ifdef DEBUG
    printf("> key %d erased in %p at pos %d\n", key, arrKeys, index);
#endif
}

template <typename KeyType>
void show_values(BNode<KeyType> *node)
{
    if (node == nullptr)
    {
        printf(":: [none]\n");
        return;
    }
    KeyType *aux = node->keys;
    int idx = 0;
    printf(":: %d:[", node->keyCount);
    while (idx < node->keyCount)
    {
        if (idx == node->keyCount - 1)
        {
            printf("%d", aux[idx]);
        }
        else
        {
            printf("%d ", aux[idx]);
        }
        idx++;
    }
    printf("]\n");
}

template <typename KeyType>
void split_node(BNode<KeyType> *node, BNode<KeyType> *parent)
{
#ifdef DEBUG
    printf("> calling split for parent addr %p and node addr %p\n", &parent, &node);
    printf(":: parent keys are ");
    show_values(parent);
    printf(":: node keys are ");
    show_values(node);
#endif
    BNode<KeyType> *newNode = new BNode<KeyType>(true);
    int middle = node->keyCount / 2;
    printf("> middle is %d:%d..\n", middle, node->keys[middle]);
    insert_key<KeyType>(newNode->keys, newNode->keyCount, node->keys[middle + 1]);
    newNode->keyCount++;
#ifdef DEBUG
    show_values(newNode);
#endif
    erase_key<KeyType>(node->keys, node->keyCount, node->keys[middle + 1]);
    node->keyCount--;
#ifdef DEBUG
    show_values(node);
#endif
    return;
}