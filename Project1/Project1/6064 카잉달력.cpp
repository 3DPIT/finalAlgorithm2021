#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int M, N;//x와 y의 최대 범위
int x, y;//날짜
int cx, cy;//계산하는 날짜
int num[40001];//날짜 체크하는 함수
int Time = 0;//날짜 결과값
void init() {//초기화 및 초기 입력
	M = N = 0;
	cx = cy = Time=0;
	memset(num, 0, sizeof(num));
	scanf("%d %d %d %d", &M, &N,&x,&y);
}
void kCal() {//카잉 달력 계산 
	int flag = 0;
	while (1) {
		cx++; cy++; Time++;
		if (cx == x && cy == y) {//결과값이면 종료
			break;
		}
		if (cx == M + 1)cx = 1;
		if (cy == N + 1)cy = 1;
		if (cx == x && cy == y) {//결과값 찾음
			flag = 1; break;
		}
		while (cx==x) {//y값 계산
			cy += M;
			cy = cy % N;
			if (cy == 0)cy = N;
			Time += M;
			if (cx == x && cy == y) {//결과값 찾음
				flag = 1; break;
			}
			if (num[cy] == 0) {
				num[cy] = 1;
			}
			else {//결과값이 없다면 -1 종료
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