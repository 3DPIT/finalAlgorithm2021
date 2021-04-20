#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
#define NSIZE 102//전체 면적


int N;//드래곤 커브 개수
int ret;//1*1 정사각형 개수

int board[NSIZE][NSIZE];//드래곤 커브 찍히는 배열
int dy[] = { 0,-1,0,1 };//드래곤 방향
int dx[] = { 1,0,-1,0 };

void init();
void dragon();
int main(void) {
	int testCase = 1;
	//scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		printf("%d\n", ret);
		//printf("#%d %d\n", tc, ret);
	}
	return 0;
}
void dragon() {
	while (N--) {//드래곤 커브 시작
		int x, y, d, g;//드래곤 커브 시작점, 시작 방향, 세대
		scanf("%d %d %d %d", &x, &y, &d, &g);
		vector<int>dir;//방향 저장
  		dir.push_back(d);
		while (g--) {
			for (int dir_index = dir.size()-1; dir_index>=0; dir_index--) {
				int direction = dir[dir_index]+1;
				direction = (direction)%4;
				dir.push_back(direction);
			}
		}
		//드래곤 방향 맵에 찍기
		board[y][x] = 1;
		for (int i = 0; i < dir.size(); i++) {
			y = y + dy[dir[i]]; x = x + dx[dir[i]];
			board[y][x] = 1;
		}
	}
	//정사각형 산출하기
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (board[i][j] == 1 && board[i][j + 1] == 1
				&& board[i + 1][j] == 1 && board[i + 1][j + 1] == 1) {
				ret++;//정사각형 개수
			}
		}
	}
}
void init() {
	memset(board, 0, sizeof(board));
	N = ret = 0;
	scanf("%d", &N);
	dragon();
}
