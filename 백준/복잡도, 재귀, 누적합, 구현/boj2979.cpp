#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
int main() {
	int A, B, C, a, b;
	int cnt[104] = {0,};
	int sum=0;
	cin >> A >> B >> C;
    
	for (int i = 0; i < 3; i++) {
		cin >> a >> b;
		for (int j = a; j < b; j++) {
			cnt[j]+=1;
		}
	}
    
	for (int i : cnt) {
		if (i == 1) sum += A;
		if (i == 2) sum += B*2;
		if (i == 3) sum += C * 3;
	}
	cout << sum << endl;
}
