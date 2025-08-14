#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> s = {7,1,5,3,6,4};
    sort(s.begin(),s.end(),greater());
    s.erase(unique(s.begin(),s.end()),s.end());
    cout << s[2]<<endl;
    cout << s.size();
}
p