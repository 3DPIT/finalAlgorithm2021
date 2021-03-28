#include <string>
#include <vector>
#include<iostream>
#include <map>
using namespace std;

bool fine_chk(string fineS) {
	int alphabetChk[27] = { 0, };
	for (int i = 0; i < fineS.size(); i++) {
		if (alphabetChk[fineS[i]-'a'] == 0) {//좋은 문자열 체크
			alphabetChk[fineS[i]-'a'] = 1;
		}
		else return false;//중복 문자열 있어서 나쁜 문자열
	}
	return true;
}
int solution(string s) {
	int answer = 0;
	map<string, int>string_chk;
	for (int i = 0; i < s.size(); i++) {
		string copy_s="";
		for (int j = i; j < s.size(); j++) {
			copy_s += s[j];
			if (string_chk[copy_s] == 0&&fine_chk(copy_s)) {
				string_chk[copy_s] = 1;
			}
		}
	}
	answer = string_chk.size();
	return answer;
}

int main(void) {
	cout<<solution("zxzxz");
	return 0;
}