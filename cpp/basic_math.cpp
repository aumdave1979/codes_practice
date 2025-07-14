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

void reverse_num(int a){
    int sign;
    if(a<0){
        sign= -1;
    }
    else{
        sign =1;
    }
    a = abs(a);
    int rev_num=0;
    int ls_dgt;
    while(a>0){
       ls_dgt = a%10;
       a=a/10;
       rev_num = (rev_num*10)+ls_dgt;
    }
    cout << rev_num*sign;
    // int reversed = 0;
    // int sign = (num < 0) ? -1 : 1;
    // num = abs(num);
    // while (num > 0) {
    //     int digit = num % 10;
    //     reversed = reversed * 10 + digit;
    //     num /= 10;
    // }
    // cout << reversed * sign;
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

int HCF(int a,int b){
     if(a%b==0){
        return b;
     }
     else return gcd(b,a%b);
}

int LCM_HCF(int a,int b){
    int lcm = (a*b)/HCF(a,b);
    cout << "LCM:" << lcm << endl;
    cout << "HCF:" << HCF(a,b);
    return 0;
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
    cout << LCM_HCF(20,24);
}