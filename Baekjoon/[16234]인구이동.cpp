/* 16234 인구이동(BFS)
 * https://www.acmicpc.net/problem/16234
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, L, R;
int dir_x[4] = {-1, 1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

bool isBoundary(int x, int y) {
    if (x < 0 ) return false;
    if (x >= N ) return false;
    if (y < 0 ) return false;
    if (y >= N ) return false;
    return true;
}

int main() {
    cin >> N >> L >> R;
    
    vector<vector<int> > map(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    int answer = 0;
    bool success;
    do{
        int g = 1;
        success = true;

        vector<vector<int> > group(N, vector<int>(N, 0));
        vector<int> peopleNum(1, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++ ){
                if(group[i][j] == 0) {
                    int sum = map[i][j];
                    int count = 1;

                    queue<pair<int, int> > q;
                    q.push(make_pair(i, j));
                    group[i][j] = g;

                    while(!q.empty()) {
                        int x = q.front().first, y = q.front().second;
                        int people = map[x][y];
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nx = x + dir_x[k], ny = y + dir_y[k];

                            if(isBoundary(nx, ny)) {
                                int sub = abs(people-map[nx][ny]);
                                if(group[nx][ny] == 0 && L<= sub && sub<=R) {
                                    q.push(make_pair(nx, ny));
                                    group[nx][ny] = g;
                                    sum += map[nx][ny];
                                    count++;
                                }
                            }
                        }
                    }

                    g++;
                    peopleNum.push_back(sum/count);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int groupNum = group[i][j];
                if(map[i][j] != peopleNum[groupNum]) success = false;
                map[i][j] = peopleNum[groupNum];
            }
        }

        answer++;
    } while (!success);

    cout << answer - 1 << endl;
}