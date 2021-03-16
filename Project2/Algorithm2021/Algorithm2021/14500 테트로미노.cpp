#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define NS 502//�ִ� �迭 ������
int N, M;// �Է����� �־����� ��
int arr[NS][NS];//�Է����� �־����� �迭
int ret;//����� ����
int D[NS][NS];//�� ����
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
//1, �� �� �� �� ����
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
bool safe(int y, int x) {//���� üũ
	return 0 <= y && y < N && 0 <= x && x < M;
}
//2. dfs�� ������ �� ����
void dfs(int y, int x, int cnt,long long int sum) {
	if (cnt == 3) {
		ret = ret < sum ? sum : ret;//�ִ밪
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
//3. �� �� �� �� Ž��
void serachA() {//��ü Ž��
	for (int a = 0; a < 4; a++) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				long long int sum = 0;//�� ���
				for (int aY = 0; aY < 3; aY++) {
					for (int aX = 0; aX < 3; aX++) {
						int ny = i + aY; int nx = j + aX;
						if (A[a][aY][aX] == 1) {
							sum += arr[ny][nx];
						}
					}//for int aX
				}//for int aY
				ret = ret < sum ? sum : ret;//�ִ밪
			}//for int j
		}//for int i

	}
}
void init() {//�ʱ�ȭ �� �ʱ� �Է�
	N = M = 0;
	ret = 0x80000000;
	memset(arr, 0x80, sizeof(arr));//�ʱ�ȭ
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
}
int main(void) {
	int testCase = 1;//�׽�Ʈ ���̽�
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