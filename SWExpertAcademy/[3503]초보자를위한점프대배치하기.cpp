/* 3503번 초보자를 위한 점프대 배치하기
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWGsV8IaAXsDFAVW&categoryId=AWGsV8IaAXsDFAVW&categoryType=CODE
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int inputN;

int main() {
    int Testcase;
    cin >> Testcase;

    for (int t = 1; t <= Testcase; t++) {
        cin >> inputN;

        vector<int> jump(inputN);
        for (int i = 0; i < inputN; i++)
            cin >> jump[i];
        sort(jump.begin(), jump.end());

        vector<int> place(inputN + 1);
        place[0] = place[inputN] = jump[0];
        int start = 1, end = inputN - 1, index = 1;
        while(index < inputN) {
            if(index < inputN)
                place[start++] = jump[index++];
            if(index < inputN)
                place[end--] = jump[index++];
        }

        int answer = 0;
        int prev = place[0];
        for (int i = 1; i <= inputN; i++) {
            int sub = abs(prev - place[i]);
            answer = max(answer, sub);
            prev = place[i];
        }

        cout << "#" << t << " " << answer << endl;
    }

    return 0;
}