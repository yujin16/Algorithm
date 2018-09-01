/* 4411번 덕환이의 카드뽑기 */

#include <iostream>
using namespace std;

int Testcase;
long long inputN, inputK;

int main() {
    cin >> Testcase;
    for (int t = 1; t <= Testcase; t++) {
        cin >> inputN >> inputK;

        long long answer = 1;
        if(inputN == 1)
            answer = 1;
        else if(inputK==0)
            answer = inputN;
        else {
            for (int n = 2; n <= inputN; n++) {
                answer = (answer + inputK + 1) % n;
                if (answer == 0) answer = n;
            }
        }

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}