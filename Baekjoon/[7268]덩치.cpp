/* 7568번 덩치(BruteForce)
 * https://www.acmicpc.net/problem/7568
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int inputN;
    cin >> inputN;

    vector<pair<int, int> > input(inputN, make_pair(0, 0));
    vector<int> answer(inputN, 1);
    for (int i = 0; i < inputN; i++)
        cin >> input[i].first >> input[i].second;

    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputN; j++) {
            if(i == j) 
                continue;
            if (input[i].first < input[j].first && input[i].second < input[j].second)
                answer[i]++;
        }
    }

    for (int i = 0; i<inputN; i++)
        cout << answer[i] << " ";

    return 0;
}