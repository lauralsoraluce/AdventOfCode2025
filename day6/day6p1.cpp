#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    vector<vector<long long>> problems;
    vector<long long> numbers;
    string line, nextLine;
    vector<long long> results;
    long long total=0;
    
    getline(cin, line);

    while (getline(cin, nextLine)) {
        stringstream ss(line);
        long long num;
        while (ss >> num) {
            numbers.push_back(num);
        }
        problems.push_back(numbers);

        line = nextLine;
        numbers.clear();
    }

    vector<char> ops;
    stringstream ss2(line);
    while (ss2 >> line) {
        ops.push_back(line[0]);
    }

    int num_cols = problems[0].size();

    for (int i=0; i<num_cols; i++) {
        if (ops[i]=='+'){
            results.push_back(0);
        } else if (ops[i]=='*') {
            results.push_back(1);
        }
    }

    for (int i=0; i<num_cols; i++) {
        if (ops[i]=='+'){
            for (int j=0; j<problems.size(); j++) {
                results[i] += problems[j][i];
            }
        }
        else if (ops[i]=='*') {
            for (int j=0; j<problems.size(); j++) {
                results[i] *= problems[j][i];
            }
        }
        total += results[i];
    }
    
    cout << total << endl;
    return 0;
}