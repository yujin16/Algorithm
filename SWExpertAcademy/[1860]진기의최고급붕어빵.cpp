/* 1860번 진기의 최고급 붕어빵
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <vector>
#define MAX(X,Y) (X)>(Y)? (X):(Y)
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int t = 0; t < testcase; t++) {
		int max_time = 0, inputN, inputM, inputK;
		cin >> inputN >> inputM >> inputK;
		vector<int> person(11112, 0);

		for (int i = 0; i < inputN; i++) {
			int time;
			cin >> time;
			person[time]++;
			max_time = MAX(max_time, time);
		}

		/*for (int i = 0; i <= max_time; i++) {
		cout << person[i] << " ";
		}
		cout << endl;*/

		int bread = 0;
		bool success = true;
		for (int i = 0; i <= max_time && success; i++) {
			//printf("%d초 %d명 %d개\n", i, person[i], bread);
			if (i != 0 && i%inputM == 0)
				bread += inputK;
			bread -= person[i];
			if (bread < 0) {
				cout << "#" << t + 1 << " Impossible" << endl;
				success = false;
			}
		}

		if (success)
			cout << "#" << t + 1 << " Possible" << endl;
	}

	return 0;
}