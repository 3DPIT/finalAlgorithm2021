#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int A, B, C, D;//���� 0�̵Ǵ� �� �� �� �̱�
long long arr[40001][4];//�Է����� �־����� �迭
int N;// �迭�� ũ��
long long int ret;//��� ��
void init() {//�ʱ� �Է�
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
}

void sumForArr() {//�迭 ��
	vector<long long>v1;
	vector<long long>v2;
	for (int a = 0; a < N; a++) {//�̸� �� ����
		for (int b = 0; b < N; b++) {
			v1.push_back(arr[a][0] + arr[b][1]);
			v2.push_back(arr[a][2] + arr[b][3]);
		}
	}
	//sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v1.size(); i++) {
		long long low = lower_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		long long high =upper_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
		if (low == v1.size())continue;
		if (v1[i]+v2[low]==0) {
			cout << high << " " << low << endl;ret++;
		}
	}
}
int main(void) {
	init();
	sumForArr();
	cout << ret << endl;
	return 0;
}

//4
//1 2 3 - 5
//5 3 4 2
//- 3 - 4 2 1
//- 1 5 - 3 - 1