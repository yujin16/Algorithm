/* 1987 알파벳(DFS)
 * https://www.acmicpc.net/problem/1987
 */

#include <iostream>
using namespace std;

int R, C, answer = 1;
char map[21][21];
bool visited[26];
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

void dfs(int x, int y, int depth) {
    if(answer < depth) answer = depth;
    for (int i = 0; i < 4; i++) {
        int nx = x + dir_x[i], ny = y + dir_y[i];
        if(0<=nx && nx<R && 0<=ny && ny<C) {
            if(!visited[map[nx][ny] - 'A']) {
                visited[map[nx][ny] - 'A'] = true;
                dfs(nx, ny, depth + 1);
                visited[map[nx][ny] - 'A'] = false;
            }
        }
    }
}

int main() {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; ++i) scanf("%s", map[i]);

    visited[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    printf("%d\n", answer);
    return 0;
}