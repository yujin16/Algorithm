/* 1546¹ø Æò±Õ
 * https://www.acmicpc.net/problem/1546
 */

#include <iostream>
using namespace std;

int main() {
	int n = 0, num = 0, max = 0, sum = 0;
	std::cin >> n;

	for (int i = 0; i<n; i++) {
		std::cin >> num;
		if (max <= num)
			max = num;
		sum += num;
	}
	double result = (double)sum / max * 100 / n;
	std::cout << result;
	return 0;
}