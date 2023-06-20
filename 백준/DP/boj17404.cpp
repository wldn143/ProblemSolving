#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;
int n, ret = MAX;
int cost[1001][3];
int dp[1001][3];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (j == i)
                dp[0][j] = cost[0][j];

            else
                dp[0][j] = MAX;
        }

        for (int j = 1; j < n; j++)
        {
            dp[j][0] = cost[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
            dp[j][1] = cost[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
            dp[j][2] = cost[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
        }

        for (int j = 0; j <= 2; j++)
        {
            if (i == j)
                continue;
            ret = min(ret, dp[n - 1][j]);
        }
    }
    cout << ret;
}
