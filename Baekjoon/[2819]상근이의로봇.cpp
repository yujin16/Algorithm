/* 2819번 상근이의로봇
 * https://www.acmicpc.net/problem/2819
 */

#include <iostream>
#include <algorithm>
using namespace std;
#define MILLION 1000000

int N, M;
long long cur_sum = 0;
int sum_x[MILLION*2+1], sum_y[MILLION*2+1];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i<N; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        sum_x[MILLION+x]++;
        sum_y[MILLION+y]++;
        cur_sum += abs(x) + abs(y);
    }

    for(int i=1; i<MILLION*2; ++i) sum_x[i] = sum_x[i-1] + sum_x[i];
    for(int i=1; i<MILLION*2; ++i) sum_y[i] = sum_y[i-1] + sum_y[i];

    char in[300001];
    scanf("%s", in);

    int x = MILLION, y = MILLION;
    for (int i = 0; i < M; ++i) {
        int increase, decrease;
        switch(in[i]) {
            case 'S': increase = sum_y[y];   decrease = N-increase; ++y; break;
            case 'J': decrease = sum_y[y-1]; increase = N-decrease; --y; break;
            case 'I': increase = sum_x[x];   decrease = N-increase; ++x; break;
            case 'Z': decrease = sum_x[x-1]; increase = N-decrease; --x; break;
        }

        cur_sum += increase - decrease;
        printf("%lld\n", cur_sum);
    }
    return 0;
}