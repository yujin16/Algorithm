/* 1932번 정수 삼각형
 * https://www.acmicpc.net/problem/1932
 */

#include <iostream>
#include <vector>
#define MAX(X, Y) ((X)>(Y)? (X):(Y))
using namespace std;

int main() {
	int inputN = 0;
	cin >> inputN;
	vector<vector<int> > dp(inputN, vector<int>(inputN, 0));
	vector<vector<int> > sum(inputN, vector<int>(inputN, 0));

	for (int i = 0; i < inputN; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> dp[i][j];

	sum[0][0] = dp[0][0];
	for (int i = 1; i < inputN; i++) {
		for (int j = 0; j < i + 1; j++) {
			int node1 = 0, node2 = 0;
			if (j - 1 >= 0) node1 = sum[i - 1][j - 1];
			if (j <= i - 1) node2 = sum[i - 1][j];
			sum[i][j] = MAX(node1, node2) + dp[i][j];
		}
	}

	int max = 0;
	for (int i = 0; i < inputN; i++)
		max = MAX(max, sum[inputN - 1][i]);

	cout << max << endl;
	return 0;
}