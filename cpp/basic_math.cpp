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
     else return HCF(b,a%b);
}

void LCM_HCF(int a,int b){
    int lcm = (a*b)/HCF(a,b);
    cout << "LCM:" << lcm << endl;
    cout << "HCF:" << HCF(a,b);
}

void check_division(int n){
    vector<int> factors;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i == 0){
            factors.push_back(i);
            if(n/i != i){
                factors.push_back(n/i);
            }
        }
    }
    sort(factors.begin(),factors.end());
    cout << "Factors: ";
    for(auto it : factors){
        cout <<it << " ";
    }
    

}

void prime(int n){
    if(n<1){
        cout << "Not prime";
        return;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout << "not prime";
            return;
        }
    }
    cout <<"Is prime";
}

 int main(){
 cout << HCF(20,24);
}