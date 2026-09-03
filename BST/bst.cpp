#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
    Node* root;

    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data) node->left = insert(node->left, value);
        else if (value > node->data) node->right = insert(node->right, value);
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (!node) return nullptr;
        if (value < node->data) node->left = deleteNode(node->left, value);
        else if (value > node->data) node->right = deleteNode(node->right, value);
        else {
            if (!node->left) { Node* temp = node->right; delete node; return temp; }
            if (!node->right) { Node* temp = node->left; delete node; return temp; }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    bool search(Node* node, int value) {
        if (!node) return false;
        if (node->data == value) return true;
        return value < node->data ? search(node->left, value) : search(node->right, value);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() { root = nullptr; }

    void insert(int value) { root = insert(root, value); }
    void remove(int value) { root = deleteNode(root, value); }
    bool search(int value) { return search(root, value); }

    void displayInorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << "\n";
    }
};

int main() {
    BST tree;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) tree.insert(v);

    tree.displayInorder();

    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << "\n";
    cout << "Search 99: " << (tree.search(99) ? "Found" : "Not Found") << "\n";

    tree.remove(30);
    cout << "After deleting 30:\n";
    tree.displayInorder();

    return 0;
}
