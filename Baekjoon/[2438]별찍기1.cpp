/* 2438�� �����1
 * https://www.acmicpc.net/problem/2438
 */

#include <iostream>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<i + 1; j++)
			cout << "*";
		cout << endl;
	}
	return 0;
}