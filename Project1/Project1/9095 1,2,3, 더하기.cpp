#include<stdio.h>
#include<iostream>
using namespace std;
int n;//전체 입력 수
int cnt;//현재 나오는 조합 수
void dfs(int idx, int sum, int num) {
	if (sum >= num) {
		if(sum==num)cnt++;// num 조합이 되는 경우
		return;
	}
	for (int i = 1; i <= 3; i++) {
		dfs(idx, sum + i, num);
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;//입력 숫자
		scanf("%d", &num);
		dfs(0,0,num);
		cout << cnt << endl;
		cnt = 0;
	}

	return 0;
}