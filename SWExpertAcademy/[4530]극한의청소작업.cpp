/* 4530 극한의청소작업
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWO6cgzKOIEDFAWw&categoryId=AWO6cgzKOIEDFAWw&categoryType=CODE
 */

#include <iostream>
#include <cmath>
using namespace std;

long long exclude4(long long end) {
    int stair[12] = { 0, };

    int index = 11;
    while (index >= 0) {
        long long div = pow(10, index);
        long long rest = end / div;

        if(rest >= 4)
            stair[index] = rest - 1;
        else
            stair[index] = rest;

        end -= rest * pow(10, index);
        index--;
    }

    long long sum = 0;
    for (int i = 0; i < 12;i++)
        sum += pow(9, i) * stair[i];

    return sum;
}

int main() {
    int Testcase;
    cin >> Testcase;

    for (int t = 1; t <= Testcase; t++) {
        long long inputA, inputB, answer = 0;
        cin >> inputA >> inputB;

        if(inputA<0 && inputB<0)
            answer = exclude4(inputA * -1) - exclude4(inputB * -1);
        else if(inputA<0 && inputB>0)
            answer = exclude4(inputA * -1) + exclude4(inputB) - 1;
        else if(inputA>0 && inputB>0)
            answer = exclude4(inputB) - exclude4(inputA);

        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}