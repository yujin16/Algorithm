#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int inputT;
	cin >> inputT;

	for (int t = 0; t < inputT; t++) {
		int inputN, inputM, answer = 0;
		cin >> inputN >> inputM;
		
		vector<vector<int> > map(inputN + 1, vector<int>());
		for (int m = 0; m < inputM; m++) {
			int a = 0, b = 0;
			cin >> a >> b;
			map[a].push_back(b);
			map[b].push_back(a);
		}

		stack<pair<int, int> > stack;
		vector<bool> start_index(inputN + 1, true);

		for (int i = 1; i <= inputN && start_index[i]; i++) {
			for (int j = 0; j < map[i].size(); j++)
				stack.push(make_pair(map[i][j], 1));

			vector<int> visit_node(inputN + 1, false);
			while (!stack.empty()) {
				int node = stack.top().first;
				int count = stack.top().second;
				stack.pop();
				visit_node[node] = true;

				if (node == i && count == 3) {
					answer++;
					for (int j = 1; j < inputN + 1; j++)
						if (visit_node[j])
							start_index[visit_node[j]] = false;
					break;
				}

				for (int j = 0; j < map[node].size(); j++) {
					if(i == map[node][j] || !visit_node[map[node][j]])
						stack.push(make_pair(map[node][j], count+1));
				}
			}
		}

		cout << "Case #" << t + 1 << endl;
		cout << answer << endl;
		for (int i = 1; i < inputN + 1; i++)
			cout << start_index[i] << endl;
	}

	return 0;
}