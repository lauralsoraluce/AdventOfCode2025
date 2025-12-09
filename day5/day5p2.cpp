#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>
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

    sort(ranges.begin(), ranges.end(), [](const Rango& a, const Rango& b) {
            return a.start < b.start;
        });

    long long prev = -1;

    for (int i=0; i<ranges.size(); i++){
        if (ranges[i].start > prev){
            count += (ranges[i].end - ranges[i].start + 1);
            prev = ranges[i].end;
        }
        else {
            if (ranges[i].end > prev) {
                count += (ranges[i].end - prev);
                prev = ranges[i].end;
            }
        }
    }

    cout << count << endl; 

    return 0;
}