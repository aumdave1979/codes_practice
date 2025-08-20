#include<bits/stdc++.h>
using namespace std;


int linear_search(vector<int> arr,int target){
    int j=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==target){
            j=i;
            break;
        }
        else{
            j=0;
        }
    }
    return j;
}

int binary_search(vector<int> arr,int target){
    int low=0;
    int high=arr.size()-1;
   
}

int main(){
    vector<int> arr = {2,4,7,10,13,18,21};
   cout << linear_search(arr,13);
     
}