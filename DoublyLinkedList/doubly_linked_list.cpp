#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() { head = tail = nullptr; }

    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) { head = tail = newNode; return; }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) { head = tail = newNode; return; }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void deleteValue(int value) {
        Node* temp = head;
        while (temp && temp->data != value) temp = temp->next;
        if (!temp) return;

        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;

        if (temp->next) temp->next->prev = temp->prev;
        else tail = temp->prev;

        delete temp;
    }

    void displayForward() {
        Node* temp = head;
        cout << "Forward: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void displayBackward() {
        Node* temp = tail;
        cout << "Backward: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertBeginning(5);
    list.displayForward();
    list.displayBackward();

    list.deleteValue(20);
    list.displayForward();

    return 0;
}
