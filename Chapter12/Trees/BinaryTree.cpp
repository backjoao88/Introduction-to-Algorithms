/***
 *
 * Representation of a Binary Tree using void pointers.
 *
 */

#include <stdio.h>
#define STACK_MAX 10

namespace Chapter12
{

    struct TNode
    {
        TNode *leftChild;
        TNode *rightChild;
        void *info;
        TNode(void *info)
        {
            this->leftChild = nullptr;
            this->rightChild = nullptr;
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

        void printNodeInfo()
        {
            printf("Node Addr %p, Left Child Addr = %p, Right Child Addr = %p, Value = %d\n", this, this->leftChild, this->rightChild, *(int *)this->info);
        }
    };

    struct Stack
    {
        int top;
        void *data[STACK_MAX];
        Stack()
        {
            this->top = -1;
            for (auto i = 0; i < STACK_MAX; i++)
            {
                data[i] = nullptr;
            }
        }
        bool is_empty()
        {
            return this->top == -1;
        }

        /*debug only*/
        void print_stack()
        {
            printf("-- stack (top = %d)\n", this->top);
            for (auto i = 0; i < STACK_MAX; i++)
            {
                printf("%p ", (int *)data[i]);
            }
            printf("\n");
        }

        void *check_top()
        {
            return this->data[this->top];
        }
        void push(void *el)
        {
            if (this->top > STACK_MAX)
            {
                return;
            }
            this->top++;
            this->data[this->top] = el;
        };

        int get_el_as_int(void *el)
        {
            return *((int *)el);
        };

        TNode *get_as_tnode(void *el)
        {
            return (TNode *)el;
        }

        void pop()
        {
            if (this->top < 0)
            {
                return;
            }
            void *last = this->data[this->top];
            this->data[this->top] = nullptr;
            this->top--;
        };
    };

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
            }
            else
            {
                insertImpl(root->rightChild, el);
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
};

using namespace Chapter12;

void test_stack()
{
    Stack *stack = new Stack();
    printf("is empty: %d\n", stack->is_empty());
    stack->print_stack();
    int value1 = 1;
    int value2 = 2;
    int value3 = 3;
    stack->push(&value1);
    stack->print_stack();
    printf("is empty: %d\n", stack->is_empty());
    stack->push(&value2);
    stack->print_stack();
    stack->push(&value3);
    printf("is empty: %d\n", stack->is_empty());
    stack->print_stack();
    int *pvalue3 = (int *)stack->check_top();
    printf("addr: %p \n", pvalue3);
    stack->pop();
    stack->print_stack();
    stack->pop();
    printf("is empty: %d\n", stack->is_empty());
    stack->print_stack();
    stack->push(&value2);
    stack->print_stack();
    stack->push(&value3);
    stack->print_stack();
    stack->pop();
    stack->print_stack();
    printf("is empty: %d\n", stack->is_empty());
    stack->pop();
    stack->print_stack();
    printf("is empty: %d\n", stack->is_empty());
    stack->pop();
    stack->print_stack();
    printf("is empty: %d\n", stack->is_empty());
}

void test_recursive_binary_tree()
{
    int first = 19;
    int second = 20;
    int third = 11;
    int fourth = 2;
    int fiveth = 7;
    int sixth = 21;
    int seventh = 31;
    int eighth = 12;
    int nineth = 5;
    int ten = 18;
    int eleven = 15;

    RecursiveBinaryTree *tree = new RecursiveBinaryTree();
    tree->insert(&first);
    tree->insert(&second);
    tree->insert(&third);
    tree->insert(&fourth);
    tree->insert(&fiveth);
    tree->insert(&sixth);
    tree->insert(&seventh);
    tree->insert(&eighth);
    tree->insert(&nineth);
    tree->insert(&ten);
    tree->insert(&eleven);

    tree->preOrder();
    tree->remove(&third);
    tree->preOrder();
}

void test_iterative_binary_tree()
{
    /* iterative binary tree */
    int itFirst = 10;
    int itSecond = 5;
    int itThird = 4;
    int itFourth = 7;
    int itFiveth = 6;
    int itSixth = 8;
    int itSeventh = 9;
    int itEighth = 11;
    int itNine = 12;

    IterativeBinaryTree *itTree = new IterativeBinaryTree();
    itTree->insert(&itFirst);
    itTree->insert(&itSecond);
    itTree->insert(&itThird);
    itTree->insert(&itFourth);
    itTree->insert(&itFiveth);
    itTree->insert(&itSixth);
    itTree->insert(&itSeventh);
    itTree->insert(&itEighth);
    itTree->insert(&itNine);
    itTree->preOrder();
    itTree->inOrder();
}

int main(void)
{
    // printf("%% test stack\n");
    // test_stack();
    printf("%% test recursive binary tree\n");
    test_recursive_binary_tree();
    // printf("%% test iterative binary tree\n");
    // test_iterative_binary_tree();
    return 0;
}