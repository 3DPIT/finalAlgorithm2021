#include<stdio.h>
#include<string>
using namespace std;
int numAble[10] = { 1,1,1,1,1,1,1,1,1,1};// 정상인 버튼 1, 비정상 버튼 0 표시
bool chkNum(int num) {// 번호 리모컨으로 누를 수 있는 번호 인지 확인 // 좀 느림
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
	return true;// 가능 한 숫자라면 1 반환
}
int chkNum1(int c) {//엄청나게 빠름 
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
	int num = 0;// 목표 채널
	scanf("%d", &num);
	int M = 0;//고장난 버튼의 개수
	scanf("%d", &M);
	for (int m = 0; m < M; m++) {//버튼 고장 난것 0으로 표시
		int breakNum = 0;//고장 버튼 숫자
		scanf("%d", &breakNum);
		numAble[breakNum] = 0;// 고장 표시 
	}
	int min = 0x7fffffff;// 최소 누르는 횟수 저장 변수
	int absNum = 0;
	if (num == 100) {//100 채널에서 부터 시작이니까.	
		printf("%d", 0);
		return 0;
	}
	int a = abs(num - 100);
	absNum = a;
	min = min > absNum ? absNum : min;//최소값 저장
	for (int i = 0; i <= 1000000; i++) {// 번호 검색 

		 if (chkNum1(i)) {//가능한 번호라면 목표 번호까지 몇번 더 누르는지 확인
			 int a = to_string(i).size();
			 a = a + abs(num - i);
			min = min > a ? a : min;//최소값 저장
		}
	}
	printf("%d", min);
	return 0;
}