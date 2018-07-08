/* 1600번 말이되고픈원숭이(DFS/BFS)
 * https://www.acmicpc.net/problem/1600
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MIN(X,Y) ((X)<(Y))? (X):(Y)
using namespace std;

int inputK = 0, inputW = 0, inputH = 0;
int dir_x_monkey[4] = { 1, 0, -1, 0 };
int dir_y_monkey[4] = { 0, 1, 0, -1 };
int dir_x_horse[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dir_y_horse[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };

struct Node {
	Node(int x, int y, int k) : node_x(x), node_y(y), node_k(k) {}
	int node_x, node_y, node_k;
};

bool isInsideBoundary(int x, int y) {
	if (x >= 0 && x < inputH && y >= 0 && y < inputW)
		return true;
	else
		return false;
}

int bfs(vector<vector<int> > &map) {
	vector<vector<vector<int> > > dp(inputH, vector<vector<int> >(inputW, vector<int>(inputK + 1, INT_MAX)));

	queue<Node> queue;
	for (int k = 0; k <= inputK; k++) {
		queue.push(Node(0, 0, k));
		dp[0][0][k] = 0;
	}

	while (!queue.empty()) {
		int x = queue.front().node_x, y = queue.front().node_y, k = queue.front().node_k;
		queue.pop();

		// monkey�̵�(1ĭ�� �̵�)
		for (int i = 0; i < 4; i++) {
			int newX = x + dir_x_monkey[i], newY = y + dir_y_monkey[i];
			if (isInsideBoundary(newX, newY) && map[newX][newY] != 1 && dp[x][y][k] + 1 < dp[newX][newY][k]) {
				dp[newX][newY][k] = dp[x][y][k] + 1;
				queue.push(Node(newX, newY, k));
			}
		}

		// horse�̵�(����Ʈ �̵�)
		for (int i = 0; i < 8; i++) {
			int newX = x + dir_x_horse[i], newY = y + dir_y_horse[i];
			if (isInsideBoundary(newX, newY) && k<inputK && map[newX][newY] != 1 && dp[x][y][k] + 1 < dp[newX][newY][k + 1]) {
				dp[newX][newY][k + 1] = dp[x][y][k] + 1;
				queue.push(Node(newX, newY, k + 1));
			}
		}
	}

	int result = INT_MAX;
	for (int k = 0; k <= inputK; k++)
		result = MIN(result, dp[inputH - 1][inputW - 1][k]);
	if (result == INT_MAX)
		result = -1;
	return result;
}

int main() {
	cin >> inputK >> inputW >> inputH;
	vector<vector<int> > map(inputH, vector<int>(inputW, 0));

	for (int i = 0; i < inputH; i++)
		for (int j = 0; j < inputW; j++)
			cin >> map[i][j];

	cout << bfs(map) << endl;
	return 0;
}