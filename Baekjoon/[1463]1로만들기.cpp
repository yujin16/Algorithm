/* 1463번 1로만들기(Dynamic Programming)
 * https://www.acmicpc.net/problem/1463
 */

// #include <iostream>
// #include <vector>
// #include <climits>
// #define MAX(X,Y) ((X)>(Y)?(X):(Y))
// using namespace std;

// int main() {
// 	int inputN = 0;
// 	cin >> inputN;
// 	vector<int> dp(inputN + 1, INT_MAX);

// 	dp[0] = 0;
// 	dp[1] = 0;
// 	dp[2] = 1;
// 	dp[3] = 1;

// 	for (int i = 4; i <= inputN; i++) {
// 		int nextIndex = i;
// 		if (i % 3 == 0)
// 			if (dp[nextIndex] > dp[i / 3])
// 				nextIndex = i / 3;
// 		if (i % 2 == 0)
// 			if (dp[nextIndex] > dp[i / 2])
// 				nextIndex = i / 2;
// 		if (dp[nextIndex] > dp[i - 1])
// 			nextIndex = i - 1;

// 		dp[i] = dp[nextIndex] + 1;
// 	}

// 	cout << dp[inputN] << endl;
// 	return 0;
// }

/* 20190714일 */
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N = 0;
int Memorization[1000001];

int main() {
    scanf("%d", &N);
    
    for (int i = 2; i <= N; ++i) Memorization[i] = INT_MAX;
    Memorization[1] = 0;

    for (int k = 1; k < N; ++k) {
        if(k*3 <= N) Memorization[k*3] = min(Memorization[k*3], Memorization[k] + 1);
        if(k*2 <= N) Memorization[k*2] = min(Memorization[k*2], Memorization[k] + 1);
        if(k+1 <= N) Memorization[k+1] = min(Memorization[k+1], Memorization[k] + 1);
    }
    printf("%d\n", Memorization[N]);
}    
