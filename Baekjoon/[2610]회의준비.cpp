/* 2610번 회의준비(Floyd-Warshall Algorithm)
 * https://www.acmicpc.net/problem/2610
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

int inputN, inputM;

int main() {
    cin >> inputN >> inputM;
    vector<vector<int> > map(inputN + 1, vector<int>(inputN + 1, INT_MAX));

    for (int i = 0; i < inputM;i++) {
        int n1, n2;
        cin >> n1 >> n2;
        map[n1][n2] = 1;
        map[n2][n1] = 1;
    }

    for (int k = 1; k <= inputN; k++) {
        for (int i = 1; i <= inputN; i++){
            for (int j = 1; j <= inputN; j++) {
                if(i == j) continue;
                if(map[i][k] == INT_MAX || map[k][j] == INT_MAX) continue;
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for (int i = 1; i<=inputN; i++) {
        int max_route = 0;
        for (int j = 1; j <= inputN; j++) {
            if(map[i][j] == INT_MAX) continue;
            max_route = max(max_route, map[i][j]);
        }
        map[i][0] = max_route;
    }

    vector<int> answer;
    vector<bool> visited(inputN + 1, false);
    for (int i = 1; i <= inputN; i++) {
        if(visited[i]) continue;

        int top = i;
        for (int j = 1; j <= inputN; j++) {
            if(map[i][j] == INT_MAX) continue;
            if(map[top][0] > map[j][0])
                top = j;
            visited[j] = true;
        }

        answer.push_back(top);
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;

    return 0;
}