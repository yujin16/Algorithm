/* 5373 큐빙(Simulation)
 * https://www.acmicpc.net/problem/5373
 */

#include <iostream>
#include <vector>
using namespace std;

int Testcase, Rotation;
char side, dir;

void rotate(char cube[][8], int side, char dir) {
    vector<char> cubeside;
    for (int i = 0; i < 8; i++)
        cubeside.push_back(cube[side][i]);
        
    if(dir == '+') {
        cube[side][0] = cubeside[6];
        cube[side][1] = cubeside[7];
        for (int i = 2; i <= 7; i++)
            cube[side][i] = cubeside[i-2];
    } else if(dir == '-') {
        for (int i = 2; i <= 7; i++)
            cube[side][i-2] = cubeside[i];
        cube[side][6] = cubeside[0];
        cube[side][7] = cubeside[1];
    }
}

void rotateU(char cube[][8], char dir) {
    vector<char> cubeside;
    for (int i = 0; i <= 2; i++) cubeside.push_back(cube[1][i]);
    for (int i = 0; i <= 2; i++) cubeside.push_back(cube[2][i]);
    for (int i = 0; i <= 2; i++) cubeside.push_back(cube[3][i]);
    for (int i = 0; i <= 2; i++) cubeside.push_back(cube[4][i]);

    int index=0;
    if(dir == '+') {
        for (int i = 0; i <= 2; i++) cube[4][i] = cubeside[index++];
        for (int i = 0; i <= 2; i++) cube[1][i] = cubeside[index++];
        for (int i = 0; i <= 2; i++) cube[2][i] = cubeside[index++];
        for (int i = 0; i <= 2; i++) cube[3][i] = cubeside[index++];
    } else if(dir == '-') {
        for (int i = 0; i <= 2; i++) cube[2][i] = cubeside[index++];
        for (int i = 0; i <= 2; i++) cube[3][i] = cubeside[index++];
        for (int i = 0; i <= 2; i++) cube[4][i] = cubeside[index++];
        for (int i = 0; i <= 2; i++) cube[1][i] = cubeside[index++];
    }
    rotate(cube, 0, dir);
}

void rotateD(char cube[][8], char dir) {
    vector<char> cubeside;
    for (int i = 4; i <= 6; i++) cubeside.push_back(cube[4][i]);
    for (int i = 4; i <= 6; i++) cubeside.push_back(cube[3][i]);
    for (int i = 4; i <= 6; i++) cubeside.push_back(cube[2][i]);
    for (int i = 4; i <= 6; i++) cubeside.push_back(cube[1][i]);

    int index=0;
    if(dir == '+') {
        for (int i = 4; i <= 6; i++) cube[1][i] = cubeside[index++];
        for (int i = 4; i <= 6; i++) cube[4][i] = cubeside[index++];
        for (int i = 4; i <= 6; i++) cube[3][i] = cubeside[index++];
        for (int i = 4; i <= 6; i++) cube[2][i] = cubeside[index++];
    } else if(dir == '-') {
        for (int i = 4; i <= 6; i++) cube[3][i] = cubeside[index++];
        for (int i = 4; i <= 6; i++) cube[2][i] = cubeside[index++];
        for (int i = 4; i <= 6; i++) cube[1][i] = cubeside[index++];
        for (int i = 4; i <= 6; i++) cube[4][i] = cubeside[index++];
    }
    rotate(cube, 5, dir);
}

void rotateF(char cube[][8], char dir) {
    vector<char> cubeside;
    for (int i = 4; i <= 6; i++) cubeside.push_back(cube[0][i]);
    for (int i = 2; i <= 4; i++) cubeside.push_back(cube[1][i]);
    for (int i = 0; i <= 2; i++) cubeside.push_back(cube[5][i]);
    for (int i = 6; i <= 7; i++) cubeside.push_back(cube[3][i]);
    cubeside.push_back(cube[3][0]);

    int index=0;
    if(dir == '+') {
        for (int i = 6; i <= 7; i++) cube[3][i] = cubeside[index++]; cube[3][0] = cubeside[index++];
        for (int i = 4; i <= 6; i++) cube[0][i] = cubeside[index++];
        for (int i = 2; i <= 4; i++) cube[1][i] = cubeside[index++];
        for (int i = 0; i <= 2; i++) cube[5][i] = cubeside[index++];
    } else if(dir == '-') {
        for (int i = 2; i <= 4; i++) cube[1][i] = cubeside[index++];
        for (int i = 0; i <= 2; i++) cube[5][i] = cubeside[index++];
        for (int i = 6; i <= 7; i++) cube[3][i] = cubeside[index++]; cube[3][0] = cubeside[index++];
        for (int i = 4; i <= 6; i++) cube[0][i] = cubeside[index++];
    }
    rotate(cube, 2, dir);
}

