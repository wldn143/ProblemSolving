#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t, n, k, a, b, w, delay[1001], dp[1001];
vector<int> map[1001];

int dfs(int idx)
{
    if (!map[idx].size())
        return delay[idx];

    if (dp[idx] != -1)
        return dp[idx];

    for (int i = 0; i < map[idx].size(); i++)
    {
        int x = map[idx][i];
        dp[idx] = max(dp[idx], dfs(x) + delay[idx]);
    }
    return dp[idx];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> delay[i];
            dp[i] = -1;
        }
        for (int i = 0; i < k; i++)
        {
            cin >> a >> b;
            map[b].push_back(a);
        }
        cin >> w;
        cout << dfs(w) << "\n";
        for (int i = 1; i <= n; i++)
        {
            map[i].clear();
        }
    }
}