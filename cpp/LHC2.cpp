#include <bits/stdc++.h>
using namespace std;

void computefine() {
    int book_id;
    int due_date;
    int return_date;

    cout << "Enter the book id: ";
    cin >> book_id;

    cout << "Enter the due date: ";
    cin >> due_date;

    cout << "Enter the return date: ";
    cin >> return_date;

    if (book_id < 1 || book_id > 1000 ||
        due_date < 1 || due_date > 31 ||
        return_date < 1 || return_date > 31) {
        cout << "Invalid input";
        return;
    }

    if (return_date <= due_date) {
        cout << "No Fine";
    } else {
        cout << "Fine for " << book_id << ": " << (return_date - due_date);
    }
}
int main() {
    computefine();
    return 0;
}
