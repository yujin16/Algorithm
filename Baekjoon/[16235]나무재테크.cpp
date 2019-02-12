/* 16235 나무재테크(Simulation)
 * https://www.acmicpc.net/problem/16235
 */

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, M, K, answer = 0;
int nutrient[11][11], map[11][11];
deque<int> trees[11][11];
int dir_r[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dir_c[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void SpringAndSummer() {
    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= N; ++c) {
            int dead_nutri = 0;
            vector<int> tmp;

            int size = trees[r][c].size();
            for (int i = 0; i < size; i++) {
                int age = trees[r][c][i];

                //spring
                if(age <= map[r][c]) {
                    map[r][c] -= age;
                    tmp.push_back(++age);
                }
                else {
                    dead_nutri += age / 2;
                    continue;
                }
            }

            //summer
            map[r][c] += dead_nutri;

            trees[r][c].clear();
            size = tmp.size();
            for (int i = 0; i < size;i++)
                trees[r][c].push_back(tmp[i]);
            answer += size;
        }
    }
}

void FallAndWinter() {
    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= N; ++c) {
            int size = trees[r][c].size();
            for (int i = 0; i < size; i++) {
                int age = trees[r][c][i];

                //fall
                if(age % 5 == 0) {
                    for (int j = 0; j < 8; ++j) {
                        int nr = r + dir_r[j], nc = c + dir_c[j];
                        if(1<=nr && nr<=N && 1<= nc && nc<=N) {
                            trees[nr][nc].push_front(1);
                            answer++;
                        }
                    }
                }
            }

            //winter
            map[r][c] += nutrient[r][c];
        }
    }
}

int main() {
    scanf("%d %d %d", &N,&M,&K);

    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            scanf("%d", &nutrient[i][j]);
            map[i][j] = 5;
        }
    }

    for(int i=1; i<=M; ++i) {
        int r, c, age;
        scanf("%d %d %d", &r, &c, &age);
        trees[r][c].push_back(age);
    }

    for(int i=0; i<K; ++i) {
        answer = 0;
        SpringAndSummer();
        FallAndWinter();
    }

    printf("%d\n", answer);
    return 0;
}