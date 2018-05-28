/* 11048번 이동하기
 * https://www.acmicpc.net/problem/11048
 */

#include <iostream>
#include <vector>
#define MAX(X,Y) ((X)>(Y)? (X):(Y))
using namespace std;

int main() {
	int inputN = 0, inputM = 0;
	cin >> inputN >> inputM;
	vector<vector<int> > map(inputN, vector<int>(inputM, 0));

	for (int i = 0; i < inputN; i++)
		for (int j = 0; j < inputM; j++)
			cin >> map[i][j];

	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputM; j++) {
			int max = 0;
			if (i - 1 >= 0)
				max = MAX(max, map[i - 1][j]);
			if (j - 1 >= 0)
				max = MAX(max, map[i][j - 1]);
			if (i - 1 >= 0 && j - 1 >= 0)
				max = MAX(max, map[i - 1][j - 1]);
			map[i][j] = map[i][j] + max;
		}
	}

	cout << map[inputN - 1][inputM - 1] << endl;
	return 0;
}