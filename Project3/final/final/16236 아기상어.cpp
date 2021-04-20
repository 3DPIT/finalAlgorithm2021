#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define NSIZE 21
int N;//������ ũ��
int seaPlace[NSIZE][NSIZE];//�ٴ��� ����
int sharkSize = 2;//�ʱ� �Ʊ� ��� ũ��
int y, x;//����� ��ġ 
int ret;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

bool safe(int y, int x);//��� �̵����� ���� 
void init();//�ʱ�ȭ �� �ʱ� �Է�
void eatFish();//���� ��� �Լ�

struct Data {
	int y; int x; int d;
};

int main(void) {
	init();
	eatFish();
	printf("%d", ret);
	return 0;
}

bool safe(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < N;
}
void init() {
	N = ret = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &seaPlace[i][j]);
			if (seaPlace[i][j] == 9) {//�Ʊ� �����ġ
				seaPlace[i][j] = 0;
				y = i;
				x = j;
			}
		}
	}
}
void eatFish() {
	int fishDie = 0;
	while (1) {//����� ���� Ȱ�� ����
		int d = 0x7fffffff; int min_y = 0x7fffffff; int min_x = 0x7fffffff;
		queue<Data>q;
		q.push({ y, x, 0 });
		int visit[NSIZE][NSIZE] = { 0, };
		visit[y][x] = 1;
		while (!q.empty()) {
			Data c = q.front(); q.pop();
			if (d < c.d)break;//�ּҰ��� �ǹ� �־ �ּҰ����� ũ�� Ż��
			if (seaPlace[c.y][c.x]!=0&&seaPlace[c.y][c.x] < sharkSize) {
				if (d >= c.d) {
					d = c.d;
					if (min_y > c.y || (min_y == c.y&&min_x > c.x)) {
						min_y = c.y; min_x = c.x;
					}
				}
			}
			for (int dir = 0; dir < 4; dir++) {//�׹��� Ž��
				Data n;
				n.y=c.y+ dy[dir]; n.x =c.x+ dx[dir];
				n.d = c.d;
				if (seaPlace[n.y][n.x] <=sharkSize && visit[n.y][n.x] == 0 && safe(n.y, n.x)) {
					visit[n.y][n.x] = ++n.d;
					q.push(n);
				}
			}

		}//while(!q.empty())
		if (d == 0x7fffffff)break;
		else {
			ret+=d;
			fishDie++;
			if (fishDie == sharkSize) {//��� ũ�� ��ŭ ������ ����
				sharkSize++;
				fishDie = 0;
			}
			y = min_y; x = min_x;
			seaPlace[y][x] = 0;
			while (!q.empty()) { q.pop(); }
		}
	}//while(1)
}