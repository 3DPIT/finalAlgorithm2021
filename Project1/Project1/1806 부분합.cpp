#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define NS 100005//배열 최대크기
int N;//입력되는 배열 크기
long long int S;//찾아야하는 값
int arr[NS];//입력되는 숫자 저장하는 배열
void init() {// 초기화 및 초기 입력 함수
	N = S = 0;
	memset(arr, 0, sizeof(arr));

	scanf("%d %ld", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
}
long long int twoPoint() {//투포인터 이용 연속되는 합 구하기
	int L, R;//인덱스
	L = R = 0;
	int sum = 0;//합 산출
	long long int min = 0x7fffffff;//결과 값 

	while (L <= R && R <= N) {
		//cout << "L : " << L << "R : " << R << "sum : " << sum << '\n';
		if (sum < S) {//현재 값이 목표 값보다 작으면  R인덱스 증가

			sum += arr[R++];
		}
		else if (sum >= S) {// 값이 크면 L인덱스 증가하고 sum 값 뺴기
			int len = R - L;
			min = min > len ? len : min;
			sum -= arr[L++];
		}

	}
	if (min == 0x7fffffff)min = 0;
	return min;
}
int main(void) {
	init();
	printf("%ld", twoPoint());
	return 0;
}