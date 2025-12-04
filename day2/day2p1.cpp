#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    long long start, end, raiz;
    char discard;
    long long count = 0;

    while (cin >> start >> discard >> end) {
        
        if (to_string(start).length() % 2 != 0) {
            long long power = pow(10, to_string(start).length());
            start = power;
        }

        if (start <= end){
            int len = to_string(start).length();
            int half_len = len / 2;
            
            long long root = stoll(to_string(start).substr(0, half_len));

            long long candidate = 0;
            while (true && candidate <= end) {
                string candidate_str = to_string(root) + to_string(root);
                
                candidate = stoll(candidate_str);

                if (candidate <= end) {

                    if (candidate >= start) {
                        count += candidate;
                    }
                    root++;
                }
            }
        }
        cin >> discard;
    }

    cout << "The sum of invalid IDs is: " << count << endl;
    return 0;

}