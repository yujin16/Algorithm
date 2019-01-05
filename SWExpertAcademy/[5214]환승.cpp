#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, M;
vector<vector<int> > map(101001);
vector<bool> visited(101001, false);
vector<int> depth(101001, -1);

int main() {
    scanf("%d %d %d", &N, &K, &M);
    for (int i = 100001; i < 100001+M; i++) {
        for (int j = 0; j < K; j++) {
            int in;
            scanf("%d", &in);
            map[i].push_back(in);
            map[in].push_back(i);
        }
    }

    queue<int> queue;
    queue.push(1);
    visited[1] = true;
    depth[1] = 1;
    while (!queue.empty()) {
        int station = queue.front();
        queue.pop();

        int size = map[station].size();
        for (int i = 0; i < size; i++) {
            int next = map[station][i];
            if(!visited[next]) {
                queue.push(next);
                visited[next] = true;
                if(next<=100000) depth[next] = depth[station] + 1;
                else depth[next] = depth[station];
            }
        }
    }

    printf("%d\n", depth[N]);
    return 0;
}