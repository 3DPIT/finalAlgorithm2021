#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define NS 51// ������ �ִ� ũ�� 
#define MS 51// ������ �ִ� ũ��
int N, M, r, c, d;// ����,����,�κ�y,�κ�x,�κ� ����
int ret;//��� ��
int dy[] = { -1,0,1,0 };// �κ��� �����̴� ���� �迭y,x
int dx[] = { 0,1,0,-1 };//0 : ��(��), 1 : ��(��), 2 : ��(�Ʒ�), 3 : ��(��)
int board[NS][MS];//�κ��� �����̴� ����
void init_input() {// �ʱ�ȭ �� �ʱ� �Է�
	memset(board, 0, sizeof(board));
	N = M = r = c = d = ret;
	scanf("%d %d %d %d %d", &N, &M, &r, &c, &d);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &board[i][j]);
		}
	}
}
void playClean(){// û�� �ùķ��̼� ����
	ret = 2;//���� 1�̱⶧���� 2���� ����
	while (1) {
		if (board[r][c] == 0) {//���� ��ġ�� û���Ѵ�.
			board[r][c] = ret++;// ���� ��ġ û��
		}
		int dir = d;//���� ���� �ƴ� �� ������ �̸� ����
		int flag = 0;//û�Ұ��� ���� Ȯ�� �÷���
		for (int i = 0; i < 4; i++) {
			dir--; if (dir == -1)dir = 3;//	���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
			int ny = r + dy[dir]; int nx = c + dx[dir];//���� ��ġ ���� ������ 
			if (board[ny][nx] == 0) {	//	���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
				r = ny; c = nx; d = dir;
				flag = 1;
				break;
			}
			//else if (board[ny][nx] != 0) {//	���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
		}
		if (flag == 0) {
			int ny = r + dy[d]; int nx = c + dx[d];//���� ��ġ ���� ������ 
			if (board[r-dy[d]][c-dx[d]]!=1) {//	�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
				r = r - dy[d]; c=c - dx[d];
			}
			else if (board[r - dy[d]][c- dx[d]] == 1) {//	�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
				break;//����
			}
			//	�κ� û�ұ�� �̹� û�ҵǾ��ִ� ĭ�� �� û������ ������, ���� ����� �� ����.
		}
	}
}

int main(void) {
	int testCase = 1;// �׽�Ʈ ���̽� ����
	//scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init_input();//�ʱ�ȭ �� �Է� ����
		playClean();//�ùķ��̼� ����
		printf("%d\n",ret - 2);
		//printf("#%d %d\n", tc, ret-2);
	}
	return 0;
}