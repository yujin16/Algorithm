/* 11057번 오르막수
 * https://www.acmicpc.net/problem/11057
 */

#include <iostream>
#include <vector>
using namespace std;;

int main() {
	int inputN = 0;
	cin >> inputN;
	vector<vector<int> > dp(inputN, vector<int>(10, 0));

	for (int i = 0; i < 10; i++)
		dp[0][i] = 1;

	for (int i = 1; i < inputN; i++) {
		for (int j = 0; j < 10; j++) {
			int sum = 0;
			for (int k = j; k < 10; k++)
				sum += dp[i - 1][k] % 10007;
			dp[i][j] = sum % 10007;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[inputN - 1][i];
		sum %= 10007;
	}

	cout << sum << endl;
	return 0;
}