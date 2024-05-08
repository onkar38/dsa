#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string name;
    vector<Node*> children;
    Node(string n) : name(n) {}
};

void buildBook(Node*& root) {
    string title;
    cout << "Enter the title of the Book: ";
    getline(cin, title);
    root = new Node(title);

    int numChapters;
    cout << "Enter the number of chapters in the book: ";
    cin >> numChapters;
    cin.ignore();

    for (int i = 0; i < numChapters; ++i) {
        string chapterName;
        cout << "Chapter " << i + 1 << ": ";
        getline(cin, chapterName);
        Node* chapter = new Node(chapterName);
        root->children.push_back(chapter);

        int numSections;
        cout << "Enter number of sections for " << chapterName << ": ";
        cin >> numSections;
        cin.ignore();

        for (int j = 0; j < numSections; ++j) {
            string sectionName;
            cout << "Section " << i + 1 << "." << j + 1 << ": ";
            getline(cin, sectionName);
            Node* section = new Node(sectionName);
            chapter->children.push_back(section);
        }
    }
}

void printNodes(Node* root, string prefix = "") {
    if (root == nullptr) return;
    cout << prefix << root->name << endl;
    for (size_t i = 0; i < root->children.size(); ++i) {
        printNodes(root->children[i], prefix + to_string(i + 1) + ".");
    }
}

int main() {
    Node* book = nullptr;
    buildBook(book);
    cout << "\n----------INDEX----------" << endl;
    cout << "TITLE:" << book->name << endl;
    cout << "CHAPTERS:" << endl;
    printNodes(book, "1.");
    delete book;
    return 0;
}
