/* 2739번 구구단
 * https://www.acmicpc.net/problem/2739
 */

#include <iostream>
using namespace std;

int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i<10; i++)
		printf("%d * %d = %d\n", n, i, n*i);
	return 0;
}