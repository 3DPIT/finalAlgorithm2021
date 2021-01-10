#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define NS 501//가로,세로 최대 크기
#define MS 501
int N, M;//보드 가로 세로 입력 변수
int board[NS][MS];//테트로미노 점수 저장 배열
int visitB[NS][MS];//보드 방문체크
int dy[] = { 0,-1,0,1 };//0 : 오른쪽, 1 : 위쪽, 2 : 왼쪽, 3 : 아래쪽
int dx[] = { 1,0,-1,0 };
int ret;//최대 결과값 변수
int A[4][3][3] = {//ㅏ,ㅜ,ㅗ,ㅓ 배열 설정
	{
		{1,0,0},
		{1,1,0},
		{1,0,0}
	},
	{
		{1,1,1},
		{0,1,0},
		{0,0,0}
	},
	{
		{0,1,0},
		{1,1,1},
		{0,0,0}
	},
	{
		{0,1,0},
		{1,1,0},
		{0,1,0}
	},
};
bool safe(int y, int x) {//범위 체크 함수
	return 0 <= y && y < N && 0 <= x && x < M;
}
void dfs(int y, int x, int cnt, int sum) {//y축,x축,쓴 칸 개수, 현재의 합
	if (cnt == 4) {//블록이 4개가 이어져있으면
		//to do
		ret = ret < sum ? sum : ret;// 최대값 산출
		return;
	}
	for (int dir = 0; dir < 4; dir++) {//방향 전환
		int ny = y + dy[dir]; int nx = x + dx[dir];
		if (safe(ny, nx) && visitB[ny][nx] == 0) {
			visitB[ny][nx] = 1;
			dfs(ny, nx, cnt + 1, sum + board[ny][nx]);// 개수 증가시키고 합 계산후 넘김
			visitB[ny][nx] = 0;
		}
	}
}
void init_input() {//초기화 및 초기 입력 
	memset(board, 0, sizeof(board));
	N = M = 0;
	ret = 0x80000000;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			{
				scanf("%d", &board[i][j]);
			}
		}
	}
}
void playGame() {// 시뮬레이션 시작 함수
	for (int y = 0; y < N; y++) {//ㅏ ㅗ ㅓ ㅜ 제외 최대값 산출
		for (int x = 0; x < M; x++) {
			visitB[y][x] = 1;
			dfs(y, x, 1, board[y][x]);
			visitB[y][x] = 0;
		}
	}
	// ㅏ ㅗ ㅓ ㅜ 계산하기 
	for (int Anum = 0; Anum < 4; Anum++) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int sum = 0;
				for (int y = 0; y < 3; y++) {
					for (int x = 0; x < 3; x++) {
						if (safe(i+y,j+x)&&A[Anum][y][x] == 1) {//범위 넘지 않고 1이면
							sum += board[i + y][j + x];
						}
					}//y
				}//x
				ret = ret < sum ? sum : ret;// 최대값 산출
			}//j
		}//i

	}//Anum
}
int main(void) {
	int testCase = 1;//테스트케이스 개수
	//scanf("%d", &testCase);//테스트케이스 개수 입력
	for (int tc = 1; tc <= testCase; tc++) {
		init_input();
		playGame();// 테트로미노 게임 시작
		//printf("#%d %d\n", tc, ret-2);
		printf("%d\n",ret);
	}
	return 0;
}