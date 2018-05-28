/* 2819번 격자판의 숫자 이어 붙이기
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7I5fgqEogDFAXB
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

int main() {
	int inputT = 0;
	cin >> inputT;

	for (int t = 0; t < inputT; t++) {
		vector<vector<int> > map(4, vector<int>(4, 0));
		vector<int> numArr;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> map[i][j];

		stack<pair<int, int> > pointStack;	// x좌표, y좌표
		stack<pair<int, int> > countStack;	// num, moveCount(depth)
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				pointStack.push(make_pair(i, j));
				countStack.push(make_pair(map[i][j], 1));
				while (!pointStack.empty() && !countStack.empty()) {
					int x = pointStack.top().first, y = pointStack.top().second;
					int num = countStack.top().first, move = countStack.top().second;
					pointStack.pop();
					countStack.pop();

					if (move == 7) {
						numArr.push_back(num);
						//cout << num << endl;
						continue;
					}

					for (int k = 0; k < 4; k++) {
						int newX = x + dir_x[k], newY = y + dir_y[k];
						if (newX >= 0 && newX < 4 && newY >= 0 && newY < 4) {
							int newNum = num * 10 + map[newX][newY];
							pointStack.push(make_pair(newX, newY));
							countStack.push(make_pair(newNum, move + 1));
						}
					}
				}
			}
		}

		sort(numArr.begin(), numArr.end());
		numArr.erase(unique(numArr.begin(), numArr.end()), numArr.end());

		cout << "#" << t + 1 << " " << numArr.size() << endl;
	}

	return 0;
}