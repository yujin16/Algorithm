/* 15685번 드래곤커브(Simulation)
 * https://www.acmicpc.net/problem/15685
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer = 0;
int x_min = 100, x_max = 0, y_min = 100, y_max = 0;
int dir_x[4] = {0, -1, 0, 1};
int dir_y[4] = {1, 0, -1, 0};
vector<vector<bool> > map(101, vector<bool>(101, false));

/* (2,4)를 (2,2)기준으로 (4,2)으로 이동하였다.
    x->x+0      x->x+2
    y->y-2      y->y+0                  */

void dragoncurve(vector<pair<int, int> > &v) {
    int x1, x2, x3, y1, y2, y3, sub_x, sub_y;
    int size = v.size();
    x2 = v[size - 1].first;
    y2 = v[size - 1].second;

    for (int i = size-2; i >= 0; i--) {
        x1 = v[i].first;
        y1 = v[i].second;

        sub_x = x2 - x1;
        sub_y = y2 - y1;

        x3 = x2 - sub_y;
        y3 = y2 + sub_x;

        if(0<=x3 && x3<=100 && 0<=y3 && y3<=100) {
            v.push_back(make_pair(x3, y3));
            map[x3][y3] = true;

            x_min = min(x_min, x3);
            x_max = max(x_max, x3);
            y_min = min(y_min, y3);
            y_max = max(y_max, y3);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        scanf("%d %d %d %d", &y, &x, &d, &g);

        vector<pair<int, int> > v;
        // 0세대 드래곤커브
        v.push_back(make_pair(x, y));
        v.push_back(make_pair(x + dir_x[d], y + dir_y[d]));
        map[x][y] = true;
        map[x + dir_x[d]][y + dir_y[d]] = true;
        x_min = min(x_min, min(x, x + dir_x[d]));
        x_max = max(x_max, max(x, x + dir_x[d]));
        y_min = min(y_min, min(y, y + dir_y[d]));
        y_max = max(y_max, max(y, y + dir_y[d]));

        // N세대 드래곤커브
        for (int j = 1; j <= g; j++)
            dragoncurve(v);
    }

    for (int x = x_min; x < x_max; x++)
        for (int y = y_min; y < y_max; y++)
            if(map[x][y] && map[x+1][y] && map[x][y+1] && map[x+1][y+1])
                answer++;

    printf("%d\n", answer);
    return 0;
}