/* 1_카카오프렌즈 컬러링북
 * 2017 kakao code festival 예선
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int inputM, inputN, answer_num = 0, answer_count = 0;
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1, 0, -1};

int dfs(vector<vector<int> > &map, vector<vector<bool> >&visited, int x, int y, int num) {
    if (visited[x][y]) return 0;
    
    int count = 1;
    visited[x][y] = true;

    for (int i = 0; i < 4;  i++) {
        int new_x = x + dir_x[i], new_y = y + dir_y[i];
        if (new_x >= 0 && new_x < inputM && new_y >= 0 && new_y < inputN)
            if(num == map[new_x][new_y])
                count += dfs(map, visited, new_x, new_y, num);
    }
    return count;
}

int main() {
    cin >> inputM >> inputN;

    vector<vector<int> > map(inputM, vector<int>(inputN, 0));
    vector<vector<bool> > visited(inputM, vector<bool>(inputN, false));
    for (int i = 0; i < inputM; i++)
        for (int j = 0; j < inputN; j++)
            cin >> map[i][j];
    
    for (int i = 0; i < inputM; i++) {
        for (int j = 0; j < inputN; j++) {
            if(map[i][j] == 0)
                visited[i][j] = true;
            if (!visited[i][j]) {
                answer_count = max(answer_count, dfs(map, visited, i, j, map[i][j]));
                answer_num++;
            }
        }
    }

    cout << answer_num << " " << answer_count << endl;
    return 0;
}