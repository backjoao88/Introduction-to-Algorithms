/**
 * Escreva um procedimento de tempo O(n) que imprima todas as chaves de uma árvore enraizada arbitrária com n nós, onde a árvore é armazenada usando a representação filho-esquerdo, irmão-direito.
 */

#include <stdio.h>

const int MAX = 10;

/**
 * Representação de uma árvore enraizada que possui no máximo 10 elementos.
 */

class Node {
   public:
    int value;
    Node* children[MAX];
    Node(int value) {
        this->value = value;
        for (int i = 0; i < MAX; i++) {
            children[i] = nullptr;
        }
    }
};

void printNthTree(Node* node) {
    if (!node) {
        return;
    }

    printf("%d ", node->value);

    for (int i = 0; i < MAX; i++) {
        printNthTree(node->children[i]);
    }
}

int main(void) {
    Node* root = new Node(10);
    root->children[0] = new Node(432);
    root->children[1] = new Node(122);
    root->children[2] = new Node(245);
    root->children[3] = new Node(223);
    root->children[4] = new Node(211);
    root->children[4]->children[0] = new Node(1);
    root->children[4]->children[1] = new Node(7);
    root->children[2]->children[0] = new Node(13);
    root->children[2]->children[1] = new Node(12);
    root->children[2]->children[2] = new Node(56);
    root->children[1]->children[0] = new Node(12);
    root->children[1]->children[1] = new Node(15);
    root->children[1]->children[2] = new Node(39);
    root->children[0]->children[0] = new Node(99);
    root->children[0]->children[1] = new Node(88);
    root->children[0]->children[2] = new Node(77);
    root->children[3]->children[0] = new Node(66);
    root->children[3]->children[1] = new Node(55);
    root->children[3]->children[2] = new Node(44);
    root->children[1]->children[0]->children[0] = new Node(33);
    root->children[1]->children[0]->children[1] = new Node(22);
    root->children[1]->children[0]->children[2] = new Node(11);
    printNthTree(root);
}