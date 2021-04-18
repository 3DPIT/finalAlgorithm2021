#include<iostream>
using namespace std;
#define NSIZE 31
#define MSIZE 271
int N, M, K;//세로 ,가로 ,미리 긋는 가로 수
int ret = -1;
int ret1 = 0x7fffffff;
int map[MSIZE][NSIZE];
void init();// 초기화 및 입력
void dfs(int y, int x, int cnt, int num);
void dfs1(int y, int x, int cnt);
int main(void) {
	init();
	//for (int num = 0; num <= 3; num++) {
	//	if (ret != -1)break;
	//	dfs(1, 1, 0, num);
	//}
	dfs1(1, 1, 0);
	if (ret1 == 0x7fffffff)ret1 = -1;
	cout << ret1 << endl;
	return 0;
}
void init() {
	N = M = K = 0;
	ret1 = 0x7fffffff;
	cin >> N >> K >> M;
	for (int k = 0; k < K; k++) {
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;//미리 다리 설치
	}
}
bool downNum() {
	int y = 1; int x = 1;
	for (int i = 1; i <= N; i++) {
		y = 1; x = i;
		while (1) {
			if (map[y][x] == 1) {
				y++;;
				x++;//오른쪽으로 이동
			}
			else if (map[y][x - 1] == 1) {
				y++;
				x--;
			}
			else if(map[y][x]==0)y++;
			if (y == M + 1)break;
		}
		if (x != i)return 0;//보지 않아도 되는 경우
	}
	return 1;//참인 경우
}
void dfs(int y, int x, int cnt, int num) {
	if (ret != -1)return;
	if (num==0||num == cnt) {
		if (downNum()) {
			ret = ret > cnt ? cnt : ret;
		}
		return;
	}

	for (int i = y; i <=M; i++) {
		for (int j = x; j <= N; j++) {
			if (map[i][j - 1] == 0 && map[i][j]==0&&map[i][j + 1] == 0) {
				map[i][j] = 1;//다리 삽입
				dfs(i, j + 1, cnt + 1, num);
				map[i][j] = 0;
			}
		}
		x = 1;
	}
}
void dfs1(int y, int x, int cnt) {
	if (ret1 < cnt)return;//최소가 아니면 생략하기
	if (cnt > 3) return;
		if (downNum()) {
			ret1 = ret1 > cnt ? cnt : ret1;
		}
	for (int i = y; i <= M; i++) {
		for (int j = x; j <= N; j++) {
			if (map[i][j - 1] == 0 && map[i][j] == 0 && map[i][j + 1] == 0) {
				map[i][j] = 1;//다리 삽입
				dfs1(i, j + 1, cnt + 1);
				map[i][j] = 0;
			}
		}
		x = 1;
	}
}
