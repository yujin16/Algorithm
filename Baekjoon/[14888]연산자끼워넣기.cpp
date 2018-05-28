/* 14888번 연산자 끼워넣기
 * https://www.acmicpc.net/problem/14888
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define MAX(X,Y) ((X)>(Y))? (X):(Y);
#define MIN(X,Y) ((X)<(Y))? (X):(Y);
using namespace std;

int main() {
	enum { SUM, SUB, MUL, DEV };
	vector<int> numbers;
	vector<int> operators;
	int input = 0;
	cin >> input;

	for (int i = 0; i < input; i++) {
		int newNum = 0;
		cin >> newNum;
		numbers.push_back(newNum);
	}

	for (int i = 0; i < 4; i++) {
		int operNum = 0;
		cin >> operNum;
		for (int j = 0; j<operNum; j++)
			operators.push_back(i);
	}

	int maxNum = INT_MIN;
	int minNum = INT_MAX;
	do {
		int result = numbers[0];
		for (int i = 0; i < operators.size(); i++) {
			switch (operators[i]) {
			case SUM: result += numbers[i + 1]; break;
			case SUB: result -= numbers[i + 1]; break;
			case MUL: result *= numbers[i + 1]; break;
			case DEV: result /= numbers[i + 1]; break;
			}
		}
		maxNum = MAX(maxNum, result);
		minNum = MIN(minNum, result);
	} while (next_permutation(operators.begin(), operators.end()));

	cout << maxNum << "\n" << minNum;
	return 0;
}