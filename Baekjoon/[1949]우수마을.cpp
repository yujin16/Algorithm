/* 1949번 우수마을(Dynamic Programming & DFS-postorder)
 * https://www.acmicpc.net/problem/1949
 */

#include <iostream>
#include <vector>
#define MAX(X, Y) ((X) > (Y)) ? (X) : (Y);
using namespace std;

int inputN = 0;
vector<int> regident;
vector<vector<int> > map;
vector<bool> visited;
vector<vector<int> > dp;

void dfs(int node) {
    visited[node] = true;

    vector<int> child_node;
    for (int i = 0; i < map[node].size(); i++) {
        int child = map[node][i];
        if (!visited[child]) {
            child_node.push_back(child);
            dfs(child);
        }
    }

    dp[node][0] = regident[node];
    for (int i = 0; i < child_node.size(); i++) {
        int child = child_node[i];
        dp[node][0] += dp[child][1];
        dp[node][1] += MAX(dp[child][0], dp[child][1]);
    }
}

int main() {
    int inputN;
    cin >> inputN;

    regident.resize(inputN + 1, 0);
    map.resize(inputN + 1);
    visited.resize(inputN + 1, false);
    dp.resize(inputN + 1, vector<int>(2, 0));

    for (int i = 1; i <= inputN; i++)
        cin >>
            regident[i];
    for (int i = 0; i < inputN - 1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        map[n1].push_back(n2);
        map[n2].push_back(n1);
    }

    dfs(1);

    int answer = MAX(dp[1][0], dp[1][1]);
    cout << answer << endl;
    return 0;
}