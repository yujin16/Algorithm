/* 1486번 장훈이의높은선반
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <vector>
#define MAX(X,Y) (X)>(Y)? (X):(Y)
using namespace std;

int inputN, inputB, result = 0;
int sum = 0, sub = 0;

void dfs(vector<int> &height, int index, int height_sum) {
	if (height_sum <= sub)
		result = MAX(result, height_sum);
	if (index >= inputN) return;

	dfs(height, index + 1, height_sum);
	height_sum += height[index];
	if (height_sum <= sub)
		dfs(height, index + 1, height_sum);
}

int main() {
	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		result = 0, sum = 0;
		cin >> inputN >> inputB;

		vector<int> height(inputN, 0);
		for (int i = 0; i < inputN; i++) {
			int node;
			cin >> node;
			height[i] = node;
			sum += node;
		}
		sub = sum - inputB;

		dfs(height, 0, 0);
		cout << "#" << t + 1 << " " << sub - result << endl;
	}
	return 0;
}