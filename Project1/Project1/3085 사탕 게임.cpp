#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#define N_SIZE 51 // ���� �ִ� ũ��
int N;// �Է����� �־����� �� 
char board[N_SIZE][N_SIZE];//���� ���� ����
int Max = 0x80000000;//�ִ� ���� ���� 
void init_input() {// �ʱ�ȭ �� �ʱ� �Է�
	//�ʱ�ȭ
	N = 0;
	Max = 0x80000000;
	memset(board, 0, sizeof(board));
	//�Է�
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
			scanf("%s", &board[i]);		
	}
}
int chk() {// �ִ� ���� ĵ�� ���� 
	// �� �˻�
	int max = 0x80000000;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			char a = board[i][j];//���� ĵ��
			int cnt = 1;//ĵ�� ���� ����
			for (int k = j + 1; k < N; k++) {
				if (a == board[i][k]) {//���� ĵ�� ���
					cnt++;
				}
				else {//���� ĵ�� �ƴϸ� ����
					break;
				}
			}
			max = max < cnt ? cnt : max;// �ִ���� ĵ�� ����
		}
	}

	// �� �˻�
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			char a = board[i][j];//���� ĵ��
			int cnt = 1;//ĵ�� ���� ����
			for (int k = i + 1; k < N; k++) {
				if (a == board[k][j]) {//���� ĵ�� ���
					cnt++;
				}
				else {//���� ĵ�� �ƴϸ� ����
					break;
				}
			}
			max = max < cnt ? cnt : max;// �ִ���� ĵ�� ����
		}
	}
	return max;
}
void search() {
	int num = chk();// ���� �ִ밪 ����
	Max = Max < num ? num : Max;
	for (int i = 0; i <N; i++) {
		for (int j = 0; j <N; j++) {
			//char copyCandy1 = board[i][j];//ĵ��1 ���� char copyCandy2 = board[i][j + 1];//ĵ��2 ����
			if (j<N-1&&board[i][j] != board[i][j+1]) {
				swap(board[i][j], board[i][j + 1]);//board[i][j] = copyCandy2; board[i][j + 1] = copyCandy1;// ��ġ ��ȯ
				num = chk();// ���� �ִ밪 ����
				Max = Max < num ? num : Max;
				swap(board[i][j], board[i][j + 1]); //board[i][j] = copyCandy1; board[i][j + 1] = copyCandy2;// ����ġ ��ȯ
			}
			//copyCandy1 = board[i][j];//ĵ��1 ���� copyCandy2 = board[i+1][j];//ĵ��2 ����
			if (i<N-1&& board[i][j] != board[i+1][j]) {
				swap(board[i][j], board[i+1][j]); //board[i][j] = copyCandy2; board[i+1][j] = copyCandy1;// ��ġ ��ȯ
				num = chk();// ���� �ִ밪 ����
				Max = Max < num ? num : Max;
				swap(board[i][j], board[i + 1][j]); //board[i][j] = copyCandy1; board[i+1][j] = copyCandy2;// ����ġ ��ȯ
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