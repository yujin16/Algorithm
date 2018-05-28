/* 10844번 쉬운 계단수
 * https://www.acmicpc.net/problem/10844
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int inputN = 0;
	cin >> inputN;
	vector<vector<long long> > dp(inputN, vector<long long>(10, 0));

	for (int i = 1; i <= 9; i++)
		dp[0][i] = 1;

	for (int i = 1; i < inputN; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[inputN - 1][i];
		sum %= 1000000000;
	}

	cout << sum << endl;
	return 0;
}