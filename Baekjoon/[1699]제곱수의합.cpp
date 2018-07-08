/* 1699번 제곱수의합(Dynamic Programming)
 * https://www.acmicpc.net/problem/1699
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#define MIN(X,Y) ((X)<(Y)? (X):(Y))
using namespace std;

int main() {
	int inputN = 0;
	cin >> inputN;
	vector<int> dp(inputN + 1, INT_MAX);

	for (int i = 1; i*i <= inputN; i++)
		dp[i*i] = 1;

	for (int i = 1; i <= inputN; i++) {
		int root = (int)sqrt(i);
		if (i != root*root)
			for (int j = root; j > 0; j--)
				dp[i] = MIN(dp[i], dp[j*j] + dp[i - j*j]);
	}

	cout << dp[inputN] << endl;
	return 0;
}