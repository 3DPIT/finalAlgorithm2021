#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define NS 41 //입력되는 배열의 최대 크기
int N;//입력할 배열의 크기
long long S;//찾아야하는 수
int arr[NS];//입력된 숫자가 저장되는 배열
long long int ret;//결과값
vector<int>leftV;//중심을 기준으로 왼쪽의 부분합
vector<int>rightV;//중심을 기준으로 오른쪽의 부분합
void init() {//초기화 및 초기입력 함수 
	N = S = ret = 0;
	memset(arr, 0, sizeof(arr));
	scanf("%d %lld", &N,&S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
}
int D[40];
void dfs(int idx, int eidx, int sum, bool flag) {//시작인덱스, 끝인덱스, 합, (0==L,1==R)
	if (idx == eidx) {
		if (flag == 0) {//왼쪽 
			if (S == sum)ret++;
			leftV.push_back(sum);
		}
		else {//오른쪽
			if (S == sum)ret++;
			rightV.push_back(sum);
		}
		return;
	}
	dfs(idx + 1, eidx, sum + arr[idx], flag);
	dfs(idx + 1, eidx, sum, flag);

}
void numSearch() {//부분수열의 합 서치
	int m = (N / 2);
	dfs(0, m, 0, 0);//왼쪽 합
	dfs(m, N, 0, 1);//오른쪽 합
	if (S == 0)ret -= 2;
	leftV.pop_back(); rightV.pop_back();
	sort(rightV.begin(), rightV.end());
 	for (int i = 0; i < leftV.size(); i++) {
		int num = S - leftV[i];
		int low = lower_bound(rightV.begin(), rightV.end(),num) - rightV.begin();
		int high = upper_bound(rightV.begin(), rightV.end(),num) - rightV.begin();
			ret += (high - low);	
	}
}
int main(void) {
	//주의 N이 1일때 확인
	init();
	numSearch();
	cout << ret << endl;
	return 0;
}