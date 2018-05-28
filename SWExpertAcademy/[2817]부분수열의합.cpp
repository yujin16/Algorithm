/* 2817번 부분 수열의 합
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
int inputN, inputK;

void dfs(vector<int> &inputArr, int index, int sum) {
	if (sum > inputK) return;
	if (sum == inputK) {
		answer++;
		return;
	}
	if (index >= inputN) return;

	dfs(inputArr, index + 1, sum);
	dfs(inputArr, index + 1, sum + inputArr[index]);
}

int main() {
	int testcase;
	cin >> testcase;

	for (int t = 1; t <= testcase; t++) {
		cin >> inputN >> inputK;

		vector<int> inputArr(inputN, 0);
		for (int i = 0; i < inputN; i++)
			cin >> inputArr[i];

		answer = 0;
		dfs(inputArr, 0, 0);

		cout << "#" << t << " " << answer << endl;
	}
	return 0;
}