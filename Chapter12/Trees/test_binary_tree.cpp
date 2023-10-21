/***
 *
 * Representation of a Binary Tree using void pointers.
 *
 */

#include "binary_tree.h"
#include <stdio.h>
#define STACK_MAX 10

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