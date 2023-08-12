/**
 *
 * Implemente as operações de dicionário INSERT, DELETE e SEARCH usando listas circulares simplesmente ligadas.
 * Quais são os tempos de execução dos seus procedimentos?
 *
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

class CircularLinkedList {
   public:
    Node* head;
    void insert(int value) {
        if (this->head == nullptr) {
            this->head = new Node(value);
            this->head->next = this->head;
            return;
        };
        Node* tmp = this->head;
        while (tmp->next != this->head) {
            tmp = tmp->next;
        };
        tmp->next = new Node(value);
        tmp->next->next = this->head;
    };

    void show() {
        Node* tmp = this->head;
        do {
            printf("%d ", tmp->value);
            tmp = tmp->next;
        } while (tmp != this->head);
        printf("\n");
    }
};

int main(void) {
    CircularLinkedList* circularLinkedList = new CircularLinkedList();
    circularLinkedList->insert(5);
    circularLinkedList->insert(1);
    circularLinkedList->insert(1);
    circularLinkedList->insert(1);
    circularLinkedList->insert(1);
    circularLinkedList->insert(1);
    circularLinkedList->insert(1);
    circularLinkedList->show();
    return 0;
}