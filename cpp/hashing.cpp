#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    // Declare array (maximum size assumed to be 1000 for safety)
    int arr[1000];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Declare hash array large enough to avoid overflow
    int hash[100001] = {0}; // assumes values in arr are <= 100000

    // Precompute frequency
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    cout << "Enter the queries:\n";
    while (q--) {
        int number;
        cin >> number;

        if (number >= 0 && number <= 100000)
            cout << hash[number] << endl;
        else
            cout << "Out of range\n";
    }

    return 0;
}
