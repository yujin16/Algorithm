/* 9328번 열쇠(BFS)
 * https://www.acmicpc.net/problem/9328
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int T, H, W, answer = 0;
string map[100];
bool key[26];

int dir_h[4] = {1, -1, 0, 0};
int dir_w[4] = {0, 0, 1, -1};

void bfs() {
    queue<pair<int, int> > queue;
    vector<pair<int, int> > door[26];

    for (int h = 0; h < H; ++h)
        for (int w = 0; w < W; ++w)
            if (h == 0 || h == H - 1 || w == 0 || w == W - 1)
                if(map[h][w] != '*')
                    queue.push(make_pair(h, w));
                    

    while(!queue.empty()) {
        int h = queue.front().first, w = queue.front().second;
        queue.pop();

        char c = map[h][w];
        if (c == '*')       continue;
        else if(c == '$')   answer++;
        else if ('a' <= c && c <= 'z') {
            key[c - 'a'] = true;
            
            int size = door[c - 'a'].size();
            for (int i = 0; i < size; ++i) {
                int dh = door[c - 'a'][i].first, dw = door[c - 'a'][i].second;
                queue.push(make_pair(dh, dw));
            }
        }
        else if ('A' <= c && c <= 'Z') {
            if(!key[c - 'A']) {
                door[c - 'A'].push_back(make_pair(h, w));
                continue;
            }
        }

        map[h][w] = '*';
        for (int i = 0; i < 4; i++) {
            int nh = h + dir_h[i], nw = w + dir_w[i];

            if (nh >= 0 && nh < H && nw >= 0 && nw < W && map[nh][nw] != '*')
                queue.push(make_pair(nh, nw));
        }
    }
}

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d %d", &H, &W);
        for (int h = 0; h < H; ++h)
            cin >> map[h];

        for (int i = 0; i < 26; ++i)
            key[i] = false;

        string in;
        cin >> in;
        if(in != "0") {
            int size = in.length();
            for (int i = 0; i < size; ++i)
                key[in[i] - 'a'] = true;
        }

        answer = 0;
        bfs();
        printf("%d\n", answer);
    }
    return 0;
}