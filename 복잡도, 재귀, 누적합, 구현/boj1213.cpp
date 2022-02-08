#include <iostream>
#include <algorithm>
#include<string>
#include <string.h>
#include <map>
using namespace std;

string s,k,res,res1;
int cnt,l;
map<string, int> p;
string arr[26];

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		k = s[i];
		p[k] += 1;
	}
    
	for (auto c : p) {
		if (c.second % 2==1) {
			arr[l] = c.first;
			l++;
		}
		cnt +=c.second / 2;
		
	}
    
	if (cnt < (s.size() / 2)) {
		cout << "I'm Sorry Hansoo";
	}
    
	else {
		for (auto c : p) {
			for (int i = 0; i < c.second / 2; i++) {
				res += c.first;
			}
		}
		res1 = res;
		reverse(res.begin(), res.end());
		for (int i = 0; i < l; i++) {
			res1 += arr[i];
		}
		res1 += res;
		cout << res1;

	}
}
