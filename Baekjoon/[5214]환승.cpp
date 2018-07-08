/* 5214번 환승(DFS/BFS)
 * https://www.acmicpc.net/problem/5214
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
	int inputN, inputK, inputM;
	cin >> inputN >> inputK >> inputM;

	vector<vector<int> > map(inputM, vector<int>(inputK, 0));
	vector<vector<int> > connected(inputN + 1, vector<int>());
	for (int m = 0; m < inputM; m++) {
		for (int k = 0; k < inputK; k++) {
			cin >> map[m][k];
			connected[map[m][k]].push_back(m);
		}
	}

	queue<int> queue;
	vector<bool> visited(inputM, false);
	vector<int> countArr(inputN + 1, INT_MAX);
	bool success = false;
	countArr[1] = 1;

	for (int i = 0; i < connected[1].size(); i++) {
		int index = connected[1][i];
		visited[index] = true;
		for (int j = 0; j < map[index].size(); j++) {
			if (map[index][j] != 1) {
				queue.push(map[index][j]);
				countArr[map[index][j]] = 2;
			}
		}
	}

	while (!queue.empty()) {
		int node = queue.front();
		int count = countArr[node];
		queue.pop();

		if (node == inputN) {
			success = true;
			break;
		}

		for (int i = 0; i < connected[node].size(); i++) {
			int index = connected[node][i];
			if (!visited[index]) {
				for (int j = 0; j < map[index].size(); j++) {
					if (map[index][j] != node && countArr[map[index][j]] > count + 1) {
						queue.push(map[index][j]);
						countArr[map[index][j]] = count + 1;
					}
				}
				visited[index] = true;
			}
		}
	}

	if (success)
		cout << countArr[inputN] << endl;
	else
		cout << "-1" << endl;
	return 0;
}