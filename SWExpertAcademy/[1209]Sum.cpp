/* 1209번 Sum
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <vector>
#define MAX(X,Y) (X)>(Y)? (X):(Y)
using namespace std;

int main() {
	for (int t = 0; t < 10; t++) {
		int testcase, result = 0;
		cin >> testcase;

		vector<vector<int> > map(100, vector<int>(100, 0));
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> map[i][j];

		int diagonal_right = 0, diagonal_left = 0;
		for (int i = 0; i < 100; i++) {
			int width = 0, height = 0;
			for (int j = 0; j < 100; j++) {
				width += map[i][j];
				height += map[j][i];
				if (i == j)diagonal_right += map[i][j];
				if (i + j == 99) diagonal_left += map[i][j];
			}
			result = MAX(result, MAX(width, height));
		}
		result = MAX(result, MAX(diagonal_left, diagonal_right));

		cout << "#" << testcase << " " << result << endl;
	}
	return 0;
}