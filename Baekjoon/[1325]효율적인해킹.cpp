/* 1325 효율적인해킹(DFS)
 * https://www.acmicpc.net/problem/1325
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int inputN, inputM, hacking;
vector<vector<int> > map(10001);

void dfs(vector<bool> &visited, int node) {
    hacking++;
    visited[node] = true;
    for (int i = 0; i < map[node].size(); i++) {
        int next_node = map[node][i];
        if(!visited[next_node])
            dfs(visited, next_node);
    }
}

int main() {
    cin >> inputN >> inputM;
    for (int i = 0; i < inputM; i++) {
        int in1, in2;
        cin >> in1 >> in2;
        map[in2].push_back(in1);
    }

    vector<int> hacking_count(inputN + 1, 0);
    int max_hacking = 0;
    for (int i = 1; i <= inputN; i++) {
        vector<bool> visited(inputN + 1, false);
        hacking = 0;
        dfs(visited, i);

        hacking_count[i] = hacking;
        max_hacking = max(max_hacking, hacking);
    }

    for (int i = 1; i <= inputN; i++)
        if(max_hacking == hacking_count[i])
            cout << i << " ";
    return 0;
}