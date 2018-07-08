/* 2858번 기숙사바닥(BruteForce)
 * https://www.acmicpc.net/problem/2858
 */

#include <iostream>
using namespace std;

int main() {
	int red, brown;
	cin >> red >> brown;

	int outputL, outputW;
	for (outputL = brown; outputL > 0; outputL--) {
		if (brown%outputL == 0) {
			outputW = brown / outputL;
			int sum = (outputL + outputW) * 2;
			if (red - 4 == sum) {
				cout << outputL + 2 << " " << outputW + 2 << endl;
				return 0;
			}
		}
	}

	return 0;
}