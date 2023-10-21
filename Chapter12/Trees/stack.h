#pragma once

#include <stdio.h>
#include "t_node.h"
#define STACK_MAX 10

namespace Chapter12
{
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
}