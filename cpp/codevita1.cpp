#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> Can_change = {
    {0,{8}},
    {1,{7}},
    {2,{3}},
    {3,{2,9}},
    {4,{9}},
    {5,{6,9}},
    {6,{5,8}},
    {7,{1}},
    {8,{0,6,9}},
    {9,{3,4,5,8}}
};

bool isValid(int hh, int mm) {
    return hh>=1 && hh<=12 && mm>=0 && mm<=59;
}
int hourDistance(int h1, int h2) {
    int diff = abs(h1 - h2);
    return min(diff, 12 - diff) * 60;
}

int minuteDistance(int m1, int m2) {
    int diff = abs(m1 - m2);
    return min(diff, 60 - diff);
}

int main() {
    string time;
    int x, y;
    cin >> time >> x >> y;

    int h1 = time[0] - '0';
    int h2 = time[1] - '0';
    int m1 = time[3] - '0';
    int m2 = time[4] - '0';
    vector<int> digits = {h1, h2, m1, m2};
    string bestTime = "";
    int minCost = INT_MAX;
    for (int pos = 0; pos < 4; pos++) {
        int original = digits[pos];
        for (int d : Can_change[original]) {
            vector<int> temp = digits;
            temp[pos] = d;
            int hh =temp[0]*10+temp[1];
            int mm =temp[2]*10+temp[3];

            if (!isValid(hh,mm)){
                continue;
            }
        
            int initHH = h1*10+h2;
            int initMM = m1*10+m2;
            int cost = hourDistance(initHH,hh)* x + minuteDistance(initMM,mm) *y;
            char buf[6];
            sprintf(buf, "%02d:%02d", hh, mm);
            string newTime = buf;
            if (cost<minCost || (cost==minCost && newTime<bestTime)) {
                minCost=cost;
                bestTime=newTime;
            }
        }
    }
    if(bestTime.empty()){
        cout << "no closest valid time possible" << endl;
    } 
    else{
        cout << bestTime << endl;
    }
    return 0;
}
