#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<int, int>rackedPoint;//�����Ȱ�
int solution(int A[8]) {
	int answer = 0x80000000;
	vector<int>pointVector;
	int length = 8;//�̰�A�� �迭 ���� �޾Ƽ� ���� 
	int MinIndex = 0x7fffffff; int MaxIndex = 0x80000000;//�ּ� �ε��� �ִ� �ε��� ����
	for(int i=0;i<length;i++){
		if (rackedPoint[A[i] + 1000000000] == 0) {//�����Ȱ� �̸� ����
			rackedPoint[A[i] + 1000000000] = 1;
		}
		pointVector.push_back(A[i] + 1000000000);//���������ϱ� ���ؼ�
		MinIndex = MinIndex > A[i] + 1000000000 ? A[i] + 1000000000 : MinIndex;
		MaxIndex = MaxIndex < A[i] + 1000000000 ? A[i] + 1000000000 : MaxIndex;		
	}
	sort(pointVector.begin(), pointVector.end());//������� ����
	for (int index = MinIndex; index < MaxIndex; index++) {
		int firstIndex=0;
		int lastIndex=0;
		if (rackedPoint[index] != 1) {//�������ɱ���
			for (int i = 0; i < pointVector.size(); i++) {//���������Ұ����� ������
				if (pointVector[i] < index) {
					firstIndex = pointVector[i];
				}
				else break;//���ų�ũ�� ����
			}
			for (int i = 0; i < pointVector.size(); i++) {//���������Ұ����� ū��
				if (pointVector[i] > index) {
					lastIndex = pointVector[i];
					break;
				}
			}
			int num1 = index - firstIndex;
			int num2 = lastIndex - index;
			//���⼭ num1�� num2���� �������� �ִ�� �����ϱ�
			if (num1 <= num2)answer = answer < num1 ? num1 : answer;
			else if (num1 > num2)answer = answer < num2 ? num2 : answer;
		}
	}
	if (answer == 0x80000000)answer = 0;//0�ΰ��

	return answer;
}
int main(void) {
	int A[8] = { 10,0,8,2,-1,12,11,3 };
	cout<<solution(A);
}
