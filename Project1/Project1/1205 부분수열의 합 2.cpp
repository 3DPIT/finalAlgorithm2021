#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define NS 41 //�ԷµǴ� �迭�� �ִ� ũ��
int N;//�Է��� �迭�� ũ��
long long S;//ã�ƾ��ϴ� ��
int arr[NS];//�Էµ� ���ڰ� ����Ǵ� �迭
long long int ret;//�����
vector<int>leftV;//�߽��� �������� ������ �κ���
vector<int>rightV;//�߽��� �������� �������� �κ���
void init() {//�ʱ�ȭ �� �ʱ��Է� �Լ� 
	N = S = ret = 0;
	memset(arr, 0, sizeof(arr));
	scanf("%d %lld", &N,&S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
}
int D[40];
void dfs(int idx, int eidx, int sum, bool flag) {//�����ε���, ���ε���, ��, (0==L,1==R)
	if (idx == eidx) {
		if (flag == 0) {//���� 
			if (S == sum)ret++;
			leftV.push_back(sum);
		}
		else {//������
			if (S == sum)ret++;
			rightV.push_back(sum);
		}
		return;
	}
	dfs(idx + 1, eidx, sum + arr[idx], flag);
	dfs(idx + 1, eidx, sum, flag);

}
void numSearch() {//�κм����� �� ��ġ
	int m = (N / 2);
	dfs(0, m, 0, 0);//���� ��
	dfs(m, N, 0, 1);//������ ��
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
	//���� N�� 1�϶� Ȯ��
	init();
	numSearch();
	cout << ret << endl;
	return 0;
}