#include<iostream>
#include<algorithm>
using namespace std;
int t,n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		int tcnt = 0, fcnt=0;
		cin >> n;
		int tpow = 2;
		int fpow = 5;
		while (tpow <= n && fpow <= n) {
			tcnt += n / tpow;
			tpow *= 2;
			fcnt += n / fpow;
			fpow *= 5;
		}
		cout << min(tcnt, fcnt) << '\n';
	}
}
