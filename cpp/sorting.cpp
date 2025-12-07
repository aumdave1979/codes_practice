#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> arrr){  
    for(int i=0;i<arrr.size();i++){
        int min = i;
        for(int j=i;j<arrr.size();j++){
            if(arrr[j]<arrr[min]){
                min =j;
            }
        swap(arrr[min],arrr[i]);
        }
    }
    for(auto it:arrr){
        cout << it << endl;
    }
}

void bubble_sort(vector<int> arrr){
    for(int i=arrr.size()-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(arrr[j]>arrr[j+1]){
                swap(arrr[j+1],arrr[j]);
            }
        }
    }
    for(auto it : arrr){
        cout << it << endl;
    }

}

    void insertion_sort(vector<int> arrr){
        for(int i=0;i<arrr.size();i++){
            int j=i;
            while(j>0 && arrr[j-1]>arrr[j]){
                swap(arrr[j],arrr[j-1]);
                j--;
            }
        }
        for(auto it: arrr){
            cout << it << endl;
        }
    } 

void quick_sort(vector<int> arrr){

}

void merge(vector<int> arrr){

 }

void merge_sort(vector<int> arrr){
    
}

void bucket_sort(vector<int> arrr){
    
}

int main(){
    vector<int> arr = {13,46,24,52,20,9};
    insertion_sort(arr);
}