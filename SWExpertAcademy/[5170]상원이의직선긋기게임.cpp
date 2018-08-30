/* 5170번 상원이의 직선 긋기 게임 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Testcase, inputN;

int main() {
    cin >> Testcase;

    for (int t = 1; t <= Testcase; t++) {
        cin >> inputN;
        vector<pair<int, int> > point(inputN);
        for (int i = 0; i<inputN; i++)
            cin >> point[i].first >> point[i].second;
        
        vector<double> gradients;
        for (int i = 0; i < inputN; i++) {
            for (int j = i + 1; j < inputN; j++) {
                double gradient;
                int x = point[i].first - point[j].first, y = point[i].second - point[j].second;

                if (x == 0)
                    gradient = 1000000;
                else
                    gradient = 1.0 * y / x;
                gradients.push_back(gradient);
            }
        }

        sort(gradients.begin(), gradients.end());
        gradients.erase(unique(gradients.begin(), gradients.end()), gradients.end());
        cout << "#" << t << " " << gradients.size() << endl;
    }
    return 0;
}