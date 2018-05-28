/* 14889번 스타트와 링크
 * https://www.acmicpc.net/problem/14889
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#define MIN(X,Y) ((X)<(Y))? (X):(Y)
using namespace std;

int inputN = 0, result = INT_MAX;

void recursive(vector<vector<int> >&map, vector<int> &team, int start, int link) {
	if (team.size() == inputN) {
		vector<int> team1, team2;
		for (int i = 0; i < inputN; i++) {
			if (team[i] == 1) team1.push_back(i);
			else team2.push_back(i);
		}

		int score1 = 0, score2 = 0;
		for (int i = 0; i < inputN / 2 - 1; i++) {
			for (int j = i + 1; j < inputN / 2; j++) {
				score1 += map[team1[i]][team1[j]] + map[team1[j]][team1[i]];
				score2 += map[team2[i]][team2[j]] + map[team2[j]][team2[i]];
			}
		}
		result = MIN(result, abs(score1 - score2));
		return;
	}

	if (start < inputN / 2) {
		team.push_back(1);
		recursive(map, team, start + 1, link);
		team.pop_back();
	}

	if (link < inputN / 2) {
		team.push_back(2);
		recursive(map, team, start, link + 1);
		team.pop_back();
	}
}

int main() {
	cin >> inputN;
	vector<vector<int> >map(inputN, vector<int>(inputN, 0));

	for (int i = 0; i < inputN; i++)
		for (int j = 0; j < inputN; j++)
			cin >> map[i][j];

	vector<int> team;
	recursive(map, team, 0, 0);

	cout << result << endl;
	return 0;
}