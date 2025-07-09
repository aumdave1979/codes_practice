#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
    for(int i=1;i<=n;i++){
        //for space
        for(int j=n-1;i>=1;i++){
            cout << " ";
        }
        //for star
        for(int j=0;j<=2*i-1;j++ ){
            cout << "*";
        }
        // for space
        for(int j=n-1;j>=1;j++){
            cout <<" " ;
        }
    cout <<endl;
    }
}