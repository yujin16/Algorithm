/* 2439번 별찍기2(Input/Output)
 * https://www.acmicpc.net/problem/2439
 */

#include <iostream>
using namespace std;

int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		for (int j = n; j>i + 1; j--)
			printf(" ");
		for (int j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}