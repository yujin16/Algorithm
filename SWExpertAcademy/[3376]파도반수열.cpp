/* 3376번 파도반수열
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		int inputN;
		cin >> inputN;

		vector<long long> arr_p(101, 0);
		arr_p[1] = 1;
		arr_p[2] = 1;
		arr_p[3] = 1;
		arr_p[4] = 2;
		arr_p[5] = 2;
		for (int i = 6; i <= inputN; i++)
			arr_p[i] = arr_p[i - 1] + arr_p[i - 5];

		cout << "#" << t + 1 << " " << arr_p[inputN] << endl;
	}
	return 0;
}