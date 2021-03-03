#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define PIZZA_SIZE 1001
int wantPizza;//�մ��� ���ϴ� ����ũ��
int m, n;//A�� ������ ����, B�� ������ ����
int aPizza[PIZZA_SIZE];//A���� ����
int bPizza[PIZZA_SIZE];//B���� ����
vector<int>aV;//������ �� ����
vector<int>bV;//������ �� ����

void init() {//�ʱ�ȭ �� �ʱ� �Է�
	m = n = wantPizza = 0;
	aV.clear(); bV.clear();
	memset(aPizza, 0, sizeof(aPizza));
	memset(bPizza, 0, sizeof(bPizza));

	scanf("%d", &wantPizza);
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		scanf("%d", &aPizza[i]);
	}
	for (int j = 0; j < n; j++) {
		scanf("%d", &bPizza[j]);
	}
}
void sumPizza() {//���� �з��ϱ�
	for (int i = 0; i < m; i++) {
		int sum = 0;
		sum += aPizza[i];
		aV.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += aPizza[j];
			aV.push_back(sum);
		}
	}
	int ck1 = m - 1;//���ؾ��ϴ� ��
	for (int i = 2; i < m; i++) {//���� ��� �̱⋚���� ȸ���ؼ� ���ϴ� �˰���
		int sum = 0;//�� ����
		for (int ck=ck1; ck <= m-1; ck++) {
			sum = 0;
			for (int ci = i, j = 1; j <= ck; j++,ci++) {
				if (ci == m)ci = 0;
				sum += aPizza[ci];
			}
			aV.push_back(sum);
		}
		ck1--;
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		sum += bPizza[i];
		bV.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += bPizza[j];
			bV.push_back(sum);
		}
	}
	 ck1 = n - 1;//���ؾ��ϴ� ��
	for (int i = 2; i < n; i++) {//���� ��� �̱⋚���� ȸ���ؼ� ���ϴ� �˰���
		int sum = 0;//�� ����
		for (int ck = ck1; ck <= n - 1; ck++) {
			sum = 0;
			for (int ci = i, j = 1; j <= ck; j++, ci++) {
				if (ci == n)ci = 0;
				sum +=bPizza[ci];
			}
			bV.push_back(sum);
		}
		ck1--;
	}
}
void retOutput() {
	sort(bV.begin(), bV.end());
	int ret = 0;
	for (int i = 0; i < aV.size(); i++) {
		if (aV[i] == wantPizza)ret++;
		if (wantPizza < aV[i])continue;//S���� ũ�� �ǹ� �����Ƿ� ����
		int num = wantPizza - aV[i];//ã�ƾ��ϴ°�
		int low = lower_bound(bV.begin(), bV.end(), num) - bV.begin();
		int high = upper_bound(bV.begin(), bV.end(), num) - bV.begin();
		ret += high - low;
	}
	for (int i = 0; i < bV.size(); i++) {
		if (bV[i] == wantPizza)ret++;
	}
	cout << ret << endl;
}
int main(void) {
	init();
	sumPizza();
	retOutput();
	return 0;
}