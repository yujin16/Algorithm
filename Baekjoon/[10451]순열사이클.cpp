/* 10451번 순열사이클(DFS/BFS)
 * https://www.acmicpc.net/problem/10451
 */

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> &map, vector<bool> &visited, int node) {
	visited[node] = true;
	if (!visited[map[node]])
		dfs(map, visited, map[node]);
}

int main() {
	int inputT = 0, inputN = 0;
	cin >> inputT;

	for (int t = 0; t < inputT; t++) {
		int count = 0;
		cin >> inputN;
		vector<int> map(inputN + 1, 0);
		vector<bool> visited(inputN + 1, false);

		for (int n = 1; n <= inputN; n++)
			cin >> map[n];

		for (int i = 1; i <= inputN; i++) {
			if (!visited[i]) {
				dfs(map, visited, i);
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}