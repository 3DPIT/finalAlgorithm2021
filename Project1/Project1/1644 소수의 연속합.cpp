#include <iostream>
#include<vector>
using namespace std;
 int MAX = 4000000;
bool check[4000000 + 1]; // true: 지워짐, false: 지워지지 않음
int chk[4000000 + 1];
vector<int >v;
void primeNum() {
	check[0] = check[1] = true;
	for (int i = 2; i*i <= MAX; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}
	for (int i = 0; i <= MAX; i++) {
		if (check[i] == false) {
			v.push_back(i);
		}
	}
}
int main() {
	int m;
	cin >> m;
	MAX = m+50;
	int p1 = 0; int p2 = 0;
	int cnt = 0;
	primeNum();
	cnt = v.size();
	int cm = m;

	m = cnt-1;
	cnt = 0;
	int L, R;
	L = R = 0;
	int sum = 0;
	if (cm == 3) {
		cout << 1 << endl;
		return 0;
	}
	while (L <= R && R <= m) {
		if (sum >=cm) {
			sum -= v[L];
			L++;
		}
		else if (sum < cm) {
			sum += v[R];
			R++;
		}
		if (sum == cm)cnt++;

	}
	
	cout << cnt << endl;
	return 0;
}

//다시 풀이 예정