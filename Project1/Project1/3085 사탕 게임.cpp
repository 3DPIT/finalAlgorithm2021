#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#define N_SIZE 51 // 맵의 최대 크기
int N;// 입력으로 주어지는 맵 
char board[N_SIZE][N_SIZE];//사탕 정보 저장
int Max = 0x80000000;//최대 길이 저장 
void init_input() {// 초기화 및 초기 입력
	//초기화
	N = 0;
	Max = 0x80000000;
	memset(board, 0, sizeof(board));
	//입력
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
			scanf("%s", &board[i]);		
	}
}
int chk() {// 최대 길이 캔디 리턴 
	// 행 검색
	int max = 0x80000000;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			char a = board[i][j];//현재 캔디
			int cnt = 1;//캔디 개수 저장
			for (int k = j + 1; k < N; k++) {
				if (a == board[i][k]) {//같은 캔디 경우
					cnt++;
				}
				else {//같은 캔디가 아니면 리턴
					break;
				}
			}
			max = max < cnt ? cnt : max;// 최대길이 캔디 저장
		}
	}

	// 열 검색
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			char a = board[i][j];//현재 캔디
			int cnt = 1;//캔디 개수 저장
			for (int k = i + 1; k < N; k++) {
				if (a == board[k][j]) {//같은 캔디 경우
					cnt++;
				}
				else {//같은 캔디가 아니면 리턴
					break;
				}
			}
			max = max < cnt ? cnt : max;// 최대길이 캔디 저장
		}
	}
	return max;
}
void search() {
	int num = chk();// 길이 최대값 저장
	Max = Max < num ? num : Max;
	for (int i = 0; i <N; i++) {
		for (int j = 0; j <N; j++) {
			//char copyCandy1 = board[i][j];//캔디1 저장 char copyCandy2 = board[i][j + 1];//캔디2 저장
			if (j<N-1&&board[i][j] != board[i][j+1]) {
				swap(board[i][j], board[i][j + 1]);//board[i][j] = copyCandy2; board[i][j + 1] = copyCandy1;// 위치 교환
				num = chk();// 길이 최대값 저장
				Max = Max < num ? num : Max;
				swap(board[i][j], board[i][j + 1]); //board[i][j] = copyCandy1; board[i][j + 1] = copyCandy2;// 원위치 교환
			}
			//copyCandy1 = board[i][j];//캔디1 저장 copyCandy2 = board[i+1][j];//캔디2 저장
			if (i<N-1&& board[i][j] != board[i+1][j]) {
				swap(board[i][j], board[i+1][j]); //board[i][j] = copyCandy2; board[i+1][j] = copyCandy1;// 위치 교환
				num = chk();// 길이 최대값 저장
				Max = Max < num ? num : Max;
				swap(board[i][j], board[i + 1][j]); //board[i][j] = copyCandy1; board[i+1][j] = copyCandy2;// 원위치 교환
			}
		}
	}
}
int main(void) 
{
	init_input();
	search();
	printf("%d\n", Max);
	return 0;
}