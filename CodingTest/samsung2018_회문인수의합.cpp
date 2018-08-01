/* 3_회문인수의 합
 * 2018 삼성전자 대학생 프로그래밍 경진대회 예선
 */

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

bool isPalindrome(int num) {
	bool answer = true;
	string s = to_string(num);
	int len = s.size() - 1;

	for (int i = 0; i < len && answer; i++) {
		if (s[i] != s[len - i])
			answer = false;
	}
	return answer;
}

int main() {
	int inputT;
	cin >> inputT;

	vector<int> palindrome;
	vector<int> vec_index(10001, 0);
	for (int i = 1; i < 10001; i++) {
		if (isPalindrome(i))
			palindrome.push_back(i);
		vec_index[i] = palindrome.size() - 1;
	}

	for (int t = 0; t < inputT; t++) {
		int inputN, answer_size=INT_MAX;
		cin >> inputN;

		vector<int> answer_index;
		for (int i = vec_index[inputN]; i >= 0; i--) {
			vector<int> tmp;
			bool success = true;
			int val = inputN, index = i;
			tmp.push_back(index);

			while (success) {
				val -= palindrome[index];

				if (val <= 0) break;
				if (index < vec_index[val]) { success = false;  break; }

				index = vec_index[val];
				tmp.push_back(index);
			}

			
			if (success && answer_size > tmp.size()) {
				answer_size = tmp.size();
				answer_index.resize((int)answer_size);
				copy(tmp.begin(), tmp.end(), answer_index.begin());
			}
		}

		cout << "Case #" << t + 1 << endl;
		if (answer_size > 3)
			cout << "0" << endl;
		else {
			cout << answer_size;
			for (int i = 0; i < answer_index.size(); i++)
				cout << " " << palindrome[answer_index[i]];
			cout << endl;
		}
	}

	return 0;
}