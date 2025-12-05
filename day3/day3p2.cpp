#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

int main() {
    string line;
    long long count = 0;

    while (cin >> line) {
        string actual = "";
        char last;
        int pos = 0;
        int found = -1;

        if (line.length() >= 12) {
            for (int i = 0; i < 12; i++) {
                pos = found+1;
                last = line[pos];
                found = pos;
                for (int j=pos; j<= (line.length()-(12-i)); j++){
                    if (line[j]> last) {
                        last = line[j];
                        found = j;
                    }
                }
                actual += last;
            }
            count += stoll(actual);
        }
    }

    cout << count << endl;

    return 0;
}