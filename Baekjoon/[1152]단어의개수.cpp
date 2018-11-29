/* 1152번 단어의 개수
 * https://www.acmicpc.net/problem/1152
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    char in[1000000];

    int count = 0;
    while(scanf("%s", in)!=EOF) {
        count++;
    }

    cout << count << endl;
    return 0;
}