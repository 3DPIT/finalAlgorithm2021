#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;// ÀÔ·Â
	cin >> s;
	int Bomb, Laser;// ÆøÅº, ·¹ÀÌÀú
	Bomb = Laser = 0;
	int size = s.size();
	for (int i = 0; i < size; i++) {
		if (s[i] == '(')Bomb++;//ÆøÅº¼ö
		else Laser++;//·¹ÀÌÀú ¹ß»ç¼ö
	}
	if (Bomb == Laser)cout << "YES" << '\n';// ¿ìÁÖ¸¦ ÁöÄ×À»¶§
	else cout << "No" << "\n";//¿ìÁÖ ¸ê¸Á 

	return 0;
}