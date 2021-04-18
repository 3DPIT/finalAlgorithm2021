#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<int, int>rackedPoint;//주차된곳
int solution(int A[8]) {
	int answer = 0x80000000;
	vector<int>pointVector;
	int length = 8;//이건A의 배열 길이 받아서 쓰셈 
	int MinIndex = 0x7fffffff; int MaxIndex = 0x80000000;//최소 인덱스 최대 인덱스 산출
	for(int i=0;i<length;i++){
		if (rackedPoint[A[i] + 1000000000] == 0) {//주차된곳 미리 저장
			rackedPoint[A[i] + 1000000000] = 1;
		}
		pointVector.push_back(A[i] + 1000000000);//음수제거하기 위해서
		MinIndex = MinIndex > A[i] + 1000000000 ? A[i] + 1000000000 : MinIndex;
		MaxIndex = MaxIndex < A[i] + 1000000000 ? A[i] + 1000000000 : MaxIndex;		
	}
	sort(pointVector.begin(), pointVector.end());//순서대로 정렬
	for (int index = MinIndex; index < MaxIndex; index++) {
		int firstIndex=0;
		int lastIndex=0;
		if (rackedPoint[index] != 1) {//주차가능구역
			for (int i = 0; i < pointVector.size(); i++) {//현재주차할곳에서 작은값
				if (pointVector[i] < index) {
					firstIndex = pointVector[i];
				}
				else break;//같거나크면 종료
			}
			for (int i = 0; i < pointVector.size(); i++) {//현재주차할곳에서 큰값
				if (pointVector[i] > index) {
					lastIndex = pointVector[i];
					break;
				}
			}
			int num1 = index - firstIndex;
			int num2 = lastIndex - index;
			//여기서 num1과 num2에서 작은값을 최대로 저장하기
			if (num1 <= num2)answer = answer < num1 ? num1 : answer;
			else if (num1 > num2)answer = answer < num2 ? num2 : answer;
		}
	}
	if (answer == 0x80000000)answer = 0;//0인경우

	return answer;
}
int main(void) {
	int A[8] = { 10,0,8,2,-1,12,11,3 };
	cout<<solution(A);
}
