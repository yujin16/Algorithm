#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

enum {NONE, HOME, CHICKEN};
int N, M, answer = INT_MAX, home_num, chicken_num;
vector<pair<int, int> > homePos;
vector<pair<int, int> > chickenPos;
vector<vector<int> >    dist;
vector<int>            selected_chicken;

void bfs_calculation() {
    int dist_sum = 0;
    for (int i = 0; i < home_num; i++) {
        int min_dist = INT_MAX;
        for (int j = 0; j < M; j++)
            min_dist = min(min_dist, dist[i][selected_chicken[j]]);
        dist_sum += min_dist;
    }
    answer = min(answer, dist_sum);
}

void dfs_selection(int size, int index) {
    if(M <= size) {
        bfs_calculation();
        return;
    }

    for (int i = index+1; i < chicken_num; i++) {
        selected_chicken.push_back(i);
        dfs_selection(size + 1, i);
        selected_chicken.pop_back();
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int in;
            scanf("%d", &in);
            if(in == HOME) homePos.push_back(make_pair(i, j));
            else if(in == CHICKEN) chickenPos.push_back(make_pair(i, j));
        }
    }

    home_num = homePos.size();
    chicken_num = chickenPos.size();
    dist.assign(home_num, vector<int>(chicken_num, 0));
    for (int i = 0; i < home_num; i++) {
        for (int j = 0; j < chicken_num; j++) {
            int r = abs(homePos[i].first - chickenPos[j].first);
            int c = abs(homePos[i].second - chickenPos[j].second);
            dist[i][j] = r + c;
        }
    }

    for (int i = 0; i < chicken_num; i++) {
        selected_chicken.push_back(i);
        dfs_selection(1, i);
        selected_chicken.pop_back();
    }

    printf("%d\n", answer);
}