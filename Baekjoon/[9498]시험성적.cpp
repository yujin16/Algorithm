/* 9498번 시험성적(Input/Output)
 * https://www.acmicpc.net/problem/9498
 */

#include <iostream>
using namespace std;

int main() {
	int n = 0;
	std::cin >> n;

	if (90 <= n && 100 >= n)
		std::cout << "A";
	else if (80 <= n && 90>n)
		std::cout << "B";
	else if (70 <= n && 80>n)
		std::cout << "C";
	else if (60 <= n && 70>n)
		std::cout << "D";
	else
		std::cout << "F";
	return 0;
}