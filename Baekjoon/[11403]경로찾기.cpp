/* 11403번 경로찾기(DFS/BFS)
 * https://www.acmicpc.net/problem/11403
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int inputN = 0;
	cin >> inputN;
	vector<vector<bool> > inputArr(inputN, vector<bool>(inputN, 0));
	vector<vector<bool> > resultArr(inputN, vector<bool>(inputN, 0));

	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputN; j++) {
			int input = 0;
			cin >> input;
			inputArr[i][j] = (input == 1) ? true : false;
		}
	}

	queue<int> queue;
	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputN; j++) {
			if (inputArr[i][j] && !resultArr[i][j]) {
				resultArr[i][j] = true;
				queue.push(j);

				while (!queue.empty()) {
					int node = queue.front();
					queue.pop();
					for (int k = 0; k < inputN; k++) {
						if (inputArr[node][k] && !resultArr[i][k]) {
							resultArr[i][k] = true;
							queue.push(k);
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputN; j++) {
			cout << ((resultArr[i][j]) ? 1 : 0) << " ";
		}
		cout << endl;
	}
	return 0;
}