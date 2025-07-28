#include <bits/stdc++.h>
using namespace std;

int main()
{
     int a =5;
     vector<int> decimal_rems;
     int decimal_rem;
     while ( a> 0)
     {
          decimal_rem = a % 2;
          decimal_rems.push_back(decimal_rem);
          a = a / 2;
     }
     string binary;
     for (int i = decimal_rems.size() - 1; i >= 0; i--)
     {
          binary += to_string(decimal_rems[i]);
     }
     cout << binary;
}