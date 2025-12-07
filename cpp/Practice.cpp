#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int> arr = {1,8,6,2,5,4,8,3,7};
   int left =0;
   int right = arr.size()-1;
   while(left < right){
      int area = 0;
      int temp_area = 0;
      int temp = right -left;
      int mini = min(arr[left],arr[right]);
      temp_area = temp*mini;
      area = max(area,temp_area);
      
      if(arr[left]<arr[right]){
         left++;
      }
      else{
         right--;
      }
   }
}