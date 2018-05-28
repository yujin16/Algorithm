/* 13460¹ø ±¸½½Å»Ãâ1
 * https://www.acmicpc.net/problem/13460
 */

#include <iostream>
#include <vector>
#include <climits>
#define MIN(X,Y) ((X)<(Y))? (X):(Y)
using namespace std;

int result = INT_MAX;
bool success = false;

enum COLOR { RED, BLUE };
enum DIR { UP, DOWN, LEFT, RIGHT };

pair<int, int> move(vector<vector<char> > &map, pair<int, int> pos, int dir, int color) {
	int x = pos.first;
	int y = pos.second;

	switch (dir) {
	case UP: do { x--; } while (map[x][y] == '.'); if (map[x][y] != 'O') x++; break;
	case DOWN: do { x++; } while (map[x][y] == '.'); if (map[x][y] != 'O') x--; break;
	case LEFT:do { y--; } while (map[x][y] == '.'); if (map[x][y] != 'O') y++; break;
	case RIGHT: do { y++; } while (map[x][y] == '.'); if (map[x][y] != 'O') y--; break;
	}

	map[pos.first][pos.second] = '.';
	if (map[x][y] != 'O') {
		if (color == RED) map[x][y] = 'R';
		if (color == BLUE) map[x][y] = 'B';
	}

	return make_pair(x, y);
}

void dfs(vector<vector<char> > &map, pair<int, int> red, pair<int, int> blue, int count) {
	if (count > 10)return;
	if (result <= count) return;
	if (map[blue.first][blue.second] == 'O') return;
	if (map[red.first][red.second] == 'O') {
		success = true;
		result = MIN(result, count);
		return;
	}

	pair<int, int> m_red;
	pair<int, int> m_blue;

	int tmp1[4] = { red.first, blue.first, red.second, blue.second };
	int tmp2[4] = { blue.first, red.first, blue.second, red.second };

	for (int i = 0; i < 4; i++) {
		if (tmp1[i] < tmp2[i]) {
			m_red = move(map, red, i, RED);
			m_blue = move(map, blue, i, BLUE);
		}
		else {
			m_blue = move(map, blue, i, BLUE);
			m_red = move(map, red, i, RED);
		}

		if (m_red == red && m_blue == blue) continue;
		dfs(map, m_red, m_blue, count + 1);

		map[red.first][red.second] = 'R';
		map[blue.first][blue.second] = 'B';
		if (map[m_red.first][m_red.second] != 'O')map[m_red.first][m_red.second] = '.';
		if (map[m_blue.first][m_blue.second] != 'O')map[m_blue.first][m_blue.second] = '.';

	}
}

int main() {
	int inputN, inputM;
	cin >> inputN >> inputM;

	pair<int, int> red;
	pair<int, int> blue;
	vector<vector<char> > map(inputN, vector<char>(inputM, '.'));
	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputM; j++) {
			char in;
			cin >> in;
			map[i][j] = in;
			if (in == 'R') red = make_pair(i, j);
			if (in == 'B') blue = make_pair(i, j);
		}
	}

	dfs(map, red, blue, 0);

	if (success)
		cout << result << endl;
	else
		cout << "-1" << endl;
	return 0;
}