#include <bits/stdc++.h>
using namespace std;

int ledMap[10] = {
    0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011,
    0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011
}

int main() {
    string t;
    int hourCost, minCost;
    cin >> t >> hourCost >> minCost;

    int digits[4] = {t[0]-'0',t[1]-'0',t[3]-'0',t[4]-'0'};
    int hour = digits[0]*10 + digits[1];
    int mins = digits[2]*10 + digits[3];
    if (hour==0) hour = 12;

    string bestTime;
    long long minTotalCost =LLONG_MAX;
    for (int i =0;i<4;i++) {
        for (int b=0;b<7;b++) {
            int modified = ledMap[digits[i]] ^ (1 << b);
            int newDigit = -1;
            for (int d=0;d<10;d++) {
                if (ledMap[d] == modified) {
                    newDigit = d;
                    break;
                }
            }
            if (newDigit == -1) continue;
            int newDigits[4];
            memcpy(newDigits,digits,sizeof(digits));
            newDigits[i] = newDigit;
            int newHour = newDigits[0]*10+newDigits[1];
            int newMin=newDigits[2]*10+newDigits[3];

            if (newHour<1 || newHour>12 || newMin<0 || newMin>59) continue;
            int hourDiff = abs(newHour - hour) %12;
            int hourMove = min(hourDiff,12 - hourDiff) *60;
            int minDiff = abs(newMin - mins) % 60;
            int minMove = min(minDiff,60-minDiff);
            long long totalCost = (long long)hourMove*hourCost+(long long)minMove*minCost;
            if (totalCost < minTotalCost) {
                minTotalCost = totalCost;
                char buf[6];
                sprintf(buf,"%02d:%02d",newHour,newMin);
                bestTime=buf;
            }
        }
    }
    if (bestTime.empty())
        cout << "no closest valid time possible\n";
    else
        cout << bestTime << "\n";
}
