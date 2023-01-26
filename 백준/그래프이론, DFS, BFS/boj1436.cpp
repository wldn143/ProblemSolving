#include<iostream>
#include<string>
using namespace std;
int n, cnt;
int s=666;
int main() {
	cin >> n;
	while (1) {
		if (to_string(s).find("666")!=string::npos) {
			cnt++;
		}
		if (cnt == n) {
			cout << s;
			break;
		}
		s++;
	}
}
