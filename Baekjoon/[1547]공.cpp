/* 1547번 공(Simulation)
 * https://www.acmicpc.net/problem/1547
 */

#include <iostream>
using namespace std;

int main() {
    int inputM;
    cin >> inputM;

    int answer = 1;
    for (int i = 0; i < inputM; i++) {
        int x, y;
        cin >> x >> y;

        if(x == answer)
            answer = y;
        else if (y == answer)
            answer = x;
    }

    cout << answer << endl;
    return 0;
}