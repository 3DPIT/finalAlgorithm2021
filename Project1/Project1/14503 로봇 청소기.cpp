#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define NS 51// 세로의 최대 크기 
#define MS 51// 가로의 최대 크기
int N, M, r, c, d;// 세로,가로,로봇y,로봇x,로봇 방향
int ret;//결과 값
int dy[] = { -1,0,1,0 };// 로봇이 움직이는 방향 배열y,x
int dx[] = { 0,1,0,-1 };//0 : 북(위), 1 : 동(오), 2 : 남(아래), 3 : 서(왼)
int board[NS][MS];//로봇이 움직이는 공간
void init_input() {// 초기화 및 초기 입력
	memset(board, 0, sizeof(board));
	N = M = r = c = d = ret;
	scanf("%d %d %d %d %d", &N, &M, &r, &c, &d);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &board[i][j]);
		}
	}
}
void playClean(){// 청소 시뮬레이션 시작
	ret = 2;//벽이 1이기때문에 2부터 시작
	while (1) {
		if (board[r][c] == 0) {//현재 위치를 청소한다.
			board[r][c] = ret++;// 현재 위치 청소
		}
		int dir = d;//현재 방향 아닐 수 있으니 미리 저장
		int flag = 0;//청소공간 유무 확인 플래그
		for (int i = 0; i < 4; i++) {
			dir--; if (dir == -1)dir = 3;//	현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
			int ny = r + dy[dir]; int nx = c + dx[dir];//다음 위치 저장 변수들 
			if (board[ny][nx] == 0) {	//	왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
				r = ny; c = nx; d = dir;
				flag = 1;
				break;
			}
			//else if (board[ny][nx] != 0) {//	왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
		}
		if (flag == 0) {
			int ny = r + dy[d]; int nx = c + dx[d];//다음 위치 저장 변수들 
			if (board[r-dy[d]][c-dx[d]]!=1) {//	네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
				r = r - dy[d]; c=c - dx[d];
			}
			else if (board[r - dy[d]][c- dx[d]] == 1) {//	네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
				break;//종료
			}
			//	로봇 청소기는 이미 청소되어있는 칸을 또 청소하지 않으며, 벽을 통과할 수 없다.
		}
	}
}

int main(void) {
	int testCase = 1;// 테스트 케이스 개수
	//scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init_input();//초기화 및 입력 시작
		playClean();//시뮬레이션 시작
		printf("%d\n",ret - 2);
		//printf("#%d %d\n", tc, ret-2);
	}
	return 0;
}