#include <bits/stdc++.h>
using namespace std;

class employee {
public:
    int emp_id;
    string name;
    char Gender;
private:
    double salary;

public:
    void set_salary(double s) {
        salary = s;
    }
    void update_salary(double s) {
        salary = s;
    }
    double get_salary() {
        return salary;
    }
};
int main() {
    employee db[10];

    db[0].emp_id = 101;
    db[0].name = "Aum Dave";
    db[0].Gender = 'M';
    db[0].set_salary(50000);

    db[1].emp_id = 102;
    db[1].name = "Diya Kalariya";
    db[1].Gender = 'F';
    db[1].set_salary(40000);

    db[2].emp_id = 103;
    db[2].name = "Om Dholariya";
    db[2].Gender = 'M';
    db[2].set_salary(45000);

    for(int i=0;i<3;i++){
        cout<<"ID: "<<db[i].emp_id<<" Name: "<<db[i].name<<" Gender: "<<db[i].Gender<<" Salary: " <<db[i].get_salary()<< endl;
    }
    return 0;
}
