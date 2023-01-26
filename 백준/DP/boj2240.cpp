#include <iostream>
#include <algorithm>
using namespace std;
int t, w, ans;
int tree[1004], dp[31][2][1001];
int main()
{
    cin >> t >> w;
    for (int i = 1; i <= t; i++)
        cin >> tree[i];

    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (j == 0)
            {
                dp[j][0][i] = dp[j][0][i - 1] + (tree[i] == 1);
            }
            else
            {
                dp[j][0][i] = max(dp[j][0][i - 1] + (tree[i] == 1), dp[j - 1][1][i - 1] + (tree[i] == 1));
                dp[j][1][i] = max(dp[j][1][i - 1] + (tree[i] == 2), dp[j - 1][0][i - 1] + (tree[i] == 2));
            }
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            ans = max(ans, dp[j][i][t]);
        }
    }
    cout << ans << "\n";
}
