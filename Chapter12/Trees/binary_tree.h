#pragma once

#include <stdio.h>
#include "t_node.h"
#include "stack.h"

namespace Chapter12
{
    struct IterativeBinaryTree
    {
        TNode *root;

        int get_el_as_int(void *el)
        {
            return *((int *)el);
        };

        TNode *get_as_tnode(void *el)
        {
            return (TNode *)el;
        }

        void inOrder()
        {
            if (this->root == nullptr)
            {
                return;
            }

            Stack *s = new Stack();
            TNode *curr = this->root;
            while (curr != nullptr || !s->is_empty())
            {
                while (curr != nullptr)
                {
                    s->push(curr);
                    curr = curr->leftChild;
                }
                curr = get_as_tnode(s->check_top());
                printf("%d ", get_el_as_int(curr->info));
                s->pop();
                curr = curr->rightChild;
            }
            printf("\n");
        }

        void preOrder()
        {
            if (this->root == nullptr)
            {
                return;
            }

            Stack *s = new Stack();
            s->push(this->root);
            while (!s->is_empty())
            {
                TNode *el = get_as_tnode(s->check_top());
                s->pop();
                if (el->rightChild != nullptr)
                    s->push(el->rightChild);
                if (el->leftChild != nullptr)
                    s->push(el->leftChild);
                printf("%d ", get_el_as_int(el->info));
            }
            printf("\n");
        }

        void insert(void *el)
        {
            if (this->root == nullptr)
            {
                TNode *node = new TNode(el);
                this->root = node;
                return;
            };
            TNode *tmp = this->root;
            TNode *last = tmp;
            while (tmp != nullptr)
            {
                last = tmp;
                if (get_el_as_int(el) < get_el_as_int(tmp->info))
                {
                    tmp = tmp->leftChild;
                }
                else
                {
                    tmp = tmp->rightChild;
                }
            }
            TNode *node = new TNode(el);
            if (get_el_as_int(el) < get_el_as_int(last->info))
            {
                last->leftChild = node;
            }
            else
            {
                last->rightChild = node;
            }
        }
    };

    struct RecursiveBinaryTree
    {
        TNode *root;

        int get_el_as_int(void *el)
        {
            return *((int *)el);
        };

        TNode *search(TNode *root, void *el)
        {
            if (root == nullptr)
            {
                return nullptr;
            }
            if (get_el_as_int(el) == get_el_as_int(root->info))
            {
                return root;
            }
            if (get_el_as_int(el) < get_el_as_int(root->info))
            {
                return search(root->leftChild, el);
            }
            else
            {
                return search(root->rightChild, el);
            }
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
        };

        void remove(void *el)
        {
            this->removeImpl(this->root, el);
        }

        void removeImpl(TNode *&root, void *el)
        {
            if (el == nullptr)
            {
                return;
            }

            if (get_el_as_int(el) > get_el_as_int(root->info))
            {
                removeImpl(root->rightChild, el);
            }
            else
            {
                if (get_el_as_int(el) < get_el_as_int(root->info))
                {
                    removeImpl(root->leftChild, el);
                }
                else
                {
                    if (root->isLeaf())
                    {
                        root = nullptr;
                        return;
                    }
                    if (root->hasChildOnLeft() && !root->hasChildOnRight())
                    {
                        root = root->leftChild;
                        return;
                    }

                    if (!root->hasChildOnLeft() && root->hasChildOnRight())
                    {
                        root = root->rightChild;
                        return;
                    }
                    TNode *aux = root;
                    while (aux->leftChild != nullptr)
                    {
                        aux = aux->leftChild;
                    };
                    root->info = aux->info;
                    removeImpl(root->leftChild, aux->info);
                }
            }
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

        void inOrder()
        {
            inOrderRecursive(this->root);
            printf("\n");
        }

        void inOrderRecursive(TNode *root)
        {
            if (root == nullptr)
            {
                return;
            }
            inOrderRecursive(root->leftChild);
            printf("%d ", get_el_as_int(root->info));
            inOrderRecursive(root->rightChild);
        }

        void posOrder()
        {
            posOrderRecursive(this->root);
            printf("\n");
        }

        void posOrderRecursive(TNode *root)
        {
            if (root == nullptr)
            {
                return;
            }
            posOrderRecursive(root->leftChild);
            posOrderRecursive(root->rightChild);
            printf("%d ", get_el_as_int(root->info));
        }
    };

}