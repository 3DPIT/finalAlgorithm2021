#include<stdio.h>
#include<vector>
using namespace std;
#define NS 100001//�ִ� ������
int N, K;// ��ȣ, ���ųѹ�
void init() {
scanf("%d %d", &N, &K);
}
void yose() {//�似Ǫ�� Ǯ��
	printf("<");
	int num[NS] = { 0 };
	int cK = -1;
	int cN = N;
	vector<int>v;//���� ����
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	for (int i = 1; i <N; i++) {
		cK = (cK + K)%cN;
		printf("%d, ",v[cK]);
		v.erase(v.begin() + cK);
		cK--; cN--;
	}
	printf("%d>",v[0]);
}
int main(void) {
	init();
	yose();

	return 0;
}
//���׸�Ʈ Ʈ�� ���� Ǯ��