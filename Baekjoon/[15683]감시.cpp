/* 15683 감시(DFS)
 * https://www.acmicpc.net/problem/15683
 */

#include <iostream>
#include <vector>
using namespace std;

#define T true
#define F false

struct CCTV{
    int x, y, type;
    CCTV(int xx, int yy, int t) : x(xx), y(yy), type(t) {}
};

int N, M, answer = 100, cctv_num;
int map[8][8];
vector<CCTV> cctv;

void check() {
    int num=0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(map[i][j] == 0) num++;

    answer = min(answer, num);
}

void turn(CCTV tv, int dir, int flag) {
    bool cctv_dir[6][4][4] = {  {},
                                {{T,F,F,F}, {F,T,F,F}, {F,F,T,F}, {F,F,F,T}},
                                {{F,T,F,T}, {T,F,T,F}},
                                {{T,T,F,F}, {F,T,T,F}, {F,F,T,T}, {T,F,F,T}},
                                {{T,T,F,T}, {T,T,T,F}, {F,T,T,T}, {T,F,T,T}},
                                {{T,T,T,T}}
                            };

    if(cctv_dir[tv.type][dir][0]) {
        for(int i=tv.x-1; i>=0 && map[i][tv.y] != 600; i--)
            map[i][tv.y] += flag;
    }
    if(cctv_dir[tv.type][dir][1]) {
        for(int i=tv.y+1; i<M && map[tv.x][i] != 600; i++)
            map[tv.x][i] += flag;
    }
    if(cctv_dir[tv.type][dir][2]) {
        for(int i=tv.x+1; i<N && map[i][tv.y] != 600; i++)
            map[i][tv.y] += flag;
    }
    if(cctv_dir[tv.type][dir][3]) {
        for(int i=tv.y-1; i>=0 && map[tv.x][i] != 600; i--)
            map[tv.x][i] += flag;
    }
}

void dfs(int depth) {
    if(cctv_num <= depth) { 
        check(); return;
    }

    int dir_size[6] = {0, 4, 2, 4, 4, 1};
    int size = dir_size[cctv[depth].type];
    for(int i=0; i<size; i++) {
        turn(cctv[depth], i, 1);
        dfs(depth+1);
        turn(cctv[depth], i, -1);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int in; scanf("%d", &in);
            map[i][j] = in * 100;
            if(1<=in && in<=5) cctv.push_back(CCTV(i, j, in));
        }
    }

    cctv_num = cctv.size();
    if(cctv_num != 0) dfs(0);
    else  check();
    
    printf("%d\n", answer);
    return 0;
}