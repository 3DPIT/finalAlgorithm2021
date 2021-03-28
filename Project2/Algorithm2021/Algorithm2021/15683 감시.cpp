#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define OFFICE_MAX_SIZE 9
int office[OFFICE_MAX_SIZE][OFFICE_MAX_SIZE];//사무실 정보 담는 배열
int N, M;//사무실의 세로와 가로 크기
int deadZone;//사각지대 최소크기 담는 변수 결과값
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int cctvNum[] = { 0,4,2,4,4,1 };//각번호별 카메라 방향 개수
struct CCTV_DATA {
	int y, x, num;
};
vector<CCTV_DATA>CCTV;//CCTV데이터 담기
bool safeZoneChk(int y, int x);//배열 범위 체크
void init_input();//초기화 및 초기 입력 함수
void cctvChk(int cnt,int cctv_idx);//dfs 탐색 진행 함수
void copyArr(int arr[OFFICE_MAX_SIZE][OFFICE_MAX_SIZE], int carr[OFFICE_MAX_SIZE][OFFICE_MAX_SIZE]);//배열 복사
void markerPaint(int dir, int cctv_idx);// 카메라 경로 찍는 함수
int main(void) {
	int testCase = 1;
	//scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init_input();
		cctvChk(0,0);
		printf("%d\n", deadZone);
		//printf("#%d %d\n", tc, deadZone);
	}
	return 0;
}
//--------------------------------------------------------------
void markerPaint(int dir,CCTV_DATA c) {
	dir = dir % 4;
	int y = c.y;
	int x = c.x;
	while (1) {
		y += dy[dir]; x += dx[dir];
		if (!safeZoneChk(y, x) || office[y][x] == 6)break;
		 office[y][x] = 9;//감시 지역 찍기
	}
}
void copyArr(int arr[OFFICE_MAX_SIZE][OFFICE_MAX_SIZE], int carr[OFFICE_MAX_SIZE][OFFICE_MAX_SIZE]) {//배열 복사
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = carr[i][j];
		}
	}
}
void cctvChk(int cnt, int cctv_idx){
	if (cnt == CCTV.size()) {//전체 카메라 방향 설정됬다면
		//최종적으로 office에 흔적남음
		int deadCnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (office[i][j] == 0)deadCnt++;
			}
		}
		deadZone = deadZone > deadCnt ? deadCnt : deadZone;//최소값 갱신
		return;
	}
	int copyOffice[OFFICE_MAX_SIZE][OFFICE_MAX_SIZE] = { 0, };
		int cctvNumber = CCTV[cctv_idx].num;
		for (int cctvDir = 0; cctvDir < cctvNum[cctvNumber]; cctvDir++) {
			copyArr(copyOffice, office);//배열 복사
			if (cctvNumber == 1) {
				markerPaint(cctvDir, CCTV[cctv_idx]);
			}else if (cctvNumber == 2) {
				markerPaint(cctvDir, CCTV[cctv_idx]);
				markerPaint(cctvDir+2, CCTV[cctv_idx]);

			}else if (cctvNumber == 3) {
				markerPaint(cctvDir, CCTV[cctv_idx]);
				markerPaint(cctvDir+1, CCTV[cctv_idx]);
			}else if (cctvNumber == 4) {
				markerPaint(cctvDir, CCTV[cctv_idx]);
				markerPaint(cctvDir+1, CCTV[cctv_idx]);
				markerPaint(cctvDir+2, CCTV[cctv_idx]);

			}else if (cctvNumber == 5) {
				markerPaint(cctvDir, CCTV[cctv_idx]);
				markerPaint(cctvDir+1, CCTV[cctv_idx]);
				markerPaint(cctvDir+2, CCTV[cctv_idx]);
				markerPaint(cctvDir+3, CCTV[cctv_idx]);
			}
			cctvChk(cnt + 1, cctv_idx+1);
			copyArr(office, copyOffice);//복구
		}
	
}
void init_input() {//초기화 및 초기 입력
	N = M = 0;
	deadZone = 0x7fffffff;
	memset(office, 0,  sizeof(office));
	CCTV.	clear();
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &office[i][j]);
			if (office[i][j] != 6 && office[i][j] != 0) {
				CCTV.push_back({ i,j ,office[i][j]});
			}
		}
	}
}
bool safeZoneChk(int y, int x) {
	return 0 <= y && y < N&&0 <= x && x < M;
}
bool isafeZoneChk(int y, int x) {
	return y<0 || y==N||x<0|| x== M;
}