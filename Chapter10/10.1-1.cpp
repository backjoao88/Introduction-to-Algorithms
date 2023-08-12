/**
 * Usando a Figura 10.1 como modelo, ilustre o resultado de cada operação na sequência PUSH(S, 4), PUSH(S, 1), PUSH(S, 3), POP(S), PUSH(S, 8) e POP(S) sobre uma pilha S inicialmente vazia armazenada no arranjo S[1 .. 6].
 */

#include <stdio.h>

const int MAX = 10;

class Stack {
   public:
    int top;
    int array[MAX];
    Stack() {
        this->top = -1;
        for (int i = 0; i < MAX; i++) {
            this->array[i] = -1;
        }
    }

    int pop() {
        if (this->top < 0) return -1;
        int temp = this->array[this->top];
        this->array[this->top] = -1;
        this->top--;
        return temp;
    }

    void push_value(int value) {
        if (this->top > MAX) return;
        this->top++;
        this->array[this->top] = value;
    }

    void print() {
        for (int i = 0; i < MAX; i++) {
            printf("%d ", this->array[i]);
        }
        printf("\n");
    }
};

int main(void) {
    Stack* stack = new Stack();

    stack->push_value(5);
    stack->print();
    stack->push_value(10);
    stack->print();
    stack->push_value(12);
    stack->print();
    stack->pop();
    stack->print();
    stack->push_value(5);
    stack->print();
    stack->push_value(10);
    stack->print();
    stack->push_value(133);
    stack->print();
    stack->push_value(10);
    stack->print();
    stack->push_value(44);
    stack->print();
    stack->push_value(12);
    stack->print();
    stack->push_value(2321);
    stack->print();
    stack->push_value(2321);
    stack->print();
    stack->pop();
    stack->print();
    stack->push_value(12321);
    stack->print();
    stack->push_value(32);
    stack->print();
    stack->push_value(232);
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    stack->pop();
    stack->print();
    return 0;
}
