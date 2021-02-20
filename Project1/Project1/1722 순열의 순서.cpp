#include<stdio.h>
#include<iostream>
using namespace std;
#define N_SIZE 21// 최대 입력으로 주어지는 수 
int N;//입력으로 주어지는 수
long long int facArr[N_SIZE];//n! 미리저장
int chkNum[N_SIZE];//사용된 숫자 체크
int Q_num;//문제 번호 1 이면 k번째 수열 출력
			//   번호 2 이면 현재 수열의 위치 출력
void init() {//초기화 및 입력
	N = Q_num = 0;
	scanf("%d", &N);
	scanf("%d", &Q_num);
}
void fac() {//펙토리얼 미리 저장
	facArr[0] = 1;
	facArr[1] = 1;
	for (int i = 2; i <= N; i++) {
		facArr[i] = i;
		facArr[i]*=facArr[i-1];
	}
}
int main(void) {
	init();
	fac();//펙토리얼 미리 저장
	if (Q_num == 1) {//k번째 수열 출력
		long long int k;//현재 위치 수열
		scanf("%lld", &k);
		long long int cnt = 0;//N과 같아지면 반복문 탈출
		long long int use = 0, rem = k;//사용한것 , 남은 수 변수
		int facNum = N - 1;//펙토리얼 더하는 수
		while (1) {//반복
			if (cnt == N)break;
			for (int i = 1; i <= N; i++) {//1부터 N까지 반복
				if (chkNum[i] == 1)continue;
				use += facArr[facNum];//더해진 위치
				rem -= facArr[facNum];//남은 위치
				if (rem <= 0) {
					rem += facArr[facNum];
					use -= facArr[facNum];
					facNum--;
					chkNum[i] = 1;//현재 확정된 값 체크
					cnt++;
					cout << i << " ";//확정된 값 출력
					break;
				}
			}
		}
	}
	else if (Q_num == 2) {//입력으로 주어진 수열의 위치 출력
		int numArr[21];//입력 수열 저장
		for (int i = 0; i < N; i++) {
			scanf("%d", &numArr[i]);
		}
		int cnt = 0;//탈출 조건 N과 같으면 
		int facNum = N - 1;//펙토리얼 더하는 수
		long long int use = 0;//현재 위치의 수 저장
		for (int i = 0; i < N; i++) {//0번 인덱스부터 탐색
			chkNum[numArr[i]] = 1;
			for (int j = 1; j <numArr[i]; j++) {
				if (chkNum[j] == 1)continue;//사용한 숫자 건너 뛰기
				use += facArr[facNum];
			}
			facNum--;
		}
		cout << use + 1;
	}
	return 0;
}