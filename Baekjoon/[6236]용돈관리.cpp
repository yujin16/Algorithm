/* 6236번 용돈관리(BinarySearch)
 * https://www.acmicpc.net/problem/6236
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int day_money[100000];

int withdraw(int money) {
    int answer = 1;
    int now = 0;
    for (int i = 0; i < N; i++) {
        if(now + day_money[i] > money) {
            answer++;
            now = day_money[i];
        }
        else   
            now += day_money[i];
    }
    return answer;
}

int main() {
    scanf("%d %d", &N, &M);

    int start = 0, end = 1000000000;
    for (int i = 0; i < N; i++) {
        scanf("%d", &day_money[i]);
        start = max(start, day_money[i]);
    }

    while (start < end) {
        int mid = (start + end) / 2;
        if(withdraw(mid) > M)
            start = mid + 1;
        else
            end = mid;
    }

    printf("%d\n", start);
    return 0;
}