/* 1315번 RPG(Dynamic Programming)
 * https://www.acmicpc.net/problem/1315
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct STAT {
    int STR;
    int INT;
    int PNT;
    bool CLEAR;
};

int inputN, answer = 0;
STAT quest[1001];
int dp[1001][1001];

void solve(int S, int I) {
    if(dp[S][I] != 0) return;

    vector<int> v;
    int point = 0;
    for (int n = 0; n < inputN; n++) {
        if(quest[n].CLEAR)
            dp[S][I]++;
        else {
            if (quest[n].STR <= S || quest[n].INT <= I) {
                v.push_back(n);
                quest[n].CLEAR = true;
                point += quest[n].PNT;
                dp[S][I]++;
            }
        }
    }

    if (point != 0) {
        for (int p1 = 0; p1 < point; p1++) {
            int p2 = point - p1;
            int s = S + p1, i = I + p2;
            if (s >= 1000)
                s = 1000;
            if(i >= 1000) i = 1000;
            solve(s, i);
        }
    }

    for (int i = 0; i < v.size(); i++)
        quest[v[i]].CLEAR = false;

        answer = max(answer, dp[S][I]);
}

int main() {
    cin >> inputN;
    for (int i = 0; i < inputN; i++) {
        int str, intel, pnt;
        cin >> str >> intel >> pnt;
        quest[i].STR = str;
        quest[i].INT = intel;
        quest[i].PNT = pnt;
        quest[i].CLEAR = false;
    }

    solve(1, 1);
    cout << answer << endl;
    return 0;
}