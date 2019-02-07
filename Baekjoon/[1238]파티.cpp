/* 1238번 파티(Dijkstra algorithm)
 * https://www.acmicpc.net/problem/1238
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1000000
int N, M, X, answer = 0;

void Dijkstra(vector<vector<pair<int, int> > > &map, vector<int> &dist) {
    dist[X] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, X));
    while(!pq.empty()) {
        int d = pq.top().first, node = pq.top().second;
        pq.pop();

        int size = map[node].size();
        for(int i=0; i<size; i++) {
            int next_node = map[node][i].first, next_dist = d + map[node][i].second;
            if(next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push(make_pair(dist[next_node], next_node));
            }
        }
    }
}

int main() {
    vector<vector<pair<int, int> > > goX(1001), goHome(1001);
    vector<int> goX_dist(1001, INF), goHome_dist(1001, INF);
    
    scanf("%d %d %d", &N, &M, &X);
    for (int i = 0; i < M; i++) {
        int start, end, t;
        scanf("%d %d %d", &start, &end, &t);
        goHome[start].push_back(make_pair(end, t));
        goX[end].push_back(make_pair(start, t));
    }
    
    Dijkstra(goX, goX_dist);
    Dijkstra(goHome, goHome_dist);

    for (int i = 1; i <= N; i++)
        answer = max(answer, goX_dist[i] + goHome_dist[i]);

    cout << answer << endl;
    return 0;
}