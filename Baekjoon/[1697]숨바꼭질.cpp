/* 1697번 숨바꼭질(BFS & Backtracking)
 * https://www.acmicpc.net/problem/1949
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    int inputN, inputK, answer=0;
    cin >> inputN >> inputK;

    vector<bool> map(200001, false);
    queue<pair<int, int> > queue; //(num, sec)
    queue.push(make_pair(inputN, 0));

    while(!queue.empty()) {
        int num = queue.front().first;
        int sec = queue.front().second;
        queue.pop();

        map[num] = true;
        if(num == inputK) {
            answer = sec;
            break;
        }

        if (num+1 <= 200000 && !map[num + 1]) queue.push(make_pair(num + 1, sec + 1));
        if (num-1 >= 0 && !map[num - 1]) queue.push(make_pair(num - 1, sec + 1));
        if (num*2 <= 200000 && !map[num * 2]) queue.push(make_pair(num * 2, sec + 1));
    }

    cout << answer << endl;
    return 0;
}