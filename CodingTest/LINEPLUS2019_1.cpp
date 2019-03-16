/*
> 문제 설명
유클리드 공간에서, 넓이가 N인 직사각형 두 변을 각각 w, h라 한다. 이때 가능한 w, h 중 |w - h|의 최솟값을 구하시오.

> 조건
사각형의 넓이 N (1 <= N <= 10^13), 변의 길이 w, h는 모두 자연수이다.

> 입력 형식
사각형 넓이 N을 표준 입력에서 읽는다.

> 출력 형식
|w - h|의 최솟값을 표준 출력에 쓴다.
*/

#include <iostream>
#include <cmath>
using namespace std;

long long N, answer;

int main() {
    scanf("%lli", &N);
    answer = N - 1;

    long long center = sqrt(N), left = center, right = center;
    for (; 1 <= left && right <= answer; --left, ++right) {
        long long r = N / left, l = N / right;

        if(N % left == 0)   answer = min(answer, abs(left - r));
        if(N % right == 0)  answer = min(answer, abs(right - l));

        if(answer != N-1) break;
    }

    printf("%lli\n", answer);
    return 0;
}