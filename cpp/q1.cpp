#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> nums;
        int count =0;
        int val = n;
        int sum=0;
        while(n>0){
            int ls_dig = n%10;
            count++;
            n/=10;
        }
        bool sign = true;
        if(count%2 !=0){
            sign = true;
            while(val>0){
                if(sign == true){
                    int ls_digit = val%10;
                    sum+=ls_digit;
                    val/=10;
                    sign = false;
                }
                else{
                    int ls_digit = val%10;
                    sum-=ls_digit;
                    val/=10;
                    sign = true;
                }
            }
        }
        else{
            sign = false;
            while(val>0){
                if(sign == true){
                    int ls_digit = val%10;
                    sum+=ls_digit;
                    val/=10;
                    sign = false;
                }
                else{
                    int ls_digit = val%10;
                    sum-=ls_digit;
                    val/=10;
                    sign = true;
                }
            }
        }
        return sum;
    }
};
