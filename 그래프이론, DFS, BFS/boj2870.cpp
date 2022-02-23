#include<iostream>
#include<string>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<string> a;
string res;

bool cmp(string a, string b) {
	if (a.size() == b.size())return a < b;
	return a.size() < b.size();
}

int main() {
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (isdigit(s[j])) {//숫자면
				if (res.length() == 1 && res == "0") {
					res = "";
				}
				res += s[j];
				if (j == s.length() - 1) {
					a.push_back(res);
					res = "";
				}
			}
			else {//문자면
				if (res != "") {
					a.push_back(res);
				}
				res = "";
			}
		}
	}
	sort(a.begin(),a.end(),cmp);
	for (int i = 0; i < a.size();i++) {
		cout << a[i] << "\n";
	}
}
