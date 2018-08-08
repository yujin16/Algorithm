/* 3_브라이언의 고민
 * 2017 kakao code festival 예선
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string sentence;
vector<bool> characters(26, false);
vector<string> answer;

bool isLower(char in) {
    if('a'<=in && in <= 'z')
        return true;
    else
        return false;
}

void rule1(char character, int start_index, int num) {
    string word;
    word = sentence[start_index - 1];
    sentence.erase(start_index - 1, 1);

    for (int i = start_index - 1; i < sentence.size();) {
        if(sentence[i] == character) {
            word += sentence[i + 1];
            sentence.erase(i, 2);
        }
        else
            break;
    }

    answer.push_back(word);
    cout << "<<< rule1 >>>" << endl;
    cout << "word : " << word << endl;
    cout << "sentence : " << sentence << endl;
}

void rule2(char character, int start_index) {
    
}

int main() {
    cin >> sentence;

    char character;
    for (int i = 0; i < sentence.size(); i++) {
        character = sentence[i];
        if (isLower(character) && !characters[character - 'a']) {
            characters[character - 'a'] = true;

            int num = 0;
            for (int j = 0; j < sentence.size(); j++)
                if(sentence[j] == character)
                    num++;
            
            if(num == 2)
                rule2(character, i);
            else if(num > 2)
                rule1(character, i, num);

            i = 0;
        }
    }

    return 0;
}