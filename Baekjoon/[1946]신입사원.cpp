/* 1946번 신입사원()
 * https://www.acmicpc.net/problem/1946
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int testcase;
    cin >> testcase;

    for (int t = 0; t < testcase; t++) {
        int inputN = 0;
        cin >> inputN;

        vector<int> interview_rank(inputN + 1);
        for (int i = 0; i < inputN; i++) {
            int document, interview;
            cin >> document >> interview;
            interview_rank[document] = interview;
        }

        vector<bool> result(inputN, true);
        int interview_rank_min = interview_rank[1];
        for (int i = 2; i <= inputN; i++) {
            if(interview_rank_min < interview_rank[i]) {
                result[i] = false;
                continue;
            }

            interview_rank_min = min(interview_rank_min, interview_rank[i]);
        }

        int answer = 0;
        for (int i = 1; i <= inputN; i++)
            if(result[i])
                answer++;
                
        cout << answer << endl;
    }
    return 0;
}