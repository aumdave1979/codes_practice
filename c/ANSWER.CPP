#include<bits/stdc++.h>
using namespace std;

// ============================================================================
// 1. TRAIN BOGIE MANAGEMENT (Stack - LIFO)
// ============================================================================
void trainBogieManagement() {
    int n;
    cin >> n;
    cin.ignore();
    
    stack<string> bogies;
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "ATTACH") {
            string bogie;
            cin >> bogie;
            bogies.push(bogie);
        }
        else if (operation == "DETACH") {
            if (!bogies.empty()) {
                bogies.pop();
            }
        }
        else if (operation == "SHOW") {
            if (bogies.empty()) {
                cout << "EMPTY" << endl;
            } else {
                vector<string> temp;
                stack<string> tempStack = bogies;
                while (!tempStack.empty()) {
                    temp.push_back(tempStack.top());
                    tempStack.pop();
                }
                reverse(temp.begin(), temp.end());
                for (int j = 0; j < temp.size(); j++) {
                    cout << temp[j];
                    if (j < temp.size() - 1) cout << " ";
                }
                cout << endl;
            }
        }
    }
}

// ============================================================================
// 2. COUNTING VALLEYS
// ============================================================================
int countingValleys(int steps, string path) {
    int level = 0;
    int valleys = 0;
    bool inValley = false;
    
    for (char step : path) {
        if (step == 'U') {
            level++;
            if (level == 0 && inValley) {
                valleys++;
                inValley = false;
            }
        } else {
            level--;
            if (level < 0) {
                inValley = true;
            }
        }
    }
    
    return valleys;
}

// ============================================================================
// 3. HOSPITAL PATIENT REGISTRATION (Queue - FIFO)
// ============================================================================
void hospitalPatientRegistration() {
    int n;
    cin >> n;
    cin.ignore();
    
    queue<string> patients;
    
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "ARRIVE") {
            string patientId;
            cin >> patientId;
            patients.push(patientId);
        }
        else if (operation == "SERVE") {
            if (!patients.empty()) {
                patients.pop();
            }
        }
        else if (operation == "NEXT") {
            if (patients.empty()) {
                cout << "NO PATIENT" << endl;
            } else {
                cout << patients.front() << endl;
            }
        }
    }
}

// ============================================================================
// 4. CUT THE STICKS
// ============================================================================
vector<int> cutSticks(vector<int> arr) {
    vector<int> result;
    
    while (!arr.empty()) {
        result.push_back(arr.size());
        int minVal = *min_element(arr.begin(), arr.end());
        
        vector<int> newArr;
        for (int x : arr) {
            if (x - minVal > 0) {
                newArr.push_back(x - minVal);
            }
        }
        arr = newArr;
    }
    
    return result;
}

// ============================================================================
// 5. DAY OF THE PROGRAMMER
// ============================================================================
string dayOfProgrammer(int year) {
    bool isLeap;
    
    if (year == 1918) {
        return "26.09.1918";
    }
    else if (year < 1918) {
        isLeap = (year % 4 == 0);
    }
    else {
        isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }
    
    int day = isLeap ? 12 : 13;
    return to_string(day) + ".09." + to_string(year);
}

// ============================================================================
// 6. DESIGNER PDF VIEWER
// ============================================================================
int designerPdfViewer(vector<int> heights, string word) {
    int maxHeight = 0;
    for (char c : word) {
        maxHeight = max(maxHeight, heights[c - 'a']);
    }
    return maxHeight * word.length();
}

// ============================================================================
// 7. DIVISIBLE SUM PAIRS
// ============================================================================
int divisibleSumPairs(int n, int k, vector<int> ar) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ar[i] + ar[j]) % k == 0) {
                count++;
            }
        }
    }
    return count;
}

// ============================================================================
// 8. DRAWING BOOK
// ============================================================================
int drawingBook(int n, int p) {
    int fromFront = p / 2;
    int fromBack = (n / 2) - (p / 2);
    return min(fromFront, fromBack);
}

// ============================================================================
// 9. ELECTRONICS SHOP
// ============================================================================
int electronicsShop(int budget, vector<int> keyboards, vector<int> drives) {
    int maxSpent = -1;
    
    for (int k : keyboards) {
        for (int d : drives) {
            int total = k + d;
            if (total <= budget && total > maxSpent) {
                maxSpent = total;
            }
        }
    }
    
    return maxSpent;
}

