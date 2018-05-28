/* 11052¹ø ºØ¾î»§ ÆÇ¸ÅÇÏ±â
 * https://www.acmicpc.net/problem/11052
 */

#include <iostream>
#include <vector>
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
using namespace std;

int main() {
	int inputN = 0;
	cin >> inputN;
	vector<int> price(inputN, 0);
	vector<int> maxPrice(inputN, 0);

	for (int i = 0; i < inputN; i++)
		cin >> price[i];

	for (int i = 0; i < inputN; i++) {
		maxPrice[i] = price[i];
		for (int j = 0; j < i; j++)
			maxPrice[i] = MAX(maxPrice[i], maxPrice[j] + maxPrice[i - j - 1]);
	}

	cout << maxPrice[inputN - 1] << endl;
	return 0;
}