#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <string.h>
#include<cstdio>
using namespace std;
char K[10001];//K개의 스킬
vector<int>v[101];
string s[101];// 스킬정보저장
int visit[101];
vector<int>a1;
void dfs(int idx,int flag) {//깊이 탐색
	int vsize = v[idx].size();
	for (int i = 0;i < vsize; i++) {
		if (visit[v[idx][i]] == 0) {
			a1.push_back(v[idx][i]);
			visit[v[idx][i]] = 1;
			dfs(v[idx][i],1);
			flag = 0;
			a1.pop_back();
		}
	}
	if (flag == 1) {
		int a1size = a1.size();
		for (int i = 0; i < a1size; i++) {
			cout << s[a1[i]] << " ";
		}
		cout << endl;
	}

}
int main() {
	int N;//스킬의 개수
	cin.getline(K, 100);
	cin >> N;
	int kSize = strlen(K);
	string a;//스킬문자열 재정의를 위함
	int idx = 0;//스킬 개수
	for (int i = 0; i < kSize; i++) {
		if (K[i] != ' ')
			a += K[i];
		else {
			s[idx++] += a;
			a.clear();
		}
	}
	s[idx++] += a;
	a.clear();
	for (int i = 0; i < N; i++) {//연계 스킬 저장
		string aSkill, bSkill;
		cin >> aSkill >> bSkill;
		int a, b;
		int cnt = 0;
		for (int j = 0; j < idx; j++) {//스킬 번호 찾기
			if (s[j] == aSkill) {
				a = j;
				cnt++;
			}
			if (s[j] == bSkill) {
				b = j;
				cnt++;
			}
			if (cnt == 2)break;
		}
		v[a].push_back(b);
	}
	for (int i = 0; i < kSize; i++) {
		visit[i] = 1;
		a1.push_back(i);
		dfs(i,0);
		a1.clear();
	}
	return 0;
}