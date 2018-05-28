/* 11053번 가장 긴 증가하는 부분수열
 * https://www.acmicpc.net/problem/11053
 */

#include <iostream>
#include <vector>
#define MAX(X,Y) ((X)>(Y)? (X):(Y))
using namespace std;

int main() {
	int inputN = 0, result = 0;
	cin >> inputN;
	vector<int> input(inputN, 0);
	vector<int> dp(inputN, 0);

	for (int i = 0; i < inputN; i++)
		cin >> input[i];

	for (int i = 0; i < inputN; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (input[j] < input[i])
				dp[i] = MAX(dp[i], dp[j] + 1);
		result = MAX(result, dp[i]);
	}

	cout << result << endl;
	return 0;
}