#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define NS 51//배열 최대 크기
int N, M;//배열크기, 치킨 뽑는수;
struct Pos {
	int y; int x;
};
vector<Pos>H;//집 정보
vector<Pos>C;//치킨 정보
vector<int>D;//뽑는 치킨
int ret;//최소 값
void dfs(int idx, int cnt) {
	if (idx == C.size()+1)return;
	if (cnt == M) {
		//C
		int sum = 0;//최소의 합 저장
		for (int h = 0; h < H.size(); h++) {
			int minDistance = 0x7fffffff;//최소
			for (int d = 0; d < D.size(); d++) {
				int distance = abs(H[h].y - C[D[d]].y) + abs(H[h].x - C[D[d]].x);
					minDistance = minDistance >distance ? distance : minDistance;
			}
			sum += minDistance;
		}// for int h
		ret = ret > sum ? sum : ret;//최종 최소 저장
		return;
	}
	D.push_back(idx);
	dfs(idx + 1, cnt + 1);
	D.pop_back();
	dfs(idx + 1, cnt);
}
void init() {//초기화 및 초기 입력
	N = M = 0;
	ret = 0x7fffffff;
	H.clear(); C.clear(); D.clear();
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num = 0;
			scanf("%d", &num);//정보
			if (1==num) H.push_back({ i,j });//집정보
			if (2==num)C.push_back({ i,j });//치킨 정보
		}
	}
}
int main(void) {
	int testCase = 1;//테스트 케이스
	//scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		dfs(0, 0);
		//printf("#%d %d\n", tc, ret);
		printf("%d\n",ret);
	}
	return 0;
}