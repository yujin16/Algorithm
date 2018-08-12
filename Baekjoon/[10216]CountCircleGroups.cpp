/* 10216번 Count Circle Groups(DFS/BFS)
 * https://www.acmicpc.net/problem/10216
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct ENEMY {
    int X;
    int Y;
    int R;
};

int inputN, answer;

bool isConnected(ENEMY e1, ENEMY e2) {
    int distance1 = pow(e1.X - e2.X, 2) + pow(e1.Y - e2.Y, 2);
    int distance2 = e1.R + e2.R;

    if(distance1 <= pow(distance2, 2))
        return true;
    else
        return false;
}

void dfs(vector<vector<int> > &area, vector<bool> &visited, int node) {
    int size = area[node].size();
    visited[node] = true;
    for (int i = 0; i < size; i++) {
        int next_node = area[node][i];
        if(!visited[next_node])
            dfs(area, visited, next_node);
    }
}

int main() {
    int Testcase;
    cin >> Testcase;

    for (int t = 0; t < Testcase;t++) {
        answer = 0;
        cin >> inputN;

        vector<ENEMY> enemy(inputN);
        for (int i = 0; i < inputN; i++)
            cin >> enemy[i].X >> enemy[i].Y >> enemy[i].R;

        vector<vector<int> > area(inputN);
        for (int i = 0; i < inputN; i++){
            for (int j = 0; j < inputN;j++) {
                if((i != j) && (isConnected(enemy[i], enemy[j]))) {
                    area[i].push_back(j);
                    area[j].push_back(i);
                }
            }
        }

        vector<bool> visited(inputN, false);
        for (int i = 0; i < inputN; i++) {
            if(!visited[i]) {
                dfs(area, visited, i);
                answer++;
            }
        }

        cout << answer << endl;
    }

    return 0;
}