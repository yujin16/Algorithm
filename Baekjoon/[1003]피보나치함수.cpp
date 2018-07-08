/* 1003번 피보나치함수(Dynamic Programming)
 * https://www.acmicpc.net/problem/1003
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int inputT = 0;
	vector<pair<int, int> > fibonacci(41, pair<int, int>(-1, -1));
	fibonacci[0].first = 1;
	fibonacci[0].second = 0;
	fibonacci[1].first = 0;
	fibonacci[1].second = 1;

	cin >> inputT;
	for (int i = 0; i < inputT; i++) {
		int inputN = 0;
		cin >> inputN;

		for (int j = 2; j <= inputN; j++) {
			if (fibonacci[j].first == -1 && fibonacci[j].second == -1) {
				fibonacci[j].first = fibonacci[j - 1].first + fibonacci[j - 2].first;
				fibonacci[j].second = fibonacci[j - 1].second + fibonacci[j - 2].second;
			}
		}
		cout << fibonacci[inputN].first << " " << fibonacci[inputN].second << endl;
	}
	return 0;
}