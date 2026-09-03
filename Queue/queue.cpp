#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;

public:
    Queue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return rear == 99; }

    void enqueue(int value) {
        if (isFull()) { cout << "Queue is full\n"; return; }
        if (isEmpty()) front = 0;
        arr[++rear] = value;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        if (front == rear) { front = rear = -1; return; }
        front++;
    }

    int peek() {
        if (isEmpty()) { cout << "Queue is empty\n"; return -1; }
        return arr[front];
    }

    void display() {
        cout << "Queue (front -> rear): ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front: " << q.peek() << "\n";

    q.dequeue();
    q.display();

    return 0;
}
