/* 5213번 진수의 홀수 약수 */

#include <iostream>
#include <cmath>
using namespace std;

int Testcase, inputL, inputR;
long long divisorSum[1000001] = {0, };

int main() {
    std::ios::sync_with_stdio(false);
    cin >> Testcase;

    for (int i = 1; i <= 1000000; i++) {
        long long sum = 0;
        int maximum = sqrt(i);

        if(i%2 == 0) {
            sum = divisorSum[i / 2] - divisorSum[i / 2 - 1];
            divisorSum[i] = divisorSum[i-1] + sum;
            continue;
        }

        for (int j = 1; j <= maximum; j++) {
            if(i % j == 0) {
                int q = i / j;
                if (q == j && j % 2 != 0) {
                    sum += j;
                    continue;
                }
                
                if (j % 2 != 0)
                    sum += j;
                if(q % 2 != 0)
                    sum += q;
            }
        }
        divisorSum[i] = divisorSum[i-1] + sum;
    }

    for (int t = 1; t <= Testcase; t++) {
        cin >> inputL >> inputR;
        cout << "#" << t << " " << divisorSum[inputR] - divisorSum[inputL-1] << endl;
    }
    return 0;
}