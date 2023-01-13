#include <iostream>
using namespace std;
int n, k;
long long dp[201][201], mod = 1000000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
        dp[1][i] = 1;

    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
            }
        }
    }
    cout << dp[k][n] % mod << "\n";
}