void rotateB(char cube[][8], char dir) {
    vector<char> cubeside;
    for (int i = 0; i <= 2; i++) cubeside.push_back(cube[0][i]);
    for (int i = 2; i <= 4; i++) cubeside.push_back(cube[3][i]);
    for (int i = 4; i <= 6; i++) cubeside.push_back(cube[5][i]);
    for (int i = 6; i <= 7; i++) cubeside.push_back(cube[1][i]); cubeside.push_back(cube[1][0]);

    int index=0;
    if(dir == '+') {
        for (int i = 6; i <= 7; i++) cube[1][i] = cubeside[index++]; cube[1][0] = cubeside[index++];
        for (int i = 0; i <= 2; i++) cube[0][i] = cubeside[index++];
        for (int i = 2; i <= 4; i++) cube[3][i] = cubeside[index++];
        for (int i = 4; i <= 6; i++) cube[5][i] = cubeside[index++];
    } else if(dir == '-') {
        for (int i = 2; i <= 4; i++) cube[3][i] = cubeside[index++];
        for (int i = 4; i <= 6; i++) cube[5][i] = cubeside[index++];
        for (int i = 6; i <= 7; i++) cube[1][i] = cubeside[index++]; cube[1][0] = cubeside[index++];
        for (int i = 0; i <= 2; i++) cube[0][i] = cubeside[index++];
    }
    rotate(cube, 4, dir);
}

void rotateL(char cube[][8], char dir) {
    vector<char> cubeside;
    for (int i = 6; i <= 7; i++) cubeside.push_back(cube[0][i]); cubeside.push_back(cube[0][0]);
    for (int i = 2; i <= 4; i++) cubeside.push_back(cube[4][i]);
    for (int i = 6; i <= 7; i++) cubeside.push_back(cube[5][i]); cubeside.push_back(cube[5][0]);
    for (int i = 6; i <= 7; i++) cubeside.push_back(cube[2][i]); cubeside.push_back(cube[2][0]);

    int index=0;
    if(dir == '+') {
        for (int i = 6; i <= 7; i++) cube[2][i] = cubeside[index++]; cube[2][0] = cubeside[index++];
        for (int i = 6; i <= 7; i++) cube[0][i] = cubeside[index++]; cube[0][0] = cubeside[index++];
        for (int i = 2; i <= 4; i++) cube[4][i] = cubeside[index++];
        for (int i = 6; i <= 7; i++) cube[5][i] = cubeside[index++]; cube[5][0] = cubeside[index++];
    } else if(dir == '-') {
        for (int i = 2; i <= 4; i++) cube[4][i] = cubeside[index++];
        for (int i = 6; i <= 7; i++) cube[5][i] = cubeside[index++]; cube[5][0] = cubeside[index++];
        for (int i = 6; i <= 7; i++) cube[2][i] = cubeside[index++]; cube[2][0] = cubeside[index++];
        for (int i = 6; i <= 7; i++) cube[0][i] = cubeside[index++]; cube[0][0] = cubeside[index++];
    }
    rotate(cube, 1, dir);
}

void rotateR(char cube[][8], char dir) {
    vector<char> cubeside;
    for (int i = 2; i <= 4; i++) cubeside.push_back(cube[0][i]);
    for (int i = 2; i <= 4; i++) cubeside.push_back(cube[2][i]);
    for (int i = 2; i <= 4; i++) cubeside.push_back(cube[5][i]);
    for (int i = 6; i <= 7; i++) cubeside.push_back(cube[4][i]); cubeside.push_back(cube[4][0]);

    int index=0;
    if(dir == '+') {
        for (int i = 6; i <= 7; i++) cube[4][i] = cubeside[index++]; cube[4][0] = cubeside[index++];
        for (int i = 2; i <= 4; i++) cube[0][i] = cubeside[index++];
        for (int i = 2; i <= 4; i++) cube[2][i] = cubeside[index++];
        for (int i = 2; i <= 4; i++) cube[5][i] = cubeside[index++];

    } else if(dir == '-') {
        for (int i = 2; i <= 4; i++) cube[2][i] = cubeside[index++];
        for (int i = 2; i <= 4; i++) cube[5][i] = cubeside[index++];
        for (int i = 6; i <= 7; i++) cube[4][i] = cubeside[index++]; cube[4][0] = cubeside[index++];
        for (int i = 2; i <= 4; i++) cube[0][i] = cubeside[index++];
    }
    rotate(cube, 3, dir);
}

int main() {
    cin >> Testcase;
    for (int t = 1; t <= Testcase; t++) {
        char cube[6][8] = {{'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
                           {'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'},
                           {'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r'},
                           {'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'},
                           {'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
                           {'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y'}};

        cin >> Rotation;
        for (int i = 0; i < Rotation; i++) {
            cin >> side >> dir;
            switch (side) {
                case 'U' : rotateU(cube, dir); break; 
                case 'D' : rotateD(cube, dir); break; 
                case 'F' : rotateF(cube, dir); break; 
                case 'B' : rotateB(cube, dir); break; 
                case 'L' : rotateL(cube, dir); break; 
                case 'R' : rotateR(cube, dir); break;
            }
        }

        cout << cube[0][0] << cube[0][1] << cube[0][2] << endl;
        cout << cube[0][7] << 'w' << cube[0][3] << endl;
        cout << cube[0][6] << cube[0][5] << cube[0][4] << endl;
    }
    return 0;
}
