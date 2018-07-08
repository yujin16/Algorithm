/* 11718번 그대로출력하기(Input/Output)
 * https://www.acmicpc.net/problem/11718
 */

#include <iostream>

int main() {
	char c = 0;
	c = getchar();
	while (c != -1) {
		printf("%c", c);
		c = getchar();
	}
	return 0;
}