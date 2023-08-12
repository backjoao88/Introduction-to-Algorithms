/**
 * Escreva um procedimento recursivo de tempo O(n) que, dada uma árvore binária de N nós, imprima a chave de cada nó da árvore.
 */

#include <stdio.h>

struct Node {
    int key;
    Node* leftChild;
    Node* rightChild;
    Node(int key) {
        this->key = key;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
};

void print(Node* node);

int main(void) {
    Node* root = new Node(18);
    root->leftChild = new Node(12);
    root->rightChild = new Node(10);
    root->leftChild->leftChild = new Node(7);
    root->leftChild->leftChild->leftChild = new Node(1);
    root->leftChild->rightChild = new Node(4);
    root->leftChild->rightChild->leftChild = new Node(2);
    root->rightChild->leftChild = new Node(2);
    root->rightChild->rightChild = new Node(21);
    print(root);
};

void print(Node* node) {
    if (!node) {
        return;
    }
    print(node->rightChild);
    print(node->leftChild);
    printf("%d\n", node->key);
}