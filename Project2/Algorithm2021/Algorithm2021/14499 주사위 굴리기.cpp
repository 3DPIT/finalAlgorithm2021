#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
#define NS 21//배열 최대 크기
int N, M;//입력으로 주어지는 배열 크기
int y, x;// 주사위 시작 위치
int K;//주사위 이동 횟수
int arr[NS][NS];//주사위 판 
int cube[7];//주사위 정보
int dy[] = { 0,0,0,-1,1 };//이동 함수
int dx[] = { 0,1,-1,0,0 };
void init() {//초기화 및 초기 입력
	N = M = y = x = 0;
	memset(arr, 0, sizeof(arr));
	memset(cube, 0, sizeof(cube));
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
}
bool safe(int y, int x) {//범위 체크
	return 0 <= y && y < N && 0 <= x && x < M;
}
void arrCopy() {//바닥 카피여부
	if (arr[y][x] == 0) {
		arr[y][x] = cube[6];
	}
	else {//0이아니면 주사위에 복사 되고 바닥 0
		cube[6] = arr[y][x];
		arr[y][x] = 0;
	}

}
void cubeMove(int dir) {//주사위 이동
	if (dir == 1) {
		int temp = cube[1]; cube[1] = cube[4]; cube[4] = cube[6]; cube[6] = cube[3]; cube[3] = temp;
	}
	if (dir == 2) {
		int temp = cube[1]; cube[1] = cube[3]; cube[3] = cube[6]; cube[6] = cube[4]; cube[4] = temp;
	}
	if (dir == 3) {
		int temp = cube[1]; cube[1] = cube[5]; cube[5] = cube[6]; cube[6] = cube[2]; cube[2] = temp;
	}
	if (dir == 4) {
		int temp = cube[1]; cube[1] = cube[2]; cube[2] = cube[6]; cube[6] = cube[5]; cube[5] = temp;
	}
}
void cubePlay() {
	int dir = 0;//방향 
	for (int k = 0; k < K; k++) {
		scanf("%d", &dir);
		//1. 인덱스 범위 넘으면 명령 무시
		y = y + dy[dir]; x = x + dx[dir];
		if (!safe(y, x)) {
			y -= dy[dir]; x -= dx[dir];
			continue;
		}
		//2. 주사위 이동 소스
		cubeMove(dir);
		//3. 바닥이 0 이거나 아닌경우 복사되는 소스
		arrCopy();
		printf("%d\n", cube[1]);
	}
}
int main(void) {
	int testCase = 1;
	//scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		cubePlay();
	}
	return 0;
}