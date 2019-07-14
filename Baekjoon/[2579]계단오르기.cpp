/* 2579번 계단오르기(Dynamic Programming)
 * https://www.acmicpc.net/problem/2579
 */

// #include <iostream>
// #include <vector>
// #define MAX(X,Y) ((X)>(Y)?(X):(Y))
// using namespace std;

// int main() {
// 	int stairNum = 0;
// 	cin >> stairNum;
// 	vector<int> scores(stairNum, 0);
// 	vector<pair<int, int> > scoreSum(stairNum, pair<int, int>(0, 0));

// 	for (int i = 0; i < stairNum; i++)
// 		cin >> scores[i];

// 	if (stairNum > 1) {
// 		scoreSum[0].first = scores[0];
// 		scoreSum[0].second = scores[0];
// 		scoreSum[1].first = scores[1] + scoreSum[0].first;
// 		scoreSum[1].second = scores[1];

// 		for (int i = 2; i < stairNum; i++) {
// 			scoreSum[i].first = scores[i] + scoreSum[i - 1].second;
// 			scoreSum[i].second = scores[i] + MAX(scoreSum[i - 2].first, scoreSum[i - 2].second);
// 		}

// 		cout << MAX(scoreSum[stairNum - 1].first, scoreSum[stairNum - 1].second) << endl;
// 	}
// 	else
// 		cout << scores[0] << endl;

// 	return 0;
// }

#include <iostream>
#include <algorithm>
using namespace std;

int N = 0;
int score[301];
int dp[301][2];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%d", &score[i]);

    dp[1][0] = score[1];
    for (int k = 2; k <= N; ++k) {
        dp[k][0] = max(dp[k-2][0], dp[k-2][1] + score[k-1]) + score[k];
        dp[k][1] = dp[k - 1][0];
    }

    printf("%d\n", dp[N][0]);
    return 0;
}
