#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define NS 51 //가로 세로 크기
#define MS 51
int dy[] = { -1,0,1,0 };//0  1  2  3 
int dx[] = { 0,1,0,-1 };//북 동 남 서
int room[NS][MS];//청소해야하는 방
int cleanArea ;//청소한 구역 수
int N, M, r, c, d;//입력 : 가로, 세로, 로봇 위치 y,x, 로봇 방향
void init() {//초기화 및 초기 입력
	N = M = r = c = d = 0;
	cleanArea = 1;
	memset(room, 0, sizeof(room));
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &room[i][j]);
		}
	}
}
void robotStart() {//로봇의 동작
	while (1) {
		if (0 == room[r][c]) {//현재 위치를 청소한다.
			room[r][c] = ++cleanArea;
		}
		//현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
		int copyD = d;//4방향 검사후 그대로 방향 유지하기 위해서 
		int flag = 1;//4방향 검사 여부 확인 1이면 청소구역 없음
		for (int cleanCnt = 1; cleanCnt <= 4; cleanCnt++) {
			//왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
			copyD = ((--copyD) + 4)%4;
			int ny = r + dy[copyD]; int nx = c+ dx[copyD];
			if (0 == room[ny][nx]) {
				r = ny; c = nx;
				d = copyD;
				flag = 0;
				break;
			}
		}
		//왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
		if (flag) {//네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
			int ny = r - dy[d]; int nx = c - dx[d];
			if (1 != room[ny][nx]) {
				r = ny; c = nx;
			}
			else if (1 == room[ny][nx]) {//네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
				break;//종료
			}
		}
	}
}
int main(void) {
	int testCase = 1;
	//scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		robotStart();
		//printf("#%d %d\n", tc, cleanArea-1);
		printf("%d\n", cleanArea-1);
	}
	return 0;
}