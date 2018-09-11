/* 4740번 밍이의 블록 게임 */

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int Testcase, inputN, inputM, inputQ;
char map[30][30];
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

void buttonU(string newline) {
    for(int i=0; i<inputM; i++)
        if(map[0][i] != '#')
            return;

    queue<char> q;
    for (int m = 0; m < inputM; m++) {
        if(newline[m] != '#')
            q.push(newline[m]);
        for (int n = inputN - 1; n >= 0; n--) {
            if(map[n][m] != '#')
                q.push(map[n][m]);
        }

        int index = inputN - 1;
        while (!q.empty()) {
            char color = q.front();
            q.pop();
            map[index--][m] = color;
        }
        while(index >= 0) {
            map[index--][m] = '#';
        }
    }
}

void buttonL() {
    queue<char> q;
    for (int n = 0; n < inputN;n++){
        for (int m = 0; m < inputM; m++) {
            if(map[n][m] != '#')
                q.push(map[n][m]);
        }

        int index = 0;
        while (!q.empty()) {
            char color = q.front();
            q.pop();
            map[n][index++] = color;
        }
        while(index < inputM) {
            map[n][index++] = '#';
        }
    }
}

void buttonR() {
    queue<char> q;
    for (int n = 0; n < inputN; n++) {
        for (int m = inputM - 1; m >= 0; m--) {
            if(map[n][m] != '#')
                q.push(map[n][m]);
        }

        int index = inputM - 1;
        while (!q.empty()) {
            char color = q.front();
            q.pop();
            map[n][index--] = color;
        }
        while(index >= 0) {
            map[n][index--] = '#';
        }
    }
}

void buttonD() {
    int maxCount = 0;
    bool visited[30][30] = {false, };
    
    queue<pair<int, int> > erase;
    for (int n = 0; n < inputN; n++) {
        for (int m = 0; m < inputM; m++) {
            if(map[n][m] == '#') visited[n][m] = true;
            if(!visited[n][m]) {
                int count = 0;
                queue<pair<int, int> > points;
                queue<pair<int, int> > q;
                q.push(make_pair(n, m));
                points.push(make_pair(n, m));
                visited[n][m] = true;

                char color;
                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    color = map[x][y];
                    q.pop();

                    count++;

                    for (int i = 0; i < 4;i++) {
                        int new_x = x + dir_x[i], new_y = y + dir_y[i];
                        if(new_x>=0 && new_x<inputN && new_y>=0 && new_y<inputM) {
                            if(!visited[new_x][new_y] && map[new_x][new_y] == color) {
                                q.push(make_pair(new_x, new_y));
                                points.push(make_pair(new_x, new_y));
                                visited[new_x][new_y] = true;
                            }
                        }
                    }
                }

                if(maxCount < count) {
                    while(!erase.empty())
                        erase.pop();
                    maxCount = count;
                }

                if(maxCount == count) {
                    while(!points.empty()) {
                        int x = points.front().first, y = points.front().second;
                        points.pop();
                        erase.push(make_pair(x, y));
                    }
                }
            }
        }
    }

    while(!erase.empty()) {
        int x = erase.front().first, y = erase.front().second;
        erase.pop();
        map[x][y] = '#';
    }

    queue<char> q;
    for (int m = 0; m < inputM; m++) {
        for (int n = inputN - 1; n >= 0; n--) {
            if(map[n][m] != '#')
                q.push(map[n][m]);
        }

        int index = inputN - 1;
        while (!q.empty()) {
            char color = q.front();
            q.pop();
            map[index--][m] = color;
        }
        while(index >= 0) {
            map[index--][m] = '#';
        }
    }
}

int main() {
    cin >> Testcase;
    for (int t = 1; t <= Testcase; t++) {
        cin >> inputN >> inputM >> inputQ;

        for (int n = 0; n < inputN;n++)
            for (int m = 0; m < inputM;m++)
                cin >> map[n][m];

        for (int q = 0; q < inputQ; q++){
            char question;
            cin >> question;

            string newline;
            switch (question) {
                case 'U': 
                    cin >> newline;
                    buttonU(newline);
                    break;
                case 'L': buttonL(); break;
                case 'R': buttonR(); break;
                case 'D': buttonD(); break;
            }
        }

        cout << "#" << t << endl;
        for (int n = 0; n < inputN;n++) {
            for (int m = 0; m < inputM;m++)
                cout << map[n][m];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}