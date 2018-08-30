/* 5357번 터널 속의 기차 */

#include <iostream>
using namespace std;

int Testcase, inputN, inputH;
int train[100000];

int main() {
    cin >> Testcase;

    for (int t = 1; t <= Testcase;t++) {
        cin >> inputN >> inputH;

        for (int i = 0; i < inputN;i++)
            cin >> train[i];

        bool light;
        int answer = 0, len = 0;
        for (int i = 0; i < inputN; i++) {
            cin >> light;

            if(light)
                len = inputH - 1;
            else {
                len -= train[i];
                if(i == 0 || i==inputN-1) len = -1;
            }

            if(len<0) {
                answer++;
                len = inputH - 1;
            }
        }
        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}