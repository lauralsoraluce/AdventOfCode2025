#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

struct Rango {
        long long start;
        long long end;
    };

int main() {
    vector<Rango> ranges;
    long long num1, num2;
    char trash;
    long long count = 0;
    string line;

    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        ss >> num1 >> trash >> num2;
        
        ranges.push_back({num1, num2});
    }

    while (cin >> num1) {
        for (const auto& r : ranges) {
            if (num1 >= r.start && num1 <= r.end) {
                count++;
                break;
            }
        }
    }

    cout << count << endl; 

    return 0;
}