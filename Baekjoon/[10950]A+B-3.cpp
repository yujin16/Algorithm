/* 10950번 A+B-3(Input/Output)
 * https://www.acmicpc.net/problem/10950
 */

#include <iostream>
using namespace std;

int Testcase;

int main() {
    cin >> Testcase;
    for (int t = 1; t <= Testcase; t++) {
        int a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}