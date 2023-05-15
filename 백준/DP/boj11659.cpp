#include <iostream>
#include <algorithm>
using namespace std;
int n, m, x, i, j, dp[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        dp[i] = dp[i - 1] + x;
    }
    while (m--)
    {
        cin >> i >> j;
        cout << dp[j] - dp[i - 1] << "\n";
    }
}