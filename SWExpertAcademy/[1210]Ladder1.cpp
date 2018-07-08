/* 1210번 Ladder1
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int dfs(vector<vector<int> > &map, vector<vector<bool> > &visited, int goal_x, int goal_y) {
	int x = 0, y = 0;
	stack<pair<int, int> >stack;
	stack.push(make_pair(goal_x, goal_y));
	visited[goal_x][goal_y] = true;

	while (!stack.empty()) {
		x = stack.top().first, y = stack.top().second;
		stack.pop();

		if (x >= 0 && x < 100 && y - 1 >= 0 && y - 1 < 100 && map[x][y - 1] == 1 && !visited[x][y - 1]) {
			stack.push(make_pair(x, y - 1));
			visited[x][y - 1] = true;
		}
		else if (x >= 0 && x < 100 && y + 1 >= 0 && y + 1 < 100 && map[x][y + 1] == 1 && !visited[x][y + 1]) {
			stack.push(make_pair(x, y + 1));
			visited[x][y + 1] = true;
		}
		else if (x - 1 >= 0 && x - 1 < 100 && y >= 0 && y < 100 && map[x - 1][y] == 1 && !visited[x - 1][y]) {
			stack.push(make_pair(x - 1, y));
			visited[x - 1][y] = true;
		}
	}

	return y;
}

int main() {
	for (int t = 0; t < 10; t++) {
		int TC = 0, result = 0, goal_x, goal_y;
		cin >> TC;

		vector<vector<int> >map(100, vector<int>(100, 0));
		vector<vector<bool> > visited(100, vector<bool>(100, false));
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				int node;
				cin >> node;
				map[i][j] = node;
				if (node == 2) {
					goal_x = i;
					goal_y = j;
				}
			}
		}

		cout << "#" << TC << " " << dfs(map, visited, goal_x, goal_y) << endl;
	}
	return 0;
}