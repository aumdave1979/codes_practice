#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> jik = {1,2,3};
    int a ;
    for(int i=jik.size()-1;i>=0;i--){
        a += pow(10,i) + jik[i];
    }
    cout << a;
}