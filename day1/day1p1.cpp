#include <iostream>
using namespace std;

int main() {
    char direction;
    int steps;

    int curr_pos = 50;
    int count = 0;

    while (cin >> direction >> steps) {
        if (direction == 'L') {
            curr_pos -= steps;
        } else if (direction == 'R') {
            curr_pos += steps;
        }

        if (curr_pos < 0)
            curr_pos += 100;
        curr_pos %= 100;

        if (curr_pos == 0) {
            count++;
        }
    }

    cout << "The password is: " << count << endl;
    return 0;

}