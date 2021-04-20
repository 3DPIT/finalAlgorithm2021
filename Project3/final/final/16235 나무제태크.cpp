#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define NS 11

int N, M, K;//땅의 최대크기, 초기 나무 의 개수, 몇년 후
int ret;//결과값
int energeSoil[NS][NS];//양분저장되는 땅
int soil[NS][NS];//로봇이 양분 뿌리는 양
int DieTreeEnerge[NS][NS];
int dy[] = { -1,-1,-1,0,0,1,1,1 };//번식 가능한 나무인경우 8방향 으로 
int dx[] = { -1,0,1,-1,1,-1,0,1 };
vector<int>tree[NS][NS];


void init();//초기화 및 초기 입력
void spring();//봄
void summer();//여름
void fall();//가을 
void winter();//겨울
void farmTree();// 나무 농사
void remainTree();//남은 나무 개수 세기

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
			sort(tree[i][j].begin(), tree[i][j].end());//오름차순으로 정렬
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j].size() == 0)break;
				if (energeSoil[i][j] - tree[i][j][k]< 0) {//양분 흡수 충분하지 않는 경우
					DieTreeEnerge[i][j] += tree[i][j][k]/ 2;//죽은 나무 나이의 절반 양분으로 저장
					tree[i][j].erase(tree[i][j].begin() + k);//나무 죽이기
					k--;
				}
				else if (energeSoil[i][j] - tree[i][j][k] >=0) {//양분 흡수 충분한 경우
					energeSoil[i][j] -= tree[i][j][k];
					tree[i][j][k]++;//한살 증가
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
				if (tree[i][j][k]% 5 == 0) {//번식 가능한 나무인 경우
					for (int dir = 0; dir < 8; dir++) {
						int ny = i + dy[dir]; int nx = j + dx[dir];
						if (0 <= ny && ny < N && 0 <= nx && nx < N) {//범위안에 존재할때
							tree[ny][nx].push_back({ 1 });//1살 나무로 번식 
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
			energeSoil[i][j] += soil[i][j];//r2d2로봇 양분 저장시키기
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