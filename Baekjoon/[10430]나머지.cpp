/* 10430번 나머지
 * https://www.acmicpc.net/problem/10430
 */

#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0, c = 0;
	std::cin >> a >> b >> c;
	std::cout << (a + b) % c << endl;
	std::cout << (a%c + b%c) % c << endl;
	std::cout << (a*b) % c << endl;
	std::cout << ((a%c)*(b%c)) % c << endl;

	return 0;
}