#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001], n, k, temp, INF = 987654321;
int main()
{
    cin >> n >> k;
    fill(dp, dp + 10001, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp > 10000)
            continue;
        for (int j = temp; j <= k; j++)
        {
            dp[j] = min(dp[j - temp] + 1, dp[j]);
        }
    }
    if (dp[k] == INF)
        cout << -1 << "\n";
    else
        cout << dp[k] << "\n";
}
