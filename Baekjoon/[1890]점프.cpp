/* 1890번 점프(Dynamic Programming)
 * https://www.acmicpc.net/problem/1890
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int inputN = 0;
	cin >> inputN;
	vector<vector<long long> > map(inputN, vector<long long>(inputN, 0));
	vector<vector<long long> > dp(inputN, vector<long long>(inputN, 0));

	for (int i = 0; i < inputN; i++)
		for (int j = 0; j < inputN; j++)
			cin >> map[i][j];

	if (map[0][0] < inputN) {
		dp[map[0][0]][0]++;
		dp[0][map[0][0]]++;
	}

	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputN; j++) {
			if (dp[i][j] != 0 && map[i][j] != 0) {
				long long jump = map[i][j];

				if (i + jump < inputN)
					dp[i + jump][j] += dp[i][j];
				if (j + jump < inputN)
					dp[i][j + jump] += dp[i][j];
			}
		}
	}

	cout << dp[inputN - 1][inputN - 1] << endl;
	return 0;
}