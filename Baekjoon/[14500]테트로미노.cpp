/* 14500번 테트로미노
 * https://www.acmicpc.net/problem/14500
 */

#include <iostream>
#include <vector>
#include <stack>
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
using namespace std;

int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

int inputN = 0;
int inputM = 0;
int result = 0;

void dfs(vector<vector<int> > &map, vector<vector<bool> > &visited, int x, int y, int sum, int count) {
	if (count == 4) {
		visited[x][y] = false;
		result = MAX(result, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int newX = x + dir_x[i], newY = y + dir_y[i];
		if (newX >= 0 && newX < inputN && newY >= 0 && newY < inputM && !visited[newX][newY]) {
			visited[newX][newY] = true;
			dfs(map, visited, newX, newY, sum + map[newX][newY], count + 1);
		}
	}

	visited[x][y] = false;
}

int main() {
	cin >> inputN >> inputM;
	vector<vector<int> > map(inputN, vector<int>(inputM, 0));
	vector<vector<bool> > visited(inputN, vector<bool>(inputM, false));

	for (int i = 0; i < inputN; i++)
		for (int j = 0; j < inputM; j++)
			cin >> map[i][j];

	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputM; j++) {
			visited[i][j] = true;
			dfs(map, visited, i, j, map[i][j], 1);

			if (i + 2 < inputN && j + 1 < inputM) {	//ㅏ
				int sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
				result = MAX(result, sum);
			}
			if (i + 2 < inputN && j - 1 >= 0) { // ㅓ
				int sum = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j];
				result = MAX(result, sum);
			}
			if (i + 1 < inputN && j + 2 < inputM) { // ㅜ
				int sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i][j + 2];
				result = MAX(result, sum);
			}
			if (i - 1 >= 0 && j + 2 < inputM) {	//ㅗ
				int sum = map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i][j + 2];
				result = MAX(result, sum);
			}
		}
	}

	cout << result << endl;
	return 0;
}