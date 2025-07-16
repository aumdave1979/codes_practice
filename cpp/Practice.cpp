#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;

    int a = 0, b = 1, next;
    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}
int main() {
    int n;
    cout << "Enter position: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
