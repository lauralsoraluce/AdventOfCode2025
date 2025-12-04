#include <iostream>
using namespace std;

int main() {
    char direction;
    int steps;

    int curr_pos = 50;
    int count = 0;

    while (cin >> direction >> steps) {
        
        for (int i = 0; i < steps; i++) {
            if (direction == 'L') {
                curr_pos--;
                if (curr_pos == -1) curr_pos = 99;
            } else if (direction == 'R') {
                curr_pos++;
                if (curr_pos == 100) curr_pos = 0;
            }
            if (curr_pos == 0){
                count++;
            }
        }

    }

    cout << "The password is: " << count << endl;
    return 0;

}