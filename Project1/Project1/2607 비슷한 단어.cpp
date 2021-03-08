#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int A[27];//첫번째 주어지는 단어
int B[27];//비교할 단어 를 저장할 배열
int N;//비교한 단어 수 
int ret;//결과값 
string s1;//입력된 단어		
string s2;//다음 입력되는 문자열
void init() {//초기화 및 초기 입력
	N = ret=0;
	s1.clear(); s2.clear();
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	scanf("%d", &N);
	cin >> s1;
	for (int i = 0; i < s1.size(); i++) {//단어별 체크
		A[s1[i] - 'A'] = 1;
	}
}
int one() {//그냥 비교
	int cnt = 0;//맞는 지 확인하기
	int visit[101] = { 0, };//체크
	for (int i = 0; i <s2.size(); i++) {
		for (int j = 0; j < s1.size(); j++) {
			if (s2[i] == s1[j]&&visit[j]==0) {
				cnt++; visit[j] = 1;
				break;
			}
		}
	}
	if (cnt == s2.size()) {
		ret++;//비슷한 단어 확인
		return true;
	}
	return false;
}
void two() {//한문자 추가해서 비교
	for (int i = 0; i < 27; i++) {
		s1.push_back(i + 'A');
		if (one()) {//한번만 맞는지 확인하면 되니까 1번만 하게 
			s1.pop_back();
			break;
		}
		s1.pop_back();
	}
}
void tree() {//한문자빼서 비교
	for (int i = 0; i < s1.size(); i++) {
		char cChar;//문자 저장
		cChar = s1[i];
		s1.erase(s1.begin() + i);//제거
		if (one()) {//한번만 맞는지 확인하면 되니까 1번만 하게 
			s1.insert(s1.begin() + i, cChar);//다시 삽입
			break;
		}
		s1.insert(s1.begin()+i,cChar);//다시 삽입
	}
}
void four() {//특정문자열 변경하고 탐색
	for (int j = 0; j < 27; j++) {
		for (int i = 0; i < s1.size(); i++) {
			char cChar;//문자 저장
			cChar = s1[i];
			s1[i] = j + 'A';
				if (one()) {//한번만 맞는지 확인하면 되니까 1번만 하게 
					s1[i] = cChar;
					break;
				}
				s1[i] = cChar;//다시 복구
		}
	}
}
void search() {//탐색 시작
	for (int i = 0; i < N - 1; i++) {
		cin >> s2;
		int s1Len = s1.size(); int s2Len = s2.size();
		// 같은 길이인 경우 1, 4
		if (s1Len == s2Len) {
			//1. 그냥 비교
			if (one() == 1)continue;
			//4. 한문자 바꿔서 비교
			four();
		}
		// 길이보다 작은 경우 3 (차이가 1)
		else if (s1Len - s2Len == 1) {
			//3. 한문자 빼서 비교
			tree();
		}
		// 길이 보다 큰 경우 2 (차이가 1)
		else if (s2Len - s1Len == 1) {
			//2. 한문자 추가 해서 비교 
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