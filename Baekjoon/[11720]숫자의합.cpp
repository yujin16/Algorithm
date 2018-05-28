/* 11720번 숫자의 합
 * https://www.acmicpc.net/problem/11720
 */

#include <iostream>
using namespace std;

int main() {
	int n = 0, num = 0, sum = 0;
	std::cin >> n;
	getchar();
	for (int i = 0; i<n; i++)
		sum += getchar() - '0';
	std::cout << sum;
	return 0;
}