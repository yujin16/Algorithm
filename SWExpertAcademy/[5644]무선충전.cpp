/* 5644번 무선충전
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRDL1aeugDFAUo&categoryId=AWXRDL1aeugDFAUo&categoryType=CODE
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum DIR{ STOP = 0, UP, RIGHT, DOWN, LEFT };
struct BC { int x, y, C, P; };

int T, M, A, userA[101], userB[101], answer;
BC battery[8];
int dir_x[5] = {0, -1, 0, 1, 0};
int dir_y[5] = {0, 0, 1, 0, -1};

bool cmp(BC a, BC b) { return a.P > b.P; }

int main() {
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; testcase++) {
        scanf("%d %d", &M, &A);
        for (int i = 0; i < M; i++) scanf("%d", &userA[i]);
        for (int i = 0; i <
         M; i++) scanf("%d", &userB[i]);
        for (int i = 0; i < A; i++) scanf("%d %d %d %d", &battery[i].y, &battery[i].x, &battery[i].C, &battery[i].P);

        sort(battery, battery + A, cmp);
        answer = 0;
        int dist, asize, bsize;
        int ax = 1, ay = 1;
        int bx = 10, by = 10;
        for (int t = 0; t <= M; t++) {
            int count = 2;
            bool afind = false, bfind = false;
            for (int i = 0; i < A; i++) {
                bool find = false;
                if(count == 0) break;

                dist = abs(ax - battery[i].x) + abs(ay - battery[i].y);
                if (!afind && dist <= battery[i].C) {afind = true; find = true; }
                dist = abs(bx - battery[i].x) + abs(by - battery[i].y);
                if (!bfind && dist <= battery[i].C) {bfind = true; find = true; }

                if(!find) continue;
                else if(afind && bfind) {
                    afind = false;
                    bfind = false;
                }
                count--;
                answer += battery[i].P;
            }
            ax += dir_x[userA[t]];
            ay += dir_y[userA[t]];
            bx += dir_x[userB[t]];
            by += dir_y[userB[t]];
        }

        printf("#%d %d\n", testcase, answer);
    }
    return 0;
}