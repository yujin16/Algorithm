/* 1003번 피보나치함수(Dynamic Programming)
 * https://www.acmicpc.net/problem/1003
 */

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
// 	int inputT = 0;
// 	vector<pair<int, int> > fibonacci(41, pair<int, int>(-1, -1));
// 	fibonacci[0].first = 1;
// 	fibonacci[0].second = 0;
// 	fibonacci[1].first = 0;
// 	fibonacci[1].second = 1;

// 	cin >> inputT;
// 	for (int i = 0; i < inputT; i++) {
// 		int inputN = 0;
// 		cin >> inputN;

// 		for (int j = 2; j <= inputN; j++) {
// 			if (fibonacci[j].first == -1 && fibonacci[j].second == -1) {
// 				fibonacci[j].first = fibonacci[j - 1].first + fibonacci[j - 2].first;
// 				fibonacci[j].second = fibonacci[j - 1].second + fibonacci[j - 2].second;
// 			}
// 		}
// 		cout << fibonacci[inputN].first << " " << fibonacci[inputN].second << endl;
// 	}
// 	return 0;
// }

#include <iostream>
using namespace std;

int T = 0, N = 0;
int dp[41][2];

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);

        dp[0][0] = 1;
        dp[1][1] = 1;

        for (int k = 2; k <= N; ++k) {
            dp[k][0] = dp[k - 1][0] + dp[k - 2][0];
            dp[k][1] = dp[k - 1][1] + dp[k - 2][1];
        }
        printf("%d %d\n", dp[N][0], dp[N][1]);
    }
    return 0;
}