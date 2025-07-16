#include<bits/stdc++.h>
using namespace std;
void stack_overflow(){
    static int count =1;
    cout << count<<'A' << endl;
    count++;
    stack_overflow();
}
void name(){
    static int count =0;
    if(count>4){
        return;
    }
    cout << "Aum" << endl;;
    count++;
    name();
}

void one_N(int n){
    static int count =1;
    if(count >n){
        return;
    }
    cout << count << endl;
    count++;
    one_N(n);
}

void n_one(int n){
    static int copy =n;
    if(copy<1){
        return;
    }
    cout << copy << endl;
    copy--;
    n_one(n);
}

void reverse_array(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    swap(arr[l], arr[r]);
    reverse_array(arr, l + 1, r - 1);
}

int main(){
    int arr[] = {1,3,2,5,4};
    reverse_array(arr,0,4);

    for(int i=0;i<5;i++){
        cout << arr[i] << endl;
    }
}