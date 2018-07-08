/* 2352번 반도체설계(Dynamic Programming)
* https://www.acmicpc.net/problem/2352
*/

#include <iostream>
#include <vector>
#define MAX(X,Y) ((X)>(Y))? (X):(Y)
using namespace std;

int main() {
	int inputN;
	cin >> inputN;

	vector<int> input(inputN, 0);
	vector<int> result;
	for (int i = 0; i < inputN; i++)
		cin >> input[i];

	result.push_back(input[0]);
	int end_pos = 0;
	for (int i = 1; i < inputN; i++) {
		if (result[end_pos] < input[i]) {
			result.push_back(input[i]);
			end_pos++;
		}
		else {
			for (int j = 0; j < result.size(); j++) {
				if (input[i] < result[j]) {
					result[j] = input[i];
					break;
				}
			}
		}
	}

	cout << result.size() << endl;
	return 0;
}