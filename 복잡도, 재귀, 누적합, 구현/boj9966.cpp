#include <iostream>
#include <algorithm>
#include<string>
#include <string.h>
#include <map>
using namespace std;

int n;
string p,s,front,back,tmp;
int check;

int main() {

	cin >> n;
	cin >> p;

	check = p.find('*');
	front = p.substr(0, check);
	back = p.substr(check + 1);

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp.length() < front.size() + back.size())
			cout << "NE\n";
		else {
			if (front == tmp.substr(0, front.size())
				&& back == tmp.substr(tmp.size() - back.size())) {
				cout << "DA\n";
			}
			else {
				cout << "NE\n";
			}
		}
	}
}
