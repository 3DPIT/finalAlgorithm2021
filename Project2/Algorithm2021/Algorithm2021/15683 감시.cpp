#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define OFFICE_MAX_SIZE 9
int office[OFFICE_MAX_SIZE][OFFICE_MAX_SIZE];//�繫�� ���� ��� �迭
int N, M;//�繫���� ���ο� ���� ũ��
int deadZone;//�簢���� �ּ�ũ�� ��� ���� �����
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int cctvNum[] = { 0,4,2,4,4,1 };//����ȣ�� ī�޶� ���� ����
struct CCTV_DATA {
	int y, x, num;
};
vector<CCTV_DATA>CCTV;//CCTV������ ���
bool safeZoneChk(int y, int x);//�迭 ���� üũ
void init_input();//�ʱ�ȭ �� �ʱ� �Է� �Լ�
void cctvChk(int cnt,int cctv_idx);//dfs Ž�� ���� �Լ�
void copyArr(int arr[OFFICE_MAX_SIZE][OFFICE_MAX_SIZE], int carr[OFFICE_MAX_SIZE][OFFICE_MAX_SIZE]);//�迭 ����
void markerPaint(int dir, int cctv_idx);// ī�޶� ��� ��� �Լ�
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
		 office[y][x] = 9;//���� ���� ���
	}
}
void copyArr(int arr[OFFICE_MAX_SIZE][OFFICE_MAX_SIZE], int carr[OFFICE_MAX_SIZE][OFFICE_MAX_SIZE]) {//�迭 ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = carr[i][j];
		}
	}
}
void cctvChk(int cnt, int cctv_idx){
	if (cnt == CCTV.size()) {//��ü ī�޶� ���� ������ٸ�
		//���������� office�� ��������
		int deadCnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (office[i][j] == 0)deadCnt++;
			}
		}
		deadZone = deadZone > deadCnt ? deadCnt : deadZone;//�ּҰ� ����
		return;
	}
	int copyOffice[OFFICE_MAX_SIZE][OFFICE_MAX_SIZE] = { 0, };
		int cctvNumber = CCTV[cctv_idx].num;
		for (int cctvDir = 0; cctvDir < cctvNum[cctvNumber]; cctvDir++) {
			copyArr(copyOffice, office);//�迭 ����
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
			copyArr(office, copyOffice);//����
		}
	
}
void init_input() {//�ʱ�ȭ �� �ʱ� �Է�
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