// ============================================================================
// 10. EQUALIZE THE ARRAY
// ============================================================================
int equalizeArray(vector<int> arr) {
    map<int, int> counts;
    for (int x : arr) {
        counts[x]++;
    }
    
    int maxFreq = 0;
    for (auto& p : counts) {
        maxFreq = max(maxFreq, p.second);
    }
    
    return arr.size() - maxFreq;
}

// ============================================================================
// 11. FAIR RATIONS
// ============================================================================
string fairRations(vector<int> arr) {
    int loaves = 0;
    
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] % 2 == 1) {
            arr[i]++;
            arr[i + 1]++;
            loaves += 2;
        }
    }
    
    if (arr[arr.size() - 1] % 2 == 1) {
        return "NO";
    }
    
    return to_string(loaves);
}

// ============================================================================
// 12. FIND DIGITS
// ============================================================================
int findDigits(int n) {
    int count = 0;
    int temp = n;
    
    while (temp > 0) {
        int digit = temp % 10;
        if (digit != 0 && n % digit == 0) {
            count++;
        }
        temp /= 10;
    }
    
    return count;
}

// ============================================================================
// 13. FLATLAND SPACE STATIONS
// ============================================================================
int flatlandSpaceStations(int n, vector<int> c) {
    sort(c.begin(), c.end());
    int maxDist = 0;
    
    maxDist = max(maxDist, c[0]);
    
    for (int i = 1; i < c.size(); i++) {
        maxDist = max(maxDist, (c[i] - c[i-1]) / 2);
    }
    
    maxDist = max(maxDist, n - 1 - c[c.size() - 1]);
    
    return maxDist;
}

// ============================================================================
// 14. GRADING STUDENTS
// ============================================================================
vector<int> gradingStudents(vector<int> grades) {
    vector<int> result;
    
    for (int grade : grades) {
        if (grade < 38) {
            result.push_back(grade);
        } else {
            int nextMultiple = ((grade / 5) + 1) * 5;
            if (nextMultiple - grade < 3) {
                result.push_back(nextMultiple);
            } else {
                result.push_back(grade);
            }
        }
    }
    
    return result;
}

// ============================================================================
// 15. HALLOWEEN SALE
// ============================================================================
int halloweenSale(int p, int d, int m, int s) {
    int games = 0;
    int currentPrice = p;
    
    while (s >= currentPrice) {
        s -= currentPrice;
        games++;
        currentPrice = max(currentPrice - d, m);
    }
    
    return games;
}

// ============================================================================
// 16. HAPPY LADYBUGS
// ============================================================================
string happyLadybugs(string b) {
    map<char, int> counts;
    bool hasEmpty = false;
    
    for (char c : b) {
        counts[c]++;
        if (c == '_') hasEmpty = true;
    }
    
    for (auto& p : counts) {
        if (p.first != '_' && p.second == 1) {
            return "NO";
        }
    }
    
    bool isHappy = true;
    for (int i = 0; i < b.length(); i++) {
        if (b[i] != '_') {
            bool leftMatch = (i > 0 && b[i-1] == b[i]);
            bool rightMatch = (i < b.length() - 1 && b[i+1] == b[i]);
            if (!leftMatch && !rightMatch) {
                isHappy = false;
                break;
            }
        }
    }
    
    if (isHappy) return "YES";
    if (hasEmpty) return "YES";
    
    return "NO";
}

// ============================================================================
// 17. JUMPING ON THE CLOUDS
// ============================================================================
int jumpingOnClouds(vector<int> c) {
    int jumps = 0;
    int i = 0;
    
    while (i < c.size() - 1) {
        if (i + 2 < c.size() && c[i + 2] == 0) {
            i += 2;
        } else {
            i += 1;
        }
        jumps++;
    }
    
    return jumps;
}

// ============================================================================
// 18. JUMPING ON THE CLOUDS: REVISITED
// ============================================================================
int jumpingCloudsRevisited(vector<int> c, int k) {
    int n = c.size();
    int energy = 100;
    int i = 0;
    
    do {
        i = (i + k) % n;
        energy -= 1;
        if (c[i] == 1) {
            energy -= 2;
        }
    } while (i != 0);
    
    return energy;
}

