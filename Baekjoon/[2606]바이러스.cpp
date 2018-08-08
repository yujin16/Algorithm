/* 2606번 바이러스(DFS)
 * https://www.acmicpc.net/problem/2606
 */

#include <iostream>
#include <vector>
using namespace std;

int answer = 0;

void dfs(vector<vector<int> > &map, vector<bool> &visited, int node) {
    answer++;
    visited[node] = true;

    for (int i = 0; i < map[node].size(); i++) {
        int next_node = map[node][i];
        if (!visited[next_node])
            dfs(map, visited, next_node);
    }
}

int main() {
    int inputC, inputN;
    cin >> inputC >> inputN;

    vector<vector<int> > map(inputC + 1);
    for (int i = 0; i < inputN; i++) {
        int in1, in2;
        cin >> in1 >> in2;
        map[in1].push_back(in2);
        map[in2].push_back(in1);
    }

    vector<bool> visited(inputC + 1);
    dfs(map, visited, 1);

    cout << answer - 1 << endl;
    return 0;
}