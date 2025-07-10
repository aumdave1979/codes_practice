#include<bits/stdc++.h>
using namespace std;

int count_digit(int a){
    int last_digit;
    int count =0;
    while(a>0){
        a=a/10;
        count++;
    } 
    return count;
}

int reverse_num(int a){
    int rev_num=0;
    int ls_dgt;
    while(a>0){
       ls_dgt = a%10;
       a=a/10;
       rev_num = (rev_num*10)+ls_dgt;
    }
    return rev_num;
}

void pallindrome(int a){
        int ls_digit;
        int revered_digit =0;
        int original = a;
        while(a>0){
            ls_digit= a%10;
            a=a/10;
            revered_digit = (revered_digit*10)+ls_digit;
        }
        if(original == revered_digit){
            cout << "is pallindrome";
        }
        else{
        cout << "not pallindrome";
        }
}

void armstrong(int a){
      int original = a;
      int k;
      cout <<"Enter the digits to check";
      cin >> k;
        int sum = 0;
        int ls_digit;
        while(a>0){
            ls_digit = a%10;
            a=a/10;
            sum += pow(ls_digit,k);
        }
    if(original == sum){
        cout << "it is armstrong number";
    }
    else{
        cout <<"it is not armstrong number";
    }
}

void check_division(int a){
    int count;
    for(int i=1;i<=a;i++){
        if(a%i == 0){
            count++;
        }
    }
    cout << count/2;

}

 int main(){
   check_division(9474);
}