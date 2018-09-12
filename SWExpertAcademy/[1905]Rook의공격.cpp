/* 1905번 Rook의 공격 */

#include <iostream>
#include <algorithm>
using namespace std;

struct Point { 
    int x, y, sum;
    Point(){};
    Point(int xx, int yy, int ss) : x(xx), y(yy), sum(ss){};
};
int T, N;
int map[301][301];
Point attackSum[100000];

bool oper(Point p1, Point p2) {
    return p1.sum > p2.sum;
}

int main() {
    cin>>T;

    for (int t = 1; t <= T;t++) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            map[i][0] = 0;
            map[0][i] = 0;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N;j++) {
                int in;
                cin >> in;
                map[i][j] = in;
                map[i][0] += in;
                map[0][j] += in;
            }
        }

        int index = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N;j++)
                attackSum[index++] = Point(i, j, map[i][0] + map[0][j] - (map[i][j] * 2));

        sort(attackSum, attackSum + index, oper);
        int limit = index;
        if (N * N > 100)
            limit = 100;
        
        //int limit = (N * N) < 100 ? N * N : 100;

        int answer = 0;
        for (int i = 0; i < limit; i++) {
            for (int j = i + 1; j < limit; j++) {
                int sum = attackSum[i].sum + attackSum[j].sum;
                if (attackSum[i].x == attackSum[j].x) {
                    sum -= map[attackSum[i].x][0];
                }
                else if(attackSum[i].y == attackSum[j].y) {
                    sum -= map[0][attackSum[i].y];
                }
                else {
                    sum -= map[attackSum[i].x][attackSum[j].y] + map[attackSum[j].x][attackSum[i].y];
                }

                answer = max(answer, sum);
            }
        }

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}