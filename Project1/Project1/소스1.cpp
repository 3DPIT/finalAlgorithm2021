#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;// �Է�
	cin >> s;
	int Bomb, Laser;// ��ź, ������
	Bomb = Laser = 0;
	int size = s.size();
	for (int i = 0; i < size; i++) {
		if (s[i] == '(')Bomb++;//��ź��
		else Laser++;//������ �߻��
	}
	if (Bomb == Laser)cout << "YES" << '\n';// ���ָ� ��������
	else cout << "No" << "\n";//���� ��� 

	return 0;
}