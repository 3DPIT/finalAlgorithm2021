#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define NS 11

int N, M, K;//���� �ִ�ũ��, �ʱ� ���� �� ����, ��� ��
int ret;//�����
int energeSoil[NS][NS];//�������Ǵ� ��
int soil[NS][NS];//�κ��� ��� �Ѹ��� ��
int DieTreeEnerge[NS][NS];
int dy[] = { -1,-1,-1,0,0,1,1,1 };//���� ������ �����ΰ�� 8���� ���� 
int dx[] = { -1,0,1,-1,1,-1,0,1 };
vector<int>tree[NS][NS];


void init();//�ʱ�ȭ �� �ʱ� �Է�
void spring();//��
void summer();//����
void fall();//���� 
void winter();//�ܿ�
void farmTree();// ���� ���
void remainTree();//���� ���� ���� ����

int main(void) {
	int testCase = 1;
	//scanf("%d", &testCase);
	for (int tc = 1; tc <= testCase; tc++) {
		init();
		while (K--) {
			farmTree();
		}
		remainTree();
		printf("%d\n", ret);
		//printf("#%d %d\n", tc, ret);
	}
	return 0;
}
void init() {
	for (int i = 0; i < NS; i++)for (int j = 0; j < NS; j++)tree[i][j].clear();
	N = M = K = 0;
	ret = 0;
	
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) {
		energeSoil[i][j] = 5;
		scanf("%d", &soil[i][j]);
	}
	for (int m = 0; m < M; m++) {
		int y, x,age;
		scanf("%d %d %d", &y, &x, &age);
		tree[y-1][x-1].push_back({ age });
	}
}
void spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sort(tree[i][j].begin(), tree[i][j].end());//������������ ����
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j].size() == 0)break;
				if (energeSoil[i][j] - tree[i][j][k]< 0) {//��� ��� ������� �ʴ� ���
					DieTreeEnerge[i][j] += tree[i][j][k]/ 2;//���� ���� ������ ���� ������� ����
					tree[i][j].erase(tree[i][j].begin() + k);//���� ���̱�
					k--;
				}
				else if (energeSoil[i][j] - tree[i][j][k] >=0) {//��� ��� ����� ���
					energeSoil[i][j] -= tree[i][j][k];
					tree[i][j][k]++;//�ѻ� ����
				}
			}
		}
	}
}
void summer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			energeSoil[i][j] += DieTreeEnerge[i][j];
			DieTreeEnerge[i][j] = 0;
		}
	}
}
void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k]% 5 == 0) {//���� ������ ������ ���
					for (int dir = 0; dir < 8; dir++) {
						int ny = i + dy[dir]; int nx = j + dx[dir];
						if (0 <= ny && ny < N && 0 <= nx && nx < N) {//�����ȿ� �����Ҷ�
							tree[ny][nx].push_back({ 1 });//1�� ������ ���� 
						}
					}
				}
			}
		}
	}
}
void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			energeSoil[i][j] += soil[i][j];//r2d2�κ� ��� �����Ű��
		}
	}
}
void farmTree() {
	spring();
	summer();
	fall();
	winter();
}
void remainTree() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ret += tree[i][j].size();
		}
	}
}