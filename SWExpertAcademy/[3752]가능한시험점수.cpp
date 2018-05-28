/* 3752번 가능한 시험 점수
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX(X,Y) ((X)>(Y))? (X):(Y)
using namespace std;

int main() {
	int testcase = 0;
	cin >> testcase;

	for (int t = 1; t <= testcase; t++) {
		int inputN, answer = 1;
		cin >> inputN;

		vector<int> score(inputN, 0);
		vector<int> score_sum(10001, -1);
		for (int i = 0; i < inputN; i++)
			cin >> score[i];

		sort(score.begin(), score.end());
		score_sum[0] = 0;

		int max_sum = 0;
		for (int i = 0; i < inputN; i++) {
			int max = max_sum;
			for (int j = 0; j <= max; j++) {
				if (score_sum[j] < 0) continue;
				if (score_sum[j] == i + 1) continue;
				if (score_sum[j + score[i]] > 0) continue;
				score_sum[j + score[i]] = i + 1;
				max_sum = MAX(max_sum, j + score[i]);
				answer++;
			}
		}

		cout << "#" << t << " " << answer << endl;
	}
	return 0;
}