/* 9465번 스티커(Dynamic Programming)
 * https://www.acmicpc.net/problem/9465
 */

#include <iostream>
#include <vector>
#define MAX(X, Y) ((X)>(Y)? (X):(Y))
using namespace std;

int main() {
	int inputT = 0, inputN = 0;
	cin >> inputT;

	for (int t = 0; t < inputT; t++) {
		cin >> inputN;
		vector<vector<int> > dp(2, vector<int>(inputN, 0));
		vector<vector<int> > scoreSum(2, vector<int>(inputN, 0));
		vector<int> scoreMax(inputN, 0);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < inputN; j++)
				cin >> dp[i][j];

		scoreSum[0][0] = dp[0][0];
		scoreSum[1][0] = dp[1][0];
		scoreMax[0] = MAX(scoreSum[0][0], scoreSum[1][0]);
		if (inputN > 1) {
			scoreSum[0][1] = dp[0][1] + dp[1][0];
			scoreSum[1][1] = dp[1][1] + dp[0][0];
			scoreMax[1] = MAX(scoreSum[0][1], scoreSum[1][1]);

			for (int i = 2; i < inputN; i++) {
				scoreSum[0][i] = dp[0][i] + MAX(scoreSum[1][i - 1], scoreMax[i - 2]);
				scoreSum[1][i] = dp[1][i] + MAX(scoreSum[0][i - 1], scoreMax[i - 2]);
				scoreMax[i] = MAX(scoreSum[0][i], scoreSum[1][i]);
			}
		}

		cout << scoreMax[inputN - 1] << endl;
	}

	return 0;
}