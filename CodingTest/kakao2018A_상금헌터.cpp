/* 1_상금헌터
 * 2018 kakao code festival 예선
 */

#include<iostream>
using namespace std;

int main() {
    int inputT;
    cin >> inputT;

    for (int t = 0; t < inputT; t++) {
        int contest1, contest2;
        cin >> contest1 >> contest2;

        int sum = 0;
        if(contest1 == 1)
            sum += 5000000;
        else if(2<= contest1 && contest1 <= 3)
            sum += 3000000;
        else if(4<=contest1 && contest1 <= 6)
            sum += 2000000;
        else if(7<= contest1 && contest1 <= 10)
            sum += 500000;
        else if(11<= contest1 && contest1 <= 15)
            sum += 300000;
        else if(16<= contest1 && contest1 <= 21)
            sum += 100000;

        if(contest2 == 1)
            sum += 5120000;
        else if(2<= contest2 && contest2 <= 3)
            sum += 2560000;
        else if(4<=contest2 && contest2 <= 7)
            sum += 1280000;
        else if(8<= contest2 && contest2 <= 15)
            sum += 640000;
        else if(16<= contest2 && contest2 <= 31)
            sum += 320000;

        cout << sum << endl;
    }
    return 0;
}