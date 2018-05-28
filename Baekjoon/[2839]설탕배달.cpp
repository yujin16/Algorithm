/* 2839번 설탕 배달
 * https://www.acmicpc.net/problem/ 2839
 */

#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int k = 0;
	std::cin >> k;
	int a = k / 5;
	for (int i = a; i >= 0; i--) {
		int g = k - i * 5;
		if (g % 3 == 0) {
			sum = i + g / 3;
			break;
		}
	}
	if (sum == 0)
		sum = -1;

	std::cout << sum;
	return 0;
}