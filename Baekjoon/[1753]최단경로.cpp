#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int, int> PAIR;

int V, E, K;
vector<PAIR> map[20001];
vector<int> dist(20001, INT_MAX);

int main() {
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        map[u].push_back(make_pair(v, w));
    }

    dist[K] = 0;
    priority_queue<PAIR, vector<PAIR>, greater<PAIR> > pq;
    pq.push(make_pair(0, K));   // (weight, spot)
    while(!pq.empty()) {
        int u = pq.top().second;        // current spot
        int w = pq.top().first;         // weight(K to u)
        pq.pop();

        int len = map[u].size();
        for (int i = 0; i < len; ++i) {
            int v = map[u][i].first;            // next spot
            int weight = map[u][i].second;      // next weight

            if (dist[v] > w + weight) {
                dist[v] = w + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for(int i=1; i<=V; ++i) {
        int tmp = dist[i];
        if(tmp == INT_MAX)
            printf("INF\n");
        else
            printf("%d\n", tmp);
    }
        
    return 0;
}