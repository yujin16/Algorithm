/* 3109번 빵집(DFS)
 * https://www.acmicpc.net/problem/3109
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int answer = 0;
int inputR, inputC;
int dir_x[3] = {-1, 0, 1};

bool dfs(vector<vector<char> > &map, int x, int y) {
    map[x][y] = 'x';
    if (y == inputC - 1) {
        answer++;
        return true;
    }

    for (int i = 0; i < 3; i++) {
        int new_x = x + dir_x[i], new_y = y + 1;
        
        if (new_x >= 0 && new_x < inputR && map[new_x][new_y] == '.')
            if(dfs(map, new_x, new_y)) return true;
    }

    return false;
}

int main() {
    cin >> inputR >> inputC;

    vector<vector<char> > map(inputR, vector<char>(inputC));
    for (int i = 0; i < inputR; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < inputC; j++)
            map[i][j] = s[j];
    }
    
    for (int i = 0; i < inputR; i++)
        dfs(map, i, 0);

    cout << answer << endl;
    return 0;
}