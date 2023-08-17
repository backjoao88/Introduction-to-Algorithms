/**
 * Implemente as operações de dicionário INSERT, DELETE e SEARCH usando listas circulares simplesmente ligadas.
 * Quais são os tempos de execução dos seus procedimentos?
 */

#include <stdio.h>

template <typename K, typename V>
class Node {
   public:
    Node(const K& c_key, const V& c_value) : key(c_key), value(c_value){};
    K key;
    V value;
    Node<K, V>* next;
};

template <typename K, typename V>
class CircularLinkedList {
   public:
    CircularLinkedList() { this->head = nullptr; };
    Node<K, V>* head;

    void addLast(const K& key, const V& value) {
        if (this->head == nullptr) {
            this->head = new Node<K, V>(key, value);
            this->head->next = this->head;
            return;
        }
        Node<K, V>* node = new Node<K, V>(key, value);
        Node<K, V>* tmp = this->head;
        while (tmp->next != this->head) {
            tmp = tmp->next;
        }
        tmp->next = node;
        node->next = this->head;
    }

    void addFront(const K& key, const V& value) {
        if (this->head == nullptr) {
            this->head = new Node<K, V>(key, value);
            this->head->next = this->head;
            return;
        }
        Node<K, V>* tmp = new Node<K, V>(key, value);
        tmp->next = this->head;

        printf("tmp %p\n", tmp);
        printf("tmp address %p\n", &tmp);
        printf("tmp nxt %p - head %p\n", tmp->next, this->head);
        printf("tmp address nxt %p - head address %p\n", &tmp->next, &this->head);
        // update last node next ref
        Node<K, V>* curr = this->head;

        while (curr->next != this->head) {
            curr = curr->next;
        }

        printf("curr next %p\n", curr->next);

        this->head = tmp;
        printf("new head %p\n", this->head);
        printf("curr next %p\n", curr->next);
        curr->next = this->head;
        printf("curr next %p\n", curr->next);
        printf("\n");
    }

    void remove(const K& key) {
        if (this->head == nullptr) {
            return;
        }

        if (this->head->key == key) {
            Node<K, V>* curr = this->head;
            while (curr->next != this->head) {
                curr = curr->next;
            }
            this->head = this->head->next;
            curr->next = this->head;
            return;
        }

        Node<K, V>* tmp = this->head;
        Node<K, V>* prev = nullptr;
        while (tmp->next != this->head) {
            if (tmp->key == key) {
                break;
            }
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = tmp->next;
    }

    V search(const K& key) {
        if (this->head == nullptr) {
            return -1;
        }

        Node<K, V>* tmp = this->head;

        if (key == tmp->key) {
            return tmp->value;
        }
        while (tmp->next != this->head) {
            if (key == tmp->key) {
                return tmp->value;
            }
            tmp = tmp->next;
        }

        return -1;
    }

    void show() {
        Node<K, V>* tmp = this->head;
        if (tmp == nullptr) {
            printf("empty.\n");
            return;
        }
        do {
            printf("%d ", tmp->value);
            tmp = tmp->next;
        } while (tmp != this->head);
        printf("\n");
    }
};

int main(void) {
    CircularLinkedList<int, int>* circularLinkedList = new CircularLinkedList<int, int>();
    circularLinkedList->addFront(44, 2);
    // circularLinkedList->show();
    circularLinkedList->addFront(1, 3);
    // circularLinkedList->show();
    circularLinkedList->addFront(2, 4);
    // circularLinkedList->show();
    circularLinkedList->addFront(3, 1);
    // circularLinkedList->show();
    circularLinkedList->addFront(4, 22);
    circularLinkedList->addFront(5, 23);
    circularLinkedList->addFront(6, 24);
    circularLinkedList->addFront(7, 25);
    circularLinkedList->addFront(8, 126);
    circularLinkedList->remove(8);
    circularLinkedList->show();
    circularLinkedList->addLast(9, 20);
    circularLinkedList->addFront(10, 255);
    circularLinkedList->addLast(11, 256);
    circularLinkedList->show();
    printf("%d \n", circularLinkedList->search(7));
    circularLinkedList->remove(7);
    circularLinkedList->show();
    circularLinkedList->remove(44);
    circularLinkedList->show();
    circularLinkedList->remove(11);
    circularLinkedList->show();
    circularLinkedList->addLast(13, 66);
    circularLinkedList->show();
    circularLinkedList->addFront(22, 33);
    circularLinkedList->show();
    circularLinkedList->remove(22);
    circularLinkedList->show();
    circularLinkedList->remove(10);
    circularLinkedList->show();
};