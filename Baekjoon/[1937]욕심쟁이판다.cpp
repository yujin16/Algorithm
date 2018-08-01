/* 1937 욕심쟁이판다(Dynamic Programming)
 * https://www.acmicpc.net/problem/1937
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int inputN, answer = 0;
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1, 0, -1};

void dfs(vector<vector<int> > &map, vector<vector<int> > &dp, int x, int y) {
    if(dp[x][y] != 0) return;

    int max_day = 0;
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int new_x = x + dir_x[i], new_y = y + dir_y[i];
        if (new_x >= 0 && new_x < inputN && new_y >= 0 && new_y < inputN) {
            if(map[new_x][new_y] > map[x][y]) {
                if(dp[new_x][new_y] == 0)
                    dfs(map, dp, new_x, new_y);
                max_day = max(max_day, dp[new_x][new_y]);
            }
        }
    }

    dp[x][y] = max_day + 1;
    answer = max(answer, dp[x][y]);
}

int main() {
    cin >> inputN;

    vector<vector<int> > map(inputN, vector<int>(inputN, 0));
    for (int i = 0; i < inputN; i++)
        for (int j = 0; j<inputN; j++)
            cin >> map[i][j];

    vector<vector<int> > dp(inputN, vector<int>(inputN, 0));
    for (int i = 0; i < inputN; i++)
        for (int j = 0; j<inputN; j++)
            dfs(map, dp, i, j);

    cout << answer << endl;
    return 0;
}