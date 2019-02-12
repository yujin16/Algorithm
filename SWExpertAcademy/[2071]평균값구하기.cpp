#include <iostream>
using namespace std;

int Testcase;

int main() {
    cin >> Testcase;
    for (int t = 1; t <= Testcase;t++) {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            int in;
            cin >> in;
            sum += in;
        }

        int answer = (sum + 5) / 10;

        cout << "#" << t << " " << answer << endl;
    }
}