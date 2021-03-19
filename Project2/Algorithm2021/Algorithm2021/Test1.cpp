#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
string s1;//돌리는 문자열
string s2;//확인하는 문자열
void rotateString() {
	char copyChar;//복사 저장하는 변수
	copyChar = s1[0];
	for (int copyIndex = 1; copyIndex < s1.size(); copyIndex++) {
		s1[copyIndex - 1] = s1[copyIndex];
	}
	s1[s1.size() - 1] = copyChar;
}

bool chkString() {// 문자열 체크하는 함수
	int cnt = 0;//틀린 개수 저장
	if (s1.size() != s2.size()) {//길이가 다른 문자열이 들어왔을 경우
		return 0;
	}
	for (int s1Index = 0; s1Index < s1.size(); s1Index++) {//문자열 돌리기
		//문자열 돌리기 
		int flag = 0;//틀린것 확인
		for (int s2Index = 0; s2Index < s2.size(); s2Index++) {//확인하는 곳
			if (s1[s2Index] != s2[s2Index]) {
				flag = 1;//틀린거 체크
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