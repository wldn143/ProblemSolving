#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int n, c;
vector<pair<int, int>> a;
bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		//아 애초에 a.size가 0이구나...
		if (a.size() == 0)
		{
			a.push_back(make_pair(k, 1));
			continue;
		}
		for (int j = 0; j < a.size(); j++)
		{
			if (a[j].first == k)
			{

				a[j].second++;
				break;
			}
			if (j == a.size() - 1)
			{
				a.push_back(make_pair(k, 0));
			}
		}
	}
	stable_sort(a.begin(), a.end(), compare);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].second; j++)
		{
			cout << a[i].first << " ";
		}
	}
}