#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PAIR;

int N, answer = 0;
PAIR map[100001];

bool cmp(PAIR a, PAIR b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) { 
        int s, e; 
        scanf("%d %d", &s, &e); 
        map[i] = PAIR(s, e); 
    }
    sort(map, map + N, cmp);

    int endTime = -1;
    for (int i = 0; i < N; ++i) {
        if (endTime <= map[i].first) {
            endTime = map[i].second;
            answer++;
        }
    }

    printf("%d\n", answer);
    return 0;
}