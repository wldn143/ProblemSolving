#include <iostream>
#include <algorithm>
using namespace std;
int n, a, dp[1001], ret;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (!a && !dp[i + 1] && i < n)
        {
            ret = 1;
            break;
        }
        for (int j = i + 1; (j <= i + a) && (j <= n); j++)
        {
            if (!dp[j])
                dp[j] = dp[i] + 1;
        }
    }

    if (ret)
        cout << -1 << "\n";
    else
        cout << dp[n] << "\n";
}