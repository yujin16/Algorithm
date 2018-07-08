/* 1803번 Shortest Path Faster
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do
 */

/*
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <functional>
#define MIN(X,Y) (X)<(Y)? (X):(Y)
using namespace std;

int inputN, inputM, start_node, arrive_node;
long long result;

void bfs(vector<vector<pair<int, int> > > &map, vector<long long> &min_weight) {
	priority_queue< pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > queue;
	queue.push(make_pair(0, start_node));

	while (!queue.empty()) {
		int cur_node = queue.top().second;
		int weight_sum = queue.top().first;
		queue.pop();

		if (result < weight_sum) continue;
		if (cur_node == arrive_node) {
			result = MIN(result, weight_sum);
			continue;
		}

		for (int i = 0; i < map[cur_node].size(); i++) {
			int next_node = map[cur_node][i].first;
			int weight = map[cur_node][i].second;

			if (next_node != start_node && weight_sum + weight < min_weight[next_node]) {
				min_weight[next_node] = weight_sum + weight;
				queue.push(make_pair(min_weight[next_node], next_node));
			}
		}
	}
}

int main() {
	int testcase;
	cin >> testcase;

	ios::sync_with_stdio(false); cin.tie(0);
	for (int t = 0; t < testcase; t++) {
		result = LLONG_MAX;
		cin >> inputN >> inputM >> start_node >> arrive_node;
		vector<vector<pair<int, int> > > map(inputN + 1,vector<pair<int, int> >());
		vector<long long> min_weight(inputN + 1, LLONG_MAX);

		for (int m = 0; m < inputM; m++) {
			int n_start, n_end, weight;
			cin >> n_start >> n_end >> weight;
			map[n_start].push_back(make_pair(n_end, weight));
			map[n_end].push_back(make_pair(n_start, weight));
		}

		bfs(map, min_weight);
		std::cout << "#" << t + 1 << " " << result << endl;
	}
	return 0;
}
*/