#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
    int numBuckets;
    vector<list<pair<int, int>>> table; // (key, value) chaining

    int hashFunction(int key) {
        return key % numBuckets;
    }

public:
    HashTable(int buckets) {
        numBuckets = buckets;
        table.resize(buckets);
    }

    void insert(int key, int value) {
        int idx = hashFunction(key);
        for (auto& pair : table[idx]) {
            if (pair.first == key) {
                pair.second = value; // update existing
                return;
            }
        }
        table[idx].push_back({key, value});
    }

    bool search(int key, int& value) {
        int idx = hashFunction(key);
        for (auto& pair : table[idx]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    void remove(int key) {
        int idx = hashFunction(key);
        table[idx].remove_if([key](pair<int, int>& p) { return p.first == key; });
    }

    void display() {
        for (int i = 0; i < numBuckets; i++) {
            cout << "Bucket " << i << ": ";
            for (auto& pair : table[i])
                cout << "(" << pair.first << "," << pair.second << ") ";
            cout << "\n";
        }
    }
};

int main() {
    HashTable ht(7);
    ht.insert(10, 100);
    ht.insert(20, 200);
    ht.insert(17, 170); // collides with 10 (10%7 == 3, 17%7 == 3)
    ht.insert(5, 50);

    ht.display();

    int value;
    if (ht.search(17, value))
        cout << "Found key 17 -> value: " << value << "\n";

    ht.remove(17);
    cout << "After removing key 17:\n";
    ht.display();

    return 0;
}
