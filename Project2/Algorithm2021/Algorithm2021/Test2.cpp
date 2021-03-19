
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
string Alpabet_Num_String;//알파벳과 숫자가 섞인 문자열
void ChkNumString();//숫자 찾아서 알파벳으로 바꾸기
int main(void) {
	cin >> Alpabet_Num_String;//초기 입력
	ChkNumString();

}
void ChkNumString() {
	for (int Alpabet_Num_String_Index = 0; Alpabet_Num_String_Index < Alpabet_Num_String.size(); Alpabet_Num_String_Index++)
	{
		if ('0'<=Alpabet_Num_String[Alpabet_Num_String_Index]&&Alpabet_Num_String[Alpabet_Num_String_Index]<='9') {//숫자라면
			char printChar = Alpabet_Num_String[Alpabet_Num_String_Index + 1];//출력할 문자
			int finalIndex= Alpabet_Num_String[Alpabet_Num_String_Index ]-'0';
			for (int printCntIndex = 0; printCntIndex < finalIndex; printCntIndex++) {//출력
				cout << printChar;
			}
		}
	}
}
