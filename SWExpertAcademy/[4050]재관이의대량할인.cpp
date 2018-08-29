/* 4050번 재관이의 대량 할인 */

#include <iostream>
#include <algorithm>
using namespace std;

int price[100001] = { 0, };

int main() {
    int Testcase;
    cin >> Testcase;

    for (int t = 1; t <= Testcase; t++) {
        int inputN;
        cin >> inputN;

        int answer = 0;
        for (int i = 0; i < inputN; i++) {
            cin >> price[i];
            answer += price[i];
        }
        sort(price, price+inputN);

        for (int i = inputN - 3; i >= 0; i-=3)
            answer -= price[i];
        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}