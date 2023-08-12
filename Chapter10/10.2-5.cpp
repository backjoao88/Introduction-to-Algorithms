/**
 *
 * Implemente as operações de dicionário INSERT, DELETE e SEARCH usando listas circulares simplesmente ligadas.
 * Quais são os tempos de execução dos seus procedimentos?
 *
 */

#include <string>
#include <utility>
#include <stdio.h>

template <typename T>
class Node {
   public:
    T value;
    Node<T>* next;
    Node(const T& value) {
        this->value = value;
    };
};

template <typename T>
class CircularLinkedList {
   public:
    Node<T>* head;
    void insert(const T& value) {
        if (this->head == nullptr) {
            this->head = new Node<T>(value);
            this->head->next = this->head;
            return;
        };
        Node<T>* tmp = this->head;
        while (tmp->next != this->head) {
            tmp = tmp->next;
        };
        tmp->next = new Node<T>(value);
        tmp->next->next = this->head;
    };

    void show() {
        Node<T>* tmp = this->head;
        do {
            printf("%d ", tmp->value);
            tmp = tmp->next;
        } while (tmp != this->head);
        printf("\n");
    }
};

template <typename K, typename V>
class Dict{
    public:
        CircularLinkedList<K>* keys;
        CircularLinkedList<V>* values;
        Dict(){
            keys = new CircularLinkedList<K>();
            values = new CircularLinkedList<V>();
        }
        void insert(const K& key, const V& value){
            this->keys->insert(key);
            this->values->insert(value);
        }

        void remove(const K& key){
            Node* tmpHead = this->keys
        }

        void showValues(){
            this->values->show();
        }
};

int main(void) {
    // CircularLinkedList<int>* circularLinkedList = new CircularLinkedList<int>();
    // circularLinkedList->insert(5);
    // circularLinkedList->insert(1);
    // circularLinkedList->insert(1);
    // circularLinkedList->insert(1);
    // circularLinkedList->insert(1);
    // circularLinkedList->insert(1);
    // circularLinkedList->insert(1);
    // circularLinkedList->show();

    Dict<int, int>* myDict = new Dict<int, int>();
    myDict->insert(0, 1);
    myDict->insert(1, 1);
    myDict->insert(2, 3);
    myDict->insert(3, 4);
    myDict->insert(4, 5);
    myDict->insert(5, 1);

    myDict->showValues();
    // myDict.remove(1);

    return 0;
}