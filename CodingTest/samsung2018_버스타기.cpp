/* 1_버스타기
 * 2018 삼성전자 대학생 프로그래밍 경진대회 예선
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int inputT;
	cin >> inputT;

	for (int t = 0; t < inputT; t++) {
		int inputN, inputK;
		cin >> inputN >> inputK;

		priority_queue<unsigned int> people;
		vector<int> bus;
		for (int n = 0; n < inputN; n++) {
			int input;
			cin >> input;
			people.push(input);
		}

		bus.push_back(people.top());
		people.pop(); 
		while (!people.empty()) {
			int top = people.top();
			people.pop();

			int size = bus.size();
			bool newbus = true;
			for (int i = 0; i < size; i++) {
				if ((bus[i] - top) > inputK) {
					bus[i] = top;
					newbus = false;
				}
			}

			if (newbus)
				bus.push_back(top);
		}

		cout << "Case #" << t + 1 << endl;
		cout << bus.size() << endl;
	}

	return 0;
}