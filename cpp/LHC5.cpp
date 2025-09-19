#include<bits/stdc++.h>
using namespace std;

int om(char op) {
    if (op == '+' || op == '-') 
        return 1;
    if (op == '*' || op == '/') 
        return 2;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {
    string line;
    cout<<"enter your expressoiopm";
    getline(cin, line);

    vector<string> tokens;

    for (size_t i = 0; i < line.size();) {
        if (isOperator(line[i])) {
            tokens.push_back(string(1, line[i]));
            i++;
        } else {
            string num;
            while (i < line.size() && !isspace(line[i]) && !isOperator(line[i])) {
                num += line[i];
                i++;
            }
            tokens.push_back(num);
        }
    }
    stack<string> st;
    vector<string> out;

    for (size_t i = 0; i < tokens.size(); i++) {
        string t = tokens[i];
        if (t.size() == 1 && isOperator(t[0])) {
            char op = t[0];
            while (!st.empty() && om(st.top()[0]) >= om(op)) {
                out.push_back(st.top());
                st.pop();
            }
            st.push(t);
        } else {
            out.push_back(t);
        }
    }
    while (!st.empty()) {
        out.push_back(st.top());
        st.pop();
    }
    for (size_t i = 0; i < out.size(); i++) {
        if (i > 0) cout << " ";
        cout << out[i];
    }

    cout << endl;
    return 0;
}
