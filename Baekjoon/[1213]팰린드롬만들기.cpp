/* 1213번 팰린드롬만들기(BruteForce)
 * https://www.acmicpc.net/problem/1213
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	char name[51] = { 0 };
	int alphabet[26] = { 0 };
	cin >> name;

	for (int i = 0; i < 51; i++)
		alphabet[name[i] - 'A']++;

	int position = -1;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] % 2 == 1) {
			if (position == -1) {
				position = i;
				alphabet[i]--;
			}
			else {
				cout << "I'm Sorry Hansoo" << endl;
				return 0;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		int len = alphabet[i] / 2;
		for (int j = 0; j < len; j++)
			printf("%c", i + 'A');
		alphabet[i] /= 2;
	}

	if (position != -1)
		printf("%c", position + 'A');

	for (int i = 25; i >= 0; i--) {
		int len = alphabet[i];
		for (int j = 0; j < len; j++)
			printf("%c", i + 'A');
	}

	return 0;
}