/* 1206¹ø View
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <vector>
#define MAX(X,Y) ((X)>(Y)? (X):(Y))
using namespace std;

int dir[4] = { -2, -1, 1, 2 };

int main() {
	for (int t = 0; t < 10; t++) {
		int inputS = 0;
		cin >> inputS;
		vector<int> map(inputS, 0);

		for (int i = 0; i < inputS; i++)
			cin >> map[i];

		int count = 0;
		for (int i = 2; i < inputS - 2; i++) {
			int len = -1;
			bool success = true;
			for (int j = 0; j < 4 && success; j++) {
				if (map[i + dir[j]] < map[i])
					len = MAX(len, map[i + dir[j]]);
				else
					success = false;

			}
			if (success)
				count += map[i] - len;
		}
		cout << "#" << t + 1 << " " << count << endl;
	}
	return 0;
}