// ============================================================================
// 19. KANGAROO
// ============================================================================
string kangaroo(int x1, int v1, int x2, int v2) {
    if (v1 == v2) {
        return (x1 == x2) ? "YES" : "NO";
    }
    
    if ((x2 - x1) % (v1 - v2) == 0 && (x2 - x1) / (v1 - v2) >= 0) {
        return "YES";
    }
    
    return "NO";
}

// ============================================================================
// 20. LIBRARY FINE
// ============================================================================
int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    if (y1 < y2) return 0;
    if (y1 > y2) return 10000;
    if (m1 < m2) return 0;
    if (m1 > m2) return 500 * (m1 - m2);
    if (d1 <= d2) return 0;
    return 15 * (d1 - d2);
}

// ============================================================================
// 21. LISA'S WORKBOOK
// ============================================================================
int lisaWorkbook(int n, int k, vector<int> arr) {
    int special = 0;
    int page = 1;
    
    for (int chapter = 0; chapter < n; chapter++) {
        int problems = arr[chapter];
        for (int problem = 1; problem <= problems; problem++) {
            if (problem == page) {
                special++;
            }
            if (problem % k == 0 || problem == problems) {
                page++;
            }
        }
    }
    
    return special;
}

// ============================================================================
// 22. FORMING A MAGIC SQUARE
// ============================================================================
int formingMagicSquare(vector<vector<int>> s) {
    vector<vector<vector<int>>> magicSquares = {
        {{8,1,6},{3,5,7},{4,9,2}},
        {{6,1,8},{7,5,3},{2,9,4}},
        {{4,9,2},{3,5,7},{8,1,6}},
        {{2,9,4},{7,5,3},{6,1,8}},
        {{8,3,4},{1,5,9},{6,7,2}},
        {{4,3,8},{9,5,1},{2,7,6}},
        {{6,7,2},{1,5,9},{8,3,4}},
        {{2,7,6},{9,5,1},{4,3,8}}
    };
    
    int minCost = INT_MAX;
    
    for (auto& magic : magicSquares) {
        int cost = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cost += abs(s[i][j] - magic[i][j]);
            }
        }
        minCost = min(minCost, cost);
    }
    
    return minCost;
}

// ============================================================================
// 23. MANASA AND STONES
// ============================================================================
vector<int> manasaStones(int n, int a, int b) {
    set<int> possibleSet;
    
    for (int i = 0; i < n; i++) {
        int value = i * a + (n - 1 - i) * b;
        possibleSet.insert(value);
    }
    
    return vector<int>(possibleSet.begin(), possibleSet.end());
}

