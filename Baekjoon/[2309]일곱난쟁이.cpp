/* 2309¹ø ÀÏ°ö ³­ÀïÀÌ
 * https://www.acmicpc.net/problem/2309
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int sum = 0;
	vector<int> height(9, 0);
	vector<int> dwarf;
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}

	int i, j;
	bool find = false;
	for (i = 0; i < 8 && !find; i++)
		for (j = i + 1; j < 9 && !find; j++)
			if (sum - 100 == height[i] + height[j])
				find = true;

	for (int k = 0; k < 9; k++)
		if (k != i - 1 && k != j - 1)
			dwarf.push_back(height[k]);

	sort(dwarf.begin(), dwarf.end());
	for (int k = 0; k < 7; k++)
		cout << dwarf[k] << endl;

	return 0;
}