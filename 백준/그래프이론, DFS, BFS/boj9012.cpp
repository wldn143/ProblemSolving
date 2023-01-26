#include<iostream>
#include<string>
using namespace std;
int t;
string s;
int main() {
	cin >> t;
	while (t--) {
		int flagStart=0;
		int open=0, close = 0;
		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')open++;
			else {
				if (open == 0) {
					flagStart = 0;
					break;
				}
				else {
					open--;
					flagStart = 1;
				}
			}
		}
		if (flagStart == 0 || open != 0)cout << "NO\n";
		else cout << "YES\n";
	}
	
}
