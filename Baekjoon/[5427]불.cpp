/* 5427น๘ บา
 * https://www.acmicpc.net/problem/5427
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int inputW = 0, inputH = 0;
int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };
enum Form { wall, fire, space, person };

struct Node {
	Node(int x, int y, int form) : node_x(x), node_y(y), node_form(form) {}
	int node_x, node_y, node_form;
};

bool isInsideBoundary(int x, int y) {
	if (x >= 0 && x < inputH && y >= 0 && y < inputW)
		return true;
	else
		return false;
}

void bfs(vector<vector<int> > &map, queue<Node> &queue) {
	vector<vector<int> > day(inputH, vector<int>(inputW, 0));
	bool escape = false;
	while (!queue.empty() && !escape) {
		int x = queue.front().node_x, y = queue.front().node_y, form = queue.front().node_form;
		queue.pop();

		if (form == person) {
			if (x == 0 || x == inputH - 1 || y == 0 || y == inputW - 1) {
				cout << day[x][y] + 1 << endl;
				escape = true;
				break;
			}
		}
		if (form == person && map[x + 1][y] == wall &&  map[x][y + 1] == wall &&  map[x - 1][y] == wall &&  map[x][y - 1] == wall)
			break;
		if (form == person && map[x + 1][y] == fire &&  map[x][y + 1] == fire &&  map[x - 1][y] == fire &&  map[x][y - 1] == fire)
			break;

		for (int i = 0; i < 4 && !escape; i++) {
			int newX = x + dir_x[i], newY = y + dir_y[i];

			if (form == fire && isInsideBoundary(newX, newY) && map[newX][newY] != fire && map[newX][newY] != wall) {
				map[newX][newY] = fire;
				queue.push(Node(newX, newY, fire));
			}
			if (form == person &&isInsideBoundary(newX, newY) && map[newX][newY] == space) {
				map[newX][newY] = person;
				day[newX][newY] = day[x][y] + 1;
				queue.push(Node(newX, newY, person));
			}
		}
	}

	if (!escape)
		cout << "IMPOSSIBLE" << endl;
}

int main() {
	int inputT = 0;
	cin >> inputT;

	for (int t = 0; t < inputT; t++) {
		cin >> inputW >> inputH;
		vector<vector<int> > map(inputH, vector<int>(inputW, 0));

		queue<Node> queue;
		for (int i = 0; i < inputH; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < inputW; j++) {
				if (s[j] == '#') { map[i][j] = wall; }
				else if (s[j] == '*') { map[i][j] = fire; queue.push(Node(i, j, fire)); }
				else if (s[j] == '.') { map[i][j] = space; }
				else if (s[j] == '@') { map[i][j] = person; }
			}
		}

		for (int i = 0; i<inputH; i++)
			for (int j = 0; j<inputW; j++)
				if (map[i][j] == person)
					queue.push(Node(i, j, person));

		bfs(map, queue);
	}
	return 0;
}