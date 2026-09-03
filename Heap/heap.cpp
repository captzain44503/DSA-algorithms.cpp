#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (heap[idx] < heap[parent]) {
                swap(heap[idx], heap[parent]);
                idx = parent;
            } else break;
        }
    }

    void heapifyDown(int idx) {
        int size = heap.size();
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int smallest = idx;

            if (left < size && heap[left] < heap[smallest]) smallest = left;
            if (right < size && heap[right] < heap[smallest]) smallest = right;

            if (smallest == idx) break;
            swap(heap[idx], heap[smallest]);
            idx = smallest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int getMin() {
        if (heap.empty()) { cout << "Heap is empty\n"; return -1; }
        return heap[0];
    }

    void extractMin() {
        if (heap.empty()) { cout << "Heap is empty\n"; return; }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() {
        cout << "Heap: ";
        for (int val : heap) cout << val << " ";
        cout << "\n";
    }
};

int main() {
    MinHeap heap;
    heap.insert(10);
    heap.insert(5);
    heap.insert(20);
    heap.insert(1);
    heap.insert(8);

    heap.display();
    cout << "Min: " << heap.getMin() << "\n";

    heap.extractMin();
    cout << "After extractMin:\n";
    heap.display();

    return 0;
}
