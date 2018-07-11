/* 9328번 열쇠(BFS)
 * https://www.acmicpc.net/problem/9328
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int inputH, inputW;
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

int bfs(vector<vector<char> > &map, vector<bool> &key) {
    int answer = 0;

    queue<pair<int, int> > queue;
    vector<pair<int, int> > door;
    for (int i = 0; i < inputH; i++)
        for (int j = 0; j < inputW; j++)
            if (i == 0 || i == inputH - 1 || j == 0 || j == inputW - 1)
                if(map[i][j] != '*')
                    queue.push(make_pair(i, j));
                    

    while(!queue.empty()) {
        int x = queue.front().first, y = queue.front().second;
        queue.pop();

        char c = map[x][y];
        if (c == '*') continue;
        else if(c == '$') answer++;
        else if ('a' <= c && c <= 'z') {
            key[c - 'a'] = true;
            for (int i = 0; i < door.size(); i++) {
                int door_x = door[i].first, door_y = door[i].second;
                char door_name = map[door_x][door_y];
                if (key[door_name-'A']) {
                    door.erase(door.begin() + i--);
                    queue.push(make_pair(door_x, door_y));
                }
                
            }
        }
        else if ('A' <= c && c <= 'Z') {
            if(!key[c - 'A']) {
                door.push_back(make_pair(x, y));
                continue;
            }
        }

        map[x][y] = '*';
        for (int i = 0; i < 4; i++) {
            int new_x = x + dir_x[i], new_y = y + dir_y[i];

            if (new_x >= 0 && new_x < inputH && new_y >= 0 && new_y < inputW && map[new_x][new_y] != '*')
                queue.push(make_pair(new_x, new_y));
        }
    }
    return answer;
}

int main() {
    int TestCase;
    cin >> TestCase;

    for (int t = 0; t < TestCase; t++) {
        string s;
        cin >> inputH >> inputW;

        vector<vector<char> > map(inputH, vector<char>(inputW));
        for (int i = 0; i < inputH; i++) {
            cin >> s;
            for (int j = 0; j < inputW; j++)
                map[i][j] = s[j];
        }

        cin >> s;
        vector<bool> key(26, false);
        if(s!= "0") 
            for (int i = 0; i < s.length(); i++)
                key[s[i] - 'a'] = true;

        cout <<  bfs(map, key) << endl;
    }
    return 0;
}