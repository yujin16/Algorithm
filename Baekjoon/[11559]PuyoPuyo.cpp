/* 11559번 Puyo Puyo(Simulation)
 * https://www.acmicpc.net/problem/11559
 */

#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#define MAX(X,Y) ((X)>(Y)? (X):(Y))
using namespace std;

//enum COLOR { R = 1, G, B, P, Y };
int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

void relocation(deque<deque<char> >&map) {
	queue<char> queue;
	int maxSize = 0;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < map.size(); j++)
			if (map[j][i] != '.') {
				queue.push(map[j][i]);
				map[j][i] = '.';
			}

		maxSize = MAX(maxSize, queue.size());

		for (int j = 0; !queue.empty(); j++) {
			map[j][i] = queue.front();
			queue.pop();
		}
	}

	map.resize(maxSize);
}

void BFS(deque<deque<char> >&map, vector<vector<bool> >&visited, int i, int j, bool &puyo) {
	queue<pair<int, int> > queue;
	stack<pair<int, int> > stack;

	queue.push(make_pair(i, j));
	visited[i][j] = true;
	stack.push(make_pair(i, j));

	while (!queue.empty()) {
		int x = queue.front().first, y = queue.front().second;
		queue.pop();

		for (int i = 0; i < 4; i++) {
			int newX = x + dir_x[i], newY = y + dir_y[i];
			if (newX >= 0 && newX < map.size() && newY >= 0 && newY < 6 &&
				map[newX][newY] == map[x][y] && !visited[newX][newY]) {
				queue.push(make_pair(newX, newY));
				visited[newX][newY] = true;
				stack.push(make_pair(newX, newY));
			}
		}
	}

	if (stack.size() >= 4) {
		puyo = true;
		while (!stack.empty()) {
			map[stack.top().first][stack.top().second] = '.';
			stack.pop();
		}
	}
}

int main() {
	int size = 0;
	deque<deque<char> > map;
	for (int i = 11; i >= 0; i--) {
		char c1, c2, c3, c4, c5, c6;
		cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
		if (c1 != '.' || c2 != '.' || c3 != '.' || c4 != '.' || c5 != '.' || c6 != '.') {
			deque<char> dq = { c1, c2, c3, c4, c5, c6 };
			map.push_front(dq);
		}
	}

	int count = 0;
	bool puyo = false;
	do {
		puyo = false;
		vector<vector<bool> >visited(map.size(), vector<bool>(6, false));
		for (int i = 0; i < map.size(); i++)
			for (int j = 0; j < 6; j++)
				if (map[i][j] != '.' && !visited[i][j])
					BFS(map, visited, i, j, puyo);
		if (puyo) {
			relocation(map);
			count++;
		}
	} while (puyo);

	cout << count << endl;
	return 0;
}