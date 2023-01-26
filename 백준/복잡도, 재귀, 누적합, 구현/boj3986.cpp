#include <iostream>
#include <algorithm>
#include<string>
#include <stack>

using namespace std;
int n,res;
string s;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		stack<char> p;
		for (char a:s) {
			if (p.size()&&a == p.top()) {
				p.pop();
			}
			else p.push(a);
		}
		if (p.empty()) res++;
	}
	cout << res;
}
