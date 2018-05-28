/* 11724번 연결 요소의 개수
 * https://www.acmicpc.net/problem/11724
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int inputN = 0, inputM = 0, count = 0;
	cin >> inputN >> inputM;
	vector<vector<int> > map(inputN + 1, vector<int>());
	vector<vector<bool> > visited(inputN + 1, vector<bool>(inputN + 1, false));

	for (int i = 0; i < inputM; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		map[x].push_back(y);
		map[y].push_back(x);
	}

	bool search = false;
	stack<int> stack;
	for (int i = 1; i <= inputN; i++) {
		search = false;

		if (map[i].size() == 0) {
			count++;
			continue;
		}

		for (int j = 0; j < map[i].size() && !visited[i][map[i][j]]; j++) {
			stack.push(map[i][j]);
			visited[i][map[i][j]] = true;
			visited[j][map[i][j]] = true;
			search = true;
		}

		while (!stack.empty() && search) {
			int node = stack.top();
			stack.pop();
			for (int k = 0; k < map[node].size() && !visited[node][map[node][k]]; k++) {
				stack.push(map[node][k]);
				visited[node][map[node][k]] = true;
				visited[map[node][k]][node] = true;
			}
		}

		if (search)
			count++;
	}

	cout << count << endl;
	return 0;
}