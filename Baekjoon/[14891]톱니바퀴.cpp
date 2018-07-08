/* 14891번 톱니바퀴(Simulation)
 * https://www.acmicpc.net/problem/14891
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
using namespace std;

int main() {
	vector<deque<int> > my_deque;
	for (int i = 0; i < 4; i++) {
		deque<int> tmp;
		for (int j = 0; j < 8; j++) {
			int num;
			scanf("%1d", &num);
			tmp.push_back(num);
		}
		my_deque.push_back(tmp);
	}



	int inputK;
	cin >> inputK;
	for (int k = 0; k < inputK; k++) {
		vector<int> state(4, 100);
		queue<int> queue;
		int index, rotate;
		cin >> index >> rotate;
		state[index - 1] = rotate;

		queue.push(index - 1);
		while (!queue.empty()) {
			int node = queue.front();
			queue.pop();

			if (state[node] == 100) continue;
			if (node - 1 >= 0 && state[node - 1] == 100) {
				if (my_deque[node - 1][2] == my_deque[node][6])
					state[node - 1] = 0;
				else
					state[node - 1] = state[node] * -1;
				queue.push(node - 1);
			}

			if (node + 1 < 4 && state[node + 1] == 100) {
				if (my_deque[node][2] == my_deque[node + 1][6])
					state[node + 1] = 0;
				else
					state[node + 1] = state[node] * -1;
				queue.push(node + 1);
			}
		}

		for (int i = 0; i < 4; i++) {
			if (state[i] == 1) {
				int value = my_deque[i][7];
				my_deque[i].pop_back();
				my_deque[i].push_front(value);
			}
			else if (state[i] == -1) {
				int value = my_deque[i][0];
				my_deque[i].pop_front();
				my_deque[i].push_back(value);
			}
		}
	}

	int score = 0;
	for (int i = 0; i < 4; i++)
		if (my_deque[i][0] == 1)
			score += (int)pow(2, i);

	cout << score << endl;
	return 0;
}