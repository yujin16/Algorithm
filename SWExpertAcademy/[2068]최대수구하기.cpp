#include <iostream>
#include <algorithm>
using namespace std;

int Testcase;

int main() {
    cin >> Testcase;
    for (int t = 1; t <= Testcase; t++) {
        int answer = -1;
        for (int i = 0; i < 10; i++) {
            int in;
            cin >> in;
            answer = max(answer, in);
        }

        cout << "#" << t << " " << answer << endl;
    }
}