#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int n, num[1000001], dp[1000001];
vector<int> v;
stack<int> s;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n; i++)
    {
        if (v.empty())
        {
            v.push_back(num[i]);
            dp[i] = 1;
        }
        else
        {
            if (v[v.size() - 1] < num[i])
            {
                v.push_back(num[i]);
                dp[i] = v.size();
            }
            else
            {
                auto p = lower_bound(v.begin(), v.end(), num[i]);
                *(p) = num[i];
                dp[i] = p - v.begin() + 1;
            }
        }
    }
    cout << v.size() << "\n";
    int len = v.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (dp[i] == len)
        {
            s.push(num[i]);
            len--;
        }
    }
    while (s.size())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}