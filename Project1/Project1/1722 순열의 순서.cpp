#include<stdio.h>
#include<iostream>
using namespace std;
#define N_SIZE 21// �ִ� �Է����� �־����� �� 
int N;//�Է����� �־����� ��
long long int facArr[N_SIZE];//n! �̸�����
int chkNum[N_SIZE];//���� ���� üũ
int Q_num;//���� ��ȣ 1 �̸� k��° ���� ���
			//   ��ȣ 2 �̸� ���� ������ ��ġ ���
void init() {//�ʱ�ȭ �� �Է�
	N = Q_num = 0;
	scanf("%d", &N);
	scanf("%d", &Q_num);
}
void fac() {//���丮�� �̸� ����
	facArr[0] = 1;
	facArr[1] = 1;
	for (int i = 2; i <= N; i++) {
		facArr[i] = i;
		facArr[i]*=facArr[i-1];
	}
}
int main(void) {
	init();
	fac();//���丮�� �̸� ����
	if (Q_num == 1) {//k��° ���� ���
		long long int k;//���� ��ġ ����
		scanf("%lld", &k);
		long long int cnt = 0;//N�� �������� �ݺ��� Ż��
		long long int use = 0, rem = k;//����Ѱ� , ���� �� ����
		int facNum = N - 1;//���丮�� ���ϴ� ��
		while (1) {//�ݺ�
			if (cnt == N)break;
			for (int i = 1; i <= N; i++) {//1���� N���� �ݺ�
				if (chkNum[i] == 1)continue;
				use += facArr[facNum];//������ ��ġ
				rem -= facArr[facNum];//���� ��ġ
				if (rem <= 0) {
					rem += facArr[facNum];
					use -= facArr[facNum];
					facNum--;
					chkNum[i] = 1;//���� Ȯ���� �� üũ
					cnt++;
					cout << i << " ";//Ȯ���� �� ���
					break;
				}
			}
		}
	}
	else if (Q_num == 2) {//�Է����� �־��� ������ ��ġ ���
		int numArr[21];//�Է� ���� ����
		for (int i = 0; i < N; i++) {
			scanf("%d", &numArr[i]);
		}
		int cnt = 0;//Ż�� ���� N�� ������ 
		int facNum = N - 1;//���丮�� ���ϴ� ��
		long long int use = 0;//���� ��ġ�� �� ����
		for (int i = 0; i < N; i++) {//0�� �ε������� Ž��
			chkNum[numArr[i]] = 1;
			for (int j = 1; j <numArr[i]; j++) {
				if (chkNum[j] == 1)continue;//����� ���� �ǳ� �ٱ�
				use += facArr[facNum];
			}
			facNum--;
		}
		cout << use + 1;
	}
	return 0;
}