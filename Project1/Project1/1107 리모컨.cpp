#include<stdio.h>
#include<string>
using namespace std;
int numAble[10] = { 1,1,1,1,1,1,1,1,1,1};// ������ ��ư 1, ������ ��ư 0 ǥ��
bool chkNum(int num) {// ��ȣ ���������� ���� �� �ִ� ��ȣ ���� Ȯ�� // �� ����
	string s = to_string(num);
	if (num == 0) {
		if (numAble[0] == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int cnt = 0;
	for (int si = 0; si < s.size(); si++) {
			if (numAble[s[si] - '0']==0) {
				return false;
			}
	}
	return true;// ���� �� ���ڶ�� 1 ��ȯ
}
int chkNum1(int c) {//��û���� ���� 
	if (c == 0) {
		if (numAble[0]==0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int len = 0;
	while (c > 0) {
		if (numAble[c % 10]==0) {
			return 0;
		}
		len += 1;
		c /= 10;
	}
	return 1;
}
int main(void) {
	int num = 0;// ��ǥ ä��
	scanf("%d", &num);
	int M = 0;//���峭 ��ư�� ����
	scanf("%d", &M);
	for (int m = 0; m < M; m++) {//��ư ���� ���� 0���� ǥ��
		int breakNum = 0;//���� ��ư ����
		scanf("%d", &breakNum);
		numAble[breakNum] = 0;// ���� ǥ�� 
	}
	int min = 0x7fffffff;// �ּ� ������ Ƚ�� ���� ����
	int absNum = 0;
	if (num == 100) {//100 ä�ο��� ���� �����̴ϱ�.	
		printf("%d", 0);
		return 0;
	}
	int a = abs(num - 100);
	absNum = a;
	min = min > absNum ? absNum : min;//�ּҰ� ����
	for (int i = 0; i <= 1000000; i++) {// ��ȣ �˻� 

		 if (chkNum1(i)) {//������ ��ȣ��� ��ǥ ��ȣ���� ��� �� �������� Ȯ��
			 int a = to_string(i).size();
			 a = a + abs(num - i);
			min = min > a ? a : min;//�ּҰ� ����
		}
	}
	printf("%d", min);
	return 0;
}