/* 3143번 가장빠른문자열타이핑
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		string inputA, inputB;
		cin >> inputA >> inputB;

		while (true) {
			int index = inputA.find(inputB);
			if (index == string::npos) break;

			inputA.replace(index, inputB.length(), "!");
		}

		cout << "#" << t + 1 << " " << inputA.length() << endl;
	}

	return 0;
}