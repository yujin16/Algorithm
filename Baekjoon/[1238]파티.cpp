/* 1238번 파티(Dijkstra algorithm)
 * https://www.acmicpc.net/problem/1238
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int inputN, inputM, inputX;

int main() {
    cin >> inputN >> inputM >> inputX;

    vector<vector<int> > route(inputN + 1, vector<int>(inputN + 1, 0));
    for (int i = 0; i < inputM; i++) {
        int start, end, time;
        cin >> start >> end >> time;
        route[start][end] = time;
    }

    queue<int> queue;

    queue.push(inputX);
    vector<int> HometoX(inputN + 1, INT_MAX);
    HometoX[inputX] = 0;
    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();

        for (int i = 1; i <= inputN; i++) {
            if(route[i][node] != 0 && HometoX[node] != INT_MAX) {
                if(HometoX[i] > HometoX[node] + route[i][node]) {
                    HometoX[i] = HometoX[node] + route[i][node];
                    queue.push(i);
                }
            }
        }
    }

    queue.push(inputX);
    vector<int> XtoHome(inputN + 1, INT_MAX);
    XtoHome[inputX] = 0;
    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();

        for (int i = 1; i <= inputN; i++) {
            if(route[node][i] != 0 && XtoHome[node] != INT_MAX) {
                if(XtoHome[i] > XtoHome[node] + route[node][i]) {
                    XtoHome[i] = XtoHome[node] + route[node][i];
                    queue.push(i);
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= inputN; i++)
        answer = max(answer, HometoX[i] + XtoHome[i]);

    cout << answer << endl;
    return 0;
}