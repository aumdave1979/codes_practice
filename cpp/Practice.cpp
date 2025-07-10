#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,last_digit;
    int count =0;
    cin >> a;
    while(a>0){
        last_digit = a%10;
        a= a/10;
        count++;
    }
    cout << count;

}