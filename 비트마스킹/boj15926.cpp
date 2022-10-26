#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
int n, cnt, res = 0, a[200001];
string s;
stack<int> st;
int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i);
        if (s[i] == ')' && !st.empty())
        {
            a[st.top()] = 1;
            a[i] = 1;
            st.pop();
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i])
            cnt++;
        else
        {
            res = max(res, cnt);
            cnt = 0;
        }
    }
    res = max(res, cnt);
    cout << res << "\n";
}
