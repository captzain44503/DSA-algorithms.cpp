#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == 99; }

    void push(int value) {
        if (isFull()) { cout << "Stack Overflow\n"; return; }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) { cout << "Stack Underflow\n"; return; }
        top--;
    }

    int peek() {
        if (isEmpty()) { cout << "Stack is empty\n"; return -1; }
        return arr[top];
    }

    void display() {
        cout << "Stack (top -> bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top: " << s.peek() << "\n";

    s.pop();
    s.display();

    return 0;
}
