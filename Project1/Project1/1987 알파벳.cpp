#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

#define NSIZE 21 // 배열 최대 가로 세로 사이즈
int R, C;//세로, 가로
int nMax = 0x80000000;// 최대값 변수
char board[NSIZE][NSIZE];//입력 배열
bool visit[NSIZE][NSIZE];//체크 배열 (탐색시 사용)
char alphabet[27];//알파벳 체크
int dy[] = { 0,1,0,-1 };//방향 검사
int dx[] = { 1,0,-1,0 };

void init() {//초기화 및 초기 입력
	R = C = 0;
	nMax = 0x80000000;
	memset(board, 0, sizeof(board));
	memset(visit, 0, sizeof(visit));
	scanf("%d %d", &R, &C);
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			scanf(" %1c", &board[r][c]);
		}
	}
}
bool safeZone(int y, int x) {// 배열 범위 체크
	return 0 <= y && y < R && 0 <= x && x < C;
}
void dfs(int y, int x, int cnt) {//탐색 할 함수
	nMax = nMax < cnt ? cnt : nMax;

	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir]; int nx = x + dx[dir];
		if (safeZone(ny,nx)&&alphabet[board[ny][nx] - 'A'] == 0&&visit[ny][nx]==0) {
			visit[ny][nx] = 1;
			alphabet[board[ny][nx] - 'A'] = 1;
			dfs(ny, nx, cnt + 1);
			alphabet[board[ny][nx] - 'A'] = 0;
			visit[ny][nx] = 0;
		}
	}
}
int main(void) {
	init();
	visit[0][0] = 1;
	alphabet[board[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	printf("%d\n", nMax);
	return 0;
}