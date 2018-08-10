/* 1563 개근상(Dynamic Programming)
 * https://www.acmicpc.net/problem/1563
 */

#include <iostream>
using namespace std;

int inputN;
int dp[1001][2][3] = { 0, };

int dfs(int day, int late, int absence) {
    if(late == 2 || absence == 3)
        return 0;

    if(day == inputN)
        return 1;

    if(dp[day][late][absence] == 0)
        dp[day][late][absence] = (dfs(day + 1, late, 0) + dfs(day + 1, late + 1, 0) + dfs(day + 1, late, absence + 1)) % 1000000;

    return dp[day][late][absence];
}

int main() {
    cin >> inputN;
    cout << dfs(0, 0, 0) << endl;
    return 0;
}