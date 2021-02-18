#include <string>
#include <vector>
#include<map>
#include<iostream>
using namespace std;
struct Data{
	string name; int start; int time; int chk; int last;
};
int solution(int n, vector<string> recipes, vector<string> orders) {
	int answer = 0;
	int time = 0;
	vector<Data> order;
	map<string, int>m;//해쉬
	for (int i = 0; i < recipes.size(); i++) {
		string a = "";//주문명 저장
		int idx = 0;
		while (recipes[i][idx] != ' ') {
			a += recipes[i][idx++];
		}
		string b = "";//굽는 시간
		for (int j = idx+1; j < recipes[i].size(); j++) {
			b += recipes[i][j];
		}
		m[a] = stoi(b);
	}

	for (int i = 0; i < orders.size(); i++) {
		string a = "";//주문명 저장
		int idx = 0;
		while (orders[i][idx] != ' ') {
			a += orders[i][idx++];
		}
		string b = "";//시작시간
		for (int j = idx + 1; j < orders[i].size(); j++) {
			b += orders[i][j];
		}
		int c = m[a];
		if (orders.size() - 1 == i) {
			order.push_back({ a,stoi(b), c,0,1 });
		}
		else
			order.push_back({ a,stoi(b), c });

	}
	int oven[50001] = { 0, };
	vector<int>a;
	while (1) {
		++time;

		for (int i = 0; i < order.size(); i++) {
			if (oven[i] != 0) {
				order[oven[i]-1].time--;
			}
		}
		for (int i = 0; i < order.size(); i++) {
			if (order[i].time != -2 && order[i].start == time) {//대기 인원먼저
				a.push_back(i);
			}
		}
		int flag = 0;
		for (int i = 0; i < order.size(); i++) {
			if (order[i].time == -1) {//오븐에서빼기
				order[i].time = -2;
				if (order[i].last == 1) {
					flag = 1;
					break;
				}
				for (int j = 0; j < n; j++) {//비어있는 오븐 탐색
					if (oven[j] == i + 1) {
						oven[j] = 0;
						order[i].chk = 0;
						break;
					}
				}//오븐 검사 넣고 빼기

			}
		}
		if (flag == 1)break;
			for(int k=0;k<a.size();k++){
				for (int j = 0; j < n; j++) {//비어있는 오븐 탐색
					if (oven[j] == 0) {
						oven[j] = a.front() + 1;//오븐 넣기
						order[a.front()].time--;
						order[a.front()].chk = 1;
						a.erase(a.begin	());
						break;
					}
				}
			}

		//탈출 조건
				int cnt = 0;
				for (int i = 0; i < order.size(); i++) {
					if (order[i].time == -2)cnt++;
				}
				if (cnt == order.size())break;

	}
	return answer=time;
}
int main(void) {
	cout << solution(3, { "SPAGHETTI 3", "FRIEDRICE 2", "PIZZA 8" }, { "PIZZA 1", "FRIEDRICE 2", "SPAGHETTI 4", "SPAGHETTI 6", "PIZZA 7", "SPAGHETTI 8" });
}