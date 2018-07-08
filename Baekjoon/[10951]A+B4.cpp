/* 10951번 A+B4(Input/Output)
 * https://www.acmicpc.net/problem/10951
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int num1, num2;
	while (scanf("%d %d", &num1, &num2) != EOF)
		printf("%d\n", num1 + num2);
	return 0;
}