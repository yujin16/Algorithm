/* 2583번 영역구하기
 * https://www.acmicpc.net/problem/2583
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int inputM, inputN, inputK;
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};
vector<int> answer;
int countNum = 0;

bool isBoundary(int x, int y) {
	bool check = true;
	if (x < 0 || x >= inputM || y < 0 || y >= inputN)
		check = false;
	return check;
}

void dfs(vector<vector<bool> > &map, int x, int y) {
	countNum++;
	map[x][y] = false;

	for (int i = 0; i < 4; i++) {
		int new_x = x + dir_x[i], new_y = y + dir_y[i];
		if (isBoundary(new_x, new_y) && map[new_x][new_y])
			dfs(map, new_x, new_y);
	}
}

int main()
{
	cin >> inputM >> inputN >> inputK;
	vector<vector<bool> > map(inputM, vector<bool>(inputN, true));

	for (int i = 0; i < inputK; i++) {
		int start_x, start_y, end_x, end_y;
		cin >> start_y >> start_x >> end_y >> end_x;

		for (int x = start_x; x < end_x; x++)
			for (int y = start_y; y < end_y; y++)
				map[x][y] = false;
	}

	for (int x = 0; x < inputM; x++) {
		for (int y = 0; y < inputN; y++) {
			if (map[x][y]) {
				countNum = 0;
				dfs(map, x, y);
				answer.push_back(countNum);
			}
		}
	}

	sort(answer.begin(), answer.end());
	cout<<answer.size()<<endl;

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	cout << endl;

	return 0;
}