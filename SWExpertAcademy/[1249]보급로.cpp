/* 1249번 보급로
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MIN(X,Y) ((X)<(Y)? (X):(Y))
using namespace std;

int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

void bfs(vector<vector<int> > &map, vector<vector<int> > &cost) {
	queue<pair<int, int> > queue;
	queue.push(make_pair(0, 0));
	cost[0][0] = 0;

	while (!queue.empty()) {
		int x = queue.front().first, y = queue.front().second;
		queue.pop();

		for (int i = 0; i < 4; i++) {
			int newX = x + dir_x[i], newY = y + dir_y[i];

			if (newX >= 0 && newX < map.size() && newY >= 0 && newY < map.size()) {
				if (cost[x][y] + map[newX][newY] < cost[newX][newY]) {
					cost[newX][newY] = cost[x][y] + map[newX][newY];
					queue.push(make_pair(newX, newY));
				}
			}
		}
	}
}

int main() {
	int inputT = 0, inputN = 0;
	cin >> inputT;

	for (int t = 0; t < inputT; t++) {
		cin >> inputN;
		vector<vector<int> > map(inputN, vector<int>(inputN, 0));
		vector<vector<int> > cost(inputN, vector<int>(inputN, INT_MAX));

		for (int i = 0; i < inputN; i++) {
			for (int j = 0; j < inputN; j++) {
				int node = 0;
				scanf("%1d", &node);
				map[i][j] = node;
			}
		}

		bfs(map, cost);
		cout << "#" << t + 1 << " " << cost[inputN - 1][inputN - 1] << endl;
	}

	return 0;
}