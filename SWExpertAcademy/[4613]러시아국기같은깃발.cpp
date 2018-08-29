/* 4613번 러시아 국기 같은 깃발
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWQl9TIK8qoDFAXj&categoryId=AWQl9TIK8qoDFAXj&categoryType=CODE
 */

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

enum COLOR { WHITE, BLUE, RED };
int color_count[51][3] = { 0, };

int main() {
    int Testcase;
    cin >> Testcase;

    for (int t = 1; t <= Testcase;t++) {
        int inputN, inputM;
        cin >> inputN >> inputM;

        for (int n = 1; n <= inputN; n++) {
            int white = 0, blue = 0, red = 0;

            for (int m = 0; m < inputM;m++) {
                char in;
                cin >> in;
                switch (in) {
                    case 'W': white++; break;
                    case 'B': blue++; break;
                    case 'R': red++; break;
                }
            }

            color_count[n][WHITE] = white + color_count[n - 1][WHITE];
            color_count[n][BLUE] = blue + color_count[n - 1][BLUE];
            color_count[n][RED] = red + color_count[n - 1][RED];
        }

        int answer = INT_MAX, white = 0, blue = 0, red = 0;
        for (int i = 1; i <= inputN - 2; i++) {
            white = (i * inputM) - color_count[i][WHITE];
            for (int j = i + 1; j <= inputN - 1; j++) {
                blue = (j - i) * inputM - (color_count[j][BLUE] - color_count[i][BLUE]);
                red = (inputN - j) * inputM - (color_count[inputN][RED] - color_count[j][RED]);
                answer = min(answer, white + blue + red);
            }
        }

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}
