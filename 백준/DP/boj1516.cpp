#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, t, val[501], dp[501];
vector<int> map[501];

int go(int idx)
{
    if (!map[idx].size())
        return val[idx];

    if (dp[idx])
        return dp[idx];

    for (int i = 0; i < map[idx].size(); i++)
    {
        int x = map[idx][i];
        dp[idx] = max(dp[idx], go(x) + val[idx]);
    }

    return dp[idx];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        while (1)
        {
            cin >> t;
            if (t == -1)
                break;
            map[i].push_back(t);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << go(i) << "\n";
}