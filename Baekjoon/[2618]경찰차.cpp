/* 2618 경찰차(Dynamic Programming)
 * https://www.acmicpc.net/problem/2618
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>
using namespace std;

int dp[1001][1001];
pair<int, int> path[1001][1001];
pair<int, int> accident[1001];

int distance(pair<int, int>p1, pair<int, int>p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
    int inputN, inputW;
    cin >> inputN >> inputW;
    
    for (int i = 1; i <= inputW; i++)
        cin >> accident[i].first >> accident[i].second;

    dp[0][0] = 0;
    dp[1][0] = distance(make_pair(1, 1), accident[1]);
    dp[0][1] = distance(make_pair(inputN, inputN), accident[1]);
    for (int w = 2; w <= inputW; w++) {
        for (int x = 0; x < w; x++) {
            for (int y = 0; y < w; y++) {
                int dist = 0;
                if ((x == w - 1 || y == w - 1) && (x != y)) {
                    if(x == 0)
                        dist = distance(make_pair(1, 1), accident[w]);
                    else
                        dist = distance(accident[x], accident[w]);

                    if(dp[w][y] == 0) {
                        dp[w][y] = dp[x][y] + dist;
                        path[w][y] = make_pair(x, y);
                    }
                    else if (dp[w][y] > dp[x][y] + dist) {
                        dp[w][y] = dp[x][y] + dist;
                        path[w][y] = make_pair(x, y);
                    }

                    if(y == 0)
                        dist = distance(make_pair(inputN, inputN), accident[w]);
                    else
                        dist = distance(accident[y], accident[w]);
                    if(dp[x][w] == 0) {
                        dp[x][w] = dp[x][y] + dist;
                        path[x][w] = make_pair(x, y);
                    }
                    else if(dp[x][w] > dp[x][y] + dist) {
                        dp[x][w] = dp[x][y] + dist;
                        path[x][w] = make_pair(x, y);
                    }
                }
            }
        }
    }

    int answer = INT_MAX;
    int path_x, path_y;
    for (int x = 0; x <= inputW; x++) {
        for (int y = 0; y<=inputW; y++) {
            if((x==inputW || y==inputW) && dp[x][y]!= 0 && answer > dp[x][y]) {
                answer = dp[x][y];
                path_x = x;
                path_y = y;
            }
        }
    }
    cout << answer << endl;

    stack<int> stack;
    for (int i = 0; i < inputW; i++) {
        int x = path[path_x][path_y].first, y = path[path_x][path_y].second;
        if(path_x != x)
            stack.push(1);
        else if(path_y != y)
            stack.push(2);

        path_x = x;
        path_y = y;
    }

    while(!stack.empty()) {
        int police = stack.top();
        stack.pop();
        cout << police << endl;
    }
    return 0;
}