#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define NS 51 //���� ���� ũ��
#define MS 51
int dy[] = { -1,0,1,0 };//0  1  2  3 
int dx[] = { 0,1,0,-1 };//�� �� �� ��
int room[NS][MS];//û���ؾ��ϴ� ��
int cleanArea ;//û���� ���� ��
int N, M, r, c, d;//�Է� : ����, ����, �κ� ��ġ y,x, �κ� ����
void init() {//�ʱ�ȭ �� �ʱ� �Է�
	N = M = r = c = d = 0;
	cleanArea = 1;
	memset(room, 0, sizeof(room));
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &room[i][j]);
		}
	}
}
void robotStart() {//�κ��� ����
	while (1) {
		if (0 == room[r][c]) {//���� ��ġ�� û���Ѵ�.
			room[r][c] = ++cleanArea;
		}
		//���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
		int copyD = d;//4���� �˻��� �״�� ���� �����ϱ� ���ؼ� 
		int flag = 1;//4���� �˻� ���� Ȯ�� 1�̸� û�ұ��� ����
		for (int cleanCnt = 1; cleanCnt <= 4; cleanCnt++) {
			//���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
			copyD = ((--copyD) + 4)%4;
			int ny = r + dy[copyD]; int nx = c+ dx[copyD];
			if (0 == room[ny][nx]) {
				r = ny; c = nx;
				d = copyD;
				flag = 0;
				break;
			}
		}
		//���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
		if (flag) {//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
			int ny = r - dy[d]; int nx = c - dx[d];
			if (1 != room[ny][nx]) {
				r = ny; c = nx;
			}
			else if (1 == room[ny][nx]) {//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
				break;//����
			}
		}
	}
}
int main(void) {
	int testCase = 1;
	//scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		robotStart();
		//printf("#%d %d\n", tc, cleanArea-1);
		printf("%d\n", cleanArea-1);
	}
	return 0;
}