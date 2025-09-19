#include<bits/stdc++.h>
using namespace std;

int main(){
    string text = "Krisha dave";
    int space=0;
    for(int i =0;i<text.size();i++){
        if(text[i] == ' '){
            space = i;
        }
    }
    cout << space << endl;
}