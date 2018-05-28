/* 3190번 뱀
 * https://www.acmicpc.net/problem/3190
 */

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

enum { LEFT = -1, RIGHT = 1 };
int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };

int main() {
	int inputN, inputK, inputL;
	cin >> inputN;
	cin >> inputK;

	vector<vector<bool> > map(inputN, vector<bool>(inputN, 0));
	for (int i = 0; i < inputK; i++) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = true;
	}

	cin >> inputL;
	queue<pair<int, int> > rotate;
	for (int i = 0; i < inputL; i++) {
		int x;
		char c;
		cin >> x >> c;
		if (c == 'L')
			rotate.push(make_pair(x, LEFT));
		else if (c == 'D')
			rotate.push(make_pair(x, RIGHT));
	}

	deque<pair<int, int> > snake;
	snake.push_back(make_pair(0, 0));

	int time = 0;
	bool die = false;
	int cur_x = 0;
	int cur_y = 0;
	int move_index = 0;
	int rotate_time = rotate.front().first;
	int rotate_dir = rotate.front().second;
	rotate.pop();
	while (!die) {
		// 머리 위치 구하기
		cur_x += dir_x[move_index];
		cur_y += dir_y[move_index];
		time++;

		// 벽에 부딪히면 종료
		if (cur_x < 0 || cur_x >= inputN || cur_y < 0 || cur_y >= inputN) { die = true; break; }

		// 자신의 몸에 부딪히면 종료
		for (int i = 1; i < snake.size(); i++)
			if (snake[i].first == cur_x && snake[i].second == cur_y) { die = true; break; }

		// 머리 이동하고 사과 없으면 꼬리 자르기
		snake.push_front(make_pair(cur_x, cur_y));
		if (!map[cur_x][cur_y])
			snake.pop_back();
		else
			map[cur_x][cur_y] = false;

		// 방향 바꾸기
		if (rotate_time == time) {
			move_index += rotate_dir;
			if (move_index < 0) move_index = 3;
			else if (move_index > 3) move_index = 0;

			if (!rotate.empty()) {
				rotate_time = rotate.front().first;
				rotate_dir = rotate.front().second;
				rotate.pop();
			}
		}
	}

	cout << time << endl;
	return 0;
}