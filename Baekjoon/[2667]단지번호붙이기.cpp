/* 2667번 단지 번호 붙이기
 * https://www.acmicpc.net/problem/2667
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

void dfs(vector<vector<int> >&map, vector<int> &result) {
	vector<vector<bool> > visited(map.size(), vector<bool>(map.size(), false));
	stack<pair<int, int> > stack;

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.size(); j++) {
			if (map[i][j] != 0 && !visited[i][j]) {
				int count = 0;

				count++;
				visited[i][j] = true;
				stack.push(make_pair(i, j));

				while (!stack.empty()) {
					int x = stack.top().first, y = stack.top().second;
					stack.pop();

					for (int k = 0; k < 4; k++) {
						int newX = x + dir_x[k], newY = y + dir_y[k];
						if (newX >= 0 && newX < map.size() && newY >= 0 && newY < map.size()
							&& map[newX][newY] != 0 && !visited[newX][newY]) {
							count++;
							visited[newX][newY] = true;
							stack.push(make_pair(newX, newY));
						}
					}
				}
				result.push_back(count);
			}
		}
	}
}

int main() {
	int inputN = 0;
	cin >> inputN;
	vector<vector<int> > map(inputN, vector<int>(inputN, 0));
	vector<int> result;

	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputN; j++) {
			int node = 0;
			scanf("%1d", &node);
			map[i][j] = node;
		}
	}

	dfs(map, result);
	sort(result.begin(), result.end());

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;

	return 0;
}