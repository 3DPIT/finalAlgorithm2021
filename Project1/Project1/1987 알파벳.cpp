#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

#define NSIZE 21 // �迭 �ִ� ���� ���� ������
int R, C;//����, ����
int nMax = 0x80000000;// �ִ밪 ����
char board[NSIZE][NSIZE];//�Է� �迭
bool visit[NSIZE][NSIZE];//üũ �迭 (Ž���� ���)
char alphabet[27];//���ĺ� üũ
int dy[] = { 0,1,0,-1 };//���� �˻�
int dx[] = { 1,0,-1,0 };

void init() {//�ʱ�ȭ �� �ʱ� �Է�
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
bool safeZone(int y, int x) {// �迭 ���� üũ
	return 0 <= y && y < R && 0 <= x && x < C;
}
void dfs(int y, int x, int cnt) {//Ž�� �� �Լ�
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