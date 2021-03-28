#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
struct coffee_data {
	int time; int num;
};
bool cmp(int a, int b) {
	return a > b;
}
bool cmp1(coffee_data a, coffee_data b) {
	if (a.time == b.time)return a.num > b.num;
	return a.time < b.time;
}
bool cmp2(coffee_data a, coffee_data b) {
	if (a.time == b.time)return a.num < b.num;
	return a.time < b.time;
}
vector<int> solution(int N, vector<int> coffee_times) {
	vector<int> answer;
	if (N == 1) {
		for (int i = 1; i <= coffee_times.size(); i++) {
			answer.push_back(i);
		}
		return answer;
	}
	vector<coffee_data> Coffee;
	for (int c_time_idx = 0; c_time_idx < coffee_times.size(); c_time_idx++) {
		Coffee.push_back({ coffee_times[c_time_idx], c_time_idx + 1 });
	}
	if (N == coffee_times.size()) {
		sort(Coffee.begin(), Coffee.end(), cmp2);
		for (int i = 0; i < Coffee.size(); i++) {
			answer.push_back(Coffee[i].num);
		}
		return answer;
	}
	vector<coffee_data> c_line;//���� Ŀ��
	vector<int>n_line;//���� Ŀ�Ǵ��
	priority_queue< int, vector<int>, greater<int> > sortCoffeeNum;
	 //vector<int>sortCoffeeNum;
	int time = 0;//�ð� ���
	while (1) {
		if (answer.size() == coffee_times.size())break;
		for (int i = 0; i < Coffee.size(); i++) {//�� ���� Ŀ�� �ӽſ� �ֱ�
			if (c_line.size() != N) {
				c_line.push_back(Coffee[i]);
				Coffee.erase(Coffee.begin() + i);
				i--;
			}
		}
		if (c_line.size() != 1 || c_line.size() != 0)sort(c_line.begin(), c_line.end(), cmp1);
		int del_time = c_line[0].time;
		for (int i = 0; i < c_line.size(); i++) {//����
			if (del_time == c_line[i].time) {
				sortCoffeeNum.push(c_line[i].num);
				c_line.erase(c_line.begin() + i);
				i--;
			}
			else {//�ð� �ٱ�
				c_line[i].time-= del_time;
			}
		}
		if (sortCoffeeNum.size() != 0) {//��� ������ �Ϸ� ��Ű��
			while (!sortCoffeeNum.empty()) {
				answer.push_back(sortCoffeeNum.top()); sortCoffeeNum.pop();
			}
		}
	}
	return answer;
}
int main(void) {
	vector<int>a = solution(3, { 4, 2, 2, 5, 3 });
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " " << endl;
	}
	return 0;
}