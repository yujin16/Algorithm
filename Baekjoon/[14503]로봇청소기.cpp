/* 14503번 로봇 청소기
 * https://www.acmicpc.net/problem/14503
 */

#include <iostream>
#include <vector>
using namespace std;

int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0, 1, 0, -1 };

int main() {
	int inputN = 0, inputM = 0;
	int posX = 0, posY = 0, dir = 0;
	cin >> inputN >> inputM;
	cin >> posX >> posY >> dir;
	vector<vector<int> >map(inputN, vector<int>(inputM, 0));

	for (int i = 0; i < inputN; i++)
		for (int j = 0; j < inputM; j++)
			cin >> map[i][j];

	while (1) {
		map[posX][posY] = 2;
		int newX = 0, newY = 0, newD = 0;

		// 네 방향 중 청소할 곳이 한 곳이라도 있으면 go=false
		bool go = true;
		for (int i = 0; i < 4; i++) {
			newX = posX + dirX[i];
			newY = posY + dirY[i];
			if (go && newX >= 0 && newX < inputN && newY >= 0 && newY < inputM && map[newX][newY] == 0)
				go = false;
		}

		if (go) {
			newD = (dir + 2) % 4;
			newX = posX + dirX[newD];
			newY = posY + dirY[newD];
			if (map[newX][newY] == 1)
				break;
			else {
				posX = newX;
				posY = newY;
				continue;
			}
		}

		newD = (dir - 1) < 0 ? 3 : dir - 1;
		newX = posX + dirX[newD];
		newY = posY + dirY[newD];

		if (newX >= 0 && newX < inputN && newY >= 0 && newY < inputM && map[newX][newY] == 0) {
			posX = newX;
			posY = newY;
			dir = newD;
			continue;
		}
		else {
			dir = newD;
			continue;
		}
	}

	int count = 0;
	for (int i = 0; i < inputN; i++)
		for (int j = 0; j < inputM; j++)
			if (map[i][j] == 2)
				count++;

	cout << count << endl;
	return 0;
}