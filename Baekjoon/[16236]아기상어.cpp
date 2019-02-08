/* 16236번 아기상어(algorithm)
 * https://www.acmicpc.net/problem/16236
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct FISH {
    int x, y, time;
    FISH(int xx, int yy, int t) : x(xx), y(yy), time(t) {}
};

int N, shark_size=2, shark_eat=0;
int dir_x[4] = {-1, 0, 1, 0};   //상좌하우
int dir_y[4] = {0, -1, 0, 1};
int map[21][21];
FISH shark = FISH(0, 0, 0);

bool cmp(FISH a, FISH b) {
    if (a.time == b.time) {
        if (a.x == b.x) {
            return a.y<b.y;
        }
        else return a.x<b.x;
    }
    else return a.time < b.time;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int in; scanf("%d", &in);
            if(in == 9) shark = FISH(i, j, 0);
            else map[i][j] = in;
        }
    }

    while(1) {
        vector<vector<bool> > visited(N, vector<bool>(N, false));
        vector<FISH> eat;

        queue<FISH> q;
        q.push(shark);
        visited[shark.x][shark.y] = true;
        
        while(!q.empty()) {
            FISH fish = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = fish.x + dir_x[i], ny = fish.y + dir_y[i];
                if(0<=nx && nx<N && 0<= ny && ny <N && !visited[nx][ny]) {
                    int s = map[nx][ny];
                    if(shark_size == s || s == 0) {    // 같은 물고기일 경우, 0일 경우 이동만시킴
                        q.push(FISH(nx, ny, fish.time + 1));
                        visited[nx][ny] = true;
                    }
                    else if(s < shark_size) {
                        visited[nx][ny] = true;
                        eat.push_back(FISH(nx,ny,fish.time+1)); // 작은 물고기일 경우 잡아먹자!
                    }
                }
            }
        }

        if(eat.size() == 0) break;
        sort(eat.begin(), eat.end(), cmp);

        shark = FISH(eat[0].x, eat[0].y, eat[0].time);
        shark_eat++;
        map[shark.x][shark.y] = 0;
        if(shark_size == shark_eat) {
            shark_size++;
            shark_eat = 0;
        }
    }

    printf("%d\n", shark.time);
    return 0;
}