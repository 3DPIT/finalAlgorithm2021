#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define NS 21
#define MS 21
int dy[] = { 0,0,0,-1,1 };//�̵��� ��ġ ��ǥ ����迭 
int dx[] = { 0,1,-1,0,0 };
//0 : ����, 1 : ��, 2 : ��, 3 : ��, 4 : �� 
int N, M;//�迭�� ũ�� N,M
int cy, cx;//�ֻ��� ��ġ ��ǥ
int k;//�̵� Ƚ��
int ret;//����� ���� ����
int cube[] = { 0,0,0,0,0,0,0 };//�ֻ��� ��
int board[NS][MS] = { 0, };// �ֻ����� �̵��ϴ� �迭
bool safe(int y, int x) {// ���� Ȯ�� �ϱ����� �Լ�
	return 0 <= y && y < N && 0 <= x && x < M;
}
void init_input() {//�ʱ�ȭ �� �Է� 
	memset(cube, 0, sizeof(cube));
	memset(board, 0, sizeof(board));
	cy = cx = N = M = ret = 0;
	scanf("%d %d %d %d %d", &N, &M,&cy,&cx,&k);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &board[i][j]);
		}
	 }	
}
void simulation() {// �ֻ��� �̵� ���� 
	for (int ki = 0; ki < k; ki++) {
		int num = 0;// �ֻ��� ���� ����
		scanf("%d", &num);
		if (num == 1&&safe(cy+dy[num],cx+dx[num])) {//���� �����̰� ������ �� �ִ� �����̶��
			cy = cy + dy[num]; cx = cx + dx[num];
			if (board[cy][cx] != 0) {
				cube[3] = board[cy][cx];
				board[cy][cx] = 0;
			}
			else if (board[cy][cx] == 0) {
				board[cy][cx] = cube[3];
			}
			int copyCube = cube[3];
			cube[3] = cube[1]; cube[1] = cube[4]; cube[4] = cube[6]; cube[6] = copyCube;
			printf("%d\n", cube[1]);//���� ���� ���
		}
		if (num == 2 && safe(cy + dy[num], cx + dx[num])) {//���� �����̰� ������ �� �ִ� �����̶��
			cy = cy + dy[num]; cx = cx + dx[num];
			if (board[cy][cx] != 0) {
				cube[4] = board[cy][cx];
				board[cy][cx] = 0;
			}
			else if (board[cy][cx] == 0) {
				board[cy][cx] = cube[4];
			}
			int copyCube = cube[4];
			cube[4] = cube[1]; cube[1] = cube[3];  cube[3] = cube[6]; cube[6] = copyCube;
			printf("%d\n", cube[1]);//���� ���� ���
		}
		if (num == 3 && safe(cy + dy[num], cx + dx[num])) {//���� �����̰� ������ �� �ִ� �����̶��
			cy = cy + dy[num]; cx = cx + dx[num];
			if (board[cy][cx] != 0) {
				cube[2] = board[cy][cx];
				board[cy][cx] = 0;
			}
			else if (board[cy][cx] == 0) {
				board[cy][cx] = cube[2];
			}
			int copyCube = cube[2];
			cube[2] = cube[1]; cube[1] = cube[5]; cube[5] = cube[6]; cube[6] = copyCube;
			printf("%d\n", cube[1]);//���� ���� 
		}
		if (num == 4 && safe(cy + dy[num], cx + dx[num])) {//���� �����̰� ������ �� �ִ� �����̶��
			cy = cy + dy[num]; cx = cx + dx[num];
			if (board[cy][cx] != 0) {
				cube[5] = board[cy][cx];
				board[cy][cx] = 0;
			}
			else if (board[cy][cx] == 0) {
				board[cy][cx] = cube[5];
			}
			int copyCube = cube[6];
			cube[6] = cube[5]; cube[5] = cube[1]; cube[1] = cube[2]; cube[2] = copyCube;
			printf("%d\n", cube[1]);//���� ���� ���
		}
	}
}
int main(void) {
	int testCase = 1;//�׽�Ʈ ���̽� ����
	scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init_input();
		simulation();
	}
	return 0;
}