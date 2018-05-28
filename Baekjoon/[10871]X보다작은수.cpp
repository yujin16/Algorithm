/* 10871번 x보다 작은 수
 * https://www.acmicpc.net/problem/10871
 */

#include <iostream>
using namespace std;

int main() {
	int n = 0, x = 0, k = 0;
	std::cin >> n >> x;

	for (int i = 0; i<n; i++) {
		std::cin >> k;
		if (k<x)
			std::cout << k << " ";
	}
	return 0;
}