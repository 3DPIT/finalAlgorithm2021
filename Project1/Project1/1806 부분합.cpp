#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define NS 100005//�迭 �ִ�ũ��
int N;//�ԷµǴ� �迭 ũ��
long long int S;//ã�ƾ��ϴ� ��
int arr[NS];//�ԷµǴ� ���� �����ϴ� �迭
void init() {// �ʱ�ȭ �� �ʱ� �Է� �Լ�
	N = S = 0;
	memset(arr, 0, sizeof(arr));

	scanf("%d %ld", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
}
long long int twoPoint() {//�������� �̿� ���ӵǴ� �� ���ϱ�
	int L, R;//�ε���
	L = R = 0;
	int sum = 0;//�� ����
	long long int min = 0x7fffffff;//��� �� 

	while (L <= R && R <= N) {
		//cout << "L : " << L << "R : " << R << "sum : " << sum << '\n';
		if (sum < S) {//���� ���� ��ǥ ������ ������  R�ε��� ����

			sum += arr[R++];
		}
		else if (sum >= S) {// ���� ũ�� L�ε��� �����ϰ� sum �� ����
			int len = R - L;
			min = min > len ? len : min;
			sum -= arr[L++];
		}

	}
	if (min == 0x7fffffff)min = 0;
	return min;
}
int main(void) {
	init();
	printf("%ld", twoPoint());
	return 0;
}