/* 1966번 프린터큐(Brute Force)
 * https://www.acmicpc.net/problem/1966
 */

#include <iostream>
#include <queue>
using namespace std;

int testcase, N, M, answer;
queue<pair<int, int> > order;
priority_queue<int, vector<int>, less<int> > q;

void start() {
    int target_order = q.top();
    q.pop();

    while(!order.empty()) {
        int cnt_order = order.front().first;
        int cnt_index = order.front().second;
        order.pop();

        if(cnt_order == target_order) {
            if(cnt_index == M) break;
            answer++;
            target_order = q.top();
            q.pop();
        }
        else {
            order.push(make_pair(cnt_order, cnt_index));
        }
    }
}

int main() {
    scanf("%d", &testcase);
    for (int t = 1; t <= testcase; t++) {
        answer = 1;
        while(!order.empty()) order.pop();
        while(!q.empty()) q.pop();

        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; ++i) {
            int in; scanf("%d", &in);
            order.push(make_pair(in, i));
            q.push(in);
        }

        start();
        printf("%d\n", answer);
    }
    return 0;
}