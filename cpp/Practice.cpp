#include <bits/stdc++.h>
using namespace std;

void partA_topArm(int n) {
    for (int i=1; i<=n; ++i) {

        // Print space
        for (int j=1;j<=n-i;++j) {
            cout << " ";
        }
        // for star
        for (int k = 1; k <= 2 * i - 1; ++k) {
            if (k % 2 == 0) {
                cout << " ";  
            } else {
                cout << "*";
            }
        }

        cout << endl;
    }
}
int main(){
    partA_topArm(5);
}
