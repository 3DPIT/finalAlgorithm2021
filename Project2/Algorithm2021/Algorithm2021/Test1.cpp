#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
string s1;//������ ���ڿ�
string s2;//Ȯ���ϴ� ���ڿ�
void rotateString() {
	char copyChar;//���� �����ϴ� ����
	copyChar = s1[0];
	for (int copyIndex = 1; copyIndex < s1.size(); copyIndex++) {
		s1[copyIndex - 1] = s1[copyIndex];
	}
	s1[s1.size() - 1] = copyChar;
}

bool chkString() {// ���ڿ� üũ�ϴ� �Լ�
	int cnt = 0;//Ʋ�� ���� ����
	if (s1.size() != s2.size()) {//���̰� �ٸ� ���ڿ��� ������ ���
		return 0;
	}
	for (int s1Index = 0; s1Index < s1.size(); s1Index++) {//���ڿ� ������
		//���ڿ� ������ 
		int flag = 0;//Ʋ���� Ȯ��
		for (int s2Index = 0; s2Index < s2.size(); s2Index++) {//Ȯ���ϴ� ��
			if (s1[s2Index] != s2[s2Index]) {
				flag = 1;//Ʋ���� üũ
				break;
			}
		}
		if (flag == 1)cnt++;
		if (flag == 0)	return 1;
		rotateString();
	}
	if (cnt == s1.size())return 0;
	//cout << cnt << endl;
}
int main(void) {
	cin >> s1 >> s2;
	cout <<chkString();
	return 0;
}