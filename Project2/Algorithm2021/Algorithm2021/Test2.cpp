
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
string Alpabet_Num_String;//���ĺ��� ���ڰ� ���� ���ڿ�
void ChkNumString();//���� ã�Ƽ� ���ĺ����� �ٲٱ�
int main(void) {
	cin >> Alpabet_Num_String;//�ʱ� �Է�
	ChkNumString();

}
void ChkNumString() {
	for (int Alpabet_Num_String_Index = 0; Alpabet_Num_String_Index < Alpabet_Num_String.size(); Alpabet_Num_String_Index++)
	{
		if ('0'<=Alpabet_Num_String[Alpabet_Num_String_Index]&&Alpabet_Num_String[Alpabet_Num_String_Index]<='9') {//���ڶ��
			char printChar = Alpabet_Num_String[Alpabet_Num_String_Index + 1];//����� ����
			int finalIndex= Alpabet_Num_String[Alpabet_Num_String_Index ]-'0';
			for (int printCntIndex = 0; printCntIndex < finalIndex; printCntIndex++) {//���
				cout << printChar;
			}
		}
	}
}
