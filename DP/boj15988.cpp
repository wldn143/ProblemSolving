#include <iostream>
using namespace std;
int t, n;
long long dp[1000001], mod = 1000000009;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i <= 1000000; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
    while (t--)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }
}