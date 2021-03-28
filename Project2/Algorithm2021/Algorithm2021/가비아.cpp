#include<stdio.h>
#include<iostream>
using namespace std;
long long int  factor(long long int n) {
	if (n == 1)return 1;
	else return n * factor(n - 1);
}
int solution(int n)
{
	int answer = 0;
	int idx = 0;
	long long int five[30];
	for (long long int i = 5, cnt = 1;cnt<15; i *= 5,cnt++) {
		five[idx++] = i;
	}
	answer = n / five[0] + n / five[1] + n / five[2] + n / five[3] + n / five[4] + n / five[5] + n / five[6] + n / five[7]
		+ n / five[8] + n / five[9] + n / five[10] + n / five[11] + n / five[12] + n / five[13] + n / five[14];
	return answer;
}
int main(void) {
	int n;
	while (1) {
		scanf("%d", &n);
		cout <<solution(n);
	}
}