#include <iostream>
using namespace std;

class ArrayOps {
    int arr[100];
    int size;

public:
    ArrayOps() { size = 0; }

    void insert(int value, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Invalid position\n";
            return;
        }
        for (int i = size; i > pos; i--)
            arr[i] = arr[i - 1];
        arr[pos] = value;
        size++;
    }

    void deleteAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position\n";
            return;
        }
        for (int i = pos; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }

    int search(int value) {
        for (int i = 0; i < size; i++)
            if (arr[i] == value) return i;
        return -1;
    }

    void display() {
        cout << "Array: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    ArrayOps a;
    a.insert(10, 0);
    a.insert(20, 1);
    a.insert(30, 2);
    a.display();

    a.insert(15, 1);
    a.display();

    a.deleteAt(0);
    a.display();

    int idx = a.search(20);
    cout << "Search 20 -> index: " << idx << "\n";

    return 0;
}
