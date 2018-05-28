/* 9096번 1, 2, 3 더하기
 * https://www.acmicpc.net/problem/9095
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int inputT = 0, result = 0;
	vector<int> dp(12, 0);
	cin >> inputT;

	dp[0] = 1;
	for (int i = 1; i <= 11; i++) {
		if (i - 1 >= 0)
			dp[i] += dp[i - 1];
		if (i - 2 >= 0)
			dp[i] += dp[i - 2];
		if (i - 3 >= 0)
			dp[i] += dp[i - 3];
	}

	for (int i = 0; i < inputT; i++) {
		int inputN;
		cin >> inputN;
		cout << dp[inputN] << endl;
	}
	return 0;
}