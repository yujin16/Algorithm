/* 11726번 2xn 타일링
 * https://www.acmicpc.net/problem/11726
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int inputN = 0;
	cin >> inputN;
	vector<int> dp(inputN, 0);

	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i < inputN; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	cout << dp[inputN - 1] << endl;
	return 0;
}