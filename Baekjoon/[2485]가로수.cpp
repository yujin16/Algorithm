/* 2485번 가로수()
 * https://www.acmicpc.net/problem/2485
 */

#include <iostream>
using namespace std;

int getGCD(int suv, int gcd) {
    int a = suv, b = gcd, r = 0;
    if(a < b) {
        a = gcd;
        b = suv;
    }
    while(b!=0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int inputN, start, prev, next;
    cin >> inputN;
    cin >> start >> prev >> next;
    
    int gcd = getGCD(prev - start, next - prev);
    prev = next;
    for (int i = 0; i < inputN - 3; i++){
        cin >> next;

        gcd = getGCD(next - prev, gcd);
        prev = next;
    }

    cout << (prev - start) / gcd - inputN + 1 << endl;
    return 0;
}