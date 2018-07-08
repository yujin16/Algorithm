/* 13398번 연속합2(Dynamic Programming)
 * https://www.acmicpc.net/problem/13398
 */

#include <iostream>
#include <climits>
#include <vector>
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
using namespace std;

int main() {
	int inputN = 0, max_sum = INT_MIN;
	cin >> inputN;
	vector<int> dp(inputN, 0);
	vector<pair<int, int> > sum(inputN, pair<int, int>());

	for (int i = 0; i < inputN; i++)
		cin >> dp[i];

	sum[0] = make_pair(dp[0], 0);
	max_sum = dp[0];
	for (int i = 1; i < inputN; i++) {
		sum[i].first = MAX(dp[i], sum[i - 1].first + dp[i]);
		sum[i].second = MAX(sum[i - 1].second + dp[i], sum[i - 1].first);
		max_sum = MAX(max_sum, MAX(sum[i].first, sum[i].second));
	}

	cout << max_sum << endl;
	return 0;
}