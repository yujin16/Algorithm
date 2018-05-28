/* 2331번 반복수열
 * https://www.acmicpc.net/problem/2331
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int inputA = 0, inputP = 0, result = 0;
	cin >> inputA >> inputP;
	vector<int> num;

	num.push_back(inputA);
	bool find = false;
	while (!find) {
		int cal = 0, pos = num.size(), n = num[pos - 1];

		while (n > 0) {
			cal += pow(n % 10, inputP);
			n /= 10;
		}
		num.push_back(cal);

		for (int i = 0; i < pos && !find; i++) {
			if (num[i] == cal) {
				result = i;
				find = true;
			}
		}
	}

	cout << result << endl;
	return 0;
}