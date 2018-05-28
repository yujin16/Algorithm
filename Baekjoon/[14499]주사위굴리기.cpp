/* 14499번 주사위 굴리기
 * https://www.acmicpc.net/problem/14499
 */

#include <iostream>
#include <vector>
using namespace std;

enum DIR { UP, EAST, WEST, NORTH, SOUTH, DOWN };
int  posX, posY;

void copy(vector<vector<int> > &map, vector<int> &dice) {
	if (map[posX][posY] == 0)
		map[posX][posY] = dice[DOWN];
	else {
		dice[DOWN] = map[posX][posY];
		map[posX][posY] = 0;
	}
}

void swap(vector<int> &dice, int t1, int t2, int t3, int t4) {
	int tmp = dice[t4];
	dice[t4] = dice[t3];
	dice[t3] = dice[t2];
	dice[t2] = dice[t1];
	dice[t1] = tmp;
}

int main() {
	int inputN, inputM, inputK;
	cin >> inputN >> inputM >> posX >> posY >> inputK;

	vector<vector<int> > map(inputN, vector<int>(inputM, 0));
	for (int i = 0; i < inputN; i++)
		for (int j = 0; j < inputM; j++)
			cin >> map[i][j];

	vector<int> dice(6, 0);
	for (int i = 0; i < inputK; i++) {
		int order;
		cin >> order;

		switch (order) {
		case EAST:
			if (posY + 1 < inputM) {
				posY += 1;
				swap(dice, UP, EAST, DOWN, WEST);
				copy(map, dice);
				cout << dice[UP] << endl;
			}
			break;
		case WEST:
			if (posY - 1 >= 0) {
				posY -= 1;
				swap(dice, WEST, DOWN, EAST, UP);
				copy(map, dice);
				cout << dice[UP] << endl;
			}
			break;
		case NORTH:
			if (posX - 1 >= 0) {
				posX -= 1;
				swap(dice, DOWN, SOUTH, UP, NORTH);
				copy(map, dice);
				cout << dice[UP] << endl;
			}
			break;
		case SOUTH:
			if (posX + 1 < inputN) {
				posX += 1;
				swap(dice, NORTH, UP, SOUTH, DOWN);
				copy(map, dice);
				cout << dice[UP] << endl;
			}
			break;
		}
	}
	return 0;
}