/* 2178번 미로탐색(DFS/BFS)
 * https://www.acmicpc.net/problem/2178
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#define MAX(X,Y) ((X)<(Y)?(X):(Y))
using namespace std;

int main() {
	int inputN = 0, inputM = 0, blockNum = 0;
	cin >> inputN >> inputM;

	vector<vector<bool> > map(inputN, vector<bool>(inputM, false));
	vector<vector<bool> > visited(inputN, vector<bool>(inputM, false));
	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputM; j++) {
			int node = 0;
			scanf("%1d", &node);
			map[i][j] = (node == 1) ? true : false;
		}
	}

	queue<pair<int, int> > queue;
	bool arrived = false;
	visited[0][0] = true;
	queue.push(pair<int, int>(0, 0));
	while (!queue.empty()) {
		int size = queue.size();
		for (int i = 0; i < size; i++) {
			int n = queue.front().first, m = queue.front().second;
			queue.pop();

			if (n == inputN - 1 && m == inputM - 1) {
				arrived = true;
				break;
			}

			if (n + 1 < inputN && map[n + 1][m] && !visited[n + 1][m]) {
				visited[n + 1][m] = true;
				queue.push(pair<int, int>(n + 1, m));
			}
			if (n > 0 && map[n - 1][m] && !visited[n - 1][m]) {
				visited[n - 1][m] = true;
				queue.push(pair<int, int>(n - 1, m));
			}
			if (m + 1 < inputM && map[n][m + 1] && !visited[n][m + 1]) {
				visited[n][m + 1] = true;
				queue.push(pair<int, int>(n, m + 1));
			}
			if (m > 0 && map[n][m - 1] && !visited[n][m - 1]) {
				visited[n][m - 1] = true;
				queue.push(pair<int, int>(n, m - 1));
			}
		}
		blockNum++;

		if (arrived)
			break;
	}
	cout << blockNum << endl;
	return 0;
}