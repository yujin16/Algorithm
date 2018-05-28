/* 14890번 경사로
 * https://www.acmicpc.net/problem/14890
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int inputN, inputL, result = 0;
	cin >> inputN >> inputL;

	vector<vector<int> > map(inputN, vector<int>(inputN, 0));
	for (int i = 0; i < inputN; i++)
		for (int j = 0; j < inputN; j++)
			cin >> map[i][j];

	for (int n = 0; n < inputN; n++) {
		vector<bool> bridge1(inputN, true);
		int high = map[n][0];
		bool success = true;

		for (int i = 1; i < inputN && success; i++) {
			if (map[n][i] == high) continue;
			else if (map[n][i] > high) {
				if (map[n][i] - high != 1) { success = false; break; }
				for (int j = 1; j <= inputL && success; j++) {
					if (i - j < 0) { success = false; break; }
					if (map[n][i - j] != high) { success = false; break; }
					if (!bridge1[i - j]) { success = false; break; }
					bridge1[i - j] = false;
				}
				high = map[n][i];
			}
			else if (map[n][i] < high) {
				if (high - map[n][i] != 1) { success = false; break; }
				high = map[n][i];
				bridge1[i] = false;
				for (int j = 1; j < inputL && success; j++) {
					if (++i >= inputN) { success = false; break; }
					if (map[n][i] != high) { success = false; break; }
					if (!bridge1[i]) { success = false; break; }
					bridge1[i] = false;
				}
			}
		}

		if (success) result++;

		vector<bool> bridge2(inputN, true);
		high = map[0][n];
		success = true;
		for (int i = 1; i < inputN && success; i++) {
			if (map[i][n] == high) continue;
			else if (map[i][n] > high) {
				if (map[i][n] - high != 1) { success = false; break; }
				for (int j = 1; j <= inputL && success; j++) {
					if (i - j < 0) { success = false; break; }
					if (map[i - j][n] != high) { success = false; break; }
					if (!bridge2[i - j]) { success = false; break; }
					bridge2[i - j] = false;
				}
				high = map[i][n];
			}
			else if (map[i][n] < high) {
				if (high - map[i][n] != 1) { success = false; break; }
				high = map[i][n];
				bridge2[i] = false;
				for (int j = 1; j < inputL && success; j++) {
					if (++i >= inputN) { success = false; break; }
					if (map[i][n] != high) { success = false; break; }
					if (!bridge2[i]) { success = false; break; }
					bridge2[i] = false;
				}
			}
		}

		if (success) result++;
	}



	cout << result << endl;
	return 0;
}