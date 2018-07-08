/* 10817번 세수(Input/Output)
 * https://www.acmicpc.net/problem/10817
 */

#include <iostream>
using namespace std;

int main() {
	int n1 = 0, n2 = 0, n3 = 0;
	std::cin >> n1 >> n2 >> n3;
	if (n1 >= n2) {
		if (n3 >= n1)
			std::cout << n1;
		else if (n2 >= n3)
			std::cout << n2;
		else
			std::cout << n3;
	}
	else {
		if (n3 >= n2)
			std::cout << n2;
		else if (n3 >= n1)
			std::cout << n3;
		else
			std::cout << n1;
	}
	return 0;
}