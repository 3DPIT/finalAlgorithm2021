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
int N, M;//���� ������ ũ�� �Է� ����
int map_arr[MAP_MAX_SIZE][MAP_MAX_SIZE];//�Է����� �־����� �� ����
int safeZone_Max;//��� ��
int directY[] = { 0,1,0,-1 };
int directX[] = { 1,0,-1,0 };
int visitChk[MAP_MAX_SIZE][MAP_MAX_SIZE] = { 0, };//�湮üũ �迭
struct virusData {int y, x;};
vector<virusData> virusSet;//���̷��� ���� ����
int safeZoneCnt();
void virusAddZone();
void init_input();//�ʱ�ȭ �� �ʱ� �Է�
void wall_install(int wallRowIndex, int wallColumnIndex, int wallCount);//.���̷��� �� ��ġ �� ����
bool safeZone(int currentY, int currentX);//������ Ȯ�� ����
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
	safeZone_Max = 0x80000000;//�ִ밪 ������ ����
	memset(map_arr, 0, sizeof(map_arr));
	scanf("%d %d", &N, &M);
	
	for (int mapRowIndex = 0; mapRowIndex < N; mapRowIndex++) {
		for (int mapColumnIndex = 0; mapColumnIndex < M; mapColumnIndex++) {
			scanf("%d", &map_arr[mapRowIndex][mapColumnIndex]);
			if (map_arr[mapRowIndex][mapColumnIndex] == VIRUS) {//���̷��� �̸� ��ǥ ����
				virusSet.push_back({ mapRowIndex, mapColumnIndex});
			}
		}
	}
}
void virusAddZone() {
	memset(visitChk, 0, sizeof(visitChk));//0���� �ʱ�ȭ
	queue<virusData>virusAddQueue;//���̷��� ���� ť
	for (int virusNum = 0; virusNum < virusSet.size(); virusNum++) {//���̷��� ����
		virusAddQueue.push(virusSet[virusNum]);
	}
	while (!virusAddQueue.empty()) {//��������� ���� ����
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
	int safeCnt = 0;//���� ����
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
	if (wallCount == 3) {//���� ���� ������ 3�϶�
		virusAddZone();
		int ret =safeZoneCnt();//����� ����
		safeZone_Max = safeZone_Max < ret ? ret : safeZone_Max;//�ִ밪 ����
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
		wallColumnIndex = 0;//0���� �����ϱ� ���ؼ�
	}
}