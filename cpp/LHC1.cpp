    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        int No_trip;
        cout << "Enter Number of Trips: ";
        cin >> No_trip;

        while (No_trip < 1 || No_trip > 5) {
            cout << "Invalid. Enter Number of Trips: ";
            cin >> No_trip;
        }

        vector<double> Efficiency;
        for (int i = 0; i < No_trip; i++) {
            double Distance, galoon_fuel;

            do {
                cout << "Enter Distance Travelled: ";
                cin >> Distance;
            } while (Distance < 0.0 || Distance > 1000.0);

            do {
                cout << "Enter Fuel Used: ";
                cin >> galoon_fuel;
            } while (galoon_fuel <= 0.0 || galoon_fuel > 100.0);

            Efficiency.push_back(Distance / galoon_fuel);
        }

        for (int i = 0; i < No_trip; i++) {
            cout << "Efficiency Trip " << (i + 1) << ": " << Efficiency[i] << endl;
        }
        double average;
        int sum =0;
        for(int i=0;i<Efficiency.size();i++){
            sum+=Efficiency[i];
        }
        average = sum/Efficiency.size();
        cout << average;
        return 0;
    }
