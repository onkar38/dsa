#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThreaded; // Flag to indicate whether the right pointer is a thread
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    newNode->isThreaded = false;
    return newNode;
}

Node* findLeftMost(Node* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

void threadedInOrderUtil(Node* root, Node*& prev) {
    if (root) {
        threadedInOrderUtil(root->left, prev);
        
        if (prev) {
            if (!prev->right) {
                prev->right = root;
                prev->isThreaded = true;
            }
        }
        
        prev = root;
        
        threadedInOrderUtil(root->right, prev);
    }
}

void convertToThreaded(Node* root) {
    Node* prev = nullptr;
    threadedInOrderUtil(root, prev);
}

void threadedInOrder(Node* root) {
    Node* cur = findLeftMost(root);
    while (cur) {
        cout << cur->data << " ";
        if (cur->isThreaded)
            cur = cur->right;
        else
            cur = findLeftMost(cur->right);
    }
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    convertToThreaded(root);

    cout << "Threaded In-order traversal: ";
    threadedInOrder(root);
    cout << endl;

    return 0;
}
