/**
 * Usando a Figura 10.2 como modelo, ilustre o resultado de cada operação na sequência ENQUEUE(Q, 4),
 * ENQUEUE(Q, 1), ENQUEUE(Q, 3), DEQUEUE(Q), ENQUEUE(Q, 8) e DEQUEUE(Q) em uma fila Q inicialmente vazia
 * armazenada no arranjo Q[1 .. 6].
 */

#include <stdio.h>

#include <cstdlib>
#include <ctime>

const int MAX_SIZE = 6;

class Queue
{
public:
    void enqueue(int value)
    {
        this->last++;
        this->m_data[this->last] = value;
    }
    void dequeue()
    {
        for (int i = 0; i < MAX_SIZE - 1; i++)
        {
            if (this->m_data[i] != -1)
            {
                this->m_data[i] = this->m_data[i + 1];
            }
        }
        this->last--;
    }
    void print()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            printf("%d  ", this->m_data[i]);
        }
        printf("\n");
    }
    Queue()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            this->m_data[i] = -1;
        }
        this->last = -1;
    }
    ~Queue();

private:
    int m_data[MAX_SIZE];
    int last;
};

int main(void)
{
    srand(time(0));
    Queue *queue = new Queue();
    queue->enqueue(1);
    queue->enqueue(3);
    queue->dequeue();
    queue->enqueue(8);
    queue->dequeue();
    queue->print();
}