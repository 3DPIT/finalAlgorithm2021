#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define NS 11 //������ �ִ� ũ��
int N;//������ ��
int city[NS][NS];//���� ���� ��� ����
bool visit[NS];//�湮üũ
int ret;//�����
struct Data {
	int idx, cost;
};
vector<Data>G[NS];//�׷��� ����
void init() {//�ʱ�ȭ �� �ʱ� �Է�
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
void dfs(int f_idx, int idx, int cnt,int cost) {//�ʱ�� ���ư��� ����, ���ۺ���, ��������
	if (cnt == N) {//��ȸ�� ���ߴٸ� 
		ret = ret > cost ? cost : ret;//�ּҰ�
		return;
	}
	for (int i = 0; i < G[idx].size(); i++) {
		if (cnt == N - 1) {//������ ���ÿ��� ù��° ���÷� �������ؼ�
			int city_cnt = 0;
			for (int j = 0; j < G[idx].size(); j++) {
				city_cnt++;
				if (G[idx][j].idx == f_idx) {
					dfs(f_idx, G[idx][i].idx, cnt + 1, cost+G[idx][i].cost);//��� �����ϸ鼭 �ѱ��
				}
			}
			if (city_cnt == G[idx].size())return;
		}
		if (visit[G[idx][i].idx] == 0) {//�湮 ���� �ʾҴٸ� �湮 üũ
			visit[G[idx][i].idx] = 1;
			dfs(f_idx, G[idx][i].idx, cnt + 1, cost + G[idx][i].cost);//��� �����ϸ鼭 �ѱ��
			visit[G[idx][i].idx] = 0;

		}
	}
}
int main(void) {
	init();
	for (int first_idx = 0; first_idx < N; first_idx++) {
		visit[first_idx] = 1;//�湮
		dfs(first_idx,first_idx,0,0);
	}
	cout << ret << endl;
	return 0;
}