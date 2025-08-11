#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> s = {7,1,5,3,6,4};
    int min = *min_element(s.begin(),s.end());
    int min_index=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==min){
            min_index = i;
        }
    }
    int max=*max_element(s.begin()+min_index,s.end());
    cout << max-min;
}
