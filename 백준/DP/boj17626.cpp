#include <iostream>
#include <algorithm>
using namespace std;
int n, k, dp[50001], mx = 50000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int mn = mx;
        for (int j = 1; j * j <= i; j++)
        {
            mn = min(mn, dp[i - j * j]);
        }
        dp[i] = mn + 1;
    }
    cout << dp[n] << "\n";
}