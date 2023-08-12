
#include <stdio.h>

#include <stack>

/**
* Representação de uma árvore binária
*/

namespace Chapter10 {

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

class BinaryTree {
   public:
    Node* m_root;
    void insert(int newKey) {
        Node* newNode = new Node(newKey);
        Node* temp = this->m_root;
        Node* last = nullptr;
        while (temp != nullptr) {
            last = temp;
            if (temp->key < newKey) {
                temp = temp->rightChild;
            } else {
                temp = temp->leftChild;
            }
        }
        if (last == nullptr) {
            last = newNode;
        } else {
            if (last->key < newKey) {
                last->rightChild = newNode;
            } else {
                last->leftChild = newNode;
            }
        }
    };

    void printNonRecursive() {
        std::stack<Node*> stack;
        Node* temp = this->m_root;
        stack.emplace(temp);
        while (!stack.empty()) {
            Node* top = stack.top();
            stack.pop();
            if (top->rightChild != nullptr) stack.emplace(top->rightChild);
            if (top->leftChild != nullptr) stack.emplace(top->leftChild);
            printf(" %d ", top->key);
        }
    }

    void printRecursive() {
        this->recursivePrint(this->m_root);
    }

    void recursivePrint(Node* node) {
        if (!node) return;
        recursivePrint(node->leftChild);
        recursivePrint(node->rightChild);
        printf("%d\n", node->key);
    }
};

} 