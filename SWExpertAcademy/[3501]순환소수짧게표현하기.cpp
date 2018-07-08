/* 3501번 순환소수짧게표현하기
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int t = 1; t <= testcase; t++) {
		int inputP, inputQ;
		cin >> inputP >> inputQ;

		int quotient = inputP / inputQ;
		int remainder = inputP % inputQ;
		cout << "#" << t << " " << quotient;	// �Ҽ��� �� ���

		if (remainder == 0) {		// ������ �������� ����
			cout << endl;
			continue;
		}

		cout << ".";		// �Ҽ����� ����� ���
		vector<int> quotient_arr;
		vector<int> remainder_arr(inputQ, -1);
		remainder_arr[remainder] = 0;

		int index = 1;
		while (true) {

			remainder *= 10;
			quotient = remainder / inputQ;
			remainder %= inputQ;

			quotient_arr.push_back(quotient);

			// ������ �������� ���
			if (remainder == 0) {
				for (int i = 0; i < quotient_arr.size(); i++)
					cout << quotient_arr[i];
				break;
			}

			// �ݺ��Ǵ� ������ ã���� ��� ���
			if (remainder_arr[remainder] >= 0) {
				int cycle_index = remainder_arr[remainder];
				for (int i = 0; i < cycle_index; i++)
					cout << quotient_arr[i];
				cout << "(";
				for (int i = cycle_index; i < quotient_arr.size(); i++)
					cout << quotient_arr[i];
				cout << ")";
				break;
			}

			// �ݺ��Ǵ� ������ ��ã���� ���
			if (remainder_arr[remainder] < 0) {
				remainder_arr[remainder] = index;
				index++;
			}
		}
		cout << endl;
	}
}