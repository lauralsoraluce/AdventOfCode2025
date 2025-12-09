#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

int main() {
    vector<string> map;
    string line;
    int count = 0;
    int total = 0;

    while (cin >> line) {
        map.push_back(line);
    }

    for (int i=0; i<map.size(); i++) {
        for (int j=0; j<map[0].size(); j++) {
            count = 0;

            if (map[i][j]=='@'){
                for (int di=-1; di<=1; di++) {
                    for (int dj=-1; dj<=1; dj++) {
                        if (di!=0 || dj!=0) {
                            int ni = i + di;
                            int nj = j + dj;
                            if (ni>=0 && ni<map.size() && nj>=0 && nj<map[0].size()) {
                                if (map[ni][nj]=='@') {
                                    count++;
                                }
                            }
                        }
                    }
                }
            if (count<4){
                total++;
            }
            }
        }
    }
    cout << total << endl;

    return 0;
}
