/* 4261번 빠른 휴대전화 키패드 */

#include <iostream>
#include <string>
using namespace std;

char num[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '7', '7', '7', '8', '8', '8', '9', '9', '9', '9'};

int main() {
    int Testcase;
    cin >> Testcase;

    for (int t = 1; t <= Testcase; t++) {
        string inputS;
        int inputN;
        cin >> inputS >> inputN;

        int answer = 0;
        for (int i = 0; i < inputN; i++) {
            string in;
            cin >> in;

            bool success = true;
            if (inputS.length() != in.length()) continue;
            for (int i = 0; i < inputS.length() && success; i++)
                if (inputS[i] != num[in[i] - 'a'])
                    success = false;
            
            if(success) answer++;
        }

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}