/* 3234번 준환이의양팔저울
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWAe7XSKfUUDFAUw
 */

#include <iostream>
#include <algorithm>
using namespace std;

int T, N, sum, answer;
int weight[10];
bool visited[10];

void start(int depth, int left, int right) {
    if(depth == N) { answer++; return; }
    if(left>= sum-left) {
        int tmp = 1;
        for (int i = N - depth; i >= 1; i--)    // 남아있는 추의 순열
            tmp = tmp * i;
        for (int i = 0; i < N - depth; i++)     // 남아있는 추의 경우의수
            tmp = tmp * 2;

        answer += tmp;
        return;
    }

    for (int i = 0; i < N; i++) {
        if(visited[i]) continue;

        visited[i] = true;
        start(depth + 1, left + weight[i], right);
        if (left >= right + weight[i])
            start(depth + 1, left, right + weight[i]);
        visited[i] = false;
    }
}

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        answer = 0;
        sum = 0;

        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            int in; scanf("%d", &in);
            weight[i] = in;
            sum += in;
        }

        start(0, 0, 0);

        printf("#%d %d\n", t, answer);
    }
    return 0;
}