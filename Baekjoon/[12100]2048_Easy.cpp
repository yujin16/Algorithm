/* 12100¹ø 2048(Easy)
 * https://www.acmicpc.net/problem/12100
 */

#include <iostream>
#include <vector>
#include <queue>
#define MAX(X,Y) ((X)>(Y)? (X):(Y))
using namespace std;

int maxNum = 0;
void up(vector<vector<int> > map, int count);
void down(vector<vector<int> > map, int count);
void left(vector<vector<int> > map, int count);
void right(vector<vector<int> > map, int count);

void up(vector<vector<int> > map, int count) {
	for (int j = 0; j < map.size(); j++) {
		queue<int> queue;
		int prevNum = 0;
		for (int i = 0; i < map.size(); i++) {
			if (map[i][j] == 0)
				continue;
			if (prevNum == map[i][j]) {
				queue.push(prevNum * 2);
				prevNum = 0;
			}
			else {
				queue.push(prevNum);
				prevNum = map[i][j];
			}
			map[i][j] = 0;
		}
		queue.push(prevNum);

		int position = 0;
		while (!queue.empty()) {
			int num = queue.front();
			queue.pop();
			if (num != 0) {
				maxNum = MAX(maxNum, num);
				map[position++][j] = num;
			}
		}
	}

	if (count < 5) {
		up(map, count + 1);
		down(map, count + 1);
		left(map, count + 1);
		right(map, count + 1);
	}
}

void down(vector<vector<int> > map, int count) {
	for (int j = 0; j < map.size(); j++) {
		queue<int> queue;
		int prevNum = 0;
		for (int i = map.size() - 1; i >= 0; i--) {
			if (map[i][j] == 0)
				continue;
			if (prevNum == map[i][j]) {
				queue.push(prevNum * 2);
				prevNum = 0;
			}
			else {
				queue.push(prevNum);
				prevNum = map[i][j];
			}
			map[i][j] = 0;
		}
		queue.push(prevNum);

		int position = map.size() - 1;
		while (!queue.empty()) {
			int num = queue.front();
			queue.pop();
			if (num != 0) {
				maxNum = MAX(maxNum, num);
				map[position--][j] = num;
			}
		}
	}

	if (count < 5) {
		up(map, count + 1);
		down(map, count + 1);
		left(map, count + 1);
		right(map, count + 1);
	}
}

void left(vector<vector<int> > map, int count) {
	for (int i = 0; i < map.size(); i++) {
		queue<int> queue;
		int prevNum = 0;
		for (int j = 0; j < map.size(); j++) {
			if (map[i][j] == 0)
				continue;
			if (prevNum == map[i][j]) {
				queue.push(prevNum * 2);
				prevNum = 0;
			}
			else {
				queue.push(prevNum);
				prevNum = map[i][j];
			}
			map[i][j] = 0;
		}
		queue.push(prevNum);

		int position = 0;
		while (!queue.empty()) {
			int num = queue.front();
			queue.pop();
			if (num != 0) {
				maxNum = MAX(maxNum, num);
				map[i][position++] = num;
			}
		}
	}

	if (count < 5) {
		up(map, count + 1);
		down(map, count + 1);
		left(map, count + 1);
		right(map, count + 1);
	}
}

void right(vector<vector<int> > map, int count) {
	for (int i = 0; i < map.size(); i++) {
		queue<int> queue;
		int prevNum = 0;
		for (int j = map.size() - 1; j >= 0; j--) {
			if (map[i][j] == 0)
				continue;
			if (prevNum == map[i][j]) {
				queue.push(prevNum * 2);
				prevNum = 0;
			}
			else {
				queue.push(prevNum);
				prevNum = map[i][j];
			}
			map[i][j] = 0;
		}
		queue.push(prevNum);

		int position = map.size() - 1;
		while (!queue.empty()) {
			int num = queue.front();
			queue.pop();
			if (num != 0) {
				maxNum = MAX(maxNum, num);
				map[i][position--] = num;
			}
		}
	}

	if (count < 5) {
		up(map, count + 1);
		down(map, count + 1);
		left(map, count + 1);
		right(map, count + 1);
	}
}

int main() {
	int inputN = 0;
	cin >> inputN;
	vector<vector<int> > map(inputN, vector<int>(inputN, 0));
	vector<vector<bool> > visited(inputN, vector<bool>(inputN, false));

	for (int i = 0; i < inputN; i++)
		for (int j = 0; j < inputN; j++)
			cin >> map[i][j];

	up(map, 1);
	down(map, 1);
	left(map, 1);
	right(map, 1);

	cout << maxNum << endl;
	return 0;
}