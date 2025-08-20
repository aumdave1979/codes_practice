#include <bits/stdc++.h>
using namespace std;

int main(){
    string s ="Aum";
    vector<char> y;
    for(int i=0;i<s.size();i++){
        y.push_back(s[i]);
    }
    for(auto it:y){
        cout << it << endl;
    }
    sort(s.begin(),s.end());
    cout << s;
}
