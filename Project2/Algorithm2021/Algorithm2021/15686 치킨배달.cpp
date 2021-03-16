#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define NS 51//�迭 �ִ� ũ��
int N, M;//�迭ũ��, ġŲ �̴¼�;
struct Pos {
	int y; int x;
};
vector<Pos>H;//�� ����
vector<Pos>C;//ġŲ ����
vector<int>D;//�̴� ġŲ
int ret;//�ּ� ��
void dfs(int idx, int cnt) {
	if (idx == C.size()+1)return;
	if (cnt == M) {
		//C
		int sum = 0;//�ּ��� �� ����
		for (int h = 0; h < H.size(); h++) {
			int minDistance = 0x7fffffff;//�ּ�
			for (int d = 0; d < D.size(); d++) {
				int distance = abs(H[h].y - C[D[d]].y) + abs(H[h].x - C[D[d]].x);
					minDistance = minDistance >distance ? distance : minDistance;
			}
			sum += minDistance;
		}// for int h
		ret = ret > sum ? sum : ret;//���� �ּ� ����
		return;
	}
	D.push_back(idx);
	dfs(idx + 1, cnt + 1);
	D.pop_back();
	dfs(idx + 1, cnt);
}
void init() {//�ʱ�ȭ �� �ʱ� �Է�
	N = M = 0;
	ret = 0x7fffffff;
	H.clear(); C.clear(); D.clear();
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num = 0;
			scanf("%d", &num);//����
			if (1==num) H.push_back({ i,j });//������
			if (2==num)C.push_back({ i,j });//ġŲ ����
		}
	}
}
int main(void) {
	int testCase = 1;//�׽�Ʈ ���̽�
	//scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		dfs(0, 0);
		//printf("#%d %d\n", tc, ret);
		printf("%d\n",ret);
	}
	return 0;
}