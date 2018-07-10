/* 1759번 암호만들기(Backtracking)
 * https://www.acmicpc.net/problem/1759
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int inputL = 0, inputC = 0;
vector<string> answer;

void backtracking(vector<char> &text, vector<bool> &combination, int node, int count) {
	if (node == inputC || count == inputL){
		if(count != inputL)
			return;

		int vowel = 0, consonant = 0;
		string s = "";
		for (int i = 0; i < inputC; i++) {
			if (combination[i]) {
				if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u')
					vowel++;
				else
					consonant++;

				s += text[i];
			}
		}

		if (vowel >= 1 && consonant >= 2)
			answer.push_back(s);
		return;
	}

	backtracking(text, combination, node + 1, count);
	combination[node] = true;
	backtracking(text, combination, node + 1, count + 1);
	combination[node] = false;
}

int main() {
	cin >> inputL >> inputC;

	vector<char> text(inputC);
	for (int i = 0; i < inputC; i++)
		cin >> text[i];

    sort(text.begin(), text.end());

	vector<bool> combination(inputC, false);
	backtracking(text, combination, 1, 0);
	combination[0] = true;
	backtracking(text, combination, 1, 1);

	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] <<endl;
	return 0;
}