#include<bits/stdc++.h>
using namespace std;

void pattern1(){
     for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << "* ";
        }
    cout << endl;
    }
}

void pattern2(){
    for(int i=0;i<4;i++){
        for(int j=0;j<=i;j++){
            cout<< "* " ;
        }
    cout<<endl;
    }
}

void pattern3(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout << j << " ";
        }
    cout << endl;
    }
}

void pattern4(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout << i << " ";
        }
    cout<<endl;
    }
}

void pattern5(){
    for(int i=1;i<=5;i++){
        for(int j=5;j>=i;j--){
            cout << "* ";
        }
    cout <<endl;
    }
}

void pattern6(){
    for(int i=1;i<=5;i++){
        int val=1;
        for(int j=5;j>=i;j--){
            cout << val << " ";
            val++;
        }
    cout <<endl;
    }
}

void pattern7(){    
    for(int i = 1; i <= 5; i++) {
    // space
        for(int j = 0; j < 5 - i; j++) {
        cout << " ";
        }
    // stars
         for(int j = 0; j <     2 * i - 1; j++) {
        cout << '*';
        }
    //space
        for(int j = 0; j < 5 - i; j++) {
        cout << " ";
        }
    cout << endl;
    }
} 

void pattern8(int line){
    for(int i=0;i<line;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=0;j<2*line -(2*i+1);j++){
            cout <<"*";
        }
        for(int j=0;j<i;j++){
            cout <<" ";
        }
    cout << endl;
    }
}

void pattern9(int line){
    for(int i = 1; i <= line; i++) {
    // space
        for(int j = 0; j < line - i; j++) {
        cout << " ";
        }
    // stars
         for(int j = 0; j < 2 * i - 1; j++) {
        cout << '*';
        }
    //space
        for(int j = 0; j < line - i; j++) {
        cout << " ";
        }
    cout << endl;
    }
    //for lower part

    for(int i=0;i<line;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=0;j<2*line -(2*i+1);j++){
            cout <<"*";
        }
        for(int j=0;j<i;j++){
            cout <<" ";
        }
    cout << endl;
    }

}

void pattern10(){
    for(int i=1;i<=5;i++){
    for(int j=1;j<=i;j++){
      cout << "* ";
    }
    cout <<endl;
  }
  //for lower pattern
  for(int i=1;i<=5-1;i++){
    for(int j=5-1;j>=i;j--){
      cout<<"* ";
    }
  cout <<endl;
  }
}

void pattern11(int n){
    int start  =1;
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            start =1;
        }
        else{
            start =0;
        }
        for(int j=1;j<=i;j++){
            cout << start;
            start = 1 - start ;
        }
    cout << endl;
    }
}

void pattern12(int n){
    int space = 2*(n-1);
    for(int i=1;i<=n;i++){
        //for numbers
        for(int j =1;j<=i;j++){
            cout << j;
        }
        for(int j=1;j<=space;j++){
            cout << " ";
        }
        for(int j=i;j=i;j++){
            cout << j;
        }
    cout << endl;
    space -=2;
    }
}

void pattern13(int n){
    int k=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << k << " ";
            k++;
        }
    cout << endl;
    }
}

void pattern14(int n){
    for(int i=0;i<n;i++){
        for(char ch ='A';ch<='A'+i;ch++){
            cout << ch << " ";
        }
    cout << endl;
    }
}

void pattern15(int n){
    for(int i =1;i<=n;i++){
        char val ='A';
        for(int j=n;j>=i;j--){
            cout << val << " ";
            val++;
        }
    cout <<  endl;
    }
}

void pattern16(int n){
    for(int i=0;i<n;i++){
        char val ='A'+i;
        for(int j=0;j<=i;j++){
            cout << val << " ";
        }
    cout << endl;
    }
}

void pattern17(int n){
    
}

int main(){
   pattern16(5);
}