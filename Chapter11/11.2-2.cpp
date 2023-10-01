/***
 *
 * 11.2-2
 * Consider a hash table with 9 slots and the hash function h(k) = k mod 9.
 * Demonstrate what happens upon inserting the keys 5; 28; 19; 15; 20; 33; 12; 17; 10 with
 * collisions resolved by chaining.
 *
 * R: It will insert by chaining in a linked list the numbers between a 0-8 range, based on a mod calculation between the key and 9.
 *
 */

#include <stdio.h>
#define HASH_SLOTS 9

struct LLNode
{
    float value;
    LLNode *next;
    LLNode(){};
    LLNode(float c_value)
    {
        this->value = c_value;
        this->next = nullptr;
    }
};

struct LL
{
    LLNode *head = nullptr; // initialize THE FUCKING POINTER THIS TIME!!!

    void insert(float value)
    {
        if (this->head == nullptr)
        {
            this->head = new LLNode(value);
            return;
        }
        LLNode *newNode = new LLNode(value);
        newNode->next = this->head;
        this->head = newNode;
    };
};

void insert(LL *T, int key, float value);
int hashFn(int key);

void insert(LL *T, int key, float value)
{
    int idx = hashFn(key);
    T[idx].insert(value);
};

void showKey(LL *T, int key)
{
    int idx = hashFn(key);
    LLNode *aux = T[idx].head;
    while (aux != nullptr)
    {
        printf("%.2f\n", aux->value);
        aux = aux->next;
    }
}

int hashFn(int key)
{
    return key % HASH_SLOTS;
}

int main(void)
{
    // 5; 28; 19; 15; 20; 33; 12; 17; 10 with
    LL data[HASH_SLOTS];
    insert(data, 5, 5.0f);
    insert(data, 28, 28.0f);
    insert(data, 19, 19.0f);
    insert(data, 15, 15.0f);
    insert(data, 20, 20.0f);
    insert(data, 33, 33.0f);
    insert(data, 12, 12.0f);
    insert(data, 17, 17.0f);
    insert(data, 10, 10.0f);
    showKey(data, 1);
    return 0;
}