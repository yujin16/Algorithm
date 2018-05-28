/* 8393Йј Че
 * https://www.acmicpc.net/problem/8393
 */

#include <iostream>
using namespace std;

int main() {
	int n = 0, sum = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		sum += i;
	std::cout << sum;
	return 0;
}