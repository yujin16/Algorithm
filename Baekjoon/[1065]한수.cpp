/* 1065¹ø ÇÑ¼ö
 * https://www.acmicpc.net/problem/1065
 */

#include <iostream>
using namespace std;

int main() {
	int inputN = 0, result = 0;
	cin >> inputN;

	if (inputN < 100)
		result = inputN;
	else {
		result = 99;
		for (int i = 111; i <= inputN; i++) {
			int firstNum = i / 100;
			int secondNum = i % 100 / 10;
			int thirdNum = i % 10;
			if (firstNum - secondNum == secondNum - thirdNum)
				result++;
		}
	}

	cout << result << endl;
	return 0;
}