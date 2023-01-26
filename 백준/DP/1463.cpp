#include <iostream>
#include <algorithm>
using namespace std;
int n, dp[1000001];
int main()
{
    cin >> n;
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0 && i % 3 == 0)
        {
            dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        }
        else if (i % 3 == 0)
            dp[i] = min(dp[i - 1] + 1, dp[i / 3] + 1);
        else if (i % 2 == 0)
            dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
        else
            dp[i] = dp[i - 1] + 1;
    }
    cout << dp[n] << "\n";
    return 0;
}