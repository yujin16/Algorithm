/* 1208번 Flatton
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcase = 10;
	for (int t = 1; t <= testcase; t++) {
		int dump = 0;
		cin >> dump;

		vector<int> map(101, 0);
		for (int i = 0; i < 100; i++) {
			int height = 0;
			cin >> height;
			map[height]++;
		}

		bool finish = false;
		while (dump > 0 && !finish) {
			int min_index = 1, max_index = 1;
			for (int i = 1; i <= 100; i++)
				if (map[i] != 0) { min_index = i; break; }
			for (int i = 100; i >= 1; i--)
				if (map[i] != 0) { max_index = i; break; }

			int sub = max_index - min_index;
			if (sub == 0 || sub == 1) {
				finish = true;
				break;
			}

			map[min_index]--;
			map[min_index + 1]++;
			map[max_index]--;
			map[max_index - 1]++;
			dump--;
		}

		int min_index = 1, max_index = 1;
		for (int i = 1; i <= 100; i++)
			if (map[i] != 0) { min_index = i; break; }
		for (int i = 100; i >= 1; i--)
			if (map[i] != 0) { max_index = i; break; }

		cout << "#" << t << " " << max_index - min_index << endl;
	}
	return 0;
}