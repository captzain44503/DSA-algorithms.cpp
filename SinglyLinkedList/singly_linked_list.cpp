#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() { head = nullptr; }

    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void deleteValue(int value) {
        if (!head) return;
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data != value)
            curr = curr->next;
        if (curr->next) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }

    bool search(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~SinglyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertBeginning(5);
    list.display();

    list.deleteValue(20);
    list.display();

    cout << "Search 30: " << (list.search(30) ? "Found" : "Not Found") << "\n";
    cout << "Search 99: " << (list.search(99) ? "Found" : "Not Found") << "\n";

    return 0;
}
