#include <iostream>
#include <vector>
using namespace std;

int N, M, S, E;
enum RESULT{NO, YES, NONE};

RESULT isPalindrom(const vector<int>&map, vector<vector<RESULT> >&memoization, int start, int end) {
    if (start == end) return YES;
    if(start > end) return YES;

    if(memoization[start][end] == YES) return YES;
    if(map[start] != map[end]) {
        memoization[start][end] = NO;
        return NO;
    }
    
    memoization[start][end] = isPalindrom(map, memoization, start + 1, end - 1);
    return memoization[start][end];
}

int main() {
    scanf("%d", &N);

    vector<int> map(N + 1, 0);
    vector<vector<RESULT> > memoization(N + 1, vector<RESULT>(N + 1, NONE));
    for (int i = 1; i <= N; i++) {
        scanf("%d", &map[i]);
        memoization[i][i] = YES;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &S, &E);
        printf("%d\n", isPalindrom(map, memoization, S, E));
    }

    return 0;
}