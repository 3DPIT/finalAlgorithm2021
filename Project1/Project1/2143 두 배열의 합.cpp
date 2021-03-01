#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
long long int N, M;//두배열 최대 입력
long long int T;// 찾아야하는 수
int A[1001], B[1001];//저장되는 배열
vector<int>sA;// A합
vector<int>sB;// B합
void init() {//초기화 및 초기 입력
	N = M = T = 0;
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	scanf("%ld", &T);// 더해서 찾아지는 수
	scanf("%d", &N);// A의 개수
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);// B의 개수
	for (int j = 0; j < M; j++) {
		scanf("%d", &B[j]);
	}
}
void preSum() {
	for (int i = 0; i < N; i++) {
		int sum = A[i];
		sA.push_back(sum);
		for (int j = i + 1; j < N; j++) {
			sum += A[j];
			sA.push_back(sum);
		}
	}
	for (int i = 0; i < M; i++) {
		int sum = B[i];
		sB.push_back(sum);
		for (int j = i + 1; j < M; j++) {
			sum += B[j];
			sB.push_back(sum);
		}
	}
	sort(sA.begin(), sA.end());
	sort(sB.begin(), sB.end());
	long long int ret = 0;//최종 결과값
	for (int i = 0; i < sA.size(); i++) {
		long long int searchNum = T - sA[i];
		int low = lower_bound(sB.begin(), sB.end(),searchNum)-sB.begin();
		int high = upper_bound(sB.begin(), sB.end(), searchNum) - sB.begin();
		ret += (high - low);
	}
	cout << ret << endl;
}
int main(void) {
	init();//초기화 및 초기 입력
	preSum();//미리 계산
	return 0;
}