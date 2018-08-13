/* 3459 승자예측하기
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWFPoj1qANoDFAV0&categoryId=AWFPoj1qANoDFAV0&categoryType=CODE
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    int Testcase;
    cin >> Testcase;

    for (int t = 1; t <= Testcase; t++) {
        long long inputN;
        cin >> inputN;

        long long sub = 4;
        inputN -= 2;
        string answer = "";

        if(inputN == -1)
            answer = "Bob";
        else {
            while (1){
                inputN -= sub;
                if(inputN < 0) {
                    answer = "Alice";
                    break;
                }

                inputN -= sub;
                if(inputN < 0) {
                    answer = "Bob";
                    break;
                }

                sub *= 4;
            }
        }

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}