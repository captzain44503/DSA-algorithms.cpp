# DSA Algorithms in C++

A collection of core data structures and algorithms implemented from scratch in C++, along with a small console-based Expense Tracker application built using these fundamentals.

Each folder is self-contained with a single `.cpp` file that includes a `main()` function demonstrating usage — just compile and run.

## Contents

| # | Topic | Folder |
|---|-------|--------|
| 1 | Array Operations | `Array/` |
| 2 | Singly Linked List | `SinglyLinkedList/` |
| 3 | Doubly Linked List | `DoublyLinkedList/` |
| 4 | Stack | `Stack/` |
| 5 | Queue | `Queue/` |
| 6 | Circular Queue | `CircularQueue/` |
| 7 | Binary Search Tree (BST) | `BST/` |
| 8 | AVL Tree (self-balancing BST) | `AVLTree/` |
| 9 | Graph (BFS & DFS) | `Graph/` |
| 10 | Hashing (Hash Table with chaining) | `Hashing/` |
| 11 | Heap (Min-Heap / Priority Queue) | `Heap/` |
| 12 | Sorting Algorithms (Bubble, Insertion, Selection, Merge, Quick) | `Sorting/` |
| 13 | Expense Tracker (mini project) | `ExpenseTracker/` |

## How to Run

Each file can be compiled independently:

```bash
g++ -std=c++17 -o output_name path/to/file.cpp
./output_name
```

Example:

```bash
g++ -std=c++17 -o bst_demo BST/bst.cpp
./bst_demo
```

## Highlights

- **AVL Tree** — implements all four rotation cases (LL, RR, LR, RL) to maintain self-balancing height property.
- **Graph** — adjacency list representation with both BFS (iterative, queue-based) and DFS (recursive).
- **Hashing** — collision handling via separate chaining using `std::list`.
- **Expense Tracker** — a small CLI project applying `struct`, `vector`, and category-wise aggregation to a practical use case (add/delete/view expenses, totals by category).

## Tech

- Language: C++ (C++17)
- No external dependencies — pure STL

## Author

Syed Zain Ul Abideen
BSCS, University of Central Punjab (Gujranwala Campus)
[GitHub](https://github.com/captzain44503) · [LinkedIn](https://linkedin.com/in/syedzain-ulabideen)
