#include<stdio.h>
using namespace std;
#define ARR_SIZE 50//배열 최대 크기
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
char chessBoard[ARR_SIZE][ARR_SIZE];// 체스 저장 배열
int main(void) {
	int N, M;// 가로 세로 입력 크기
	int Min = 0x7fffffff;//최소값 저장
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
			scanf("%s", &chessBoard[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for(int num=0;num<2;num++){
				int cnt = 0;// 개수 카운트
				int flag = 0;//탈출 체크
				for (int ci = 0; ci < 8; ci++) {
					if (i + 8 > N) {
						flag = 1;
						break;//범위 넘어가면 못가게
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
				Min = Min > cnt ? cnt : Min;//최소값 저장
			}
		}
	}
	printf("%d\n", Min);
}