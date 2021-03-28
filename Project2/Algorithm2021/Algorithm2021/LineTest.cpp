//2
#include<iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(string inp_str) {
	vector<int> answer;
	//1. 8 �� password ���� �� 15 �� ���Ե��� �ʴ´ٸ�
	if (inp_str.size() < 8 || inp_str.size() > 15) answer.push_back(1);
	//2. password�� �Ʒ� 4 ������ ���� �׷��� ������, �ٸ� � ���ڵ� �����ؼ��� �ȵ˴ϴ�.
	//[1] ���ĺ� �빮��(A~Z) A
	//[2] ���ĺ� �ҹ���(a~z) a
	//[3] ����(0~9) num
	//[4] Ư������(~!@#$%^&*) special
	//3. password��(2.)���� ��õ� 4 ������ ���� �׷� �߿��� 3 ���� �̻��� �����ؾ� �մϴ�.
	int two_flag = 0;//2�� ��Ģ ���� Ȯ��
	int A = 0; int a = 0; int num = 0; int special = 0;
	int chkChar[200] = { 0, };//���ڿ� �ƽ�Ű �ڵ� �ִ�
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
	//4. password�� ���� ���ڰ� 4�� �̻� ���ӵ� �� �����ϴ�.
	for (int inp_str_index = 0; inp_str_index < inp_str.size()-1; inp_str_index++) {
		char compChar = inp_str[inp_str_index];
		int cnt = 1;//�� ���� ������ ����
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
	//5. password�� ���� ���ڰ� 5�� �̻� ���Ե� �� �����ϴ�.
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