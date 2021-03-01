#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
long long int N, M;//�ι迭 �ִ� �Է�
long long int T;// ã�ƾ��ϴ� ��
int A[1001], B[1001];//����Ǵ� �迭
vector<int>sA;// A��
vector<int>sB;// B��
void init() {//�ʱ�ȭ �� �ʱ� �Է�
	N = M = T = 0;
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	scanf("%ld", &T);// ���ؼ� ã������ ��
	scanf("%d", &N);// A�� ����
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);// B�� ����
	for (int j = 0; j < M; j++) {
		scanf("%d", &B[j]);
	}
}
void preSum() {
	for (int i = 0; i < N; i++) {
		int sum = A[i];
		sA.push_back(sum);
		for (int j = i + 1; j < N; j++) {
			sum += A[j];
			sA.push_back(sum);
		}
	}
	for (int i = 0; i < M; i++) {
		int sum = B[i];
		sB.push_back(sum);
		for (int j = i + 1; j < M; j++) {
			sum += B[j];
			sB.push_back(sum);
		}
	}
	sort(sA.begin(), sA.end());
	sort(sB.begin(), sB.end());
	long long int ret = 0;//���� �����
	for (int i = 0; i < sA.size(); i++) {
		long long int searchNum = T - sA[i];
		int low = lower_bound(sB.begin(), sB.end(),searchNum)-sB.begin();
		int high = upper_bound(sB.begin(), sB.end(), searchNum) - sB.begin();
		ret += (high - low);
	}
	cout << ret << endl;
}
int main(void) {
	init();//�ʱ�ȭ �� �ʱ� �Է�
	preSum();//�̸� ���
	return 0;
}