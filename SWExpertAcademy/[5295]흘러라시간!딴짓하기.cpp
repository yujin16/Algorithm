/* 5295번 흘러라 시간! 딴 짓하기 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int Testcase, inputN;
int map[3][100001];

int main() {
    cin >> Testcase;

    for (int t = 1; t <= Testcase;t++) {
        vector<vector<int> > num_count(3, vector<int>(100001));
        cin >> inputN;

        for (int i = 1; i<=inputN; i++)
            cin >> map[0][i];
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= inputN; j++) {
                int num, index = map[0][j];
                cin >> num;
                map[i][index] = num;
                num_count[i][num]++;
            }
        }

        queue<int> erase_num;
        for (int i = 1; i <=2; i++)
            for (int j = 1; j <= inputN; j++)
                if(num_count[i][j] == 0)
                    erase_num.push(j);
        
        int answer = 0;
        while(!erase_num.empty()) {
            int index = erase_num.front();
            erase_num.pop();

            if(map[0][index] == 0) continue;

            map[0][index] = 0;
            answer++;

            int second_num = map[1][index];
            num_count[1][second_num]--;
            if(num_count[1][second_num] <= 0)
                erase_num.push(second_num);

            int third_num = map[2][index];
            num_count[2][third_num]--;
            if(num_count[2][third_num] <= 0)
                erase_num.push(third_num);
        }
        cout << "#" << t << " " << answer << endl;
    }
    return 0;
}