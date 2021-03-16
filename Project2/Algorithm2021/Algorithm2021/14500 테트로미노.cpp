#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define NS 502//최대 배열 사이즈
int N, M;// 입력으로 주어지는 것
int arr[NS][NS];//입력으로 주어지는 배열
int ret;//결과값 저장
int D[NS][NS];//블럭 저장
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
//1, ㅏ ㅗ ㅓ ㅜ 구현
int A[4][3][3] = {
	{
		{1,0,0},
		{1,1,0},
		{1,0,0}
	},
	{
		{0,1,0},
		{1,1,1},
		{0,0,0}
	},
	{
		{1,1,1},
		{0,1,0},
		{0,0,0}
	},
	{
		{0,1,0},
		{1,1,0},
		{0,1,0}
	},
};
bool safe(int y, int x) {//범위 체크
	return 0 <= y && y < N && 0 <= x && x < M;
}
//2. dfs로 나머지 블럭 구현
void dfs(int y, int x, int cnt,long long int sum) {
	if (cnt == 3) {
		ret = ret < sum ? sum : ret;//최대값
		return;
	}
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir]; int nx = x + dx[dir];
		if (safe(ny,nx)&&D[ny][nx] == 0) {
			D[ny][nx] = 1;
			dfs(ny, nx, cnt + 1,sum+arr[ny][nx]);
			D[ny][nx] = 0;
		}
	}
}
//3. ㅏ ㅗ ㅓ ㅜ 탐색
void serachA() {//전체 탐색
	for (int a = 0; a < 4; a++) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				long long int sum = 0;//합 계산
				for (int aY = 0; aY < 3; aY++) {
					for (int aX = 0; aX < 3; aX++) {
						int ny = i + aY; int nx = j + aX;
						if (A[a][aY][aX] == 1) {
							sum += arr[ny][nx];
						}
					}//for int aX
				}//for int aY
				ret = ret < sum ? sum : ret;//최대값
			}//for int j
		}//for int i

	}
}
void init() {//초기화 및 초기 입력
	N = M = 0;
	ret = 0x80000000;
	memset(arr, 0x80, sizeof(arr));//초기화
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
}
int main(void) {
	int testCase = 1;//테스트 케이스
	//scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; +j++) {
				D[i][j] = 1;
				dfs(i, j, 0, arr[i][j]);
				D[i][j] = 0;
			}
		}
		serachA();
		//printf("#%d %d\n", tc, ret);
		printf("%d\n", ret);
	}
	return 0;
}