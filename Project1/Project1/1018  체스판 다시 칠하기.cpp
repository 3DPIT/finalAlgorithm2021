#include<stdio.h>
using namespace std;
#define ARR_SIZE 50//�迭 �ִ� ũ��
char chess[2][8][8] = {
	{
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'}
	},
	{
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'}
	}
};
char chessBoard[ARR_SIZE][ARR_SIZE];// ü�� ���� �迭
int main(void) {
	int N, M;// ���� ���� �Է� ũ��
	int Min = 0x7fffffff;//�ּҰ� ����
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
			scanf("%s", &chessBoard[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for(int num=0;num<2;num++){
				int cnt = 0;// ���� ī��Ʈ
				int flag = 0;//Ż�� üũ
				for (int ci = 0; ci < 8; ci++) {
					if (i + 8 > N) {
						flag = 1;
						break;//���� �Ѿ�� ������
					}
					for (int cj = 0; cj < 8; cj++) {
						if (j + 8 > M) {
							flag = 1;
							break;
						}
						if (chessBoard[i + ci][j + cj] != chess[num][ci][cj]) {
							cnt++;
						}
					}
					if (flag)break;
				}
				if (flag)break;
				Min = Min > cnt ? cnt : Min;//�ּҰ� ����
			}
		}
	}
	printf("%d\n", Min);
}