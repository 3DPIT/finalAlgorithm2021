#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int M, N;//x�� y�� �ִ� ����
int x, y;//��¥
int cx, cy;//����ϴ� ��¥
int num[40001];//��¥ üũ�ϴ� �Լ�
int Time = 0;//��¥ �����
void init() {//�ʱ�ȭ �� �ʱ� �Է�
	M = N = 0;
	cx = cy = Time=0;
	memset(num, 0, sizeof(num));
	scanf("%d %d %d %d", &M, &N,&x,&y);
}
void kCal() {//ī�� �޷� ��� 
	int flag = 0;
	while (1) {
		cx++; cy++; Time++;
		if (cx == x && cy == y) {//������̸� ����
			break;
		}
		if (cx == M + 1)cx = 1;
		if (cy == N + 1)cy = 1;
		if (cx == x && cy == y) {//����� ã��
			flag = 1; break;
		}
		while (cx==x) {//y�� ���
			cy += M;
			cy = cy % N;
			if (cy == 0)cy = N;
			Time += M;
			if (cx == x && cy == y) {//����� ã��
				flag = 1; break;
			}
			if (num[cy] == 0) {
				num[cy] = 1;
			}
			else {//������� ���ٸ� -1 ����
				flag = 1;
				Time = -1;
				break;
			}
		}
		if(flag)break;
	}
}
int main(void) {
	int testCase = 1;
	scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		kCal();
		cout << Time << endl;
	}
	return 0;
}