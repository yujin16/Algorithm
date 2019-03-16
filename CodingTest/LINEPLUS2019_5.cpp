/*
> 문제 설명
연인 코니와 브라운은 광활한 들판에서 '나 잡아 봐라' 게임을 한다. 이 게임은 브라운이 코니를 잡거나 코니가 너무 멀리 달아나면 끝난다. 게임이 끝나는데 걸리는 최소 시간을 구하시오.

> 조건
코니는 처음 위치에서 1초 후 1만큼 움직이고, 이 후에는 가속이 붙어 매 초마다 이전 이동 거리 + 1 만큼 움직인다. 즉, 시간에 따른 코니의 위치는 C, C + 1, C + 3, C + 6, ...이다.
브라운은 현재 위치 B에서 다음 순간 B - 1, B + 1, 2 * B 중 하나로 이동할 수 있다.
코니와 브라운의 위치 x는 0 <= x <= 200,000이다.
브라운은 범위를 벗어나는 위치로는 이동할 수 없고, 코니가 범위를 벗어나면 게임이 끝난다.

> 입력 형식
표준 입력의 첫 줄에서 코니의 위치 C와 브라운의 위치 B를 공백으로 구분하여 순서대로 읽는다.

> 출력 형식
브라운이 코니를 잡을 수 있는 최소 시간 N초의 N을 표준 출력에 쓴다.
브라운이 코니를 잡지 못한 상태로 게임이 끝나면 표준 출력에 -1을 쓴다.

> 예
입력: 11 2
출력: 5
코니의 위치: 11, 12, 14, 17, 21, 26, ...
브라운의 위치: 2, 3, 6, 12, 13, 26, ...
브라운은 코니를 5초 만에 잡을 수 있다.
*/

#include <iostream>
#include <climits>
using namespace std;

int CONY, BROWN, answer = -1, TIME = 0;

void backtracking(int cony, int depth) {
    if (cony < 0 || 200000 < cony) return;

    if(TIME < depth) return;
    else if(TIME == depth) {
        if(cony == BROWN) {
            answer = TIME;
            return;
        }
    }
    else if(depth < TIME) {
        if(cony > BROWN) {
            backtracking(cony - 1, depth + 1);
            if(cony % 2 == 0)
                backtracking(cony / 2, depth + 1);
        }
        else if(cony < BROWN) {
            backtracking(cony + 1, depth + 1);
        }
    }
}

int main() {
    scanf("%d %d", &CONY, &BROWN);

    while(answer == -1) {
        backtracking(CONY, 0);

        CONY += ++TIME;
        if(CONY < 0 || 200000 < CONY) break;
    };

    printf("%d\n", answer);
    return 0;
}