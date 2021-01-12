#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
#define NS 9 //가로의 최대 크기
#define MS 9 // 세로의 최대 크기
int N, M; // 입력으로 주어지는 가로 세로크기
int board[NS][MS];// 입력으로 주어지는 배열
int ret = 0x80000000;//최대값 최신화 시킬 변수
int zeroCnt = 0;//안전지대의 개수
int dy[] = { 0,1,0,-1 };//바이러스가 움직이는 방향
int dx[] = { 1,0,-1,0 };
struct Data {//큐를 위한 구조체
	int y, x;
};
vector<Data>D;//바이러스 미리 저장
void init_input() {//초기화 및 초기 입력
	N = M = zeroCnt = 0;  ret = 0x80000000;
	memset(board, 0, sizeof(board));

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 0) zeroCnt++;// 안전지대 개수 카운트
			if (board[i][j] == 2)	D.push_back({ i,j });
		}
	}
}

bool safe(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}
void dfs(int y, int x, int cnt) {// 벽 놓는 함수
	if (cnt == 3) {// 벽  3개 세운경우
		int visit[NS][MS] = { 0, };//방문 배열 체크
		queue<Data>q;
		int virusCnt = 0;
		for (int i = 0; i < D.size(); i++) {
			visit[D[i].y][D[i].x] = 1;
			q.push({ D[i].y, D[i].x });
		}
					while (!q.empty()) {
						Data c = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++) {
							Data n;
							n.y = c.y + dy[dir]; n.x = c.x + dx[dir];
							if (safe(n.y,n.x)&&board[n.y][n.x] == 0 && visit[n.y][n.x] == 0) {
								//바이러스 전염가능한곳이고 방문한 곳이 아니라면 참
								visit[n.y][n.x] = 1;
								virusCnt++;
								q.push(n);
							}// if board, visit
						}//for dir
					}//while q.
		int safeZone = zeroCnt - virusCnt;// 안전지대 수
		ret = ret < safeZone ? safeZone : ret;//최대값
		return;
	}
	for (int i = y; i < N; i++) {
		for (int j = x; j < M; j++) {
			if (board[i][j] == 0) {//벽이 안세워진 곳인라면
				board[i][j] = 1;// 벽세우기
				dfs(i, j, cnt + 1);
				board[i][j] = 0;
			}
		}
		x = 0;
	}
}
void play() {
	dfs(0, 0, 0);
}
int main(void) {
	int testCase = 1;// 테스트케이스 개수 변수
	//scanf("%d", &testCase);//테스트 케이스 개수 입력
	for (int tc = 1; tc <= testCase; tc++) {
		init_input();
		play();// 시뮬레이션 시작

		printf("%d\n", ret-3);//출력 
		//printf("#%d %d\n", tc, ret-3);
	}
	return 0;
}