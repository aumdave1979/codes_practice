#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<string> undo, redo;
    string input;

    while (cin >> input && input != "end") {
        if (input == "add") {
            string text;
            cin >> text;
            undo.push(text);
            while (!redo.empty()) redo.pop();
    }
        else if (input == "undo") {
            if (!undo.empty()) {
                redo.push(undo.top());
                undo.pop();
            }
        } 
        else if (input == "redo") {
            if (!redo.empty()) {
                undo.push(redo.top());
                redo.pop();
            }
        }
    }
    vector<string> result;
    while (!undo.empty()) {
        result.push_back(undo.top());
        undo.pop();
    }
    reverse(result.begin(), result.end());
    cout << "Current:";
    for (auto &word : result) cout << " " << word;
    cout << "\n";
    return 0;
}
