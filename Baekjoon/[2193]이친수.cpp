/* 2193번 이친수
 * https://www.acmicpc.net/problem/2193
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int inputN = 0;
	cin >> inputN;
	vector<long long> dp(inputN, 0);

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < inputN; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[inputN - 1] << endl;
	return 0;
}