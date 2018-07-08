/* 1493번 수의새로운연산
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> map;

int sharp(int x, int y) {
	int index = x + y - 1;
	return map[index] + index - y;
}

int binarySearch(int start_index, int end_index, int find_num) {
	if (end_index - start_index == 1) return start_index;

	int center_index = (end_index + start_index + 1) / 2;
	int value = map[center_index];

	if (find_num < value) return binarySearch(start_index, center_index, find_num);
	else if (find_num == value) return center_index;
	else return binarySearch(center_index, end_index, find_num);
}

pair<int, int> ampersand(int num) {
	int index = binarySearch(1, map.size() - 1, num);

	int x = 1 + (num - map[index]);
	int y = index - (num - map[index]);
	return make_pair(x, y);
}

int main() {
	int testcase;
	cin >> testcase;

	map.push_back(1);
	int last_num = 1;
	for (int i = 1; i <= 500; i++) {
		last_num += i - 1;
		map.push_back(last_num);
	}

	for (int t = 0; t < testcase; t++) {
		int result = 0, inputA, inputB;
		cin >> inputA >> inputB;

		pair<int, int> a = ampersand(inputA);
		pair<int, int> b = ampersand(inputB);

		result = sharp(a.first + b.first, a.second + b.second);
		cout << "#" << t + 1 << " " << result << endl;
	}
	return 0;
}