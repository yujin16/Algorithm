/* 4301 콩많이심기
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWLv-yZah48DFAVV&categoryId=AWLv-yZah48DFAVV&categoryType=CODE
 */

#include <iostream>
#include <vector>
using namespace std;

enum STATE { POSSIBLE, IMPOSSIBLE, EMPTY };

int main() {
    int Testcase;
    cin >> Testcase;

    for (int t = 1; t <= Testcase; t++) {
        int inputN, inputM;
        cin >> inputN >> inputM;

        int answer = 0;
        vector<vector<int> > map(inputM, vector<int>(inputN, EMPTY));
        for (int i = 0; i < inputM; i++) {
            for (int j = 0; j < inputN; j++) {
                if(map[i][j] == EMPTY) {
                    map[i][j] = POSSIBLE;
                    answer++;

                    if(i+2 < inputM)
                        map[i + 2][j] = IMPOSSIBLE;
                    if(j+2 < inputN)
                        map[i][j + 2] = IMPOSSIBLE;
                }
            }
        }

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}