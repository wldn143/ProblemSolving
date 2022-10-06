#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int n, m;
int res[1000001], a[1000001];
stack<int> st;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		while (st.size() && a[st.top()] < a[i])
		{
			res[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}
	for (int i = 0; i < n; i++)
	{
		int c = res[i];
		if (!c)
			c = -1;
		cout << c << " ";
	}
}
