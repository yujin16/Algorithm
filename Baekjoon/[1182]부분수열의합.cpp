/* 1182번 부분수열의합(BruteForce)
 * https://www.acmicpc.net/problem/1182
 */

#include <iostream>
using namespace std;

int N, S, answer = 0, IN[20];

void dfs(int depth, int sum) {
    if(N <= depth) {
        if(sum == S) answer++;
        return;
    }

    dfs(depth + 1, sum);
    dfs(depth + 1, sum + IN[depth]);
}

int main() {
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++)
        scanf("%d", &IN[i]);

    dfs(0, 0);

    if(S == 0) answer -= 1;
    printf("%d\n", answer);
    return 0;
}