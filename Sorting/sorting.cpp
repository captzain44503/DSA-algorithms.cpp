#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>& arr) {
    for (int val : arr) cout << val << " ";
    cout << "\n";
}

void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
    cout << "Bubble Sort: ";
    printArray(arr);
}

void insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    cout << "Insertion Sort: ";
    printArray(arr);
}

void selectionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
    cout << "Selection Sort: ";
    printArray(arr);
}

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < (int)left.size() && j < (int)right.size())
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i < (int)left.size()) arr[k++] = left[i++];
    while (j < (int)right.size()) arr[k++] = right[j++];
}

void mergeSortHelper(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortHelper(arr, l, m);
    mergeSortHelper(arr, m + 1, r);
    merge(arr, l, m, r);
}

void mergeSort(vector<int> arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
    cout << "Merge Sort: ";
    printArray(arr);
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(vector<int> arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
    cout << "Quick Sort: ";
    printArray(arr);
}

int main() {
    vector<int> original = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original: ";
    printArray(original);

    bubbleSort(original);
    insertionSort(original);
    selectionSort(original);
    mergeSort(original);
    quickSort(original);

    return 0;
}
