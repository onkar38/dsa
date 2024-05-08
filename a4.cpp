#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    void insert(int val) {
        root = insertUtil(root, val);
        cout << "Inserted value: " << val << endl;
    }

    int longestPath() {
        return longestPathUtil(root);
    }

    int minValue() {
        Node* curr = root;
        while (curr->left != nullptr) {
            curr = curr->left;
        }
        return curr->data;
    }

    void swapLR() {
        swapLRUtil(root);
        cout << "Swapped left and right pointers at every node." << endl;
    }

    bool search(int val) {
        bool found = searchUtil(root, val);
        if (found) {
            cout << "Value " << val << " found in the tree." << endl;
        } else {
            cout << "Value " << val << " not found in the tree." << endl;
        }
        return found;
    }

    void printSwappedTree() {
        cout << "Swapped tree structure:" << endl;
        printLevelOrder(root);
    }

private:
    Node* insertUtil(Node* root, int val) {
        if (root == nullptr) {
            return new Node(val);
        }
        if (val < root->data) {
            root->left = insertUtil(root->left, val);
        } else {
            root->right = insertUtil(root->right, val);
        }
        return root;
    }

    int longestPathUtil(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(longestPathUtil(root->left), longestPathUtil(root->right));
    }

    void swapLRUtil(Node* root) {
        if (root == nullptr) {
            return;
        }
        swap(root->left, root->right);
        swapLRUtil(root->left);
        swapLRUtil(root->right);
    }

    bool searchUtil(Node* root, int val) {
        if (root == nullptr) {
            return false;
        }
        if (root->data == val) {
            return true;
        }
        if (val < root->data) {
            return searchUtil(root->left, val);
        } else {
            return searchUtil(root->right, val);
        }
    }

    void printLevelOrder(Node* root) {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();
                cout << node->data << " ";
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            cout << endl;
        }
    }
};

int main() {
    BST bst;

    cout << "Enter values to insert into the binary search tree (enter -1 to stop):\n";
    int val;
    while (true) {
        cin >> val;
        if (val == -1) break;
        bst.insert(val);
    }

    // Find number of nodes in longest path from root
    cout << "Number of nodes in the longest path from root: " << bst.longestPath() << endl;

    // Minimum data value found in the tree
    cout << "Minimum data value found in the tree: " << bst.minValue() << endl;

    // Change the tree so that the roles of the left and right pointers are swapped at every node
    bst.swapLR();

    // Display the swapped tree structure
    bst.printSwappedTree();

    // Search for a value
    cout << "Enter a value to search for: ";
    cin >> val;
    bst.search(val);

    return 0;
}













// #include <iostream>
// #include <queue>
// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) : data(val), left(nullptr), right(nullptr) {}
// };

// class BST {
// public:
//     Node* root;

//     BST() : root(nullptr) {}

//     void insert(int val) {
//         root = insertUtil(root, val);
//     }

//     int longestPath() {
//         return longestPathUtil(root);
//     }

//     int minValue() {
//         Node* curr = root;
//         while (curr->left != nullptr) {
//             curr = curr->left;
//         }
//         return curr->data;
//     }

//     void swapLR() {
//         swapLRUtil(root);
//     }

//     bool search(int val) {
//         return searchUtil(root, val);
//     }

// private:
//     Node* insertUtil(Node* root, int val) {
//         if (root == nullptr) {
//             return new Node(val);
//         }
//         if (val < root->data) {
//             root->left = insertUtil(root->left, val);
//         } else {
//             root->right = insertUtil(root->right, val);
//         }
//         return root;
//     }

//     int longestPathUtil(Node* root) {
//         if (root == nullptr) {
//             return 0;
//         }
//         return 1 + max(longestPathUtil(root->left), longestPathUtil(root->right));
//     }

//     void swapLRUtil(Node* root) {
//         if (root == nullptr) {
//             return;
//         }
//         swap(root->left, root->right);
//         swapLRUtil(root->left);
//         swapLRUtil(root->right);
//     }

//     bool searchUtil(Node* root, int val) {
//         if (root == nullptr) {
//             return false;
//         }
//         if (root->data == val) {
//             return true;
//         }
//         if (val < root->data) {
//             return searchUtil(root->left, val);
//         } else {
//             return searchUtil(root->right, val);
//         }
//     }
// };

// int main() {
//     BST bst;

//     cout << "Enter values to insert into the binary search tree (enter -1 to stop):\n";
//     int val;
//     while (true) {
//         cin >> val;
//         if (val == -1) break;
//         bst.insert(val);
//     }

//     // Find number of nodes in longest path from root
//     cout << "Number of nodes in the longest path from root: " << bst.longestPath() << endl;

//     // Minimum data value found in the tree
//     cout << "Minimum data value found in the tree: " << bst.minValue() << endl;

//     // Change the tree so that the roles of the left and right pointers are swapped at every node
//     bst.swapLR();

//     // Search for a value
//     cout << "Enter a value to search for: ";
//     cin >> val;
//     cout << "Searching for value " << val << ": " << (bst.search(val) ? "Found" : "Not found") << endl;

//     return 0;
// }
