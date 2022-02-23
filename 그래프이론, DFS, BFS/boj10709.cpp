#include<iostream>
using namespace std;
int h,w;
char c;
int idx = -1;
int cnt;

int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		int cnt = 0;
		int idx = -1;
		for (int j = 0; j < w; j++) {
			cin >> c;
			if (c == 'c') {
				cnt = 0;
				idx = j;
				cout << cnt << " ";
			}
			else {
				if (idx != -1) {
					cnt++;
					cout << cnt << " ";
				}
				else {
					cout << "-1" << " ";
				}
			}
		}
		cout << "\n";
	}
}
