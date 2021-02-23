#include<stdio.h>
#include<iostream>
using namespace std;
int arr[4];//조합 선정
int chk[4];//위치 체크
void dfs1(int cnt,int idx) {
	if (cnt == 2) {
		for (int i = 0; i < 4; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = idx; i < 4; i++) {
		if (chk[i] == 0) {
			chk[i] = 1;
			arr[i] = 1;
			dfs1(cnt + 1,i);
			arr[i] = 0;
			chk[i] = 0;
		}
	}
}
int main(void) {
	dfs1(0,0);
	return 0;
}