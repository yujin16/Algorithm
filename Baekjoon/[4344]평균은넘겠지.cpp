/* 4344번 평균은넘겠지(BruteForce)
 * https://www.acmicpc.net/problem/4344
 */

#include <iostream>
using namespace std;

int main() {
	int n1 = 0, n2 = 0, n3 = 0, n4 = 0, sum = 0;
	std::cin >> n1;

	for (int i = 0; i<n1; i++) {
		sum = 0;
		std::cin >> n2;
		int *num = (int*)malloc(sizeof(int)*n2);
		for (int j = 0; j < n2; j++) {
			std::cin >> n3;
			num[j] = n3;
			sum += n3;
		}
		n4 = 0;
		for (int j = 0; j < n2; j++)
			if (num[j] > sum / n2)
				n4++;
		free(num);

		printf("%.3lf%%\n", (double)n4 / n2 * 100);
	}
	return 0;
}