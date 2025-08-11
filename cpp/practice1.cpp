#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int> s= {2,4,1};
   int min = *min_element(s.begin(),s.end()-1);
   int min_index;
    for(int i=0;i<s.size();i++){
        if(s[i] == min);
        min_index = i;
    }
    int max=*max_element(s.begin()+min_index,s.end());
    cout << min <<endl;
    cout << max<<endl;
    cout << max-min;
}