// ============================================================================
// MAIN FUNCTION WITH TEST CASES
// ============================================================================
int main() {
    cout << "============================================================" << endl;
    cout << "       COMPLETE SOLUTIONS FOR ALL PROBLEMS (C++)" << endl;
    cout << "============================================================" << endl;
    
    // Test 1: Counting Valleys
    cout << "\n1. Counting Valleys:" << endl;
    cout << "   Result: " << countingValleys(8, "UDDDUDUU") << " valleys" << endl;
    
    // Test 2: Cut the Sticks
    cout << "\n2. Cut the Sticks:" << endl;
    vector<int> sticks = {5, 4, 4, 2, 2, 8};
    vector<int> cutResult = cutSticks(sticks);
    cout << "   Result: ";
    for (int x : cutResult) cout << x << " ";
    cout << endl;
    
    // Test 3: Day of Programmer
    cout << "\n3. Day of the Programmer:" << endl;
    cout << "   2017: " << dayOfProgrammer(2017) << endl;
    cout << "   2016: " << dayOfProgrammer(2016) << endl;
    
    // Test 4: Designer PDF Viewer
    cout << "\n4. Designer PDF Viewer:" << endl;
    vector<int> heights(26, 1);
    heights[1] = 3; // b
    cout << "   Area for 'abc': " << designerPdfViewer(heights, "abc") << endl;
    
    // Test 5: Divisible Sum Pairs
    cout << "\n5. Divisible Sum Pairs:" << endl;
    vector<int> arr1 = {1, 3, 2, 6, 1, 2};
    cout << "   Result: " << divisibleSumPairs(6, 3, arr1) << " pairs" << endl;
    
    // Test 6: Drawing Book
    cout << "\n6. Drawing Book:" << endl;
    cout << "   Pages for n=6, p=2: " << drawingBook(6, 2) << endl;
    
    // Test 7: Electronics Shop
    cout << "\n7. Electronics Shop:" << endl;
    vector<int> keyboards = {3, 1};
    vector<int> drives = {5, 2, 8};
    cout << "   Max spend: $" << electronicsShop(10, keyboards, drives) << endl;
    
    // Test 8: Equalize Array
    cout << "\n8. Equalize Array:" << endl;
    vector<int> arr2 = {3, 3, 2, 1, 3};
    cout << "   Min deletions: " << equalizeArray(arr2) << endl;
    
    // Test 9: Fair Rations
    cout << "\n9. Fair Rations:" << endl;
    vector<int> arr3 = {2, 3, 4, 5, 6};
    cout << "   Loaves: " << fairRations(arr3) << endl;
    
    // Test 10: Find Digits
    cout << "\n10. Find Digits:" << endl;
    cout << "   Count for 1012: " << findDigits(1012) << endl;
    
    // Test 11: Flatland Space Stations
    cout << "\n11. Flatland Space Stations:" << endl;
    vector<int> stations = {0, 4};
    cout << "   Max distance: " << flatlandSpaceStations(5, stations) << endl;
    
    // Test 12: Grading Students
    cout << "\n12. Grading Students:" << endl;
    vector<int> grades = {73, 67, 38, 33};
    vector<int> rounded = gradingStudents(grades);
    cout << "   Rounded: ";
    for (int g : rounded) cout << g << " ";
    cout << endl;
    
    // Test 13: Halloween Sale
    cout << "\n13. Halloween Sale:" << endl;
    cout << "   Games: " << halloweenSale(20, 3, 6, 80) << endl;
    
    // Test 14: Happy Ladybugs
    cout << "\n14. Happy Ladybugs:" << endl;
    cout << "   Can be happy: " << happyLadybugs("RBY_YBR") << endl;
    
    // Test 15: Jumping on Clouds
    cout << "\n15. Jumping on Clouds:" << endl;
    vector<int> clouds1 = {0, 0, 1, 0, 0, 1, 0};
    cout << "   Min jumps: " << jumpingOnClouds(clouds1) << endl;
    
    // Test 16: Jumping Revisited
    cout << "\n16. Jumping on Clouds Revisited:" << endl;
    vector<int> clouds2 = {0, 0, 1, 0, 0, 1, 1, 0};
    cout << "   Final energy: " << jumpingCloudsRevisited(clouds2, 2) << endl;
    
    // Test 17: Kangaroo
    cout << "\n17. Kangaroo:" << endl;
    cout << "   Will meet: " << kangaroo(0, 3, 4, 2) << endl;
    
    // Test 18: Library Fine
    cout << "\n18. Library Fine:" << endl;
    cout << "   Fine: " << libraryFine(9, 6, 2015, 6, 6, 2015) << endl;
    
    // Test 19: Lisa's Workbook
    cout << "\n19. Lisa's Workbook:" << endl;
    vector<int> chapters = {4, 2, 6, 1, 10};
    cout << "   Special problems: " << lisaWorkbook(5, 3, chapters) << endl;
    
    // Test 20: Forming Magic Square
    cout << "\n20. Forming a Magic Square:" << endl;
    vector<vector<int>> square = {{4, 9, 2}, {3, 5, 7}, {8, 1, 5}};
    cout << "   Min cost: " << formingMagicSquare(square) << endl;
    
    // Test 21: Manasa Stones
    cout << "\n21. Manasa and Stones:" << endl;
    vector<int> stones = manasaStones(3, 1, 2);
    cout << "   Possible values: ";
    for (int s : stones) cout << s << " ";
    cout << endl;
    
    cout << "\n============================================================" << endl;
    cout << "                ALL SOLUTIONS COMPLETE!" << endl;
    cout << "============================================================" << endl;
    
    return 0;
}