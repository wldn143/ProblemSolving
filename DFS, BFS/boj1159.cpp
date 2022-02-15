#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
int n;
string s;
int arr[26] = { 0, };
int flag = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		arr[s[0] - 'a']+=1;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) {
			cout << char(97 + i);
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << "PREDAJA" << "\n";
	}
}
