/* 1808번 지희의고장난계산기
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <vector>
#include <climits>
#define MIN(X,Y) ((X)<(Y))? (X):(Y)
using namespace std;

int goalNum = 0;
int result = INT_MAX;

void addNode(vector<pair<int, int> > &nodeNum, int num, int count, int size) {
	if (num == goalNum) {
		result = count + 1;
		return;
	}

	for (int i = 0; i < size; i++) {
		int newNode = num * 10 + nodeNum[i].first;
		if (newNode <= goalNum && num != 0) {
			addNode(nodeNum, newNode, count + 1, size);
			nodeNum.push_back(make_pair(newNode, count + 1));
		}
	}
}

void backTracking(vector<pair<int, int> > &nodeNum, vector<bool> &check, int num, int count) {
	count++;

	if (num == 1) {
		result = MIN(result, count);
		return;
	}

	if (check[num]) return;
	check[num] = true;

	for (int i = 0; i < nodeNum.size(); i++) {
		if (nodeNum[i].first > 1 && num % nodeNum[i].first == 0)
			backTracking(nodeNum, check, num / nodeNum[i].first, count + nodeNum[i].second);
	}
}

int main() {
	int testCase = 0, count = 0;
	cin >> testCase;

	for (int t = 0; t < testCase; t++) {
		vector<pair<int, int> > nodeNum;
		vector<bool> check(1000001, false);
		result = INT_MAX;

		for (int i = 0; i < 10; i++) {
			int node;
			cin >> node;
			if (node == 1) nodeNum.push_back(make_pair(i, 1));
		}
		cin >> goalNum;

		int size = nodeNum.size();
		for (int i = 0; i < size; i++)
			addNode(nodeNum, nodeNum[i].first, nodeNum[i].second, size);

		if (result == INT_MAX)
			backTracking(nodeNum, check, goalNum, -1);

		if (result == INT_MAX)
			cout << "#" << t + 1 << " " << -1 << endl;
		else
			cout << "#" << t + 1 << " " << result << endl;
	}
	return 0;
}