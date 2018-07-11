/* 1008번 A/B(Input/Output)
 * https://www.acmicpc.net/problem/1008
 */

#include <iostream>
using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;

    double result = a / b;
    printf("%.10lf\n", result);
    return 0;
}