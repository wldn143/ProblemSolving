#include <iostream>
using namespace std;
int n, dp[1001][11], ret;
int main()
{
    cin >> n;
    for (int i = 0; i <= 9; i++)
        dp[1][i] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= j; k++)
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
        }
    }
    for (int i = 0; i <= 9; i++)
        ret = (ret + dp[n][i]) % 10007;
    cout << ret << "\n";
}