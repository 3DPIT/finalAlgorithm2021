#include<stdio.h>
#include<iostream>
using namespace std;
long long int E, S, M;//지구, 태양, 달 날짜
int main(void) {
	int time = 0;
	scanf("%d %d %d", &E, &S, &M);
	if (E == 1 && S == 1 && M == 1) {
		cout << 1 << endl;
		return 0;
	}
	int e, s, m;
	e = s = m = 1;
	while (1) {
		time++;
		if (e == E && s == S && m == M) {
			cout << time << endl;
			break;
		}
		e++; s++; m++;
		if (e == 16)e = 1;
		if (s == 29)s = 1;
		if (m == 20)m = 1;
	}
	return 0;
}