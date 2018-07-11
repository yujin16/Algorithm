/* 4963번 섬의개수(DFS/BFS)
 * https://www.acmicpc.net/problem/4963
 */

#include <iostream>
#include <vector>
using namespace std;

 int inputW, inputH, answer = 0;
 int dir_x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
 int dir_y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

 void dfs(vector<vector<bool> > &map, int x, int y) {
     map[x][y] = true;

     for(int i=0; i<8; i++) {
         int new_x = x+dir_x[i], new_y = y+dir_y[i];
         if(new_x>=0 && new_x<inputH && new_y >= 0 && new_y<inputW && !map[new_x][new_y])
            dfs(map, new_x, new_y);
     }
 }

int main() {
    while(1) {
        cin>>inputW>>inputH;
        if(inputW ==0 && inputH == 0) break;

        vector<vector<bool> > map(inputH, vector<bool>(inputW));
        for(int i=0; i<inputH; i++) {
            for(int j=0; j<inputW; j++) {
                char in;
                cin >> in;

                if(in == '0') map[i][j] = true;       //sea
                else if(in == '1') map[i][j] = false; //land
            }
        }

        answer = 0;
        for(int i=0; i<inputH; i++) {
            for(int j=0; j<inputW; j++) {
                if(!map[i][j]) {
                    dfs(map, i, j);
                    answer++;
                }
            }
        }

        cout << answer << endl;
    }
    return 0;
}