/* 4366번 정식이의 은행업무 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int Testcase;
    cin >> Testcase;

    for (int t = 1; t <= Testcase; t++) {
        string binary, ternary;
        cin >> binary >> ternary;

        int binary_num = 0;
        for (int i = 0; i < binary.length(); i++)
            if(binary[i] == '1')
                binary_num += pow(2, binary.length() - 1 - i);

        int answer = 0;
        for (int i = 0; i < binary.length(); i++) {
            int change_num = binary_num;
            if (binary[i] == '0')
                change_num += pow(2, binary.length() - 1 - i);
            else if (binary[i] == '1')
                change_num -= pow(2, binary.length() - 1 - i);

            answer = change_num;
            int diff = 0, index = ternary.length() - 1;
            while (change_num > 0) {
                if(ternary[index--] - '0' != change_num%3) diff++;
                if(diff >= 2) break;
                change_num /= 3;
            }
            if(diff == 1 && index == -1) break;
        }

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}