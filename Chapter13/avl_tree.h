#include "../Chapter12/Trees/binary_tree.h"
#include "../Chapter12/Trees/t_node.h"
#include <algorithm>

using namespace Chapter12;

namespace Chapter13
{
    struct AvlNode : TNode
    {
    public:
        int height = 0;
        AvlNode(int c_height, void *info) : TNode(info)
        {
            height = c_height;
        }
    };
    struct AvlTree : RecursiveBinaryTree
    {

        int height(AvlNode *node)
        {
            if (node == nullptr)
            {
                return -1;
            }
            return node->height;
        }

        void preOrder()
        {
            preOrderRecursive(this->root);
            printf("\n");
        }

        void preOrderRecursive(TNode *root)
        {
            if (root == nullptr)
            {
                return;
            }
            printf("%d ", get_el_as_int(root->info));
            preOrderRecursive(root->leftChild);
            preOrderRecursive(root->rightChild);
        }

        void preOrderHeights()
        {
            preOrderRecursiveHeights(static_cast<AvlNode *>(this->root));
            printf("\n");
        }

        void preOrderRecursiveHeights(AvlNode *root)
        {
            if (root == nullptr)
            {
                return;
            }
            printf("%d ", root->height);
            preOrderRecursiveHeights(static_cast<AvlNode *>(root->leftChild));
            preOrderRecursiveHeights(static_cast<AvlNode *>(root->rightChild));
        }

        void insert(void *el)
        {
            this->insertImpl(this->root, el);
        }

        void insertImpl(TNode *&root, void *el)
        {
            if (root == nullptr)
            {
                TNode *node = new TNode(el);
                root = node;
                AvlNode *avlNode = static_cast<AvlNode *>(root);
                int leftHeight = height(cast(avlNode->leftChild));
                int rightHeight = height(cast(avlNode->rightChild));
                int avlNodeHeight = 1 + std::max(leftHeight, rightHeight);
                avlNode->height = avlNodeHeight;
                return;
            }

            if (get_el_as_int(el) < get_el_as_int(root->info))
            {
                insertImpl(root->leftChild, el);
                root->leftChild->parent = root;
            }
            else
            {
                insertImpl(root->rightChild, el);
                root->rightChild->parent = root;
            }
            AvlNode *avlNode = static_cast<AvlNode *>(root);
            int leftHeight = height(cast(avlNode->leftChild));
            int rightHeight = height(cast(avlNode->rightChild));
            int avlNodeHeight = 1 + std::max(leftHeight, rightHeight);
            avlNode->height = avlNodeHeight;
        };

        AvlNode *cast(TNode *node)
        {
            return static_cast<AvlNode *>(node);
        }

        AvlNode *simplyRotateFromLeft(AvlNode *nodeToBeRotated)
        {
            AvlNode *leftNode = static_cast<AvlNode *>(nodeToBeRotated->leftChild);
            nodeToBeRotated->leftChild = leftNode->rightChild;
            leftNode->rightChild = nodeToBeRotated;
            nodeToBeRotated->height = 1 + std::max(height(static_cast<AvlNode *>(nodeToBeRotated->leftChild)), height(static_cast<AvlNode *>(nodeToBeRotated->rightChild)));
            leftNode->height = 1 + std::max(height(static_cast<AvlNode *>(leftNode->leftChild)), nodeToBeRotated->height);
            return leftNode;
        }
    };
};