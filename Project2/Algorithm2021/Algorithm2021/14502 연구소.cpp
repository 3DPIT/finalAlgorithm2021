#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
#define MAP_MAX_SIZE 9
#define INSTALL_WALL 1
#define UNINSTALL_WALL 0
#define VIRUS 2
int N, M;//가로 세로의 크기 입력 변수
int map_arr[MAP_MAX_SIZE][MAP_MAX_SIZE];//입력으로 주어지는 맵 정보
int safeZone_Max;//결과 값
int directY[] = { 0,1,0,-1 };
int directX[] = { 1,0,-1,0 };
int visitChk[MAP_MAX_SIZE][MAP_MAX_SIZE] = { 0, };//방문체크 배열
struct virusData {int y, x;};
vector<virusData> virusSet;//바이러스 정보 저장
int safeZoneCnt();
void virusAddZone();
void init_input();//초기화 및 초기 입력
void wall_install(int wallRowIndex, int wallColumnIndex, int wallCount);//.바이러스 벽 설치 및 증식
bool safeZone(int currentY, int currentX);//안전존 확인 변수
int main(void) {
	init_input();
	wall_install(0,0,0);
	cout << safeZone_Max << '\n';
}

bool safeZone(int currentY, int currentX) {
	return 0 <= currentY && currentY < N && 0 <= currentX && currentX < M;
}
void init_input() {
	N = M = 0;
	safeZone_Max = 0x80000000;//최대값 저장할 변수
	memset(map_arr, 0, sizeof(map_arr));
	scanf("%d %d", &N, &M);
	
	for (int mapRowIndex = 0; mapRowIndex < N; mapRowIndex++) {
		for (int mapColumnIndex = 0; mapColumnIndex < M; mapColumnIndex++) {
			scanf("%d", &map_arr[mapRowIndex][mapColumnIndex]);
			if (map_arr[mapRowIndex][mapColumnIndex] == VIRUS) {//바이러스 이면 좌표 저장
				virusSet.push_back({ mapRowIndex, mapColumnIndex});
			}
		}
	}
}
void virusAddZone() {
	memset(visitChk, 0, sizeof(visitChk));//0으로 초기화
	queue<virusData>virusAddQueue;//바이러스 증식 큐
	for (int virusNum = 0; virusNum < virusSet.size(); virusNum++) {//바이러스 저장
		virusAddQueue.push(virusSet[virusNum]);
	}
	while (!virusAddQueue.empty()) {//비어있을때 까지 증식
		virusData currentPos = virusAddQueue.front(); virusAddQueue.pop();
		for (int directionNum = 0; directionNum < 4; directionNum++) {
			virusData nextPos;
			nextPos.y = currentPos.y + directY[directionNum];
			nextPos.x = currentPos.x + directX[directionNum];
			if (safeZone(nextPos.y, nextPos.x) && map_arr[nextPos.y][nextPos.x] == 0 && visitChk[nextPos.y][nextPos.x] == 0) {
				visitChk[nextPos.y][nextPos.x] = VIRUS;
				virusAddQueue.push(nextPos);
			}
		}
	}
}
int safeZoneCnt() {
	int safeCnt = 0;//안전 지역
	for (int mapRowIndex = 0; mapRowIndex < N; mapRowIndex++) {
		for (int mapColumnIndex = 0; mapColumnIndex < M; mapColumnIndex++) {
			if (map_arr[mapRowIndex][mapColumnIndex] == 0 && visitChk[mapRowIndex][mapColumnIndex] == 0) {
				safeCnt++;
			}
		}
	}
	return safeCnt;
}
void wall_install(int wallRowIndex, int wallColumnIndex, int wallCount) {
	if (wallCount == 3) {//벽을 세운 개수가 3일때
		virusAddZone();
		int ret =safeZoneCnt();//결과값 저장
		safeZone_Max = safeZone_Max < ret ? ret : safeZone_Max;//최대값 갱신
		return;
	}
	for (int wY = wallRowIndex; wY < N; wY++) {
		for (int wX = wallColumnIndex; wX < M; wX++) {
			if (map_arr[wY][wX] == UNINSTALL_WALL) {
				map_arr[wY][wX] = INSTALL_WALL;
				wall_install(wY, wX + 1, wallCount+1);
				map_arr[wY][wX] = UNINSTALL_WALL;
			}
		}
		wallColumnIndex = 0;//0부터 시작하기 위해서
	}
}