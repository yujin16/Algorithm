/* 1244번 최대 상금
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <vector>
#include <cstring>
#define MAX(X,Y) ((X)>(Y))? (X):(Y)
using namespace std;

int result = 0;
int change = 0;
void swap(char* number, int x, int y) {
	char tmp = number[x];
	number[x] = number[y];
	number[y] = tmp;
}

void prize(vector<int> &check, char* number, int c) {
	int size = strlen(number);

	int n = atoi(number);
	check[n]++;

	if (check[n] > 100) return;
	if (change == c) {
		result = MAX(result, n);
		return;
	}

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (number[i] == number[j]) continue;
			swap(number, i, j);
			prize(check, number, c + 1);
			swap(number, i, j);
		}
	}
}

int main() {
	int Testcase = 0;
	cin >> Testcase;

	for (int t = 0; t < Testcase; t++) {
		char number[6];
		cin >> number >> change;

		vector<int> check(1000000, 0);
		result = 0;
		prize(check, number, 0);

		cout << "#" << t + 1 << " " << result << endl;
	}
	return 0;
}