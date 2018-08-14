/* 4796번 의석이의우뚝선산(Dynamic Programming)
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWS2h6AKBCoDFAVT&categoryId=AWS2h6AKBCoDFAVT&categoryType=CODE&&&
 */

#include <iostream>
#include <vector>
using namespace std;

int inputN;

int main() {
    int Testcase;
    cin >> Testcase;

    for (int t = 1; t <= Testcase; t++) {
        cin >> inputN;
        
        vector<int> input(inputN);
        for (int i = 0; i < inputN;i++)
            cin >> input[i];

        vector<int> dp(inputN, 0);
        dp[0] = 0;
        for (int i = 1; i < inputN; i++) {
            if(input[i - 1] > input[i]) {
                if(dp[i-1] == 0) {
                    int index = i - 1;
                    while (index-1>=0 && input[index-1] < input[index]) {
                        dp[i]++;
                        index--;
                    }
                }
                else {
                    dp[i] = dp[i - 1];
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < inputN; i++)
            answer += dp[i];

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}