#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
#define NS 9 //������ �ִ� ũ��
#define MS 9 // ������ �ִ� ũ��
int N, M; // �Է����� �־����� ���� ����ũ��
int board[NS][MS];// �Է����� �־����� �迭
int ret = 0x80000000;//�ִ밪 �ֽ�ȭ ��ų ����
int zeroCnt = 0;//���������� ����
int dy[] = { 0,1,0,-1 };//���̷����� �����̴� ����
int dx[] = { 1,0,-1,0 };
struct Data {//ť�� ���� ����ü
	int y, x;
};
vector<Data>D;//���̷��� �̸� ����
void init_input() {//�ʱ�ȭ �� �ʱ� �Է�
	N = M = zeroCnt = 0;  ret = 0x80000000;
	memset(board, 0, sizeof(board));

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 0) zeroCnt++;// �������� ���� ī��Ʈ
			if (board[i][j] == 2)	D.push_back({ i,j });
		}
	}
}

bool safe(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}
void dfs(int y, int x, int cnt) {// �� ���� �Լ�
	if (cnt == 3) {// ��  3�� ������
		int visit[NS][MS] = { 0, };//�湮 �迭 üũ
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
								//���̷��� ���������Ѱ��̰� �湮�� ���� �ƴ϶�� ��
								visit[n.y][n.x] = 1;
								virusCnt++;
								q.push(n);
							}// if board, visit
						}//for dir
					}//while q.
		int safeZone = zeroCnt - virusCnt;// �������� ��
		ret = ret < safeZone ? safeZone : ret;//�ִ밪
		return;
	}
	for (int i = y; i < N; i++) {
		for (int j = x; j < M; j++) {
			if (board[i][j] == 0) {//���� �ȼ����� ���ζ��
				board[i][j] = 1;// �������
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
	int testCase = 1;// �׽�Ʈ���̽� ���� ����
	//scanf("%d", &testCase);//�׽�Ʈ ���̽� ���� �Է�
	for (int tc = 1; tc <= testCase; tc++) {
		init_input();
		play();// �ùķ��̼� ����

		printf("%d\n", ret-3);//��� 
		//printf("#%d %d\n", tc, ret-3);
	}
	return 0;
}