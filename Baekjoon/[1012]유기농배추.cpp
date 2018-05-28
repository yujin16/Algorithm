/* 1012번 유기농 배추
 * https://www.acmicpc.net/problem/1012
 */

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t = 0, m = 0, n = 0, k = 0;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int result = 0;
		cin >> m >> n >> k;
		vector<vector<int> > map(m, vector<int>(n, 0));
		vector<vector<int> > visited(m, vector<int>(n, 0));

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}

		queue<pair<int, int> > queue;
		for (int i = 0; i< m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1 && visited[i][j] != 1) {
					visited[i][j] = 1;
					queue.push(pair<int, int>(i, j));
					while (!queue.empty()) {
						int x = queue.front().first, y = queue.front().second;
						queue.pop();
						if (x + 1<map.size() && map[x + 1][y] == 1 && visited[x + 1][y] != 1) {
							queue.push(pair<int, int>(x + 1, y));
							visited[x + 1][y] = 1;
						}
						if (x - 1 >= 0 && map[x - 1][y] == 1 && visited[x - 1][y] != 1) {
							queue.push(pair<int, int>(x - 1, y));
							visited[x - 1][y] = 1;
						}
						if (y + 1<map[x].size() && map[x][y + 1] == 1 && visited[x][y + 1] != 1) {
							queue.push(pair<int, int>(x, y + 1));
							visited[x][y + 1] = 1;
						}
						if (y - 1 >= 0 && map[x][y - 1] == 1 && visited[x][y - 1] != 1) {
							queue.push(pair<int, int>(x, y - 1));
							visited[x][y - 1] = 1;
						}
					}
					result++;
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}