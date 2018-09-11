/* 3349번 최솟값으로 이동하기 */

#include <iostream>
#include <cmath>
using namespace std;

struct POINT { int x, y; };
int T, W, H, N, answer;

int main() {
    cin >> T;

    for (int t = 1; t <= T; t++){
        POINT prev, cur, sub;
        answer = 0;

        cin >> W >> H >> N;
        cin >> prev.x >> prev.y;

        for (int i = 0; i < N - 1; i++) {
            cin >> cur.x >> cur.y;

            sub.x = cur.x - prev.x;
            sub.y = cur.y - prev.y;

            if(sub.x > 0 && sub.y > 0) {
                int diagonal = min(sub.x, sub.y);
                answer += diagonal;
                answer += (sub.x - diagonal) + (sub.y - diagonal);
            }
            else if(sub.x<0 && sub.y <0) {
                int diagonal = max(sub.x, sub.y);
                answer += diagonal * -1;
                answer += (sub.x - diagonal + sub.y - diagonal) * -1;
            }
            else
                answer += abs(sub.x) + abs(sub.y);

            prev.x = cur.x;
            prev.y = cur.y;
        }

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}