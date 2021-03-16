#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
#define NS 21//�迭 �ִ� ũ��
int N, M;//�Է����� �־����� �迭 ũ��
int y, x;// �ֻ��� ���� ��ġ
int K;//�ֻ��� �̵� Ƚ��
int arr[NS][NS];//�ֻ��� �� 
int cube[7];//�ֻ��� ����
int dy[] = { 0,0,0,-1,1 };//�̵� �Լ�
int dx[] = { 0,1,-1,0,0 };
void init() {//�ʱ�ȭ �� �ʱ� �Է�
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
bool safe(int y, int x) {//���� üũ
	return 0 <= y && y < N && 0 <= x && x < M;
}
void arrCopy() {//�ٴ� ī�ǿ���
	if (arr[y][x] == 0) {
		arr[y][x] = cube[6];
	}
	else {//0�̾ƴϸ� �ֻ����� ���� �ǰ� �ٴ� 0
		cube[6] = arr[y][x];
		arr[y][x] = 0;
	}

}
void cubeMove(int dir) {//�ֻ��� �̵�
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
	int dir = 0;//���� 
	for (int k = 0; k < K; k++) {
		scanf("%d", &dir);
		//1. �ε��� ���� ������ ��� ����
		y = y + dy[dir]; x = x + dx[dir];
		if (!safe(y, x)) {
			y -= dy[dir]; x -= dx[dir];
			continue;
		}
		//2. �ֻ��� �̵� �ҽ�
		cubeMove(dir);
		//3. �ٴ��� 0 �̰ų� �ƴѰ�� ����Ǵ� �ҽ�
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