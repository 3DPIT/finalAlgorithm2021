#include <iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;
map<string, int>CONTENTS, GAME, HARDWARE, PORTAL, SI;
string JOB[5] = { "CONTENTS","GAME","HARDWARE","PORTAL","SI" };//사전순으로 저장된 순서로 바로 뽑기위해서
int job_Score[5];//사전순으로 점수가 저장됨 
string solution(vector<string> table, vector<string> languages, vector<int> preference) {
	string answer = "";
	//정보 저장
	for (int i = 0; i < table.size(); i++) {//과목별로 테이블이 현재는 고정되어있지만 바뀐경우 
		//과목이 그대로라는 전제조건하에 알아서 점수 부여
		int score = 5; //5점부터 1점까지 부여하기 위해서
		string jobString = "";//잡정보
		int flag = 0;//잡 표시만 하기위해
		for (int j = 0; j < table[i].size(); j++) {
			if(flag==0)jobString += table[i][j];
			if (table[i][j] == 32) {//공백인 경우
				flag = 1;
				j++;
				string lan = "";//언어
				if (j == table[i].size())break;
				while (table[i][j] != 32 && j < table[i].size()) {//공백이거나 범위 넘는경우 종료
					lan += table[i][j];
					j++;
				}
				if (jobString == "CONTENTS ")CONTENTS[lan] = score--;
				if (jobString == "GAME ")GAME[lan] = score--;
				if (jobString == "HARDWARE ")HARDWARE[lan] = score--;
				if (jobString == "PORTAL ")PORTAL[lan] = score--;
				if (jobString=="SI ")SI[lan] = score--; //현재는 테이블값 고정
				j--;
			}
		}
	}
	//점수 측정
	for (int lan_index = 0; lan_index < languages.size(); lan_index++) {
		auto a = SI[languages[lan_index]];
		auto b = CONTENTS[languages[lan_index]];
		auto c = HARDWARE[languages[lan_index]];
		auto d = PORTAL[languages[lan_index]];
		auto e = GAME[languages[lan_index]];
		job_Score[4] += (a*preference[lan_index]);
		job_Score[0] += (b*preference[lan_index]);
		job_Score[2] += (c*preference[lan_index]);
		job_Score[3] += (d*preference[lan_index]);
		job_Score[1] += (e*preference[lan_index]);
	}
	int maxNum = 0x80000000;
	for (int max_index = 0; max_index < 5; max_index++) {//최대 점수 뽑기
		maxNum = maxNum < job_Score[max_index] ? job_Score[max_index] : maxNum;
	}
	for (int lanScore_index = 0; lanScore_index < 5; lanScore_index++) {
		if (maxNum == job_Score[lanScore_index]) {
			answer += JOB[lanScore_index];
			break;
		}
	}
	return answer;
}
int main(void) {
	cout<<solution({ "SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA" },
		{ "JAVA", "JAVASCRIPT" }, {7,5});
}