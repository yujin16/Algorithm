/* 2468번 안전영역
 * https://www.acmicpc.net/problem/2468
 */

#include <iostream>
#include <vector>
#include <queue>
#define MAX(X,Y) ((X)>(Y))? (X):(Y)
using namespace std;

int result = 1;
int max_high = 0;

int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };

int main() {
	int inputN;
	cin >> inputN;

	vector<vector<int> > map(inputN, vector<int>(inputN, 0));
	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputN; j++) {
			int in;
			cin >> in;
			max_high = MAX(max_high, in);
			map[i][j] = in;
		}
	}

	for (int high = 1; high < max_high; high++) {
		vector<vector<bool> > visited(inputN, vector<bool>(inputN, false));
		int count = 0;

		for (int i = 0; i < inputN; i++) {
			for (int j = 0; j < inputN; j++) {
				if (visited[i][j]) continue;
				if (map[i][j] <= high)continue;

				queue<pair<int, int> > queue;
				queue.push(make_pair(i, j));
				visited[i][j] = true;

				while (!queue.empty()) {
					int x = queue.front().first;
					int y = queue.front().second;
					queue.pop();

					for (int k = 0; k < 4; k++) {
						int new_x = x + dir_x[k], new_y = y + dir_y[k];
						if (new_x >= 0 && new_x < inputN && new_y >= 0 && new_y < inputN && !visited[new_x][new_y]) {
							if (map[new_x][new_y] > high) {
								queue.push(make_pair(new_x, new_y));
								visited[new_x][new_y] = true;
							}
						}
					}
				}
				count++;
			}
		}
		result = MAX(result, count);
	}

	cout << result << endl;
	return 0;
}