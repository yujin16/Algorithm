/* 2011번 암호코드
* https://www.acmicpc.net/problem/2011
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define NUM(X) (X-'0')
using namespace std;

int main() {
	char input[5001] = { 0 };
	int dp[5001] = { 0 };
	int count = 0;
	scanf("%s", &input);

	int position = 0;
	if (NUM(input[0]) != 0)
		dp[position++] = 1;
	else
		dp[position++] = 0;

	if (input[1] != '\0') {
		int sum = NUM(input[0]) * 10 + NUM(input[1]);
		if (NUM(input[0]) != 0 && NUM(input[1]) != 0 && sum > 0 && sum <= 26)
			dp[1] = dp[0] + 1;
		else
			dp[1] = dp[0];
		position++;
	}

	while (input[position] != '\0') {
		int sum = NUM(input[position - 1]) * 10 + NUM(input[position]);
		if (position)
			if (NUM(input[position - 1]) == 0)
				dp[position] = dp[position - 1];
			else if (NUM(input[position]) == 0)
				dp[position] = dp[position - 2];
			else if (sum > 0 && sum <= 26)
				dp[position] = (dp[position - 1] + dp[position - 2]) % 1000000;
			else
				dp[position] = dp[position - 1];
		position++;
	}

	cout << dp[--position] << endl;
	return 0;
}