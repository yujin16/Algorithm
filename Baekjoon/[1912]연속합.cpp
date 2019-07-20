/* 1912번 연속합(Dynamic Programming)
 * https://www.acmicpc.net/problem/1546
 */

// #include <iostream>
// #include <climits>
// #define MAX(X, Y) ((X)>(Y))? (X):(Y);
// using namespace std;

// int main() {
// 	int num = 0, currentMax = 0, resultMax = INT_MIN;
// 	cin >> num;

// 	for (int i = 0; i < num; i++) {
// 		int newNum = 0;
// 		cin >> newNum;
// 		currentMax = MAX(currentMax + newNum, newNum);
// 		resultMax = MAX(currentMax, resultMax);
// 	}

// 	cout << resultMax;
// 	return 0;
// }

/*20190715 */
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N = 0, score = 0, curMax = 0, answer = INT_MIN;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &score);

        curMax = max(curMax + score, score);
        answer = max(answer, curMax);
    }
    printf("%d\n", answer);
    return 0;
}