#include<stdio.h>
#include<iostream>
using namespace std;
int n;//��ü �Է� ��
int cnt;//���� ������ ���� ��
void dfs(int idx, int sum, int num) {
	if (sum >= num) {
		if(sum==num)cnt++;// num ������ �Ǵ� ���
		return;
	}
	for (int i = 1; i <= 3; i++) {
		dfs(idx, sum + i, num);
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;//�Է� ����
		scanf("%d", &num);
		dfs(0,0,num);
		cout << cnt << endl;
		cnt = 0;
	}

	return 0;
}