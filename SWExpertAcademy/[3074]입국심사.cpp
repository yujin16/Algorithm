/* 3074번 입국심사
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcase = 0;
	cin >> testcase;

	for (int t = 1; t <= testcase; t++) {
		int inputN, inputM;
		cin >> inputN >> inputM;

		vector<int> time_arr(inputN, 0);
		for (int i = 0; i < inputN; i++)
			cin >> time_arr[i];

		long long low = 0;
		long long high = 1000000000000000000;
		long long mid = 0;
		long long people_count = 0;
		while (true) {
			people_count = 0;
			mid = (low + high) / 2;

			for (int i = 0; i < inputN; i++)
				people_count += mid / time_arr[i];

			if (high <= low) {
				cout << "#" << t << " " << mid << endl;
				break;
			}

			if (inputM <= people_count)
				high = mid;
			else if (people_count <= inputM)
				low = mid + 1;
		}
	}
	return 0;
}