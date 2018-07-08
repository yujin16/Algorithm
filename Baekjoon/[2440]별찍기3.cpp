/* 2440번 별찍기3(Input/Output)
 * https://www.acmicpc.net/problem/2440
 */

#include <iostream>
using namespace std;

int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = n; i>0; i--) {
		for (int j = i; j>0; j--)
			printf("*");
		printf("\n");
	}
	return 0;
}