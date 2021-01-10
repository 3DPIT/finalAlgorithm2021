#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define NS 501//����,���� �ִ� ũ��
#define MS 501
int N, M;//���� ���� ���� �Է� ����
int board[NS][MS];//��Ʈ�ι̳� ���� ���� �迭
int visitB[NS][MS];//���� �湮üũ
int dy[] = { 0,-1,0,1 };//0 : ������, 1 : ����, 2 : ����, 3 : �Ʒ���
int dx[] = { 1,0,-1,0 };
int ret;//�ִ� ����� ����
int A[4][3][3] = {//��,��,��,�� �迭 ����
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
bool safe(int y, int x) {//���� üũ �Լ�
	return 0 <= y && y < N && 0 <= x && x < M;
}
void dfs(int y, int x, int cnt, int sum) {//y��,x��,�� ĭ ����, ������ ��
	if (cnt == 4) {//����� 4���� �̾���������
		//to do
		ret = ret < sum ? sum : ret;// �ִ밪 ����
		return;
	}
	for (int dir = 0; dir < 4; dir++) {//���� ��ȯ
		int ny = y + dy[dir]; int nx = x + dx[dir];
		if (safe(ny, nx) && visitB[ny][nx] == 0) {
			visitB[ny][nx] = 1;
			dfs(ny, nx, cnt + 1, sum + board[ny][nx]);// ���� ������Ű�� �� ����� �ѱ�
			visitB[ny][nx] = 0;
		}
	}
}
void init_input() {//�ʱ�ȭ �� �ʱ� �Է� 
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
void playGame() {// �ùķ��̼� ���� �Լ�
	for (int y = 0; y < N; y++) {//�� �� �� �� ���� �ִ밪 ����
		for (int x = 0; x < M; x++) {
			visitB[y][x] = 1;
			dfs(y, x, 1, board[y][x]);
			visitB[y][x] = 0;
		}
	}
	// �� �� �� �� ����ϱ� 
	for (int Anum = 0; Anum < 4; Anum++) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int sum = 0;
				for (int y = 0; y < 3; y++) {
					for (int x = 0; x < 3; x++) {
						if (safe(i+y,j+x)&&A[Anum][y][x] == 1) {//���� ���� �ʰ� 1�̸�
							sum += board[i + y][j + x];
						}
					}//y
				}//x
				ret = ret < sum ? sum : ret;// �ִ밪 ����
			}//j
		}//i

	}//Anum
}
int main(void) {
	int testCase = 1;//�׽�Ʈ���̽� ����
	//scanf("%d", &testCase);//�׽�Ʈ���̽� ���� �Է�
	for (int tc = 1; tc <= testCase; tc++) {
		init_input();
		playGame();// ��Ʈ�ι̳� ���� ����
		//printf("#%d %d\n", tc, ret-2);
		printf("%d\n",ret);
	}
	return 0;
}