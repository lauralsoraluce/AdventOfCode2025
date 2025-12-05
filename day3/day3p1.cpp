#include <iostream>
#include <string>
#include <cmath>
#include <set>
using namespace std;

int main() {
    string line;
    char actual;
    char last;
    long long count = 0;


    while (cin >> line) {
        if (line.length() >= 2) {
            last = line[0];
            actual = line[1];

            for (int i=1; i< line.length(); i++) {
                // If we find a greater number & we are not at the end of the string
                if (line[i]> last && i< line.length()-1) {
                    last = line[i];
                    actual = line[i+1];
                }
                else if (line[i]> actual) {
                    actual = line[i];
                }
            }

            count += ((last-'0')*10 + (actual-'0'));
        }
    }

    cout << count << endl;

    return 0;
}