/* 2441번 별찍기4(Input/Output)
 * https://www.acmicpc.net/problem/2441
 */

#include <iostream>
using namespace std;

int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = n; i>0; i--) {
		for (int j = n - i; j>0; j--)
			printf(" ");
		for (int j = i; j>0; j--)
			printf("*");
		printf("\n");
	}
	return 0;
}