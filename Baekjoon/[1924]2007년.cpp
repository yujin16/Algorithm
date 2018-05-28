/* 1924¹ø 2007³â
 * https://www.acmicpc.net/problem/1924
 */

#include <iostream>
using namespace std;

int main() {
	int month = 0, day = 0, sum = 0;
	cin >> month >> day;
	for (int i = 1; i < month; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			sum += 31;
		else if (i == 2)
			sum += 28;
		else
			sum += 30;
	}
	sum += day - 1;
	sum %= 7;

	if (sum == 0)
		cout << "MON";
	else if (sum == 1)
		cout << "TUE";
	else if (sum == 2)
		cout << "WED";
	else if (sum == 3)
		cout << "THU";
	else if (sum == 4)
		cout << "FRI";
	else if (sum == 5)
		cout << "SAT";
	else if (sum == 6)
		cout << "SUN";

	return 0;
}