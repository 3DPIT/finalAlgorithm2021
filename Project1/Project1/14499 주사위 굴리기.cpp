#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#define NS 21
#define MS 21
int dy[] = { 0,0,0,-1,1 };//이동할 위치 좌표 저장배열 
int dx[] = { 0,1,-1,0,0 };
//0 : 정지, 1 : 동, 2 : 서, 3 : 북, 4 : 남 
int N, M;//배열의 크기 N,M
int cy, cx;//주사위 위치 좌표
int k;//이동 횟수
int ret;//결과값 저장 변수
int cube[] = { 0,0,0,0,0,0,0 };//주사위 값
int board[NS][MS] = { 0, };// 주사위가 이동하는 배열
bool safe(int y, int x) {// 범위 확인 하기위한 함수
	return 0 <= y && y < N && 0 <= x && x < M;
}
void init_input() {//초기화 및 입력 
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
void simulation() {// 주사위 이동 시작 
	for (int ki = 0; ki < k; ki++) {
		int num = 0;// 주사위 방향 변수
		scanf("%d", &num);
		if (num == 1&&safe(cy+dy[num],cx+dx[num])) {//방향 동쪽이고 움직일 수 있는 공간이라면
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
			printf("%d\n", cube[1]);//위에 숫자 출력
		}
		if (num == 2 && safe(cy + dy[num], cx + dx[num])) {//방향 서쪽이고 움직일 수 있는 공간이라면
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
			printf("%d\n", cube[1]);//위에 숫자 출력
		}
		if (num == 3 && safe(cy + dy[num], cx + dx[num])) {//방향 북쪽이고 움직일 수 있는 공간이라면
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
			printf("%d\n", cube[1]);//위에 숫자 
		}
		if (num == 4 && safe(cy + dy[num], cx + dx[num])) {//방향 남쪽이고 움직일 수 있는 공간이라면
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
			printf("%d\n", cube[1]);//위에 숫자 출력
		}
	}
}
int main(void) {
	int testCase = 1;//테스트 케이스 변수
	scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init_input();
		simulation();
	}
	return 0;
}