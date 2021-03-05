#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define NS 11 //도시의 최대 크기
int N;//도시의 수
int city[NS][NS];//도시 여행 비용 저장
bool visit[NS];//방문체크
int ret;//결과값
struct Data {
	int idx, cost;
};
vector<Data>G[NS];//그래프 저장
void init() {//초기화 및 초기 입력
	N = 0;
	ret = 0x7fffffff;
	memset(city, 0, sizeof(city));
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cost;
			scanf("%d", &cost);
			if (cost != 0) {
				G[i].push_back({ j,cost });
			}
		}
	}
}
void dfs(int f_idx, int idx, int cnt,int cost) {//초기로 돌아가는 변수, 시작변수, 개수세기
	if (cnt == N) {//순회를 다했다면 
		ret = ret > cost ? cost : ret;//최소값
		return;
	}
	for (int i = 0; i < G[idx].size(); i++) {
		if (cnt == N - 1) {//마지막 도시에서 첫번째 도시로 가기위해서
			int city_cnt = 0;
			for (int j = 0; j < G[idx].size(); j++) {
				city_cnt++;
				if (G[idx][j].idx == f_idx) {
					dfs(f_idx, G[idx][i].idx, cnt + 1, cost+G[idx][i].cost);//비용 저장하면서 넘기기
				}
			}
			if (city_cnt == G[idx].size())return;
		}
		if (visit[G[idx][i].idx] == 0) {//방문 하지 않았다면 방문 체크
			visit[G[idx][i].idx] = 1;
			dfs(f_idx, G[idx][i].idx, cnt + 1, cost + G[idx][i].cost);//비용 저장하면서 넘기기
			visit[G[idx][i].idx] = 0;

		}
	}
}
int main(void) {
	init();
	for (int first_idx = 0; first_idx < N; first_idx++) {
		visit[first_idx] = 1;//방문
		dfs(first_idx,first_idx,0,0);
	}
	cout << ret << endl;
	return 0;
}