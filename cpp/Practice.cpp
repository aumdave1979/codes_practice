#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> s = {2,2,1,1,3};
    int unique = 0;
    for(int i=0;i<s.size();i++){
        unique ^= s[i];
    }
    cout << unique;
    
}
