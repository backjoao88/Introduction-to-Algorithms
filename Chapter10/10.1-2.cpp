/**
 * Explique como implementar duas pilhas em um único arranjo A[1 .. n] de tal modo que nenhuma delas sofra
 * um estouro a menos que o número total de elementos em ambas as pilhas juntas seja n. As operações PUSH e
 * POP devem ser executadas no tempo O(1).
 */

#include <stdio.h>

const int N = 10;

class TwoStacks {
   public:
    TwoStacks() {
        this->topFirstStack = -1;
        this->topSecondStack = N;
        for (int i = 0; i < N; i++) {
            this->m_data[i] = -1;
        }
    }
    ~TwoStacks();

    void push_1(int value) {
        if ((this->topSecondStack + 1) == this->topFirstStack) return;
        this->topFirstStack++;
        this->m_data[this->topFirstStack] = value;
    }
    void push_2(int value) {
        if ((this->topSecondStack - 1) == this->topFirstStack) return;
        this->topSecondStack--;
        this->m_data[this->topSecondStack] = value;
    }

    int pop_1() {
        if (this->topFirstStack == 0) return -1;
        int temp = this->m_data[this->topFirstStack];
        this->m_data[this->topFirstStack] = -1;
        this->topFirstStack--;
        return temp;
    }

    int pop_2() {
        if (this->topSecondStack == N) return -1;
        int temp = this->m_data[this->topSecondStack];
        this->m_data[this->topSecondStack] = -1;
        this->topSecondStack++;
        return temp;
    }

    void print() {
        for (int i = 0; i < N; i++) {
            printf("%d ", this->m_data[i]);
        }
        printf("\n");
    }

   private:
    int m_data[N];
    int topFirstStack;
    int topSecondStack;
};

int main(void) {
    TwoStacks* stacks = new TwoStacks();
    stacks->push_1(1);
    stacks->push_1(33);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_1(44);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->pop_2();
    stacks->print();
    stacks->pop_2();
    stacks->print();
    stacks->pop_2();
    stacks->print();
    stacks->pop_2();
    stacks->print();
    stacks->pop_2();
    stacks->print();
    stacks->pop_2();
    stacks->print();
    stacks->pop_2();
    stacks->print();
    stacks->pop_2();
    stacks->print();
    stacks->pop_2();
    stacks->print();
    stacks->pop_2();
    stacks->print();
    stacks->pop_2();
    stacks->print();
    stacks->push_1(13);
    stacks->print();
    stacks->push_1(11);
    stacks->print();
    stacks->push_1(12);
    stacks->print();
    stacks->push_1(14);
    stacks->print();
    stacks->push_1(15);
    stacks->print();
    stacks->push_2(15);
    stacks->print();
    stacks->pop_1();
    stacks->print();
    stacks->pop_1();
    stacks->print();
    stacks->pop_1();
    stacks->print();
    stacks->pop_1();
    stacks->print();
    stacks->pop_1();
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
    stacks->push_2(2);
    stacks->print();
}