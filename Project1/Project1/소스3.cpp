#include<iostream>
using namespace std;
int arr[10001];//À§Ä¡
int main(void) {
	int N, M, E;
	cin >> N >> M >> E;
	int max = 0x80000000;
	for (int i = 0; i < N; i++) {
		int p;//¶¥Äá
		cin >> p;
		max = max < p ? p : max;
		arr[p] = 1;//¶¥Äá Ç¥½Ã
	}
	//¹è¿­ º¹»ç
	int carr[1001];
	for (int i = 0; i < 1001; i++) {
		carr[i] = arr[i];
	}
	//¿ŞÂÊ Å½»ö
	int cnt = 0;
	for (int i = E; i <= max; i++) {
		if (carr[i] == 1) {
			cnt++;
			carr[i] = 2;
		}
		if (cnt == M) break;
	}
	int start = -1;
	int end = -1;
	int flag = 0;
	carr[E] = 2;
	arr[E] = 2;
	for (int i= 0; i <= max; i++) {
		if (carr[i] == 2) {
			if (flag == 0) {
				flag = 1;
				start = i;
			}
			end = i;
		}
	}
	int min = 0x7fffffff;
	min = min > ((end - start) - 1) ? ((end - start) - 1) : min;
	//¿À¸¥ÂÊ Å½»ö
	cnt = 0;
	for (int j = E; j >= 1; j--) {
		if (arr[j] == 1) {
			cnt++;
			arr[j] = 2;
		}
		if (cnt == M) break;
	}
	start = -1; end = -1;
	flag = 0;
	for (int i = 0; i <= max; i++) {
		if (arr[i] == 2) {
			if (flag == 0) {
				flag = 1;
				start = i;
			}
			end = i;
		}
	}
	min = min > ((end - start) - 1) ? ((end - start) - 1) : min;
	
	cout << min << endl;
}