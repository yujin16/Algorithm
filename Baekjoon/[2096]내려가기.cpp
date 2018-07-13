/* 2096번 내려가기(Dymanic Programming)
 * https://www.acmicpc.net/problem/2096
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int dir_y[3] = {-1, 0, 1};

int main() {
    int inputN;
    cin >> inputN;

    vector<pair<int, int> > pre_vec(3, make_pair(0, 0));
    vector<pair<int, int> > in_vec(3, make_pair(0, 0));
    for (int n = 0; n < inputN; n++) {
        for (int i = 0; i < 3; i++) {
            int in;
            cin >> in;
            in_vec[i] = make_pair(in, in);
        }

        for (int i = 0; i < 3; i++) {
            int maxsum = INT_MIN, minsum = INT_MAX;
            
            for (int j = 0; j < 3; j++) {
                int index = i + dir_y[j];

                if (index >= 0 && index < 3) {
                    maxsum = max(maxsum, pre_vec[index].first);
                    minsum = min(minsum, pre_vec[index].second);
                }
            }

            in_vec[i].first += maxsum;
            in_vec[i].second += minsum;
        }

        pre_vec.assign(in_vec.begin(), in_vec.end());
    }

    int answer_max = INT_MIN, answer_min = INT_MAX;
    for (int i = 0; i<3; i++) {
        answer_max = max(answer_max, pre_vec[i].first);
        answer_min = min(answer_min, pre_vec[i].second);
    }

    cout << answer_max << " " << answer_min << endl;
    return 0;
}