/* 1110번 더하기 사이클
 * https://www.acmicpc.net/problem/1110
 */

#include <iostream>
using namespace std;

int main() {
	int num = 0, n1 = 0, n2 = 0, n3 = 0, result = 0;
	std::cin >> num;
	n3 = num;
	do {
		n1 = n3 / 10;
		n2 = n3 % 10;
		n3 = n2 * 10 + (n1 + n2) % 10;
		result++;
	} while (num != n3);
	std::cout << result;
	return 0;
}