/* 4_부스터
 * 2018 kakao code festival 예선
 */

#include <iostream>
#include <vector>
using namespace std;

int startP, endP, inputHP;
int curX, curY;

void dfs(vector<pair<int, int> > &checkPoint, int x, int y) {
    if(checkPoint[endP].first == curX && checkPoint[endP].second == curY) {
        return;
    }


}

int main() {
    int inputN, inputQ;
    cin >> inputN >> inputQ;

    vector<pair<int, int> > checkPoint(inputN+1);
    for (int i = 1; i <= inputN; i++) {
        int x, y;
        cin >> x >> y;
        checkPoint[i] = make_pair(x, y);
    }

    for (int q = 0; q < inputQ; q++) {
        int startP, endP, inputHP;
        cin >> startP >> endP >> inputHP;
        curX = checkPoint[startP].first, curY = checkPoint[startP].second;

        int hp = inputHP;
        bool booster = true;
        vector<bool> used(inputN + 1, false);
        used[startP] = true;

        

    }

    return 0;
}