#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s;
int main() {
	while (1) {
		getline(cin, s);
		if (s == ".")break;

		stack<char> stk;
        
		int flag = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[')stk.push(s[i]);
			else {
				if (s[i] == ')') {
					if (!stk.empty() && stk.top() == '(') stk.pop();
					else {
						flag = 0;
						break;
					}
				}
				if (s[i] == ']') {
					if (!stk.empty() && stk.top() == '[') stk.pop();
					else {
						flag = 0;
						break;
					}
				}
			}
		}

		if (flag==1&&stk.empty()) cout << "yes\n";
		else cout << "no\n";
		
	}
}
