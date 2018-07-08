/* 1260번 DFS과BFS(DFS/BFS)
 * https://www.acmicpc.net/problem/1260
 */

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void dfs(vector<vector<int> >&map, vector<int>& visited, int v) {
	stack<int> stack;
	stack.push(v);

	while (!stack.empty()) {
		int node = stack.top();
		stack.pop();

		if (visited[node] != 1) {
			visited[node] = 1;
			cout << node << " ";
		}

		for (int i = map.size() - 1; i >= 0; i--) {
			if (map[node][i] == 1 && visited[i] != 1)
				stack.push(i);
		}
	}
}

void bfs(vector<vector<int> >&map, vector<int>& visited, int v) {
	queue<int> queue;
	visited[v] = 1;
	queue.push(v);
	while (!queue.empty()) {
		int node = queue.front();
		queue.pop();
		for (int i = 1; i < map.size(); i++) {
			if (map[node][i] == 1 && visited[i] != 1) {
				visited[i] = 1;
				queue.push(i);
			}
		}
		cout << node << " ";
	}
}

int main() {
	int n = 0, m = 0, v = 0;
	cin >> n >> m >> v;

	vector<vector<int> > map(n + 1, vector<int>(n + 1, 0));
	vector<int> DFS_visited(n + 1, 0);
	vector<int> BFS_visited(n + 1, 0);

	for (int i = 0; i<m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		map[n1][n2] = 1;
		map[n2][n1] = 1;
	}

	dfs(map, DFS_visited, v);
	cout << endl;
	bfs(map, BFS_visited, v);
	return 0;
}