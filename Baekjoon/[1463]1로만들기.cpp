/* 1463번 1로 만들기
 * https://www.acmicpc.net/problem/1463
 */

#include <iostream>
#include <vector>
#include <climits>
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
using namespace std;

int main() {
	int inputN = 0;
	cin >> inputN;
	vector<int> dp(inputN + 1, INT_MAX);

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= inputN; i++) {
		int nextIndex = i;
		if (i % 3 == 0)
			if (dp[nextIndex] > dp[i / 3])
				nextIndex = i / 3;
		if (i % 2 == 0)
			if (dp[nextIndex] > dp[i / 2])
				nextIndex = i / 2;
		if (dp[nextIndex] > dp[i - 1])
			nextIndex = i - 1;

		dp[i] = dp[nextIndex] + 1;
	}

	cout << dp[inputN] << endl;
	return 0;
}