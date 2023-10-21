#pragma once
#include <stdio.h>

namespace Chapter12
{
    struct TNode
    {
        TNode *leftChild;
        TNode *rightChild;
        TNode *parent;
        void *info;
        TNode(void *info)
        {
            this->leftChild = nullptr;
            this->rightChild = nullptr;
            this->parent = nullptr;
            this->info = info;
        }

        bool hasChildOnRight()
        {
            return this->rightChild != nullptr;
        }

        bool hasChildOnLeft()
        {
            return this->leftChild != nullptr;
        }

        bool isLeaf()
        {
            return this->leftChild == nullptr && this->rightChild == nullptr;
        }

        void printValue()
        {
            printf("%d ", *(int *)this->info);
        }

        void printNodeInfo()
        {
            printf("Node Addr %p, Left Child Addr = %p, Right Child Addr = %p, Value = %d\n", this, this->leftChild, this->rightChild, *(int *)this->info);
        }
    };
};