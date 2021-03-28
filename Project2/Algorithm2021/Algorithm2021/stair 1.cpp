#include <string>
#include <vector>
#include<iostream>
using namespace std;
vector<string>flag_rules_argument_V;
vector<string>flag_rules_argument_type_V;
//1. program으로 시작합니다.
//2. 각 flag argument는 대응하는 flag의 flag_argument_type과 일치합니다.
//3. 각 flag는 0번이나 1번 나타납니다.
//4. flag_rules에 존재하는 flag만 나타납니다.
void argument_add(int idx, vector<string> flag_rules) {
	string flag_rules_argument, flag_rules_argument_type;	//argument, type
	int argument_flag = 1;
	for (int content_index = 0; content_index < flag_rules[idx].size(); content_index++) {
		if (flag_rules[idx][content_index] == '-') {//명령어
			while (flag_rules[idx][content_index] != 32) {//공백까지 //argument
				flag_rules_argument += flag_rules[idx][content_index];
				/*if (flag_rules_argument.size() != 2) {
					content_index+=2;
				}
				else */content_index++;
			}
			argument_flag = 0;
		}
		if (argument_flag == 0) {//타입
			content_index++;
			while (flag_rules[idx][content_index] != 32 && content_index != flag_rules[idx].size()) {
				flag_rules_argument_type += flag_rules[idx][content_index];
				content_index++;
			}
			flag_rules_argument_V.push_back(flag_rules_argument);//저장
			flag_rules_argument_type_V.push_back(flag_rules_argument_type);
			flag_rules_argument.clear(); flag_rules_argument_type.clear();
		}
	}
}
bool commandChk(string argument, char word) {
	int idx = 0;
	for (int argument_row = 0; argument_row < flag_rules_argument_V.size(); argument_row++) {
		if (argument == "-e") { idx = 3; break; }
		if (argument == flag_rules_argument_V[argument_row]) {//일치하는거면
			if (flag_rules_argument_type_V[argument_row][0] == 'S'&&
				flag_rules_argument_type_V[argument_row][1] == 'T')idx = 0;
			else if (flag_rules_argument_type_V[argument_row][0] == 'N'&&
				flag_rules_argument_type_V[argument_row][1] == 'U'&&
				flag_rules_argument_type_V[argument_row][2] == 'M')idx = 1;
			else if (flag_rules_argument_type_V[argument_row][0] == 'N'&&
				flag_rules_argument_type_V[argument_row][1] == 'U'&&
				flag_rules_argument_type_V[argument_row][2] == 'L')idx = 3;
		}
	}

	if (idx == 0) {//STRING
		int in_chk = 0;
		if ('A' <= word && word <= 'Z')in_chk = 1;
		if ('a' <= word && word <= 'z')in_chk = 1;
		if (in_chk == 0)return false;//잘못 입력
	}
	if (idx == 1) {//NUMBER
		int in_chk = 0;
		if ('0' <= word && word <= '9') in_chk = 1;
		if (in_chk == 0)return false;//잘못 입력
	}
	if (idx == 3) {//NULL

	}
}
vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
	vector<bool> answer;
	//argumet와 type 뽑아내기
	for (int flag_rules_index = 0; flag_rules_index < flag_rules.size(); flag_rules_index++) {
		argument_add(flag_rules_index, flag_rules);
	}
	for (int commands_index = 0; commands_index < commands.size(); commands_index++) {//참 거짓 여부 판단
		bool check = true;
		string commandString = "";//명령어 뽑아내기
		int flagFirst = 1;
		for (int com_column = 0; com_column < commands[commands_index].size()+1; com_column++) {
			int while_out_flag = 0;
			if (commands[commands_index][com_column] == 32||com_column== commands[commands_index].size()) {//공백인경우
				if (flagFirst) {
					if (program.size() != commandString.size()) {
						check = false; flagFirst = 0; while_out_flag = 1; answer.push_back(0); break;
					}
					else {//비교
						flagFirst = 0;
						for (int comp_i = 0; comp_i < program.size(); comp_i++) {
							if (program[comp_i] != commandString[comp_i]) {//프로그램명 다른경우
								check = false;	flagFirst = 0; answer.push_back(0); while_out_flag = 1; break;
							}
						}
					}
				}// 프로그램명 일치 않함
				else if (commandString[0] == '-') {//명령어 만난경우
					com_column += 1;
					if (commandString == "-e") {
						break;
					}
					while (commands[commands_index][com_column] != ' ') {
						if (!commandChk(commandString, commands[commands_index][com_column])) {//잘못 된 경우
							while_out_flag = 1;
							check = false;
							answer.push_back(0);
							break;
						}
						com_column++;
					}
				}
				else if (commandString[0] != '-') {//그냥 명령어 없이 시작인경우
					while_out_flag = 1;
					check = false;
					answer.push_back(0);
					break;
				}
				if (while_out_flag)break;
				commandString.clear();
				com_column++;
				if (com_column == commands[commands_index].size())break;

			}
			commandString += commands[commands_index][com_column];
		}
		if(check==true)answer.push_back(1);
	}
	return answer;
}
int main(void) {
	//vector<bool>v=solution("line",
	//	{"-s STRING", "-n NUMBER", "-e NULL"},
	//	{"line -n 100 -s hi -e", "lien -s Bye"});
	vector<bool>v = solution("line",
		{ "-s STRING", "-n NUMBER", "-e NULL" },
		{ "line -s 123 -n HI", "line fun" });
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}