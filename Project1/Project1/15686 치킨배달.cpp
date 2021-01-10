#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
#define NS 51//배열의 최대 크기
int board[NS][NS];//집과 치킨의 정보가 담긴 배열
int N, M;//배열의 입력크기, 최대 치킨집 선택 변수
int ret;//결과 값
vector<int>D;//치킨집 선택
struct Data {
	int y, x;//집과 치킨집의 인덱스
}home[251],chicken[14];
int homeIdx, chickenIdx;//집과 치킨집의 개수
void init_input() {//초기화 및 초기 입력
	memset(home, 0, sizeof(home));
	memset(chicken, 0, sizeof(chicken));
	memset(board, 0, sizeof(board));
	homeIdx = chickenIdx = 0;
	D.clear();
	N = M = 0;
	ret = 0x7fffffff;//최소값
	
	scanf("%d %d", &N,&M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j]==1) {//집인 경우
				home[homeIdx].y = i; home[homeIdx].x = j; homeIdx++;
			}
			else if (board[i][j] == 2) {//치킨집인 경우
				chicken[chickenIdx].y = i; chicken[chickenIdx].x = j; chickenIdx++;
			}
		}
	}
}
void dfs(int idx) {
	if (idx > chickenIdx)return;//범위 넘어서면 리턴
	if (D.size() == M) {//최대 M개선택
		int sum=0;//도시 치킨거리 저장
		for (int h = 0; h < homeIdx; h++) {
			int CDM = 0x7fffffff;//chicken Distance Min; 최소 치킨 거리 저장 배열
			for (int c = 0; c < D.size(); c++) {
				int d = abs(home[h].y - chicken[D[c]].y) + abs(home[h].x - chicken[D[c]].x);
				CDM = CDM > d ? d : CDM;//최소값 저장
			}
			sum += CDM;//최소 거리 저장
		}
		ret = ret > sum ? sum : ret;//도시치킨거리 최소 저장
		return;
	}
	D.push_back(idx);//치킨집 선택
	dfs(idx + 1);//선택
	D.pop_back();
	dfs(idx + 1);//선택 안함
}
int main(void) {
	int testCase = 1;//테스트 케이스 변수
	//scanf("%d", &testCase);//테스트 케이스 개수입력
	for (int tc = 1; tc <= testCase; tc++) {
		init_input();
		dfs(0);
		printf("%d\n", ret);
		//printf("#%d %d\n", tc, ret);
	}
	return 0;
}