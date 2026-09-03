#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
    Node* root;

    int height(Node* node) { return node ? node->height : 0; }

    int balanceFactor(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    void updateHeight(Node* node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);

        if (value < node->data) node->left = insert(node->left, value);
        else if (value > node->data) node->right = insert(node->right, value);
        else return node;

        updateHeight(node);
        int balance = balanceFactor(node);

        // Left Left
        if (balance > 1 && value < node->left->data)
            return rotateRight(node);

        // Right Right
        if (balance < -1 && value > node->right->data)
            return rotateLeft(node);

        // Left Right
        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left
        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << "(h" << node->height << ") ";
        inorder(node->right);
    }

public:
    AVLTree() { root = nullptr; }

    void insert(int value) { root = insert(root, value); }

    void displayInorder() {
        cout << "Inorder (with heights): ";
        inorder(root);
        cout << "\n";
    }
};

int main() {
    AVLTree tree;
    int values[] = {10, 20, 30, 40, 50, 25};
    for (int v : values) tree.insert(v);

    // This sequence forces multiple rotation types (LL, RR, LR)
    tree.displayInorder();
    cout << "Tree stays balanced automatically after each insert (AVL property).\n";

    return 0;
}
