/* 2146 다리만들기(DFS/BFS)
* https://www.acmicpc.net/problem/2146
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#define MIN(X,Y) ((X)<(Y)? (X):(Y))
using namespace std;

int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

void dfs(vector<vector<bool> >&map, vector<vector<int> >&labelArr, int inputN) {
	vector<vector<bool> >visited(inputN, vector<bool>(inputN, false));
	stack<pair<int, int> >stack;
	int label = 1;
	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputN; j++) {
			if (map[i][j] && !visited[i][j]) {
				visited[i][j] = true;
				stack.push(make_pair(i, j));
				labelArr[i][j] = label;

				while (!stack.empty()) {
					int x = stack.top().first, y = stack.top().second;
					stack.pop();

					for (int k = 0; k < 4; k++) {
						int newX = x + dir_x[k], newY = y + dir_y[k];
						if (newX >= 0 && newX < inputN && newY >= 0 && newY < inputN
							&& map[newX][newY] && !visited[newX][newY]) {
							visited[newX][newY] = true;
							stack.push(make_pair(newX, newY));
							labelArr[newX][newY] = label;
						}
					}
				}
				label++;
			}
		}
	}
}

int bfs(vector<vector<bool> >&map, vector<vector<int> >&labelArr, int inputN) {
	vector<vector<int> >dist(inputN, vector<int>(inputN, -1));
	queue<pair<int, int> >queue;
	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputN; j++) {
			if (map[i][j]) {
				queue.push(make_pair(i, j));
				dist[i][j] = 0;
			}
		}
	}

	while (!queue.empty()) {
		int x = queue.front().first, y = queue.front().second;
		queue.pop();
		for (int i = 0; i < 4; i++) {
			int newX = x + dir_x[i], newY = y + dir_y[i];
			if (newX >= 0 && newX < inputN && newY >= 0 && newY < inputN && labelArr[newX][newY] == 0) {
				labelArr[newX][newY] = labelArr[x][y];
				queue.push(make_pair(newX, newY));
				dist[newX][newY] = dist[x][y] + 1;
			}
		}
	}

	int result = INT_MAX;
	for (int x = 0; x < inputN; x++) {
		for (int y = 0; y < inputN; y++) {
			for (int k = 0; k < 4; k++) {
				int newX = x + dir_x[k], newY = y + dir_y[k];
				if (newX >= 0 && newX < inputN && newY >= 0 && newY < inputN && labelArr[x][y] != labelArr[newX][newY])
					result = MIN(result, dist[x][y] + dist[newX][newY]);
			}
		}
	}

	return result;
}

int main() {
	int inputN = 0, result = 0;
	cin >> inputN;

	vector<vector<bool> >map(inputN, vector<bool>(inputN, true));
	vector<vector<int> >labelArr(inputN, vector<int>(inputN, 0));
	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputN; j++) {
			int input = 0;
			cin >> input;
			map[i][j] = (input == 1) ? true : false;
		}
	}

	dfs(map, labelArr, inputN);
	result = bfs(map, labelArr, inputN);

	cout << result << endl;
	return 0;
}