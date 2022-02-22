#include<iostream>
#include<string>
using namespace std;
int a[30],mcnt,jcnt,mflag,flag;
int main() {
	string s;
	while (1) {
		cin >> s;
		if (s == "end")break;
		mcnt = 0, jcnt = 0, mflag = 1, flag = 0;
		for (int i = 0; i < s.size(); i++) {
			int idx = s[i] - 'a';//이거도 굳이?
			a[idx]++;//굳이? 그냥 직관적으로 해도될듯..?
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') mcnt++, jcnt = 0,mflag=0;
			else jcnt++, mcnt = 0;
			if (mcnt == 3 || jcnt == 3) {
				flag = 1;
				break;
			}
			if (i >= 1) {
				if (s[i - 1] == s[i] && (s[i] != 'e' && s[i] != 'o')) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0 && mflag == 0) {
			cout << "<" << s << ">" << " is acceptable.\n";
		}
		else cout << "<" << s << ">" << " is not acceptable.\n";
	}
}
