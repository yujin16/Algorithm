/* 1398번 동전문제
 * https://www.acmicpc.net/problem/1398
 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int inputT = 0;
	long long inputN = 0;
	cin >> inputT;

	for (int i = 0; i < inputT; i++) {
		int countCoin = 0;
		cin >> inputN;

		for (int j = 15; j >= 0; j--) {
			long long coin10 = pow(10, j);
			long long coin25 = 1;
			if (j % 2 == 1 && j != 15)
				coin25 = pow(10, j - 1) * 25;

			if (inputN / coin10 == 0)
				continue;
			if (coin10 == coin25) {
				countCoin += inputN;
				break;
			}

			int coin25Num = 0;
			for (int k = 0; k <= inputN / coin25 && coin25 != 1; k++)
				if ((inputN - (coin25*coin25Num)) % coin10 >= (inputN - (coin25*k)) % coin10)
					coin25Num = k;
			countCoin += coin25Num;
			inputN -= coin25*coin25Num;
			countCoin += inputN / coin10;
			inputN = inputN%coin10;
		}
		cout << countCoin << endl;
	}
	return 0;
}