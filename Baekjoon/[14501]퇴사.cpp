/* 14501Ήψ Επ»η
 * https://www.acmicpc.net/problem/14501
 */

#include <iostream>
#include <vector>
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
using namespace std;

int main() {
	int inputN = 0, resultPrice = 0;
	cin >> inputN;
	vector<int> inputT(inputN + 1, 0);
	vector<int> inputP(inputN + 1, 0);
	vector<int> maxPrice(inputN + 1, 0);

	for (int i = 1; i <= inputN; i++) {
		cin >> inputT[i];
		cin >> inputP[i];
	}

	for (int i = inputN; i > 0; i--) {
		int nextDay = i + inputT[i];
		if (nextDay <= inputN)
			for (int j = nextDay; j <= inputN; j++)
				maxPrice[i] = MAX(maxPrice[j] + inputP[i], maxPrice[i]);
		else if (nextDay == inputN + 1)
			maxPrice[i] = inputP[i];
		resultPrice = MAX(resultPrice, maxPrice[i]);
	}

	cout << resultPrice << endl;
	return 0;
}