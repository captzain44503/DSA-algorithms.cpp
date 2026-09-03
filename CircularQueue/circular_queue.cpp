#include <iostream>
using namespace std;

class CircularQueue {
    int arr[5];
    int front, rear;
    int capacity;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        capacity = 5;
    }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear + 1) % capacity == front; }

    void enqueue(int value) {
        if (isFull()) { cout << "Circular Queue is full\n"; return; }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Circular Queue is empty\n"; return; }
        if (front == rear) { front = rear = -1; return; }
        front = (front + 1) % capacity;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << "Circular Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.display();

    cq.enqueue(6); // should show full

    cq.dequeue();
    cq.enqueue(6);
    cq.display();

    return 0;
}
