#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> digit = {1, 5, 6, 7, 4, 6};

    int small = digit[0];
    int big = digit[0];
    for (int i = 1; i < digit.size(); i++) {
        if (digit[i] < small) {
            small = digit[i];
        }
        if (digit[i] > big) {
            big = digit[i];
        }
    }
    cout << big << endl;
    cout << small << endl;
    return 0;
}
