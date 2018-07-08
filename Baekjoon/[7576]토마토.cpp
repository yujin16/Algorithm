/* 7576번 토마토(DFS/BFS)
 * https://www.acmicpc.net/problem/7576
 */

#include <iostream>
#include <vector>
#include <queue>
#define MAX(X,Y) ((X)>(Y)? (X):(Y))
using namespace std;

int dir_n[4] = { 0, 1, 0, -1 };
int dir_m[4] = { 1, 0, -1, 0 };

int main() {
	int inputM = 0, inputN = 0;
	cin >> inputM >> inputN;
	vector<vector<int> >map(inputN, vector<int>(inputM, 0));
	vector<vector<int> >day(inputN, vector<int>(inputM, -1));

	for (int n = 0; n < inputN; n++)
		for (int m = 0; m < inputM; m++)
			cin >> map[n][m];

	queue<pair<int, int> >queue;
	for (int n = 0; n < inputN; n++) {
		for (int m = 0; m < inputM; m++) {
			if (map[n][m] == 1) {
				day[n][m] = 0;
				queue.push(make_pair(n, m));
			}
		}
	}

	while (!queue.empty()) {
		int n = queue.front().first, m = queue.front().second;
		queue.pop();
		for (int i = 0; i < 4; i++) {
			int newN = n + dir_n[i], newM = m + dir_m[i];
			if (0 <= newN && newN < inputN && 0 <= newM && newM < inputM && map[newN][newM] == 0) {
				map[newN][newM] = 1;
				day[newN][newM] = day[n][m] + 1;
				queue.push(make_pair(newN, newM));
			}
		}
	}

	int result = 0;
	for (int n = 0; n < inputN; n++) {
		for (int m = 0; m < inputM; m++) {
			if (day[n][m] == -1 && map[n][m] != -1) {
				cout << "-1" << endl;
				return 0;
			}
			result = MAX(result, day[n][m]);
		}
	}

	cout << result << endl;
	return 0;
}