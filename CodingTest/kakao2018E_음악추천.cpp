/* 3_음악추천
 * 2018 kakao code festival 예선
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int> > &tree, vector<vector<int> > &child, int node) {
    for (int i = 0; i < tree[node].size(); i++) {
        int next_node = tree[node][i];
        dfs(tree, child, next_node);
        for (int j = 0; j < child[next_node].size(); j++)
            child[node].push_back(child[next_node][j]);
    }
}

int main() {
    int inputN, inputK, inputJ;
    cin >> inputN >> inputK >> inputJ;

    // 트리만들기(인접리스트)
    vector<vector<int> > tree(inputN + 1);
    for (int i = 2; i <= inputN; i++) {
        int parent_node;
        cin >> parent_node;
        tree[parent_node].push_back(i);
    }

    // 각 노드의 자식 구하기
    vector<vector<int> > child(inputN + 1);
    for (int i = 1; i <= inputN; i++)
        child[i].push_back(i);
    dfs(tree, child, 1);

    /*for (int i = 1; i <= inputN; i++) {
        for (int j = 0; j < child[i].size(); j++)
            cout << child[i][j] << " ";
        cout << endl;
    }*/

    // 곡의 가수가 누군지 저장, 가수의 곡이 몇 곡인지 저장.
    vector<int> singerOfsong(inputN + 1, 0);
    vector<int> songNumOfsinger(inputN + 1);
    for (int i = 1; i <= inputN; i++) {
        int singer;
        cin >> singer;
        singerOfsong[i] = singer;
        songNumOfsinger[singer]++;
    }

    // 시간에 따른 데이터 받기
    vector<int> scoreOfsinger(inputN + 1, 0);
    vector<int> timeOfsinger(inputN + 1, -1);
    for (int k = 0; k < inputK; k++) {
        int inputT, inputP, inputS;
        cin >> inputT >> inputP >> inputS;

        int child_num = child[inputP].size();
        int score = inputS / child_num;
        for (int i = 0; i < child_num; i++) {
            int node = child[inputP][i];
            int singer_num = singerOfsong[node];

            if(scoreOfsinger[singer_num] < inputJ) {
                scoreOfsinger[singer_num] += score / songNumOfsinger[singer_num];
                if(scoreOfsinger[singer_num] > inputJ && timeOfsinger[singer_num] == -1)
                timeOfsinger[singer_num] = inputT;
            }
        }
    }

    for (int i = 1; i <= inputN; i++) {
        int singer_num = singerOfsong[i];
        cout << timeOfsinger[singer_num] << endl;
    }
    return 0;
}