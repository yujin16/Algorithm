/* 2156번 포도주시식(Dynamic Programming)
 * https://www.acmicpc.net/problem/2156
 */

#include <iostream>
#include <vector>
#define MAX(X, Y) ((X)>(Y)? (X):(Y))
using namespace std;

int main() {
	int inputN = 0, result = 0;
	cin >> inputN;
	vector<int> input(inputN, 0);
	vector<pair<int, int> > dp(inputN, pair<int, int>(0, 0));

	for (int i = 0; i < inputN; i++)
		cin >> input[i];

	dp[0] = make_pair(input[0], 0);
	result = dp[0].first;
	if (inputN > 1) {
		dp[1] = make_pair(input[0] + input[1], input[0]);
		result = dp[1].first;
	}

	for (int i = 2; i < inputN; i++) {
		dp[i].first = MAX(dp[i - 2].first, dp[i - 2].second + input[i - 1]) + input[i];
		dp[i].second = MAX(dp[i - 1].first, dp[i - 1].second);
		result = MAX(dp[i].first, dp[i].second);
	}

	cout << result << endl;
	return 0;
}