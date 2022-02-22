#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
vector<pair<int, int>> a;
//int a[1004];
int n, c, x,flag,idx,idx2;
int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		v.push_back(make_pair(0, 0));
		a.push_back(make_pair(0, 0));
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		for (int j = 0; j < n; j++) {
			if (a[j].first == x) { //탐색시 발견
				flag = 1;
				idx2 = j;
				break;
			}
		}

		if (flag == 1) {//발견하면
			v[idx2].second++;
			flag = 0;
		}
		
		else {
			a[idx].first = x;
			a[idx].second=idx;
			v[idx].first = x;
			v[idx].second++;
			idx++;
		}
	}
	
	int k = 0;
	int tmp1 = 0;
	int tmp2 = 0;

	while (1) {
		if (k == n - 1)break;
		if (v[k + 1].second > v[k].second) {
			tmp1 = v[k].first;
			tmp2 = v[k].second;
			v[k].first = v[k + 1].first;
			v[k].second = v[k + 1].second;
			v[k + 1].first = tmp1;
			v[k + 1].second = tmp2;
			k = 0;
		}
		else {
			k++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].second; j++) {
			if (v[i].first > 0) {
				cout << v[i].first << " ";

			}
		}
	}
}
