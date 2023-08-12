/**
 * Implemente uma pilha usando uma lista simplesmente ligada L. As operações PUSH e POP ainda devem demorar
 * o tempo O(1).
 */

#include <stdio.h>

class Node {
   public:
    int value;
    Node* next;
    Node(int value) {
        this->value = value;
    };
};

class LinkedList {
   public:
    Node* head;
    void insert(int value) {
        if (this->head == nullptr) {
            this->head = new Node(value);
            return;
        }
        Node* tmp = this->head;
        Node* newNode = new Node(value);
        this->head = newNode;
        this->head->next = tmp;
    };

    void remove() {
        Node* tmp = this->head->next;
        this->head = tmp;
    };

    void show() {
        Node* tmp = this->head;
        while (tmp != nullptr) {
            printf("%d ", tmp->value);
            tmp = tmp->next;
        };
        printf("\n");
    }
};

int main() {
    LinkedList* linkedList = new LinkedList();
    linkedList->insert(5);
    linkedList->insert(6);
    linkedList->insert(6);
    linkedList->insert(6);
    linkedList->remove();
    linkedList->remove();
    linkedList->remove();
    linkedList->remove();
    linkedList->insert(2);
    linkedList->insert(6);
    linkedList->insert(6);
    linkedList->show();
    return 0;
};