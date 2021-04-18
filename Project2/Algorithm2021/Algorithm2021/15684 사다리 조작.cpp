#include<iostream>
using namespace std;
#define NSIZE 31
#define MSIZE 271
int N, M,K;//���� ,���� ,�̸� �ߴ� ���� ��
int ret = -1;
int map[MSIZE][NSIZE];
void init();// �ʱ�ȭ �� �Է�
void dfs(int y, int x, int cnt,int num);
int main(void) {
	init();
	for (int num = 1; num <= N * M; num++) {
		if (ret != -1)break;
		dfs(1, 1, 0, num);
	}
	cout << ret << endl;
	return 0;
}
void init() {
	N = M = K = 0;
	ret = -1;
	cin >> N >> K >> M;
	for (int k = 0; k < K; k++) {
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;//�̸� �ٸ� ��ġ
	}
}
bool downNum() {
	int y = 1; int x = 1;
	for(int i=1;i<=N;i++){
		y = 1; x = 1;
		while (1) {
			if (map[y][x] == 1) {
				x++;//���������� �̵�
			}
			else if (map[y][x - 1] == 1) {
				x--;
			}
			y++;
			if (y == M + 1)break;
		}
		if (y != i)return 0;//���� �ʾƵ� �Ǵ� ���
	}
	return 1;//���� ���
}
void dfs(int y, int x, int cnt,int num) {
	if (ret != -1)return;
	if (num == cnt) {
		if (downNum()) {
			ret = cnt;
		}
		return;
	}

	for (int i = y; i < M; i++) {
		for (int j = x; j < N; j++) {
			if (map[y][x - 1] == 0 && map[y][x + 1] == 0) {
				map[y][x] = 1;//�ٸ� ����
				dfs(y, x+1, cnt + 1,num);
				map[y][x] = 0;
			}
		}
		x = 0;
	}
}