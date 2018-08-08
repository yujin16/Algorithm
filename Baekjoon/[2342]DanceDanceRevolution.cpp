/* 2342 Dance Dance Revolution(Dynamic Programming)
 * https://www.acmicpc.net/problem/2342
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

int answer = INT_MAX;
int dp[100001][5][5] = {0, };

int move(int cur, int next) {
    int power = 0;
    if(cur == next)
        power = 1;
    else if (cur == 0)
        power = 2;
    else if(abs(cur - next) == 1 || abs(cur - next) == 3)
        power = 3;
    else if(abs(cur - next) == 2)
        power = 4;

    return power;
}

int main() {
    vector<int> input;
    while(1) {
        int in;
        cin >> in;

        if(in == 0)break;
        input.push_back(in);
    }

    dp[1][input[0]][0] = 2;
    dp[1][0][input[0]] = 2;

    for (int i = 1; i < input.size(); i++) {
        for (int left = 0; left < 5; left++) {
            for (int right = 0; right < 5; right++) {
                int ddr = input[i];
                if(dp[i][left][right] == 0) continue;

                int power = dp[i][left][right];

                if(ddr != right) {
                    if (dp[i + 1][ddr][right] == 0)
                        dp[i + 1][ddr][right] = power + move(left, ddr);
                    else
                        dp[i + 1][ddr][right] = min(dp[i + 1][ddr][right], power + move(left, ddr));
                }
                
                if(ddr != left) {
                    if(dp[i + 1][left][ddr] == 0)
                        dp[i + 1][left][ddr] = power + move(right, ddr);
                    else
                        dp[i + 1][left][ddr] = min(dp[i + 1][left][ddr], power + move(right, ddr));
                }
            }
        }        
    }

    for (int left = 0; left < 5; left++)
        for (int right = 0; right < 5; right++)
            if(dp[input.size()][left][right] != 0)
                answer = min(answer, dp[input.size()][left][right]);

    cout << answer << endl;
    return 0;
}