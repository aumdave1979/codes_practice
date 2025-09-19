#include <bits/stdc++.h>
using namespace std;

int main() {
    int choose;
    cin >> choose;

    while (choose) {
        cout << "Press 1 to enter: ";

        int employee_id;
        do {
            cout << "Enter employee id: ";
            cin >> employee_id;
        } while (employee_id < 1 || employee_id > 1000);

        double basic_pay;
        do {
            cout << "Enter the basic pay: ";
            cin >> basic_pay;
        } while (basic_pay < 1000.0);

        double bonus;
        if (basic_pay > 50000) {
            bonus = 0.1 * basic_pay;
        } else {
            bonus = 0.05 * basic_pay;
        }

        double allowance_pct;
        do {
            cout << "Enter the allowance_pct: ";
            cin >> allowance_pct;
        } while (allowance_pct < 0 || allowance_pct > 50.0);

        double deduction;
        do {
            cout << "Enter deduction: ";
            cin >> deduction;
        } while (deduction < 0.0 || deduction > 5000.0);

        double gross = basic_pay + (basic_pay * allowance_pct / 100.0);
        double net = gross - deduction + bonus;

        cout << fixed << setprecision(2);
        cout << "Net Salary: " << net << endl;
    }
    
    return 0;
}
