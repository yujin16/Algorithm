/* 11721번 열개씩끊어출력하기(Input/Output)
 * https://www.acmicpc.net/problem/11721
 */

#include <iostream>
using namespace std;

int main() {
	char *ch = (char*)calloc(100, sizeof(char));
	std::cin >> ch;

	int current = 0;
	while (ch[current] != '\0') {
		std::cout << ch[current++];
		if (current % 10 == 0)
			std::cout << endl;
	}
	free(ch);
	return 0;
}