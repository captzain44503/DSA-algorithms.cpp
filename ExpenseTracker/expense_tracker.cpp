#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Expense {
    int id;
    string category;
    string description;
    double amount;
};

class ExpenseTracker {
    vector<Expense> expenses;
    int nextId = 1;

public:
    void addExpense(string category, string description, double amount) {
        expenses.push_back({nextId++, category, description, amount});
        cout << "Expense added successfully.\n";
    }

    void deleteExpense(int id) {
        for (size_t i = 0; i < expenses.size(); i++) {
            if (expenses[i].id == id) {
                expenses.erase(expenses.begin() + i);
                cout << "Expense deleted.\n";
                return;
            }
        }
        cout << "Expense ID not found.\n";
    }

    void displayAll() {
        if (expenses.empty()) {
            cout << "No expenses recorded.\n";
            return;
        }
        cout << left << setw(5) << "ID" << setw(15) << "Category"
             << setw(25) << "Description" << "Amount\n";
        cout << string(60, '-') << "\n";
        for (auto& e : expenses) {
            cout << left << setw(5) << e.id << setw(15) << e.category
                 << setw(25) << e.description << fixed << setprecision(2)
                 << e.amount << "\n";
        }
    }

    void totalByCategory() {
        cout << "\n--- Totals by Category ---\n";
        vector<string> seen;
        for (auto& e : expenses) {
            bool found = false;
            for (auto& s : seen) if (s == e.category) found = true;
            if (found) continue;
            seen.push_back(e.category);

            double total = 0;
            for (auto& e2 : expenses)
                if (e2.category == e.category) total += e2.amount;

            cout << e.category << ": " << fixed << setprecision(2) << total << "\n";
        }
    }

    double grandTotal() {
        double total = 0;
        for (auto& e : expenses) total += e.amount;
        return total;
    }
};

int main() {
    ExpenseTracker tracker;

    // Demo data (simulating user input for showcase purposes)
    tracker.addExpense("Food", "Lunch at cafeteria", 350.0);
    tracker.addExpense("Transport", "Bus fare", 100.0);
    tracker.addExpense("Food", "Dinner", 600.0);
    tracker.addExpense("Books", "DSA reference book", 1200.0);

    cout << "\n";
    tracker.displayAll();

    tracker.totalByCategory();

    cout << "\nGrand Total: " << fixed << setprecision(2)
         << tracker.grandTotal() << "\n";

    tracker.deleteExpense(2);
    cout << "\nAfter deleting expense ID 2:\n";
    tracker.displayAll();

    return 0;
}
