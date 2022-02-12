#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
int n;
string s,ret;
int main() {
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			if (s[i] >= 78 && s[i] <= 90) s[i] = s[i] - 13;
			else s[i] = s[i] + 13;
		}
		else if (s[i] >= 97 && s[i] <= 122) {
			if (s[i] >= 110 && s[i] <= 122) s[i] = s[i] - 13;
			else s[i] = s[i] + 13;
		}		
		ret += s[i];
	}
	cout << ret;
}
