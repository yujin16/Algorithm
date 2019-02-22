/* 6603번 로또(DFS)
 * https://www.acmicpc.net/problem/6603
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int K, lotto[13];
bool visited[13];

void recursive(int select, int depth, string answer) {
    if(depth >= 6) {
        int len = answer.length();
        for (int i = 0; i < len; i++)
            printf("%c", answer[i]);
        printf("\n");
        return;
    }
    answer += " ";
    
    visited[select] = true;
    for (int i = select + 1; i < K; i++)
        recursive(i, depth + 1, answer + to_string(lotto[i]));
    visited[select] = false;
}

int main() {
    while(1) {
        scanf("%d", &K); if(K == 0)break;
        for (int i = 0; i < K; i++) scanf("%d", &lotto[i]);

        for (int i = 0; i <= K - 6; i++)
            recursive(i, 1, to_string(lotto[i]));
        printf("\n");
    }
    return 0;
}

/*int main() {
    while(1) {
        scanf("%d", &K); if(K == 0)break;
        for (int i = 0; i < K; i++) scanf("%d", &lotto[i]);

        for (int i = 0; i < 6; i++) visited[i] = true;
        for (int i = 6; i < K; i++) visited[i] = false;

        do {
            for (int i = 0; i < K; i++) {
                if(visited[i]) printf("%d ", lotto[i]);
            }
            printf("\n");
        } while(prev_permutation(visited, visited+K));
        printf("\n");
    }
    return 0;
}*/