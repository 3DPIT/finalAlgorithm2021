//2
#include<iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(string inp_str) {
	vector<int> answer;
	//1. 8 ≤ password 길이 ≤ 15 에 포함되지 않는다면
	if (inp_str.size() < 8 || inp_str.size() > 15) answer.push_back(1);
	//2. password는 아래 4 종류의 문자 그룹을 제외한, 다른 어떤 문자도 포함해서는 안됩니다.
	//[1] 알파벳 대문자(A~Z) A
	//[2] 알파벳 소문자(a~z) a
	//[3] 숫자(0~9) num
	//[4] 특수문자(~!@#$%^&*) special
	//3. password는(2.)에서 명시된 4 종류의 문자 그룹 중에서 3 종류 이상을 포함해야 합니다.
	int two_flag = 0;//2번 규칙 위배 확인
	int A = 0; int a = 0; int num = 0; int special = 0;
	int chkChar[200] = { 0, };//문자열 아스키 코드 최대
	for (int inp_str_index = 0; inp_str_index < inp_str.size(); inp_str_index++) {
		chkChar[inp_str[inp_str_index]]++;
		if ('A' <= inp_str[inp_str_index] && inp_str[inp_str_index] <= 'Z')A = 1;
		else if ('a' <= inp_str[inp_str_index] && inp_str[inp_str_index] <= 'z')a = 1;
		else if ('0' <= inp_str[inp_str_index] && inp_str[inp_str_index] <= '9')num = 1;
		else if ('~' == inp_str[inp_str_index] || '!' == inp_str[inp_str_index] || '@' == inp_str[inp_str_index]
						|| '#' == inp_str[inp_str_index] || '$' == inp_str[inp_str_index] || '%' == inp_str[inp_str_index]
						|| '^' == inp_str[inp_str_index] || '&' == inp_str[inp_str_index] || '*' == inp_str[inp_str_index])special = 1;
		else { two_flag = 1; }
	}
	if (two_flag)answer.push_back(2);
	if (A + a + num + special < 3)answer.push_back(3);
	//4. password에 같은 문자가 4개 이상 연속될 수 없습니다.
	for (int inp_str_index = 0; inp_str_index < inp_str.size()-1; inp_str_index++) {
		char compChar = inp_str[inp_str_index];
		int cnt = 1;//비교 문자 같은지 여부
		int copy_index = inp_str_index;
		for (int compi = inp_str_index + 1; compi < inp_str.size(); compi++) {
			if (compChar != inp_str[compi])break;
			cnt++;
			copy_index = compi;
		}
		if (cnt != 1) {
			answer.push_back(4); break;
		}
	}
	//5. password에 같은 문자가 5개 이상 포함될 수 없습니다.
	for (int passwordSamei = 0; passwordSamei < 200; passwordSamei++) {
		if (chkChar[passwordSamei] >= 5) {
			answer.push_back(5); break;
		}
	}
	if (answer.size() == 0)answer.push_back(0);
	return answer;
}
int main(void) {
	vector<int>a = solution("}>}>}>}>A>}>aTa+!12-3");
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	vector<int>a1 = solution("aaaaZZZZ)");
	for (int i = 0; i < a1.size(); i++) {
		cout << a1[i] << " ";
	}
	cout << endl;
	vector<int>a2 = solution("CaCbCgCdC888834A");
	for (int i = 0; i < a2.size(); i++) {
		cout << a2[i] << " ";
	}
	cout << endl;
	vector<int>a3 = solution("UUUUU");
	for (int i = 0; i < a3.size(); i++) {
		cout << a3[i] << " ";
	}
	cout << endl;
	vector<int>a4 = solution("ZzZz9Z824");
	for (int i = 0; i < a4.size(); i++) {
		cout << a4[i] << " ";
	}
	cout << endl;





	return 0;
}