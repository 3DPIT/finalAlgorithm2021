#include<stdio.h>
#include<vector>
using namespace std;
#define NS 100001//최대 사이즈
int N, K;// 번호, 제거넘버
void init() {
scanf("%d %d", &N, &K);
}
void yose() {//요세푸스 풀이
	printf("<");
	int num[NS] = { 0 };
	int cK = -1;
	int cN = N;
	vector<int>v;//숫자 저장
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	for (int i = 1; i <N; i++) {
		cK = (cK + K)%cN;
		printf("%d, ",v[cK]);
		v.erase(v.begin() + cK);
		cK--; cN--;
	}
	printf("%d>",v[0]);
}
int main(void) {
	init();
	yose();

	return 0;
}
//세그먼트 트리 배우고 풀기