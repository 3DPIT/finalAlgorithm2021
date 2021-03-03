#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define PIZZA_SIZE 1001
int wantPizza;//손님이 원하는 피자크기
int m, n;//A의 나눠진 개수, B의 나눠진 개수
int aPizza[PIZZA_SIZE];//A피자 저장
int bPizza[PIZZA_SIZE];//B피자 저장
vector<int>aV;//피자의 합 저장
vector<int>bV;//피자의 합 저장

void init() {//초기화 및 초기 입력
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
void sumPizza() {//피자 분류하기
	for (int i = 0; i < m; i++) {
		int sum = 0;
		sum += aPizza[i];
		aV.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += aPizza[j];
			aV.push_back(sum);
		}
	}
	int ck1 = m - 1;//더해야하는 수
	for (int i = 2; i < m; i++) {//원인 경우 이기떄문에 회전해서 더하는 알고리즘
		int sum = 0;//합 저장
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
	 ck1 = n - 1;//더해야하는 수
	for (int i = 2; i < n; i++) {//원인 경우 이기떄문에 회전해서 더하는 알고리즘
		int sum = 0;//합 저장
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
		if (wantPizza < aV[i])continue;//S보다 크면 의미 없으므로 제외
		int num = wantPizza - aV[i];//찾아야하는것
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