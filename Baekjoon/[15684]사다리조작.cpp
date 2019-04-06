/* 15684 사다리조작(BruteForce)
 * https://www.acmicpc.net/problem/15684
 */

#include <iostream>
#include <vector>
using namespace std;

int N, M, H, answer = 5;
int map[32][12];
vector<pair<int, int> > possible;
int size, max_depth;

void check(int depth) {
    bool success = true;
    for(int i=1; i<=N && success; ++i) {
        int next = i;
        for(int j=1; j<=H; ++j) if(map[j][next] != 0) next = map[j][next];
        if(next != i) success = false;
    }
    if(success) answer = min(answer, depth);
}

void dfs(int index, int depth) {
    if(max_depth == depth)  { check(depth); return; }
    if(size == index)       { check(depth); return; }

    int h = possible[index].first;
    int n = possible[index].second;

    if(map[h][n] == 0 && map[h][n+1] == 0) {
        map[h][n] = n + 1;
        map[h][n + 1] = n;
        dfs(index + 1, depth + 1);
        map[h][n] = 0;
        map[h][n + 1] = 0;
    }
    dfs(index + 1, depth);
}

int main() {
    scanf("%d %d %d", &N, &M, &H);
    for (int i = 0; i < M; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        map[a][b] = b + 1;
        map[a][b + 1] = b;
    }

    for(int i=1; i<=H; ++i) {
        for (int j = 1; j < N; ++j) {
            if (map[i][j] == 0 && map[i][j + 1] == 0)
                possible.push_back(make_pair(i, j));
        }
    }

    size = possible.size();
    for (int i = 0; i <= 3; ++i) {
        max_depth = i;
        dfs(0, 0);
        if(answer != 5) break;
    }

    if(answer > 3) answer = -1;
    printf("%d\n", answer);
    return 0;
}