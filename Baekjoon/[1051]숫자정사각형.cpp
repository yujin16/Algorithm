/* 1052번 숫자정사각형(Dynamic Programming)
 * https://www.acmicpc.net/problem/1052
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int inputN, inputM;
    cin >> inputN >> inputM;

    vector<vector<int> > map(inputN, vector<int>(inputM, 0));
    for (int i = 0; i < inputN; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < inputM; j++)
            map[i][j] = s[j] - '0';
    }

    int inputS = min(inputN, inputM);
    int answer = 1;
    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputM; j++) {
            for (int size = 1; size < inputS; size++) {
                if(i+size >= inputN || j+size >= inputM)
                    continue;
                    
                int num1 = map[i][j];               // top_left
                int num2 = map[i][j + size];        // top_right
                int num3 = map[i + size][j];        // bottom_left
                int num4 = map[i + size][j + size]; // bottom_right

                int ssize = (size + 1) * (size + 1);
                if (num1 == num2 && num1 == num3 && num1 == num4 && answer < ssize)
                    answer = ssize;
            }
        }
    }

    cout << answer << endl;
    return 0;
}