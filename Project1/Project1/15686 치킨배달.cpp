#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
#define NS 51//�迭�� �ִ� ũ��
int board[NS][NS];//���� ġŲ�� ������ ��� �迭
int N, M;//�迭�� �Է�ũ��, �ִ� ġŲ�� ���� ����
int ret;//��� ��
vector<int>D;//ġŲ�� ����
struct Data {
	int y, x;//���� ġŲ���� �ε���
}home[251],chicken[14];
int homeIdx, chickenIdx;//���� ġŲ���� ����
void init_input() {//�ʱ�ȭ �� �ʱ� �Է�
	memset(home, 0, sizeof(home));
	memset(chicken, 0, sizeof(chicken));
	memset(board, 0, sizeof(board));
	homeIdx = chickenIdx = 0;
	D.clear();
	N = M = 0;
	ret = 0x7fffffff;//�ּҰ�
	
	scanf("%d %d", &N,&M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j]==1) {//���� ���
				home[homeIdx].y = i; home[homeIdx].x = j; homeIdx++;
			}
			else if (board[i][j] == 2) {//ġŲ���� ���
				chicken[chickenIdx].y = i; chicken[chickenIdx].x = j; chickenIdx++;
			}
		}
	}
}
void dfs(int idx) {
	if (idx > chickenIdx)return;//���� �Ѿ�� ����
	if (D.size() == M) {//�ִ� M������
		int sum=0;//���� ġŲ�Ÿ� ����
		for (int h = 0; h < homeIdx; h++) {
			int CDM = 0x7fffffff;//chicken Distance Min; �ּ� ġŲ �Ÿ� ���� �迭
			for (int c = 0; c < D.size(); c++) {
				int d = abs(home[h].y - chicken[D[c]].y) + abs(home[h].x - chicken[D[c]].x);
				CDM = CDM > d ? d : CDM;//�ּҰ� ����
			}
			sum += CDM;//�ּ� �Ÿ� ����
		}
		ret = ret > sum ? sum : ret;//����ġŲ�Ÿ� �ּ� ����
		return;
	}
	D.push_back(idx);//ġŲ�� ����
	dfs(idx + 1);//����
	D.pop_back();
	dfs(idx + 1);//���� ����
}
int main(void) {
	int testCase = 1;//�׽�Ʈ ���̽� ����
	//scanf("%d", &testCase);//�׽�Ʈ ���̽� �����Է�
	for (int tc = 1; tc <= testCase; tc++) {
		init_input();
		dfs(0);
		printf("%d\n", ret);
		//printf("#%d %d\n", tc, ret);
	}
	return 0;
}