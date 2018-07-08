/* 13458번 시험감독(BruteForce)
 * https://www.acmicpc.net/problem/13458
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int placeNum = 0, inputB = 0, inputC = 0;
	long long result = 0;
	cin >> placeNum;
	vector<int> examinees(placeNum, 0);

	for (int i = 0; i < placeNum; i++)
		cin >> examinees[i];
	cin >> inputB >> inputC;

	for (int i = 0; i < placeNum; i++) {
		int examinee = examinees[i];
		examinee -= inputB;
		result += 1;
		if (examinee>0)
			result += (examinee + inputC - 1) / inputC;
	}

	cout << result;
	return 0;
}