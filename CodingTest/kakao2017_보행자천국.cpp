/* 2_보행자천국
 * 2017 kakao code festival 예선
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int inputM, inputN, answer = 0;
int dir_x[2] = {1, 0};
int dir_y[2] = {0, 1};

void dfs(vector<vector<int> > &city_map, int x, int y) {
    if (x == inputM - 1 && y == inputN - 1){
        answer++;
        return;
    }

    for (int i = 0; i<2; i++) {
        int new_x = x + dir_x[i], new_y = y + dir_y[i];

        if(new_x < inputM && new_y < inputN) {
            switch(city_map[new_x][new_y]) {
                case 0 : dfs(city_map, new_x, new_y); break;
                case 1 : break;
                case 2:
                    while (new_x < inputM && new_y < inputN) {
                        if (city_map[new_x][new_y] == 0) {
                            dfs(city_map, new_x, new_y);
                            break;
                        }
                        if (city_map[new_x][new_y] == 1)
                            break;
                        new_x += dir_x[i];
                        new_y += dir_y[i];
                    } 
                    break;
            }
        }
    }
}

int main() {
    cin >> inputM >> inputN;

    vector<vector<int> > city_map(inputM, vector<int>(inputN, 0));
    for (int i = 0; i < inputM; i++)
        for (int j = 0; j < inputN; j++)
            cin >> city_map[i][j];

    dfs(city_map, 0, 0);
    cout << answer % 20170805 << endl;
    return 0;
}