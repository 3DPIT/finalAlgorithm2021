#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int A[27];//ù��° �־����� �ܾ�
int B[27];//���� �ܾ� �� ������ �迭
int N;//���� �ܾ� �� 
int ret;//����� 
string s1;//�Էµ� �ܾ�		
string s2;//���� �ԷµǴ� ���ڿ�
void init() {//�ʱ�ȭ �� �ʱ� �Է�
	N = ret=0;
	s1.clear(); s2.clear();
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	scanf("%d", &N);
	cin >> s1;
	for (int i = 0; i < s1.size(); i++) {//�ܾ üũ
		A[s1[i] - 'A'] = 1;
	}
}
int one() {//�׳� ��
	int cnt = 0;//�´� �� Ȯ���ϱ�
	int visit[101] = { 0, };//üũ
	for (int i = 0; i <s2.size(); i++) {
		for (int j = 0; j < s1.size(); j++) {
			if (s2[i] == s1[j]&&visit[j]==0) {
				cnt++; visit[j] = 1;
				break;
			}
		}
	}
	if (cnt == s2.size()) {
		ret++;//����� �ܾ� Ȯ��
		return true;
	}
	return false;
}
void two() {//�ѹ��� �߰��ؼ� ��
	for (int i = 0; i < 27; i++) {
		s1.push_back(i + 'A');
		if (one()) {//�ѹ��� �´��� Ȯ���ϸ� �Ǵϱ� 1���� �ϰ� 
			s1.pop_back();
			break;
		}
		s1.pop_back();
	}
}
void tree() {//�ѹ��ڻ��� ��
	for (int i = 0; i < s1.size(); i++) {
		char cChar;//���� ����
		cChar = s1[i];
		s1.erase(s1.begin() + i);//����
		if (one()) {//�ѹ��� �´��� Ȯ���ϸ� �Ǵϱ� 1���� �ϰ� 
			s1.insert(s1.begin() + i, cChar);//�ٽ� ����
			break;
		}
		s1.insert(s1.begin()+i,cChar);//�ٽ� ����
	}
}
void four() {//Ư�����ڿ� �����ϰ� Ž��
	for (int j = 0; j < 27; j++) {
		for (int i = 0; i < s1.size(); i++) {
			char cChar;//���� ����
			cChar = s1[i];
			s1[i] = j + 'A';
				if (one()) {//�ѹ��� �´��� Ȯ���ϸ� �Ǵϱ� 1���� �ϰ� 
					s1[i] = cChar;
					break;
				}
				s1[i] = cChar;//�ٽ� ����
		}
	}
}
void search() {//Ž�� ����
	for (int i = 0; i < N - 1; i++) {
		cin >> s2;
		int s1Len = s1.size(); int s2Len = s2.size();
		// ���� ������ ��� 1, 4
		if (s1Len == s2Len) {
			//1. �׳� ��
			if (one() == 1)continue;
			//4. �ѹ��� �ٲ㼭 ��
			four();
		}
		// ���̺��� ���� ��� 3 (���̰� 1)
		else if (s1Len - s2Len == 1) {
			//3. �ѹ��� ���� ��
			tree();
		}
		// ���� ���� ū ��� 2 (���̰� 1)
		else if (s2Len - s1Len == 1) {
			//2. �ѹ��� �߰� �ؼ� �� 
			two();
		}
	}
}
int main(void) {
	init();
	search();
	cout << ret << endl;
	return 0;
}