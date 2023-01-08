#include <iostream>
#include <algorithm>
using namespace std;
int n, t[16], p[16], dp[21];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];

    for (int i = n; i >= 1; i--)
    {
        if (i + t[i] - 1 > n)
            dp[i] = dp[i + 1];
        else
            dp[i] = max(dp[i + 1], p[i] + dp[i + t[i]]);
    }
    cout << dp[1] << "\n";
}