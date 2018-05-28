/* 14502번 연구소
 * https://www.acmicpc.net/problem/14502
 */

#include <iostream>
#include <vector>
#include <queue>
#define MAX(X,Y) ((X)>(Y))? (X):(Y)
using namespace std;

int space_size = 0;
int max_space = 0;
int inputN, inputM;

vector<pair<int, int> > space;
vector<pair<int, int> > virus;

void bfs(vector<vector<int> > map) {
	int count = 0;
	queue<pair<int, int> > queue;
	for (int i = 0; i < virus.size(); i++)
		queue.push(make_pair(virus[i].first, virus[i].second));

	while (!queue.empty()) {
		int x = queue.front().first;
		int y = queue.front().second;
		queue.pop();

		if (x + 1 < inputN && map[x + 1][y] == 0) {
			count++;
			queue.push(make_pair(x + 1, y));
			map[x + 1][y] = 2;
		}
		if (x - 1 >= 0 && map[x - 1][y] == 0) {
			count++;
			queue.push(make_pair(x - 1, y));
			map[x - 1][y] = 2;
		}
		if (y + 1 < inputM && map[x][y + 1] == 0) {
			count++;
			queue.push(make_pair(x, y + 1));
			map[x][y + 1] = 2;
		}
		if (y - 1 >= 0 && map[x][y - 1] == 0) {
			count++;
			queue.push(make_pair(x, y - 1));
			map[x][y - 1] = 2;
		}
	}

	max_space = MAX(max_space, space_size - count);
}

void dfs(vector<vector<int> > &map, int index, int depth) {
	if (depth == 3) {
		bfs(map);
		return;
	}

	for (int i = index + 1; i < space_size; i++) {
		map[space[i].first][space[i].second] = 1;
		dfs(map, i, depth + 1);
		map[space[i].first][space[i].second] = 0;
	}
}

int main() {
	cin >> inputN >> inputM;

	vector<vector<int> > map(inputN, vector<int>(inputM, 0));

	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputM; j++) {
			int x;
			cin >> x;
			if (x == 0)
				space.push_back(make_pair(i, j));
			if (x == 2)
				virus.push_back(make_pair(i, j));
			map[i][j] = x;
		}
	}

	space_size = space.size();
	for (int i = 0; i < space_size; i++) {
		map[space[i].first][space[i].second] = 1;
		dfs(map, i, 1);
		map[space[i].first][space[i].second] = 0;
	}

	cout << max_space - 3 << endl;
	return 0;
}