/* 2231 분해합(Brute Force)
 * https://www.acmicpc.net/problem/2231
 */

#include <iostream>
using namespace std;

int N, answer;

int main() {
    scanf("%d", &N);
    for(int i=N-54; i<N; ++i) {
        int n = i, sum = i;
        while(n>0) {
            sum += n%10;
            n/=10;
        }
        if(sum == N) {
            answer = i;
            break;
        }
    }
    printf("%d\n", answer);
	return 0;
}